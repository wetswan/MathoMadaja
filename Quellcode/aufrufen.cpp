/* Diese Funktions-Datei enthält die Funktion "aufrufen".
*  Damit werden externe Dateien aufgerufen.
*
* Datei: aufrufen.cpp Autor: Jan Ripper
* Datum: 02.06.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*			Jan Ripper - 03.06.2008 - Funktionskommentar an Richtlinien angepasst
*			Jan Ripper - 02.06.2008 - Fertige Funktion inkl. Statusrückgabe
*/
#include "aufrufen.h"

/**
* Funktionsbeschreibung: Diese Funktion ist fuer das Aufrufen externer Dateien zustaendig. <br>
* <br>
* Eingabeparameter:  Erhaelt vom Hauptmodul den strVerweis mit dem Pfad der auszufuehrenden <br>
*			     Datei <br>
* <br>
* Rueckgabe: Funktion gibt ERFOLG zurueck wenn die Datei erfolgreich ausgefuehrt wurde,<br>
*		ansonsten wird SFEHLER zurueckgegeben. <br>
* <br>
*/
STATUS aufrufen (char *strVerweis)
{
	/** Initialisierung einer Integer-Variable fuer die Statusrueckgabe */
	int iStatus, iWandlung;
	/** Initialisierung einer Variable fuer die Stringumwandlung */
	WCHAR W_strUnicode[MAX_PATH];
	/** Umwandlung des vom Hauptmodul erhaltenen Strings */
	iWandlung = MultiByteToWideChar( CP_ACP, 0, strVerweis, MAX_PATH, W_strUnicode, MAX_PATH);
	/** Aufruf des gewuenschten Programms und Zuweisung des Rueckgabewerts von ShellExecute an iStatus */
	iStatus = (int)ShellExecute(NULL,L"open",W_strUnicode,NULL,NULL,SW_SHOWNORMAL);
	/* Hinweise zu ShellExecute -> http://www.c-plusplus.de/forum/viewtopic-var-p-is-18134.html */
	/** Statusrueckgabe von ShellExecute. Quelle: http://www.oehive.org/node/528 */
	if( iStatus > 32 && iWandlung != 0)
		{ 
			return ERFOLG;
		}
	else
		{ 
			return SFEHLER;
		}

}
