/* Erfasst neue Eingabe als Struktur, gibt dann einen Zeiger auf allokierten Speicherbereich zurück. 
*  Lösch-Funktion löscht einzelne Eingaben aus Liste.
*
* Datei: eingabe.cpp Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "zeitstempel.h"
#include "eingabe.h"

#include <string.h>
#include <malloc.h>


/**
* Funktionsbeschreibung: Erzeugt neuen Speicher für eine vollstaendige Eingabe. <br>
* <br>
* Eingabeparameter:  Erhaelt beim Initialisieren die Quelle von wo bzw. was, den Zielpfad oder das Zielverzeichnis (nur bei Kopieren), <br>
*			      Aenderungsschema, eine Taetigkeit, Termin und die Id (die von der Qt Liste vergeben wird. <br>
* <br>
* Rueckgabe: Zeiger auf des neue Element oder NULL <br>
* <br>
*/
EINGABE * eingabe_neu( const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema, TAETIGKEIT TAT_FktWahl, 
					   TERMIN T_TerminEingabe, int iId ) {
	EINGABE * E_Neu = (EINGABE *) calloc(1, sizeof(EINGABE)); 
	if( E_Neu == NULL ) {
		return NULL;
	}
	
	strcpy(E_Neu->strSchema, strSchema);
	strcpy(E_Neu->strQuelle, strVerweisQuelle);
	
	if (strVerweisZiel != NULL) {
		strcpy(E_Neu->strZiel,   strVerweisZiel);
	}
	
	E_Neu->T_Termin = T_TerminEingabe;
	/** Mit der Funktion zeitsortiert wird ein Sortiermuster generiert, welches im Datentyp EINGABE <br>
	   gespeichert wird. Beim naechsten Start vom Programm kann dann danach sortiert werden. */
	E_Neu->lli_SortMuster = (long long int) zeitsortiert(T_TerminEingabe, iANZ_ZEICHEN_SORT);
	
	E_Neu->TAT_Funktion   = TAT_FktWahl;
	
	E_Neu->i_Id           = iId;
	return E_Neu;
}

/* Anzupassende Eingabe wird hier initialisiert und an aufrufende Fkt zurückgegeben */
/**
* Funktionsbeschreibung: Passt alle enthaltenen Elemente in Eingabe an <br>
* <br>
* Eingabeparameter:  Erhaelt beim Aufruf die Quelle von wo bzw. was, den Zielpfad oder das Zielverzeichnis (nur bei Kopieren), <br>
*			      Aenderungsschema, eine Taetigkeit, Termin und die Id (die neu von der Qt Liste vergeben wird. <br>
* <br>
* Rueckgabe: Kein <br>
* <br>
*/
void eingabe_aendern(EINGABE *E, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema, TAETIGKEIT TAT_FktWahl, 
					   TERMIN T_TerminEingabe, int iId) {
	//EINGABE *E =  (EINGABE *) calloc(1, sizeof(EINGABE));
	
	if( E == NULL ) {
		return;
	}
	
	strcpy(E->strSchema, strSchema);
	strcpy(E->strQuelle, strVerweisQuelle);
	
	if (strVerweisZiel != NULL) {
		strcpy(E->strZiel,   strVerweisZiel);
	}
	
	E->T_Termin = T_TerminEingabe;
	/** Mit der Funktion zeitsortiert wird ein Sortiermuster generiert, welches im Datentyp EINGABE <br>
	   gespeichert wird. Beim naechsten Start vom Programm kann dann danach sortiert werden. */
	E->lli_SortMuster = (long long int) zeitsortiert(T_TerminEingabe, iANZ_ZEICHEN_SORT);
	
	E->TAT_Funktion   = TAT_FktWahl;
	
	E->i_Id           = iId;
}

/**
* Funktionsbeschreibung: Loescht eine Eingabe <br>
* <br>
* Eingabeparameter:  Erhaelt die Adresse des zu löschenden Elements. <br>
* <br>
* Rueckgabe: Kein <br>
* <br>
*/
void eingabe_loeschen(EINGABE ** E_Loeschen) {
	free(*E_Loeschen);
	*E_Loeschen = NULL;
}
