/* Erstellt neue Listen, fügt Eingaben hinzu und löscht ganze Listen
*
* Datei: eingabe.h Autor: Marco Bezzon
* Datum: 15.05.2008
*
* Historie: <WER hat WANN WAS geaendert / ergaenzt>
*/
#include "eingabe.h"
#include "sortieren.h"
#include "eingabeliste.h"

#include <malloc.h>
#include <stdio.h>


/**
* Funktionsbeschreibung:  Initialisiert Speicherplatz fuer eine neue Liste.  <br>
*  <br>
* Eingabeparameter: Keine  <br>
*  <br>
* Rueckgabe: Zeiger auf neuen Speicherplatz <br>
* <br>
* Besonderes:  <br>
*/
EINGABELISTE * eingabeliste_Init (void) {
    /* Erzeugen neuer Eingabeliste, die mit NULLen initialisiert wird, durch calloc */
	EINGABELISTE *EL_L = (EINGABELISTE *) calloc(1, sizeof(EINGABELISTE));
    
	if(EL_L == NULL) {
        return NULL;
    }

	return EL_L;
}



/**
* Funktionsbeschreibung:  Fuegt neues Element Eingabe in die Eingabeliste ein und verkettet diese daraufhin.  <br>
* <br>
* Eingabeparameter: Adresse der Eingabeliste (beim 1. mal NULL), VON-Pfad, NACH-Pfad, Aenderungsschema, Taetigkeit, Termin und temp. Id, die von der Qt-Liste des Programms vergeben wird. <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
* Besonderes: Ruft intern eingabeliste_Init() auf. <br>
*/
void eingabeliste_Einfuegen ( EINGABELISTE ** EL_Liste, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema, 
							  TAETIGKEIT TAT_FktWahl, TERMIN T_TerminEingabe, int iTempId) {
	EINGABELISTE * EL_N = *EL_Liste;
	/* Neuen Knoten einfuegen: */
	*EL_Liste = eingabeliste_Init();
	(*EL_Liste)->E_Taetigkeit = eingabe_neu(strVerweisQuelle, strVerweisZiel, strSchema, TAT_FktWahl, T_TerminEingabe, iTempId);
	(*EL_Liste)->EL_Vorherige = EL_N;
	if (EL_N != NULL) {
		EL_N->EL_Naechste = *EL_Liste;
	}
}



/**
* Funktionsbeschreibung:  Passt nachtraeglich ein vorhandenes Element in der Liste an.   <br>
* <br>
* Eingabeparameter: Adresse der Eingabeliste (beim 1. mal NULL), VON-Pfad, NACH-Pfad, Aenderungsschema, Taetigkeit, Termin und temp. Id, die von der Qt-Liste des Programms vergeben wird. <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
* Besonderes:  <br>
*/
void eingabeliste_EingabeAnpassen ( EINGABELISTE ** EL_Liste, const char *strVerweisQuelle, const char *strVerweisZiel, const char *strSchema,
							  TAETIGKEIT TAT_FktWahl, TERMIN T_TerminEingabe, int iId) {
	EINGABELISTE * EL_Suchliste = *EL_Liste;
	
	while (EL_Suchliste != NULL) {
		if (EL_Suchliste->E_Taetigkeit->i_Id == iId) { 
			eingabe_aendern(EL_Suchliste->E_Taetigkeit, strVerweisQuelle, strVerweisZiel, strSchema, TAT_FktWahl, T_TerminEingabe, iId );
			return;
		}
		else {
			EL_Suchliste = EL_Suchliste->EL_Naechste; 
		}
	}						  
}



/**
* Funktionsbeschreibung:  Loescht komplette Liste und gibt Speicher wieder frei.  <br>
* <br>
* Eingabeparameter: Adresse der Eingabeliste (notwendigerweise auf 1. Element) <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
* Besonderes:  <br>
*/
void eingabeliste_element_Loeschen (EINGABELISTE ** EL_Loeschen, int iId) {	
	EINGABE ** E;
	EINGABELISTE * EL_Muell, *EL_Davor, *EL_Danach;
	EINGABELISTE * EL_Renner = *EL_Loeschen;
	int iFlag = 0, iTempId=iId;	
	
	while(EL_Renner != NULL) {
	
		if (EL_Renner->E_Taetigkeit->i_Id == iId) {
			EL_Davor  = EL_Renner->EL_Vorherige;
			EL_Danach = EL_Renner->EL_Naechste;
			
			if (EL_Davor != NULL) {
				EL_Davor->EL_Naechste   = EL_Danach;
			}
			
			if (EL_Danach != NULL) {
				EL_Danach->EL_Vorherige = EL_Davor;
			}
			
			EL_Muell  = EL_Renner;
			EL_Renner = EL_Renner->EL_Naechste;
			E = &(EL_Muell->E_Taetigkeit);
			eingabe_loeschen(E);
			free(EL_Muell);
			iFlag = 1;
		}
		
		if (iFlag == 1 && EL_Renner != NULL) {
				EL_Renner->E_Taetigkeit->i_Id = iTempId;
				iTempId++;
		}
		
		if(EL_Renner != NULL) {
			EL_Renner = EL_Renner->EL_Naechste;
		}
	}
}



