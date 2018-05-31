/*
* Diese Header Datei beinhaltet alle Header die für die Loeschen-Funktion notwendig sind.
*
* Datei: Loeschen.cpp Autor: David Garus
* Datum: 01.06.2008
*
* Historie: 03.06.2008
* -Prototypen korrigiert
* - Marco Bezzon: Zugriff auf Konvertierungsfunktion aus globalfunctions.h
*/
#ifndef H_LOESCHEN
#define H_LOESCHEN

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <shellapi.h>
#include "datentypen.h"
#include "globalfunctions.h"

STATUS loeschen(char *strVerweis);
#endif 
