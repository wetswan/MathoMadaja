/* Führt die Funktion kopieren aus von Quell- nach Ziel-Verzeichnis
* kann Ordner oder Dateien kopieren
*
* Datei: kopieren.cpp Autor: Thomas Harr
* Datum: 26.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
* - Marco Bezzon: Zugriff auf Konvertierungsfunktion aus globalfunctions.h
*/
#include "kopieren.h"

/** <br>
* Funktionsbeschreibung: Diese Funktion ist für das Kopieren von Verzeichnissen / Dateien zustaendig<br>
* <br>
* Eingabeparameter:  Der Pfad von welcher Quelle nach welches Ziel kopiert werden soll.<br>
* <br>
* Rueckgabe: Funktion gibt ERFOLG zurück wenn Kopiervorgang erfolgreich ausgefuehrt wurde, <br>
*		ansonsten wird SFEHLER zurueckgegeben. <br>
* <br>
*/
STATUS kopieren(char *strVerweisQuelle, char *strVerweisZiel) {
	/** Strings, die nachher aus \\ statt / bestehen sollen */
	char strConvVerweisQuelle[MAX_PATH];
	char strConvVerweisZiel[MAX_PATH];
	
	int iWandlung1, iWandlung2;
	/** Initialisierung zweier Variable für die Stringumwandlung */
	TCHAR T_strQuelle[MAX_PATH], T_strZiel[MAX_PATH];
	
	/** Umwandlung der Strings */
	convSlashToBackslash(strConvVerweisQuelle, strVerweisQuelle);
	convSlashToBackslash(strConvVerweisZiel, strVerweisZiel);
	
    /** Umwandlung des vom Hauptmodul erhaltenen Strings */
	iWandlung1 = MultiByteToWideChar( CP_ACP, 0, strConvVerweisQuelle, MAX_PATH, T_strQuelle, MAX_PATH);
	iWandlung2 = MultiByteToWideChar( CP_ACP, 0, strConvVerweisZiel, MAX_PATH, T_strZiel, MAX_PATH);

	/** Initialisierung zweier Variablen mit der Laenge des Pfades */
	int i_lenZiel = wcslen(T_strZiel), i_lenQuelle = wcslen(T_strQuelle);
	
	/** Initialisierung zweier Variablen deren Laenge um 2 erhoeht wurde um den Pfad mit doppel 0 abzuschliessen */
	TCHAR *pszFrom = new TCHAR[i_lenQuelle+2];
	TCHAR *pszTo   = new TCHAR[i_lenZiel+2]; 

	/** Das Kopieren des Pfads in die Variablen mit vergroessertem Speicherplatz */
	wcscpy(pszFrom, T_strQuelle);
	wcscpy(pszTo, T_strZiel);
	
	/** Das Anhaengen der Pfadabschliessenden Doppel 0 */
	pszFrom[i_lenQuelle] = 0;
	pszFrom[i_lenQuelle+1] = 0;
	pszTo[i_lenZiel] = 0;
	pszTo[i_lenZiel+1] = 0;

	/** Aufrufen des structs der SHFileOperation und zuweisen der Variablen */
	SHFILEOPSTRUCT fileop;
	fileop.hwnd = NULL; // no status display
	fileop.wFunc = FO_COPY; // delete operation
	fileop.pFrom = (LPCTSTR) pszFrom; // source file name as double null terminated string
	fileop.pTo   = (LPCTSTR) pszTo; // destination file name as double null terminated string
	fileop.fFlags = FOF_NOCONFIRMMKDIR | FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI; // do not prompt the user   
    fileop.fAnyOperationsAborted= FALSE;
	fileop.lpszProgressTitle= NULL;
	fileop.hNameMappings = NULL;


	/** Zuweisen der Integer-Variable mit dem Rueckgabewert von SHFileOperation */
	int ret = SHFileOperation(&fileop);
	
	/** Loeschen des Pfades aus den Variablen (Speicherplatz freigeben) */
	delete [] pszFrom;
	delete [] pszTo;

	/** Rueckgabewert der SHFileOperation umwandeln in Rueckgabe des Status an die main.c */
	if( ret==0 && iWandlung1 != 0 && iWandlung2 != 0 ){
		return (ERFOLG);
	}
	else{
		return (SFEHLER);
	}
}