/**
* Funktionsbeschreibung:  Einzelne Elemente aus der Liste loeschen  <br>
* <br>
* Eingabeparameter: Adresse der Eingabeliste (notwendigerweise auf 1. Element), Temporaere Id, gegeben durch Qt-Liste <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
* Besonderes:  <br>
*/ 
void eingabeliste_Loeschen (EINGABELISTE ** EL_Loeschen) {
	EINGABE ** E;
	EINGABELISTE * EL_Muell;
	EINGABELISTE * EL_Renner = *EL_Loeschen;
	
	while (EL_Renner != NULL) { 
		EL_Muell = EL_Renner;
		EL_Renner = EL_Renner->EL_Naechste;
		E = &(EL_Muell->E_Taetigkeit);
		eingabe_loeschen (E);
		free (EL_Muell);
	}

EL_Loeschen = NULL;
}



/**
* Funktionsbeschreibung:  Einzelne Elemente in der Liste nach Id suchen  <br>
* <br>
* Eingabeparameter: Eingabeliste (notwendigerweise 1. Element), Temporaere Id, gegeben durch Qt-Liste <br>
* <br>
* Rueckgabe: Zeiger auf einzelnes Element aus der Liste.  <br>
* <br>
* Besonderes:  <br>
*/
EINGABE * eingabeliste_Suche(const EINGABELISTE * EL_Suchliste, int iId) { 
	while (EL_Suchliste != NULL) {
		if (EL_Suchliste->E_Taetigkeit->i_Id == iId) { 
			return ( EL_Suchliste->E_Taetigkeit ); 
		}
		else {
			EL_Suchliste = EL_Suchliste->EL_Naechste; 
		}
	}
	return (NULL);
}


/**
 * Funktionsbeschreibung: Sichert alle Nutzdaten der Liste binär in Datei <br>
 * <br>
 * Eingabeparameter: Adresse des ersten Elements der Eingabeliste, <br>
 * Dateipfad und Name in welchen gespeichert werden soll <br>
 *
 * Rückgabe: STATUS, ob Fehler beim Datei schreiben oder Erfolg
 *
 */
STATUS eingabeliste_Sichern(const EINGABELISTE *EL_ZuSichern, char *strDatei) {
	FILE *fp = NULL; 
	const EINGABELISTE *EL_Renner = EL_ZuSichern;
	
	if ( (fp = fopen(strDatei, "wb")) == NULL ) {
		return SFEHLER;
	}
	
	while ( EL_Renner != NULL ) {
		if (EL_Renner->E_Taetigkeit != NULL) {
		fwrite(EL_Renner->E_Taetigkeit, sizeof(EINGABE), 1, fp);
		EL_Renner = EL_Renner->EL_Naechste;
		}	
	}
	
	fclose(fp);
	return ERFOLG;
}


/**
 * Funktionsbeschreibung: Ladet alle Nutzdaten von Datei <br>
 * <br>
 * Eingabeparameter: Adresse des ersten Elements der Eingabeliste, <br>
 * Dateipfad und Name in welchen gespeichert wurde <br>
 *
 * Rückgabe: STATUS, ob Fehler beim Datei lesen oder Erfolg
 *
 */
STATUS eingabeliste_Laden(EINGABELISTE **EL_ZuLaden, char *strDatei) {
	FILE *fp = NULL;
	EINGABE E_Ptr, E_Leer;
	DOPPELANKER DA_Laden;
	DA_Laden.EL_Erst  = NULL;
	DA_Laden.EL_Letzt = NULL;
	int iMerk         = 0;
	
	if ( (fp = fopen(strDatei, "rb")) == NULL ) {
		return SFEHLER;
	}
	
	while(!feof(fp)) { /* fread() soll immer ein Element lesen, sonst Schleife abbrechen! */
		if (fread(&E_Ptr, sizeof(EINGABE), 1, fp) != 1) {
			break;
		}
		
		eingabeliste_Einfuegen(EL_ZuLaden, E_Ptr.strQuelle, E_Ptr.strZiel, E_Ptr.strSchema, E_Ptr.TAT_Funktion, E_Ptr.T_Termin, 0);
		if ( iMerk == 0 ) {
			DA_Laden.EL_Erst = *EL_ZuLaden;
			iMerk = 1;
		}
		E_Ptr = E_Leer;
		DA_Laden.EL_Letzt    = *EL_ZuLaden;
	}
	fclose(fp);
	*EL_ZuLaden = DA_Laden.EL_Erst;
	
	*EL_ZuLaden = sortlist(*EL_ZuLaden, vergleiche_ints);
	
	if (*EL_ZuLaden != NULL) {
		return ERFOLG;
	}
	else {
		return SFEHLER;
	}
}
