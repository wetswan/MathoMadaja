/* Diese Funktions-Datei enthält die Funktion um / Zeichen in \\ zu konvertieren.
*  Damit kann dann alles mögliche kopiert und gelöscht werden.
*
* Datei: globalfunctions.cpp Autor: Marco Bezzon
* Datum: 09.06.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*
*
*/
#include "globalfunctions.h"

/**
* Funktionsbeschreibung: Diese Funktion dient dem Konvertieren von Strings mit / Zeichen. <br>
* <br>
* Eingabeparameter:  Erhaelt Quell- und Zieldatei(pfad) <br> 
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void convSlashToBackslash(char *strDest, char *strSrc) {
	int iLength = strlen(strSrc);
	int iLv1 = 0, iLv2 = 0, iLv3 = 0;

	for(iLv1 = 0; iLv1 < iLength; iLv1++) {
		if (strSrc[iLv1] == '/') {
			for (iLv2 = 0; iLv2 < 2; iLv2++) {
				strDest[iLv3 + iLv2] = '\\';
			}
		iLv3 = iLv3 + iLv2;	
		}	
		else {
			strDest[iLv3] = strSrc[iLv1];			
			iLv3++;
		}
	}

	strDest[iLv3] = '\0';
}
