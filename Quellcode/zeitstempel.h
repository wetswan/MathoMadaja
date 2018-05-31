/* Dieses Modul soll anhand eines übergebenen TERMINs
* 2 Zeichenketten erstellen:
* 1) Zeichenkette zur Darstellungen im Datum / Zeitformat für die Ausgabe (in Logdatei z.B.)
* 2) Zeichenkette die einen Zeitstempel darstellt. Dieser Zeitstempel soll bei Rückgabe in
*    ein long long int umgewandelt werden und als Such- bzw. Vergleichsmuster benutzt werden,
*    um nicht einzelne Elemente von TERMIN miteinander vergleichen zu müssen. 
*	 Vorteil also: TERMIN-Umwandlung ermöglicht sortieren, vergleichen über einen Wert und schöne Ausgabe!
*
* Datei: zeitstempel.h Autor: Marco Bezzon
* Datum: 16.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#ifndef H_ZEITSTEMPELH
#define H_ZEITSTEMPELH

#include "datentypen.h"


STATUS zeitformatiert(TERMIN T_Ref, char **strTerminAusgabe, int iMaxGroesse);


long long int zeitsortiert(TERMIN T_Ref, int iMaxGroesse);


TERMIN ZeitInTermin(struct tm *tm_zeit);


STATUS TerminSpeichern(TERMIN T_Ref, char *strDatei);
#endif
