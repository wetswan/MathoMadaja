/*
 * Diese Header-Datei enth�lt die notwendigen eigendefinierten Datentypen des MathoMadaja-Projekt.
 *
 * Datei: logdatei.cpp Autor: Marco Bezzon
 * Datum: 15.05.2008
 *
 * Historie: <WER hat WANN WAS geaendert / ergaenzt>
 */

#ifndef H_DATENTYPENH
#define H_DATENTYPENH

/* Konstanten zur Festlegung der Gr��e der Pfad- und  desSchema-Arrays */
#define ANZ_CHAR 255
#define ANZ_SCHEMA 9

/* Taetigkeit, welche es Auszuf�hren gilt */
typedef enum { TFEHLER, TKEINE ,AUFRUFEN, LOESCHEN, AENDERN, KOPIEREN } TAETIGKEIT;

/* Regelm��igkeit: Wie oft soll die T�tigkeit ausgef�hrt werden */
typedef enum { KEINE, TAEGLICH, WOECHENTLICH, MONATLICH } REGEL;

/* Log-Datei Status: Wird der Funktion Log-Datei �bergeben, um entsprechendes auszugeben */
typedef enum { LFEHLER, START, ENDE, PROGSTART, PROGENDE } LOGSTAT;

/* R�ckgabestatus der "Haupt"-Funktionen, ob erfolgreich abgearbeitet wurde */
typedef enum { SFEHLER, ERFOLG } STATUS;

/* Sprache-Auswahl, momentan noch nicht weiter ber�cksichtigt */
typedef enum { DEUTSCH } SPRACHE;

typedef struct {
		int iTag;
		int iMonat;
		int iJahr;
		} DATUM;

typedef struct {
		int iSekunde;
		int iMinute;
		int iStunde;
		} ZEIT;

/* Termin-Datentyp enth�lt Wochentag, Tag des Monats, Datum, Zeitpunkt und Regelm��igkeit wann was ausgef�hrt werden soll */
typedef struct {
	    int iW_Tag;
		REGEL R_Regelmaessigkeit;
		DATUM D_Datum;
		ZEIT  Z_Zeit;
		} TERMIN;

/** 
  * Datentyp EINGABE enthaelt die eigentlichen Eingaben (Nutzdaten)  eines Benutzers und kann so gespeichert werden.<br>
  * T_Termin: Enthaelt Datum und Uhrzeit, wann eine Taetigkeit ausgefuehrt werden soll.<br>
  * lli_SortMuster: Eine Ganzzahl, die einem Zeitstempel gleicht (Sortiermuster).<br>
  * strQuelle: String, der enthalten sein MUSS, gueltig f�r alle Taetigkeiten.<br>
  * strZiel: String, der enthalten sein KANN, nur beim Kopieren notwendig.<br>
  * strSchema: String, der enthalten sein KANN, beinhaltet Aenderungsschema f�r die Fkt. Aendern.<br>
  * TAT_Funktion: Enthaelt die T�tigkeit, die ausgefuehrt werden soll.<br>
  * i_Id: Temporaere Id, zugewiesen von der Liste (Listenindex = Id).<br>
  */
typedef struct Eingabe {
		TERMIN T_Termin;
		long long int lli_SortMuster;
		char strQuelle[ANZ_CHAR + 1];
		char strZiel[ANZ_CHAR + 1];
		char strSchema[ANZ_SCHEMA + 1];
		TAETIGKEIT TAT_Funktion;
		int i_Id;
		} EINGABE;

/**
 * Dieser Datentyp dient zur Verwaltung der Nutzdaten. 
 * Die Liste wird doppelt verkettet. 
 */
typedef struct EingabeListe {
		EINGABE *E_Taetigkeit;
		struct EingabeListe *EL_Naechste;
		struct EingabeListe *EL_Vorherige;
		} EINGABELISTE;

/**
 * Doppelanker zur Erleichterung der Suche und des Sortierens, 
 * sowie das Anf�gen neuer Elemente an die Liste.
 */
typedef struct doppelAnker {
	EINGABELISTE * EL_Erst;  /* Erster in Liste */
	EINGABELISTE * EL_Letzt; /* Letzter in Liste*/
}DOPPELANKER;

#endif
