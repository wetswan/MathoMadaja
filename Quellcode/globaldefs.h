/* Globale Definitionen für das Projekt / insbesondere für die 
*  Erstellung der Logdatei
*
* Datei: globaldefs.h Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#ifndef H_GLOBALDEFSH
#define H_GLOBALDEFSH
	
	#define ANZ_SPR 1
	#define ANZ_LOGZ 40
	#define ANZ_TATZ 40
	#define ANZ_STAT 20
	#define ANZ_REGEL 20

	#define LEN_DATFORMAT 25	/* "01.01.2000 ; 00:00:00\0" */
	#define LEN_SORT 20

	const char str_C_START[ANZ_SPR][ANZ_LOGZ]     = { "START" }; 
	const char str_C_ENDE[ANZ_SPR][ANZ_LOGZ]      = { "ENDE" };
	const char str_C_PROGSTART[ANZ_SPR][ANZ_LOGZ] = { "PROGRAMMSTART" }; 
	const char str_C_PROGENDE[ANZ_SPR][ANZ_LOGZ]  = { "PROGRAMMENDE" };
	const char str_C_FEHLERLOG[ANZ_SPR][ANZ_LOGZ] = { "FEHLER: Kein START- oder ENDE-Status" };

	const char str_C_AUFRUFEN[ANZ_SPR][ANZ_TATZ]  = { "AUFRUFEN" };
	const char str_C_LOESCHEN[ANZ_SPR][ANZ_TATZ]  = { "LOESCHEN" };
	const char str_C_AENDERN[ANZ_SPR][ANZ_TATZ]   = { "AENDERN" };
	const char str_C_KOPIEREN[ANZ_SPR][ANZ_TATZ]  = { "KOPIEREN" };
	const char str_C_KEINE[ANZ_SPR][ANZ_TATZ]	  = { "Keine" };	
	const char str_C_FEHLERTAT[ANZ_SPR][ANZ_TATZ] = { "FEHLER: TAETIGKEIT nicht vorhanden" };

	const char str_C_ERFOLG[ANZ_SPR][ANZ_STAT]    = { "ERFOLGREICH" };
	const char str_C_FEHLER[ANZ_SPR][ANZ_STAT]    = { "NICHT ERFOLGREICH" };
	
	const char str_C_TAEGLICH[ANZ_SPR][ANZ_REGEL]     = { "Täglich" };
	const char str_C_WOECHENTLICH[ANZ_SPR][ANZ_REGEL] = { "Wöchentlich" };
	const char str_C_MONATLICH[ANZ_SPR][ANZ_REGEL]    = { "Monatlich" };
 
	const int iMAX_LEN_DATUM_UHRZEIT_AUSGABE = LEN_DATFORMAT;
	const int iANZ_ZEICHEN_SORT		         = LEN_SORT;
	
	/* Zeitänderungsoperator abhängig von struct tm, bei der man immer 1900 dazuzählen muss, um aufs aktuelle Jahr zu kommen, bzw. 1 um korrekten Monat zu bekommen */
	const int iZEIT_AENDERUNG_JAHR           = 1900;
	const int iZEIT_AENDERUNG_MONAT          = 1;

#endif
