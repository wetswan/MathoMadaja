/* Erfasst neue Eingabe als Struktur, gibt dann einen Zeiger auf allokierten Speicherbereich zur�ck. 
*  L�sch-Funktion l�scht einzelne Eingaben aus Liste.
*
* Datei: eingabe.h Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#ifndef H_EINGABEH
#define H_EINGABEH

#include "globaldefs.h"
#include "datentypen.h"

/* Konstruktor: Neue Eingabe mit geg. Daten */
EINGABE * eingabe_neu( const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema, 
					   TAETIGKEIT TAT_FktWahl, TERMIN T_TerminEingabe, int iId );

/* Bereits vorhandene Eingabe aendern */
void eingabe_aendern(EINGABE *E, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema, TAETIGKEIT TAT_FktWahl, 
					   TERMIN T_TerminEingabe, int iId);
					   
/* Destruktor: Zu l�schende Eingabe */
void eingabe_loeschen(EINGABE ** E_Loeschen);

#endif
