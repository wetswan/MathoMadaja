/* Füllt eine Eingabeliste mit Eingaben
*
* Datei: eingabeliste.h Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#ifndef H_EINGABELISTEH
#define H_EINGABELISTEH

#include "datentypen.h"


EINGABELISTE *eingabeliste_Init(void);


void eingabeliste_Einfuegen ( EINGABELISTE ** EL_Liste, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema,
							  TAETIGKEIT TAT_FktWahl, TERMIN T_TerminEingabe, int iTempId);


void eingabeliste_EingabeAnpassen ( EINGABELISTE ** EL_Liste, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema,
							  TAETIGKEIT TAT_FktWahl, TERMIN T_TerminEingabe, int iId);
							  

void eingabeliste_Loeschen (EINGABELISTE ** EL_Loeschen);


void eingabeliste_element_Loeschen (EINGABELISTE ** EL_Loeschen, int iId);


EINGABE * eingabeliste_Suche(const EINGABELISTE * EL_Suchliste, int iId);


STATUS eingabeliste_Sichern(const EINGABELISTE *EL_ZuSichern, char *strDatei);

/* Nutzdaten aus Datei auslesen und Eingabeliste füllen, die daraufhin sortiert wird. */
STATUS eingabeliste_Laden(EINGABELISTE **EL_ZuLaden, char *strDatei);

#endif
