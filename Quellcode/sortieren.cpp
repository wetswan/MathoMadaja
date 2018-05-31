/* Dies ist die Sortier Funktion (Merge-Sort-Algorithmus).
*  Der Funktion wird eine Liste mit Eingaben übergeben und ein Funktionspointer, 
*  der die Vergleichsfunktion zur Sortierung aufrufen soll. 
*  Zurückgegeben wird ein Pointer auf das erste Element der Sortierung. 
*  Achtung: Der Kopf-Pointer wird nicht mehr der gleiche sein wie vor der Sortierung!
*           Die Verkettung der Elemente untereinander ändert sich ebenfalls.
*
* Datei: sortieren.cpp Autor: Marco Bezzon
* Datum: 16.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "eingabeliste.h"
#include "sortieren.h"
#include <stdio.h>

/* Vergleichsfunktion, die im Hauptmodul als Parameter übergeben wird, 
   um die "Zeitstempel" von Eingaben zu vergleichen */ 
long long int vergleiche_ints(EINGABELISTE **EL_A, EINGABELISTE **EL_B) {
    return ((*EL_A)->E_Taetigkeit->lli_SortMuster) - ((*EL_B)->E_Taetigkeit->lli_SortMuster);
}


/* Der eigentliche Sortieralgorithmus (Merge-Sort: iterativ) */
EINGABELISTE * sortlist(EINGABELISTE *EL_Liste, long long int (*vergleiche) (EINGABELISTE **EL_A, EINGABELISTE **EL_B)) {
	EINGABELISTE *EL_Links, *EL_Rechts, *EL_Erg = NULL, *EL_Ende, *EL_Alt;
	int i_InSize, i_nMerges, i_LeftSize, i_RightSize, iLv;
	 
	/* Kommt eine leere Liste rein, 
	 soll ein NULL-Pointer direkt zurückgegeben werden	*/ 
    if (EL_Liste == NULL)
		return NULL;

    i_InSize = 1;

    while (1) {
        EL_Links = EL_Liste;
		EL_Alt   = EL_Liste;		       
        EL_Liste = NULL;
        EL_Ende  = NULL;

        i_nMerges = 0;		/* in i_nMerges wird gezählt, wie oft die Liste zusammengeführt wird */

        while (EL_Links) {
            i_nMerges++;  /* Eine Zusammenführung ist zu tun */
            /* step `insize' places along from p */
            EL_Rechts = EL_Links;
            i_LeftSize = 0;
            
			for (iLv = 0; iLv < i_InSize; iLv++) {
                i_LeftSize++;
				EL_Rechts = EL_Rechts->EL_Naechste;
                
				if (EL_Rechts == NULL) {
					break;
				}
            }
			
			/* Falls EL_Rechts nicht auf NULL zeigt, dann müssen zwei Listen zusammengeführt werden */
            i_RightSize = i_InSize;

            /* Das soll im Folgenden geschehen: Führe 2 Listen zusammen */
            while (i_LeftSize > 0 || (i_RightSize > 0 && EL_Rechts != NULL)) {

                /* Entscheide ob das Folgeelement von EL_Links oder EL_Rechts kommt */
                if (i_LeftSize == 0) {
					/* EL_Links ist leer; Ergebnis muss also von EL_Rechts kommen. */
					EL_Erg    = EL_Rechts; 
					EL_Rechts = EL_Rechts->EL_Naechste; 
					i_RightSize--;
				} 
				
				else if (i_RightSize == 0 || EL_Rechts == NULL) {
				
				/* EL_Rechts ist leer; Ergebnis muss also von EL_Links kommen. */
					EL_Erg   = EL_Links; 
					EL_Links = EL_Links->EL_Naechste; 
					i_LeftSize--;
				} 
				
				else if (vergleiche(&EL_Links, &EL_Rechts) > 0) {
				/* Erstes Element von EL_Links ist kleiner (oder gleich);
				   EL_Erg kommt von EL_Links */
					EL_Erg = EL_Links; 
					EL_Links = EL_Links->EL_Naechste; 
					i_LeftSize--;
				}	 
				
				else {
					/* Erstes Element von EL_Rechts ist kleiner;
					EL_Erg kommt von EL_Rechts */
					EL_Erg    = EL_Rechts; 
					EL_Rechts = EL_Rechts->EL_Naechste; 
					i_RightSize--;
			}

                /* Füge das nächste Element zur Liste hinzu */
			if (EL_Ende != NULL) {
				EL_Ende->EL_Naechste = EL_Erg;
			} 
			else {
				EL_Liste = EL_Erg;
			}
		EL_Erg->EL_Vorherige = EL_Ende;
		EL_Ende = EL_Erg;
		}
		
        EL_Links = EL_Rechts;
		}

	    EL_Ende->EL_Naechste = NULL;

        /* Die Anzahl der Zusammenführungen wird immer kleiner -> Teile, Herrsche Prinzip.
		   Wenn nur noch eine Zusammenführung getätigt wurde, ist die Sortierung fertig. */
        if (i_nMerges <= 1) {  /* Um Fehler abzufangen wird auch noch unter 1 abgefragt! */	
			return EL_Liste;
		}

		/* Andernfalls wiederhole und führe mit doppelter Größe zusammen */
        i_InSize = i_InSize * 2;
	}
}
