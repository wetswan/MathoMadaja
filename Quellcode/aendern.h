/* Diese Header-Datei enthält den Prototyp zur Funktion aendern
*
* Datei: aendern.h
* Autor: Markus Schüler
* Datum: 01.06.2008
*
* Historie: 07.06.2008 Marco Bezzon
*		- Anpassung der Headerdateien
*		- convert_in_str hinzugefügt
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <tchar.h>
#include <shellapi.h>
#include "datentypen.h"

/* Funktion aendern gibt einen Wert vom typ STATUS (datentypen.h) zurück 
und bekommt die Zeiger auf das Schema und Zielverzeichnis
*/
STATUS aendern(char *, char *);

/*Funktionsprototypen, genauere Erläuterungen der Funktionen unterhalb der aendern()-Funktion*/
void quelldateiname_erstellen(char *cdateipfad, char * cpfad,char * cdateiname);
void zieldateiname_erstellen(char *cdateipfad, char * cpfad,char * cdateiname,int idateinummer,int idateianzahl);
void pfad_erstellen(char *cpfad, char * cpfad1);
void convert_in_str(char *str, TCHAR *to_conv, int laenge);
