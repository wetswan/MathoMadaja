/* Diese Header-Datei enthält den Prototyp zur Funktion kopieren
*
* Datei: kopieren.h Autor: Thomas Harr
* Datum: 26.05.2008
*
* Historie: 
* - Marco Bezzon: Zugriff auf Konvertierungsfunktion aus globalfunctions.h
*/
#ifndef H_KOPIEREN
#define H_KOPIEREN
#include <windows.h>
#include <tchar.h>
#include <shellapi.h>
#include <stdio.h>
#include "datentypen.h"
#include "globalfunctions.h"


/* Funktion Kopieren gibt einen Wert vom typ STATUS (datentypen.h) zurück 
und bekommt die Zeiger auf das Ziel- und das Quellverzeichnis*/
STATUS kopieren(char *strVerweisQuelle, char *strVerweisZiel);
#endif
