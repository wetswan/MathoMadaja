/* Sortiert die Liste absteigend nach TERMIN
*
* Datei: sortieren.h Autor: Marco Bezzon
* Datum: 16.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "datentypen.h"

long long int vergleiche_ints(EINGABELISTE **EL_A, EINGABELISTE **EL_B);

EINGABELISTE * sortlist(EINGABELISTE *EL_Liste, long long int (*vergleiche) (EINGABELISTE **EL_A, EINGABELISTE **EL_B));
