/* Funktion aendern() zum ändern der Dateien in einem Verzeichnis.
Verzeichnis und Dateien werden vorgegeben, ebenso eine Vorlage zur Umbenennung.
Diese Funktion wurde erstellt im Rahmen des Projekts MathoMadaja.
Wunderbärchen!
*
* Datei: <aendern.cpp>
* Autor: <Markus Schüler>
* Datum: <04.06.2008>
*
* Historie: 04.06.08 Umwandlung der Strings auf C-Winapi-Standard gebracht / Marco Bezzon
*			    255 durch MAX_PATH ersetzt
* 	         09.06.08 Keine Rueckgabe mehr von Pointer, sondern Verarbeitung durch Call by Reference / Marco Bezzon
*/
#include "aendern.h"

/**
* Funktionsbeschreibung:  Diese Funktion liest ein spezifiziertes Verzeichnis (cdateipfad) aus und sucht sich dort <br>
*				  zum String passende Dateien und benennt diese anhand cdateivorlage um. <br>
*	<br>
* Eingabeparameter: cdateipfad: 'c:/test/ *' wird in dieser Form vom Hauptprogramm uebergeben. <br> 
*			    cdateivorlage: 'read#.txt', wobei '#' durch eine fortlaufende Nummer ersetzt wird <br>
* <br>
* Rueckgabe: Bei erfolgreichem Aendern wird der STATUS ERFOLG zurueckgegeben, ansonsten SFEHLER <br>
*
* Besonderes: Weitere Bearbeitung von Strings in Unterprogrammen (auch in diesem Modul deklariert)
*/
STATUS aendern(char * cdateipfad, char * cdateivorlage)
{
	HANDLE fHandle;
	WIN32_FIND_DATA wfd;
	char Dest[MAX_PATH];
	char cquelldateipfad[MAX_PATH];
	char czieldateipfad[MAX_PATH];
	char cverzeichnispfad[MAX_PATH];
	char tmpStr[MAX_PATH];
	TCHAR T_strUnicode[MAX_PATH];
	
	int idateianzahl=0;
	int ilaufendenummer=1;
	int iWandlung;

	/*cverzeichnispfad soll nur den Pfad des Verzeichnisses beinhalten, keine Dateibezeichnungen*/
	pfad_erstellen(tmpStr, cdateipfad);
	strcpy(cverzeichnispfad, tmpStr); /*Vorbereitung, wird für später benötigt*/
	
	iWandlung = MultiByteToWideChar( CP_ACP, 0, cdateipfad, MAX_PATH, T_strUnicode, MAX_PATH);
	
	/*Umwandeln des Dateipfades in UniCode für findfirst()-Fkt*/
	fHandle = FindFirstFile(T_strUnicode, &wfd);

	if (fHandle == INVALID_HANDLE_VALUE)
	{
		return(SFEHLER);
	}
	else
	{
		/*do-Schleife durchsucht das Verzeichnis nach passenden Dateien*/
		/*Die Schleife wird zweimal durchlaufen, das erste Mal, um die Zahl der umzubenennden Datein zu ermitteln,
		das zweite Mal zum umbenennen*/

/*Schleife 1: Dateien zählen*/
		do
		{
			  /* Eintrag nur behandeln, wenn es nicht . oder .. ist
				(werden nur bei Unterverzeichnissen mit zurückgeliefert)*/
	        if (!( (wfd.cFileName[0]=='.') && ( (wfd.cFileName[1]=='.' && wfd.cFileName[2]==0) || wfd.cFileName[1]==0 ) ))
			{
				if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
					idateianzahl++;
				}
			}
		}
		while (FindNextFile(fHandle,&wfd));
		FindClose(fHandle);
		
		fHandle = FindFirstFile(T_strUnicode,&wfd);
/*Schleife 2: umbenennen*/
		do
		{
	        if (!( (wfd.cFileName[0]=='.') && ( (wfd.cFileName[1]=='.' && wfd.cFileName[2]==0) || wfd.cFileName[1]==0 ) ))
			{
				if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
					/*Vorbereiten der Parameter für rename()*/
					convert_in_str(tmpStr, wfd.cFileName, wcslen(wfd.cFileName));
					strcpy(Dest, tmpStr);
					quelldateiname_erstellen(tmpStr, cverzeichnispfad, Dest);
					strcpy (cquelldateipfad, tmpStr);
					tmpStr[0] = '\0';
					zieldateiname_erstellen(tmpStr, cverzeichnispfad,cdateivorlage,ilaufendenummer,idateianzahl);
					strcpy (czieldateipfad, tmpStr);
					/*Hier wird nun endlich umbenannt...*/
					rename(cquelldateipfad,czieldateipfad);
					ilaufendenummer++;
				}
			}
		}
		while (FindNextFile(fHandle,&wfd));
	}

	FindClose(fHandle);

	return (ERFOLG);
}





