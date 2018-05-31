/* Diese Quellcode-Datei erstellt die Log-Datei für das MathoMadaja-Projekt.
* Neue Textzeilen werden immer an der obersten Zeile eingefügt.
*
* Datei: logdatei.cpp Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "zeitstempel.h"
#include "logdatei.h"

#include <stdio.h>
#include <time.h>
#include <locale.h>


/**
* Funktionsbeschreibung:  logdatei soll den Start und das Ende einer Tätigkeit, sowie des Programms 
*				  mitprotokollieren.
*
* Eingabeparameter: Pfad- und / oder Name der Logdatei, Logdateistatus, Erfolgsstatus der abgearbeiteten Tätigkeit, Termin, 
*			    Tätigkeit, Hauptpfad der Verarbeitung, Zielpfad nur bei Kopieren
*
* Rueckgabe: Bei erfolgreichem Protokollieren wird der STATUS ERFOLG zurückgegeben.
* Falls Logdatei schreibgeschützt oder nicht zu öffnen ist wird SFEHLER zurückgegeben.
*
* Besonderes: 
*/
STATUS logdatei(char *strLogdatei, LOGSTAT L_StartEnde, STATUS S_FktStatus, TERMIN T_Ref, TAETIGKEIT TAT_Ref, char *strVerwQuelle, char *strVerwZiel) {
	FILE *fp = fopen(strLogdatei, "at+");
	time_t t_zeit;
    struct tm *tm_zeitinfo;
	char *strDatumUhrzeitAusgabe;
	STATUS S_Erfolg;

    /* damit die Datumsausgabe deutsch ist (Systemeinstellung) */
    setlocale(LC_ALL, "");
    /* aktuelle Kalenderzeit abrufen und speichern */
    time(&t_zeit);
    /* als lokale Zeit in Elemente der Struktur zerlegen */
    tm_zeitinfo = localtime(&t_zeit);

	if (fp == NULL) {
		/* Falls Datei nicht vorhanden ist, muss sie neu mit "wt+" Modus angelegt werden. */
		fp = fopen(strLogdatei, "wt+");
			if (fp == NULL) {	
				return SFEHLER;
			}
	}

	switch (L_StartEnde) {
		case START: 
					fprintf(fp, "** %40s ;", str_C_START[0]);
					break;
		case ENDE:
					fprintf(fp, "** %40s ;", str_C_ENDE[0]);
					break;
		case PROGSTART:
					fprintf(fp, "** %40s ;", str_C_PROGSTART[0]);
					break;
		case PROGENDE:
					fprintf(fp, "** %40s ;", str_C_PROGENDE[0]);
					break;		
		default: 
					fprintf(fp, "** %40s ;", str_C_FEHLERLOG[0]);
					break;
	}
	
	/* Datum ; Uhrzeit ausgeben */
	S_Erfolg = zeitformatiert(T_Ref, &strDatumUhrzeitAusgabe, iMAX_LEN_DATUM_UHRZEIT_AUSGABE);

	fprintf(fp, " %s ; ", strDatumUhrzeitAusgabe);

	switch (TAT_Ref) {
		case AUFRUFEN:	
						fprintf(fp, "%10s ; ", str_C_AUFRUFEN[0]);
						break;
		case LOESCHEN:	
						fprintf(fp, "%10s ; ", str_C_LOESCHEN[0]);
						break;
		case AENDERN:	
						fprintf(fp, "%10s ; ", str_C_AENDERN[0]);
						break;
		case KOPIEREN:	
						fprintf(fp, "%10s ; ", str_C_KOPIEREN[0]);
						break;
		case TKEINE:	
						fprintf(fp, "           ; ");
						break;
		default:		
						fprintf(fp, "%10s ; ", str_C_FEHLERTAT[0]);
						break;
	}

	switch(S_FktStatus) {
		case ERFOLG:
						fprintf(fp, "%20s ; ", str_C_ERFOLG[0]);
						break;
		default:
						fprintf(fp, "%20s ; ", str_C_FEHLER[0]);
						break;
	}

	fprintf(fp, "%s ; ", strVerwQuelle);
	fprintf(fp, "%s ; ", strVerwZiel);

	fprintf(fp, " **\n");
	fclose(fp);
	return ERFOLG;
}
