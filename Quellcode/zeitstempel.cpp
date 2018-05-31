/* Dieses Modul soll anhand eines übergebenen TERMINs
* 2 Zeichenketten erstellen:
* 1) Zeichenkette zur Darstellungen im Datum / Zeitformat für die Ausgabe (in Logdatei z.B.)
* 2) Zeichenkette die einen Zeitstempel darstellt. Dieser Zeitstempel soll bei Rückgabe in
*    ein long long int umgewandelt werden und als Such- bzw. Vergleichsmuster benutzt werden,
*    um nicht einzelne Elemente von TERMIN miteinander vergleichen zu müssen. 
*	 Vorteil also: TERMIN-Umwandlung ermöglicht sortieren, vergleichen über einen Wert und schöne Ausgabe!
*
* Datei: zeitstempel.cpp Autor: Marco Bezzon
* Datum: 17.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "zeitstempel.h"
#include "globaldefs.h"

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


/**
* Funktionsbeschreibung:  Formatiert eine Variable vom Typ Termin in einen String zur Ausgabe in die Logdatei. 
*
* Eingabeparameter: Termin, Adresse des ausreichend großen Strings in den geschrieben wird, Größe des Strings
*
* Rückgabe: Bei erfolgreichem Formatieren wird der STATUS ERFOLG zurückgegeben.
*
* Besonderes: 
*/
STATUS zeitformatiert(TERMIN T_Ref, char **strTerminAusgabe, int iMaxGroesse) {
	char *strTMPTerminAusgabe = (char *) calloc(iMaxGroesse, sizeof(char));
	int iLv;

	if (strTMPTerminAusgabe == NULL) {
		return SFEHLER;
	}
	
	/* Zeichen H gilt als Platzhalter und soll später als Leerzeichen wieder dargestellt werden */
	sprintf(strTMPTerminAusgabe, "%2d.%2d.%4dH;H%2d:%2d:%2d", T_Ref.D_Datum.iTag,
															T_Ref.D_Datum.iMonat,
															T_Ref.D_Datum.iJahr,
															T_Ref.Z_Zeit.iStunde,	
															T_Ref.Z_Zeit.iMinute,
															T_Ref.Z_Zeit.iSekunde);

	/* Wenn die Ganzzahlen kleiner 2-Stellen sind, sollen sie im String trotzdem 
	   2-stellig mit einer 0 an erster Stelle dargestellt werden. Daher wird jedes
	   Leerzeichen im String durch eine 0 ersetzt!
	   Vor dem ';' und danach soll dennoch eine Leerzeile erscheinen, deshalb Platzhalter 'H' eingebaut!
	*/
	
	for(iLv = 0; iLv < iMaxGroesse; iLv++) {
		if(strTMPTerminAusgabe[iLv] != '\0' && strTMPTerminAusgabe[iLv] == ' ') {
			strTMPTerminAusgabe[iLv] = '0';
		}

		if(strTMPTerminAusgabe[iLv] != '\0' && strTMPTerminAusgabe[iLv] == 'H') {
			strTMPTerminAusgabe[iLv] = ' ';
		}
	}
	
	/* Rückgabe der übergebenen Referenz von strTerminAusgabe */
	*strTerminAusgabe = strTMPTerminAusgabe;

	return ERFOLG;
}



/**
* Funktionsbeschreibung: Um nach Termin sinnvoll sortieren zu können wird in dieser Funktion ein "Zeitstempel" erzeugt.  
*				  Dieser wird in Eingaben zurückgeschrieben und kann dann wie ein Zahlenfeld sortiert werden!
*	
* Eingabeparameter: Termin, Ausreichend große Länge des Zeitstempels
*
* Rückgabe: long long int Zeitstempel.
*
* Besonderes: in der Funktion wird sprintf() verwendet und dann mit atod() in Zahl konvertiert.
*/
long long int zeitsortiert(TERMIN T_Ref, int iMaxGroesse) {
	char *strTMPSortMuster    = (char *) calloc(iMaxGroesse, sizeof(char));
	int iRegelTag = 0, iRegelWoch = 0, iRegelMon = 0, iLv;
	long long int lliSortMuster = 0;

	if (strTMPSortMuster == NULL) {
		return -1;
	}
	
	switch(T_Ref.R_Regelmaessigkeit) {
		case TAEGLICH: 
						iRegelTag = 1;
						break;
		case WOECHENTLICH:
						iRegelWoch = 1;
						break;
		case MONATLICH:
						iRegelMon = 1;
						break;
		default:
						iRegelTag = 0;
						iRegelWoch = 0;
						iRegelMon = 0;
						break;
	}


	sprintf(strTMPSortMuster, "%1d%1d%1d%4d%2d%2d%2d%2d%2d", iRegelMon,
															 iRegelWoch,
															 iRegelTag,
															 T_Ref.D_Datum.iJahr,
															 T_Ref.D_Datum.iMonat,
															 T_Ref.D_Datum.iTag,
															 T_Ref.Z_Zeit.iStunde,	
															 T_Ref.Z_Zeit.iMinute,
															 T_Ref.Z_Zeit.iSekunde);

	for(iLv = 0; iLv < iMaxGroesse; iLv++) {
			if(strTMPSortMuster[iLv] != '\0' && strTMPSortMuster[iLv] == ' ') {
				strTMPSortMuster[iLv] = '0';
			}
		}
	
	lliSortMuster = (long long int) atof(strTMPSortMuster);

	return ( lliSortMuster );
}



/**
* Funktionsbeschreibung: Konvertiert Variablen vom Typ struct tm in TERMIN um.
*	
* Eingabeparameter: Variable vom Typ struct tm
*
* Rückgabe: TERMIN
*
* Besonderes:
*/
TERMIN ZeitInTermin(struct tm *tm_zeit) {
	TERMIN T_Fuell;
	T_Fuell.D_Datum.iJahr      = tm_zeit->tm_year + iZEIT_AENDERUNG_JAHR;
	T_Fuell.D_Datum.iMonat     = tm_zeit->tm_mon  + iZEIT_AENDERUNG_MONAT;
	T_Fuell.D_Datum.iTag       = tm_zeit->tm_mday;
	T_Fuell.Z_Zeit.iStunde     = tm_zeit->tm_hour;
	T_Fuell.Z_Zeit.iMinute     = tm_zeit->tm_min;
	T_Fuell.Z_Zeit.iSekunde    = tm_zeit->tm_sec;
	T_Fuell.iW_Tag			   = tm_zeit->tm_wday;
	if (T_Fuell.iW_Tag == 0) { /* Sonntag in tm_wday = 0, soll aber zur Überprüfung mit Qt auf 7 gesetzt werden */
		T_Fuell.iW_Tag = 7;
	}
	return T_Fuell;
}



/**
* Funktionsbeschreibung: Speichert einen Termin in einer Datei (BINÄR).
*	
* Eingabeparameter: Variable vom Typ TERMIN
*
* Rückgabe: Erfolg oder Fehler
*
* Besonderes:
*/
STATUS TerminSpeichern(TERMIN T_Ref, char *strDatei) {
	FILE *fp = fopen(strDatei, "wb");
	
	if (fp == NULL) {
		fclose(fp);	
		return SFEHLER;
	}
	
	fwrite(&T_Ref, sizeof(TERMIN), 1, fp);
	fclose(fp);
	return ERFOLG;
}