/*Diese Funktion erstellt den korrekten Dateinamen samt Pfad zur Nutzung der rename()-Funktion*/
/**
* Funktionsbeschreibung:  Diese Funktion erstellt den korrekten Dateinamen samt Pfad zur Nutzung der rename()-Funktion <br>
*	<br>
* Eingabeparameter: String cpfad <br> 
*			    String cdateiname <br>
* <br>
* Rueckgabe: Zeiger auf die neue Zeichenkette, bestehend aus Pfad und Dateiname <br>
* <br>
* Besonderes: <br>
*/
void quelldateiname_erstellen(char *cdateipfad, char * cpfad,char * cdateiname)
{		
	strcpy(cdateipfad,cpfad);
	strcat(cdateipfad,cdateiname);
}


/**
* Funktionsbeschreibung:  Diese Funktion erstellt den Namen der Zieldatei für die Funktion rename(). <br>
*				  Sie ersetzt das '#' in cdateiname durch die Nummer, die uebergeben wird. <br>
*				   und achtet dabei auf evtl nötige Führungsnullen bei mehr als 10/100/1000 Dateien <br>
* Eingabeparameter: String cpfad,  String cdateiname, aktuelle Nummer der Datei, Gesamtanzahl der Dateien in Selektion <br>
* <br>
* Rueckgabe: Zeiger auf die neue Zeichenkette, bestehend aus Pfad, Dateiname und Nummerierung <br>
* <br>
* Besonderes: <br>
*/
void zieldateiname_erstellen(char *cdateipfad, char * cpfad,char * cdateiname,int idateinummer,int idateianzahl)
{
	char cdateinameend[MAX_PATH];
	int i=0;
	int i2=0;
	int i3=0;
	char ceinfuegen[5] = "0000";

	cdateinameend[0] = '\0';
	
	/*Prüfen, wie viele Stellen für die Nummerierung eingefügt werden müssen,
	erstellen des Einfügestrings*/
	if (idateianzahl<10)
	{
		sprintf(ceinfuegen,"%d",idateinummer);
	}
	if ((idateianzahl>=10)&&(idateianzahl<100))
	{
		sprintf(ceinfuegen,"%.2d",idateinummer);
	}
	if ((idateianzahl>=100)&&(idateianzahl<1000))
	{
		sprintf(ceinfuegen,"%.3d",idateinummer);
	}
	if (idateianzahl>=1000)
	{
		sprintf(ceinfuegen,"%.4d",idateinummer);
	}

	/*Hier wird der neue Dateiname zusammengebaut, dh das '#' wird durch den Einfuegenstring ersetzt,
	nachfolgende chars des Dateinamens werden nach hinten geschoben*/
	i2=0;
	for(i=0;i <= (int) strlen(cdateiname);i++)
	{
		if(cdateiname[i2]=='#')
		{
			for (i3=0; i3 <= (int) strlen(ceinfuegen);i3++)
			{
				cdateinameend[i2+i3]=ceinfuegen[i3];
			}

			i2+=(strlen(ceinfuegen)-1);
		}
		else
		{
			cdateinameend[i2]=cdateiname[i];
		}
		i2++;
	}
	cdateinameend[i2-1]='\0';

	strcpy(cdateipfad,cpfad);
	strcat(cdateipfad,cdateinameend);
}



/**
* Funktionsbeschreibung:  Diese Funktion schneidet bei einem übergebenen Pfad samt Dateinamen den Dateinamen ab, <br>
*				  so dass nur noch der Pfad einschließlich abschliessendem / stehe bleibt. <br>
*				   <br>
* Eingabeparameter: String cpfad1 <br>
* <br>
* Rueckgabe: Zeiger auf die neue Zeichenkette, bestehend aus Pfad ohne Datei <br>
* <br>
* Besonderes: <br>
*/
void pfad_erstellen(char *cpfad, char * cpfad1)
{
	int i=0;
	int ipfadlaenge=0;

	ipfadlaenge=strlen(cpfad1);
	
	/*Ermitteln der Pfadlaenge inkl. abschl. '/' */
	while(cpfad1[ipfadlaenge] != '/')
	{
		ipfadlaenge--;
	}
	
	/*charweise Kopieren des chararrays bis zum abschließenden '/' */
	for(i=0;i<=ipfadlaenge;i++) 
	{
		cpfad[i]=cpfad1[i];
	}

	cpfad[ipfadlaenge+1]='\0'; /*Anfügen des ArrayEndes*/
}


/**
* Funktionsbeschreibung:  Diese Funktion konvertiert ein TCHAR oder LPTSTR in ein C-Array. <br>
*				   <br>
* Eingabeparameter: Zeichenkette vom Typ TCHAR, Anzahl der Elemente in dieser Kette. <br>
* <br>
* Rueckgabe: Zeiger auf C-Zeichenkette. <br>
* <br>
* Besonderes: <br>
*/
void convert_in_str(char *str, TCHAR *to_conv, int laenge) {
int j;

for (j = 0; j < laenge; j++) {
	if (to_conv[j] != 0) 
		str[j] = (char) to_conv[j];
}
str[j] = '\0';
}
