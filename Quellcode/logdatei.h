/* Diese Quellcode-Datei erstellt die Log-Datei für das MathoMadaja-Projekt.
* Neue Textzeilen werden immer an der obersten Zeile eingefügt.
*
* Datei: logdatei.h Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#ifndef H_LOGDATEIH
#define H_LOGDATEIH

#include "globaldefs.h"
#include "datentypen.h"

STATUS logdatei(char *strLogdatei, LOGSTAT L_StartEnde, STATUS S_FktStatus, TERMIN T_Ref, TAETIGKEIT TAT_Ref, char *strVerwQuelle, char *strVerwZiel);

#endif
