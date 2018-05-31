/*Beeinhaltet die GUI Darstellung, 
also hier ist das ganze Interface definiert
*
* Datei: mathomadaja.cpp Autor: David Garus
* Datum: 01.05.2008
*
* Historie: Entwicklungsphase, d.h. andauernde �nderungen
*/
/* Klassenheader zur Bereitstellung der Qt-Objekte und Signale */
#include "MathoMadaja.h"
#include "loeschen.h"
#include "aufrufen.h"
#include "kopieren.h"
#include "aendern.h"

/**
* Funktionsbeschreibung: Konstruktor der Klasse MathoMadaja. Initialisiert die Qt-Objekte und weitere notwendige Klassenvariablen <br>
* 				 um globale Behandlung zu unterdruecken. <br>
* <br>
* Eingabeparameter:  Zeiger auf das "Parent-Window" <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
MathoMadaja::MathoMadaja(QMainWindow *parent) : QMainWindow(parent){ 
        setupUi(this);
		/* F�r Verarbeitung der Logdatei zu Beginn sind folgende 4 Variablen n�tig */
		TERMIN T_StartZeit;
		STATUS S_RueckgabeStatus;
		time_t t_zeit;
		struct tm *tm_zeitinfo;
		
		textEdit = new QTextEdit;
		
		QStrBuCaption    = Taetigkeit_anlegen->text();
		QStrModBuCaption = "T�tigkeit ab�ndern";
		
		QStr_Trenner     =  " - ";
		
		/* Initialisierung des Timers mit einem Zeitintervall von 1 Sek. 
		ruft nach Ablaufen der Zeit die Klassen-Methode TimerUpdate, um eingestellte T�tigkeiten zu pr�fen, auf. */
		QTimer *timer = new QTimer(this);	
		connect(timer, SIGNAL(timeout()), this, SLOT(TimerUpdate()));
		timer->start(1000);
		
		/* damit die Datumsausgabe deutsch ist (Systemeinstellung) */
		setlocale(LC_ALL, "");
		/* aktuelle Kalenderzeit abrufen und speichern */
		time(&t_zeit);
		/* als lokale Zeit in Elemente der Struktur zerlegen */
		tm_zeitinfo = localtime(&t_zeit);
		
		/* Folgende Funktion wandelt struct tm in TERMIN um (Dekl. in zeitstempel.h)  */
		T_StartZeit = ZeitInTermin(tm_zeitinfo);
		
		/*Verbindet jeweils das im QT-Designer festgelegte Element, mit einer der folgenden Funktionen*/

		/*Hier sind die Funktionen der Buttons Definiert*/
		connect( Laden , SIGNAL ( clicked() ) , this , SLOT ( Oeffnen() ) );
		connect( ManuellerStart , SIGNAL ( clicked() ) , this , SLOT ( slotManuellerStart() ) );

		/*Hier sind die Funktionen der Elemente aus der Navigationsleiste definiert*/
		connect( actionBeenden_2 , SIGNAL ( triggered() ) , this , SLOT ( slotBeenden() ) );
		connect( actionNeu , SIGNAL ( triggered() ) , this , SLOT ( neueDatei() ) );
		connect( actionOeffnen , SIGNAL ( triggered() ) , this , SLOT ( Oeffnen() ) );
		connect( actionSpeichern , SIGNAL ( triggered() ) , this , SLOT ( Speichern() ) );
		connect( actionSpeichern_unter , SIGNAL ( triggered() ) , this , SLOT ( Speichern_unter() ) );
		connect( action_ber , SIGNAL ( triggered() ) , this , SLOT ( Ueber() ) );
		connect( actionLogAnzeigen , SIGNAL ( triggered() ) , this , SLOT ( ShowLogFile() ) );
		connect( actionLogEntfernen , SIGNAL ( triggered() ) , this , SLOT ( DelLogFile() ) );
		connect( actionHilfe_aufrufen, SIGNAL (triggered() ), this , SLOT( ShowHelpFile() ) );
	
		connect( textEdit -> document() , SIGNAL ( contentsChanged() ) , this , SLOT ( Dokument_wurde_geaendert() ) );

        aktuelleDatei("einstellungen.mmdj");
		
		/*Bevor der Benutzer die Zeit und das Datum festlegt, 
		wird hier alles erst mal auf die System-Zeit und auf das System-Datum festgelegt*/
		ZeitAenderung->setTime(QTime::currentTime() );
		DatumsAenderung->setDate(QDate::currentDate() );

		/*Hier sind die Funktionen aufgelistet die f�r die Anzeige des aktuellen Datums zust�ndig sind*/
		connect( DatumsAenderung, SIGNAL(dateChanged(const QDate &)),Kalender, SLOT(setSelectedDate(const QDate &)));
		connect( Kalender , SIGNAL ( selectionChanged() ) , this , SLOT( ausgewaehltes_Datum_wurde_geaendert() ) );
		
		/* T�tigkeiten anlegen, �ndern, l�schen Signale verbinden */
		connect( Taetigkeit_anlegen , SIGNAL ( clicked( ) ) , this , SLOT( NeueTaetigkeitHinzu() )  );
		connect( Taetigkeit_entfernen, SIGNAL ( clicked( ) ) , this , SLOT( TaetigkeitEntfernen() )  );
		connect( Taetigkeit_anpassen,  SIGNAL ( clicked( ) ), this , SLOT( TaetigkeitAnpassen() ) );
		
		/*Diese Check Boxen werden hier mit der Funktion weiter unten verbunden/connectiert*/
		connect( taeglich , SIGNAL ( clicked( ) ) , this , SLOT( CheckBoxen_taeglich() )  );
		connect( woechentlich , SIGNAL ( clicked( )   ) , this , SLOT( CheckBoxen_woechentlich() )  );
		connect( monatlich , SIGNAL ( clicked( ) ) , this , SLOT( CheckBoxen_monatlich() )  );
		
		/*Bis es keine alternative gibt, werden hier alle Durchsuchen Buttons also 
		[...]-Buttons einzeln mit jeweils einer einzelfunktion verkn�pft*/
		/* ERSETZT DURCH SPEZIELLE VERZEICHNIS UND DATEI BUTTONS!!! */
		/*Dies sind alle VERZEICHNIS BUTTONS die mit der Funktion OpenDir verbunden sind*/
		connect( buVonVerz , SIGNAL ( clicked() ), this , SLOT( OpenDir_Durchsuchen_Von() ) );
		connect( buNachVerz , SIGNAL ( clicked() ), this , SLOT( OpenDir_Durchsuchen_Nach() ) );
		connect( buAendVerz , SIGNAL ( clicked() ), this , SLOT( OpenDir_Durchsuchen_Aendern() ) );
		connect( buLoeschVerz , SIGNAL ( clicked() ), this , SLOT( OpenDir_Durchsuchen_Loeschen() ) );

		/*Dies sind alle DATEI BUTTONS, eingeschlossen ist auch der Durchsuchen Button f�r die Funktion Ausf�hren*/
		connect( Durchsuchen_Ausfuehren , SIGNAL ( clicked() ), this , SLOT( OpenFile_Durchsuchen_Ausfuehren() ) );
		connect( buVonDat , SIGNAL ( clicked() ), this , SLOT( OpenFile_Durchsuchen_Von() ) );
		connect( buNachDat , SIGNAL ( clicked() ), this , SLOT( OpenFile_Durchsuchen_Nach() ) );
		connect( buAendDat , SIGNAL ( clicked() ), this , SLOT( OpenFile_Durchsuchen_Aendern() ) );
		connect( buLoeschDat , SIGNAL ( clicked() ), this , SLOT( OpenFile_Durchsuchen_Loeschen() ) );
		
		/* Initialisierung beim Start des Programms der Liste mit NULL */
		EL_MMDJ_Liste = NULL;
		DA_MMDJ_Anker.EL_Erst  = NULL;
		DA_MMDJ_Anker.EL_Letzt = NULL;
		
		ladenDatei(curFile);
		
		/* AnpassenFlag darf beim Start nicht gesetzt sein! */
	    iAnpassenFlag		   = 0;
		
		/* Programmstart wird protokolliert: Default-Parameter werden direkt �bergeben (siehe datentypen.h) */
		strcpy(strLogdatei, "logdatei.txt");
		strcpy(strEndedatei, "sitzung.end");
		strcpy(strHilfedatei, "hilfe.chm");
		
		S_RueckgabeStatus = logdatei(strLogdatei, PROGSTART, ERFOLG, T_StartZeit, TKEINE, "\0", "\0");
		
		if (S_RueckgabeStatus == SFEHLER) {
				LogDateiError();
		}
 }

 
/**
* Funktionsbeschreibung: Destruktor der Klasse MathoMadaja. Gibt Speicher wieder frei, loescht die Liste und speichert das Anwendungsende in Datei <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
MathoMadaja::~MathoMadaja() {
		/* F�r Verarbeitung der Logdatei zum Beenden sind folgende 4 Variablen n�tig */
		TERMIN T_EndeZeit;
		STATUS S_RueckgabeStatus;
		time_t t_zeit;
		struct tm *tm_zeitinfo;
		
		/* damit die Datumsausgabe deutsch ist (Systemeinstellung) */
		setlocale(LC_ALL, "");
		/* aktuelle Kalenderzeit abrufen und speichern */
		time(&t_zeit);
		/* als lokale Zeit in Elemente der Struktur zerlegen */
		tm_zeitinfo = localtime(&t_zeit);
		
		T_EndeZeit = ZeitInTermin( tm_zeitinfo );
		TerminSpeichern( T_EndeZeit, strEndedatei );
		
		S_RueckgabeStatus = logdatei(strLogdatei, PROGENDE, ERFOLG, T_EndeZeit, TKEINE, "\0", "\0");
		
		if (S_RueckgabeStatus == SFEHLER) {
			LogDateiError();
		}
		
		/* Eingabeliste: Alle Elemente loeschen und Speicher wieder freigeben */
		if (EL_MMDJ_Liste != NULL) {
			eingabeliste_Loeschen ( &EL_MMDJ_Liste );
		}
}



/**
* Funktionsbeschreibung: Anzeige einer Warnung, wenn die Logdatei nicht beschrieben werden konnte <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::LogDateiError() {
	QMessageBox::about(this, tr("Fehler"),
		tr("Die Log-Datei konnte nicht geschrieben werden.<br>"
		"Bitte �berpr�fen Sie, dass die Datei nicht schreibgesch�tzt ist<br>"
		"und noch gen�gend Speicher vorhanden ist."));
}



/**
* Funktionsbeschreibung: Timer-Routine, die im 1 Sekunden Intervall aufgerufen wird. Verarbeitet daraufhin alle Listeneintraege  <br>
*				 und fuehrt gegebenenfalls gespeicherte Taetigkeiten aus. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::TimerUpdate()
{
	time_t t_zeit;
	struct tm *tm_zeitinfo;
	TERMIN T_Zeit, T_Merker;
	EINGABELISTE *EL_Renner = NULL;
	EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Erst;
	EL_Renner = EL_MMDJ_Liste;
	STATUS S_Fkt = ERFOLG, S_Log = ERFOLG;
	int iRunFlag = 0;
	
	if ( EL_Renner == NULL ) { /* Bei leerer Liste muss hier nichts getan werden */
		return;
	}
	
	while (EL_Renner != NULL) { /* In dieser Schleife die Liste durchgehen, ob eine T�tigkeitausgef�hrt werden soll. */
		iRunFlag = 0;
		T_Merker = EL_Renner->E_Taetigkeit->T_Termin; /* T_Merker wird nur benutzt f�r die einfachere Darstellung im Programm */
		
		/* damit die Datumsausgabe deutsch ist (Systemeinstellung) */
		setlocale(LC_ALL, "");
		/* aktuelle Kalenderzeit abrufen und speichern */
		time(&t_zeit);
		/* als lokale Zeit in Elemente der Struktur zerlegen */
		tm_zeitinfo = localtime(&t_zeit);
		
		/* Folgende Funktion wandelt struct tm in TERMIN um (Dekl. in zeitstempel.h) , 
		damit der Inhalt mit den Listeneintr�gen verglichen werden kann */
		T_Zeit = ZeitInTermin(tm_zeitinfo);
		
		switch(EL_Renner->E_Taetigkeit->T_Termin.R_Regelmaessigkeit) {
			case TAEGLICH: /* Bei T�glich soll nur das Startdatum der T�tigkeit und die Uhrzeit gepr�ft werden. 
							   Au�erdem soll beachtet werden, ob aktuelles Jahr und aktueller Monat. */
					if (T_Merker.D_Datum.iJahr == T_Zeit.D_Datum.iJahr) {
						if (T_Merker.D_Datum.iMonat == T_Zeit.D_Datum.iMonat) { /* Bei aktuellem Monat muss gecheckt werden, ob Tag noch in Kriterienbereich f�llt */
							if (T_Merker.D_Datum.iTag <= T_Zeit.D_Datum.iTag) {
								if ( T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && 
									 T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde ) {
									 iRunFlag = 1;
								}
							
							}
							
						}
						else if (T_Merker.D_Datum.iMonat < T_Zeit.D_Datum.iMonat) { /* Wenn Monat vergangen, dann stimmt jeder Tag und es muss nur die Zeit gecheckt werden */
								if ( T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && 
									 T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde ) {
									 iRunFlag = 1;
								}
						}
					}
					else if ( T_Merker.D_Datum.iJahr < T_Zeit.D_Datum.iJahr ) { /* Wenn bereits Folgejahr erreicht, dann nur noch Zeit checken und jeden Tag ausf�hren */
						if ( T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && 
									 T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde ) {
									 iRunFlag = 1;
								}
					}

				break;
				
				
				
			case WOECHENTLICH: /* Bei W�chentlich soll nur das Startdatum der T�tigkeit und der Wochentag gepr�ft werden. 
								   Au�erdem soll beachtet werden, ob aktuelle Jahr*/
					if ( T_Merker.D_Datum.iJahr == T_Zeit.D_Datum.iJahr ) {
						if (T_Merker.D_Datum.iMonat == T_Zeit.D_Datum.iMonat) {
							if (T_Merker.D_Datum.iTag <= T_Zeit.D_Datum.iTag) {
								if (T_Merker.iW_Tag == T_Zeit.iW_Tag && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
									T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde) {
								iRunFlag = 1;
								}
							}
						}
						else if (T_Merker.D_Datum.iMonat < T_Zeit.D_Datum.iMonat) { /* Wenn Monat vergangen, dann stimmt jeder Tag und es muss nur die Zeit gecheckt werden */
							if (T_Merker.iW_Tag == T_Zeit.iW_Tag && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
									T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde) {
									iRunFlag = 1;
								}
						}
					}
					else if ( T_Merker.D_Datum.iJahr < T_Zeit.D_Datum.iJahr ) {
						if (T_Merker.iW_Tag == T_Zeit.iW_Tag && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
									T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde) {
									iRunFlag = 1;
								}
					}
				break;
				
				
				
			case MONATLICH: /* Bei Monatlich muss der Tag, das Jahr UND die Zeit passen, 
							      Au�erdem soll beachtet werden, ob aktuelles Jahr */
					if ( T_Merker.D_Datum.iJahr == T_Zeit.D_Datum.iJahr ) {
						if ( T_Merker.D_Datum.iMonat <= T_Zeit.D_Datum.iMonat) {
							if (T_Merker.D_Datum.iTag == T_Zeit.D_Datum.iTag && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
							    T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde) {
								iRunFlag = 1;
							}
						}
					}
					else if( T_Merker.D_Datum.iJahr < T_Zeit.D_Datum.iJahr ) {
						if (T_Merker.D_Datum.iTag == T_Zeit.D_Datum.iTag && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
							    T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde) {
								iRunFlag = 1;
						}
					}
				break;
				
				
				
			default: /* Bei keiner Regelm��igkeit muss nur zu dem bestimmten Termin ausgef�hrt werden! */
					if ( T_Merker.D_Datum.iTag == T_Zeit.D_Datum.iTag && T_Merker.D_Datum.iMonat == T_Zeit.D_Datum.iMonat && 
						 T_Merker.D_Datum.iJahr == T_Zeit.D_Datum.iJahr && T_Merker.Z_Zeit.iSekunde == T_Zeit.Z_Zeit.iSekunde && 
						 T_Merker.Z_Zeit.iMinute == T_Zeit.Z_Zeit.iMinute && T_Merker.Z_Zeit.iStunde  == T_Zeit.Z_Zeit.iStunde ) {
								iRunFlag = 1;
						}
					break;
		}
		
		if (iRunFlag == 1) { /* T�tigkeit ausf�hren und protokollieren */
			S_Log = logdatei( strLogdatei, START, ERFOLG, T_Merker, EL_Renner->E_Taetigkeit->TAT_Funktion, EL_Renner->E_Taetigkeit->strQuelle, EL_Renner->E_Taetigkeit->strZiel);		
			
			switch(EL_Renner->E_Taetigkeit->TAT_Funktion) {
				case AUFRUFEN:
					S_Fkt = aufrufen(EL_Renner->E_Taetigkeit->strQuelle);	
					break;
				case LOESCHEN:
					S_Fkt = loeschen(EL_Renner->E_Taetigkeit->strQuelle);			
					break;
				case AENDERN:
					S_Fkt = aendern(EL_Renner->E_Taetigkeit->strQuelle, EL_Renner->E_Taetigkeit->strSchema);
					break;
				case KOPIEREN:
					S_Fkt = kopieren(EL_Renner->E_Taetigkeit->strQuelle, EL_Renner->E_Taetigkeit->strZiel);
					break;
				default:
					break;
			}	
			
			/* ----------------------------------------------- ENDE-Zeit f�r die Abarbeitung setzen ----------------------------------------- */
			/* damit die Datumsausgabe deutsch ist (Systemeinstellung) */
			setlocale(LC_ALL, "");
			/* aktuelle Kalenderzeit abrufen und speichern */
			time(&t_zeit);
			/* als lokale Zeit in Elemente der Struktur zerlegen */
			tm_zeitinfo = localtime(&t_zeit);
		
			/* Folgende Funktion wandelt struct tm in TERMIN um (Dekl. in zeitstempel.h) , 
			damit der Inhalt mit den Listeneintr�gen verglichen werden kann */
			T_Zeit = ZeitInTermin(tm_zeitinfo);
			
			S_Log = logdatei( strLogdatei, ENDE, S_Fkt, T_Zeit, EL_Renner->E_Taetigkeit->TAT_Funktion, EL_Renner->E_Taetigkeit->strQuelle, EL_Renner->E_Taetigkeit->strZiel);	
		}
		
	EL_Renner = EL_Renner->EL_Naechste;
	}
	
	EL_Renner = DA_MMDJ_Anker.EL_Erst;
}


/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Quelldatei (Kopieren) anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenFile_Durchsuchen_Von( ) 
{
	ChangeDropdown("buVonDat");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Zieldatei (Kopieren) anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenFile_Durchsuchen_Nach( ) 
{
	ChangeDropdown("buNachDat");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Aenderndatei anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenFile_Durchsuchen_Aendern( ) 
{
	ChangeDropdown("buAendDat");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Loeschendatei anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenFile_Durchsuchen_Loeschen( ) 
{
	ChangeDropdown("buLoeschDat");
}

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Ausfuehrendatei anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenFile_Durchsuchen_Ausfuehren( ) 
{
	ChangeDropdown("Durchsuchen_Ausfuehren");
}

/**
* Funktionsbeschreibung: Selektion-Routine zur Auswahl des entsprechenden Dialogs <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::ChangeDropdown(const QString &QStrBuName)  {
QString fileName = QFileDialog::getOpenFileName(this, 
						tr("Datei �ffnen"),
						"C:/Programme/");

if (!fileName.isEmpty()) {
	if (QStrBuName == "buAendDat") {
		DropDown_Aendern->setEditText( fileName );
	}
	else if(QStrBuName == "buVonDat") {
		DropDown_Von->setEditText( fileName );
	}
	else if(QStrBuName == "buNachDat") { 
		DropDown_Nach->setEditText( fileName );
	}
	else if (QStrBuName == "buLoeschDat") {
		DropDown_Loeschen->setEditText( fileName );
	}
	else if (QStrBuName == "Durchsuchen_Ausfuehren") {
		DropDown_Ausfuehren->setEditText( fileName );
	}
}

}

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Quellordner (Kopieren) anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenDir_Durchsuchen_Von( )  {
	OpenDir("buVonVerz");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Zielordner (Kopieren) anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenDir_Durchsuchen_Nach( )  {
	OpenDir("buNachVerz");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Aenderungsordner anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenDir_Durchsuchen_Aendern( )  {
	OpenDir("buAendVerz");
} 

/**
* Funktionsbeschreibung: Oeffnen-Dialog fuer Loeschordner anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenDir_Durchsuchen_Loeschen( )  {
	OpenDir("buLoeschVerz");
}

/**
* Funktionsbeschreibung: Selektion-Routine zur Auswahl des entsprechenden Dialogs <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::OpenDir(const QString &QStrBuName) {
	QString pathName = QFileDialog::getExistingDirectory(this, 
							tr("Verzeichnis �ffnen"),
							"C:/Programme/",
							QFileDialog::ShowDirsOnly );

	if (!pathName.isEmpty()) {
		if (QStrBuName == "buAendVerz") {
			DropDown_Aendern->setEditText( pathName );
		}	
		else if(QStrBuName == "buVonVerz") {
			DropDown_Von->setEditText( pathName );
		}
		else if(QStrBuName == "buNachVerz") {
			DropDown_Nach->setEditText( pathName );
		}
		else if (QStrBuName == "buLoeschVerz") {
			DropDown_Loeschen->setEditText( pathName );
		}
	}
}



/* ------------------------------------------------------ START T�tigkeit hinzuf�gen bzw. nach Anpassen zur�ckschreiben --------------------------------------------------------------- */
/**
* Funktionsbeschreibung: Fuegt eine neue Taetigkeit der Liste hinzu oder schreibt angepasste Taetigkeiten in die Liste zurueck <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::NeueTaetigkeitHinzu() {
	int iTempId = -1;
	TERMIN T_Setzen;
	QByteArray Qba1, Qba2, Qba3, Qba4, Qba5, Qba6; /* F�r jedes Dropdown Feld ein QByteArray, damit C-Strings korrekt erzeugt werden k�nnen! */
	QString QStr_Von     = DropDown_Von->currentText();
    const char *str_Von  = NULL;
	QString QStr_Nach    = DropDown_Nach->currentText();
	const char *str_Nach = NULL;
	QString QStr_Aend    = DropDown_Aendern->currentText();
	const char *str_Aend = NULL;
	QString QStr_Sort    = Sortierung->text();
	const char *str_Sort = NULL;
	QString QStr_Loesch  = DropDown_Loeschen->currentText();
	const char *str_Loesch     = NULL;
	QString QStr_Ausf    = DropDown_Ausfuehren->currentText();
	const char *str_Ausf = NULL;
	int iTaetigkeitId    = (int) Taetigkeit_Liste->currentRow();
	EINGABE *E_Anzupassen= NULL;
	QListWidgetItem *QLWI_Aendern = NULL;
	
	QTime   QT_ZeitAend  = ZeitAenderung->time();
	QDate   QD_DatumAend = DatumsAenderung->date();
	
	QString QStrZeit     = QT_ZeitAend.toString( "hh:mm:ss" );
	QString QStrDatum    = QD_DatumAend.toString( "dd.MM.yyyy" );
	
	QString QStrTemp, QStrRegelTemp;
	
	/*  Umwandlung der QStrings in Standard C-Strings */
	Qba1        = QStr_Von.toLatin1();
	str_Von     = (char *) Qba1.data();
	Qba2        = QStr_Nach.toLatin1();
	str_Nach    = (char *) Qba2.data(); 
	Qba3        = QStr_Aend.toLatin1();
	str_Aend   = (char *) Qba3.data();
	Qba4        = QStr_Sort.toLatin1();
	str_Sort   = (char *) Qba4.data();
	Qba5        = QStr_Loesch.toLatin1();
	str_Loesch = (char *) Qba5.data();
	Qba6        = QStr_Ausf.toLatin1();
	str_Ausf   = (char *) Qba6.data();
	
	T_Setzen.D_Datum.iJahr      = (int) QD_DatumAend.year();
	T_Setzen.D_Datum.iMonat     = (int) QD_DatumAend.month();
	T_Setzen.D_Datum.iTag       = (int) QD_DatumAend.day();
	T_Setzen.iW_Tag				= (int) QD_DatumAend.dayOfWeek(); 	
	T_Setzen.Z_Zeit.iStunde     = (int) QT_ZeitAend.hour();
	T_Setzen.Z_Zeit.iMinute     = (int) QT_ZeitAend.minute();
	T_Setzen.Z_Zeit.iSekunde    = (int) QT_ZeitAend.second();
	
	if ( taeglich->checkState( ) == Qt::Checked ) {
		T_Setzen.R_Regelmaessigkeit = TAEGLICH;
		QStrRegelTemp = QString( str_C_TAEGLICH[0] );
	} 
	else if ( woechentlich->checkState( ) == Qt::Checked) {
		T_Setzen.R_Regelmaessigkeit = WOECHENTLICH;
		QStrRegelTemp = QString( str_C_WOECHENTLICH[0] );
	}
	else if ( monatlich->checkState( ) == Qt::Checked) {
		T_Setzen.R_Regelmaessigkeit = MONATLICH;
		QStrRegelTemp = QString( str_C_MONATLICH[0] );
	}
	else {
		T_Setzen.R_Regelmaessigkeit = KEINE;
		QStrRegelTemp = QString( str_C_KEINE[0] );
	}	
	
	/* Die �ber-Abfrage, ob hinzugef�gt ( 0 ) oder ge�ndert ( 1 ) wird */
	if (iAnpassenFlag == 0) { /* Liste ans Ende setzen, damit hinzugef�gt wird! */
		EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Letzt;
	
		/* Pr�fung, ob die Strings leer sind oder gef�llt, wenn mehrere gef�llt, wird einfach eins nach dem anderen als Eingabe in der Eingabeliste erfasst! */
		if( strlen(str_Von) != 0 && strlen(str_Nach) != 0 ) {
			QStrTemp = CreateListEntry(QString( str_C_KOPIEREN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Von, QStr_Nach, "", QStr_Trenner);
	
			Taetigkeit_Liste->addItem(QStrTemp);
			iTempId = (int) (Taetigkeit_Liste->count() - 1);
		
			eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Von, str_Nach, "\0", KOPIEREN, T_Setzen, iTempId);
		
			if ( DA_MMDJ_Anker.EL_Erst == NULL ) {
				DA_MMDJ_Anker.EL_Erst = EL_MMDJ_Liste;
			}
		}
		/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
		else if ( (strlen(str_Von) != 0 && strlen(str_Nach) == 0) || (strlen(str_Von) == 0 && strlen(str_Nach) != 0) ){
			QMessageBox::about(this, tr("Fehler beim Erfassen"),
									tr("VON und NACH m�ssen beide gef�llt sein!"));	
		}
	
		if( strlen(str_Aend) != 0 && strlen(str_Sort) != 0 ) {
			QStrTemp = CreateListEntry(QString( str_C_AENDERN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Aend, "", QStr_Sort, QStr_Trenner);
	
			Taetigkeit_Liste->addItem(QStrTemp);
			iTempId = (int) (Taetigkeit_Liste->count() - 1);
		
			eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Aend, "\0", str_Sort, AENDERN, T_Setzen, iTempId);
		
			if ( DA_MMDJ_Anker.EL_Erst == NULL ) {
				DA_MMDJ_Anker.EL_Erst = EL_MMDJ_Liste;
			}
		}
		/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
		else if ( (strlen(str_Aend) != 0 && strlen(str_Sort) == 0) || (strlen(str_Aend) == 0 && strlen(str_Sort) != 0) ) {				
			QMessageBox::about(this, tr("Fehler beim Erfassen"),
									tr("�NDERN und Sortierschema m�ssen beide gef�llt sein!"));	
		}
	
		if( strlen(str_Loesch) != 0 ) {
			QStrTemp = CreateListEntry(QString( str_C_LOESCHEN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Loesch, "", "", QStr_Trenner);
	
			Taetigkeit_Liste->addItem(QStrTemp);
			iTempId = (int) (Taetigkeit_Liste->count() - 1);		
	
			eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Loesch, "\0", "\0", LOESCHEN, T_Setzen, iTempId);

			if ( DA_MMDJ_Anker.EL_Erst == NULL ) {
				DA_MMDJ_Anker.EL_Erst = EL_MMDJ_Liste;
			}
		}
	
		if ( strlen(str_Ausf) != 0 ) {
			QStrTemp = CreateListEntry(QString( str_C_AUFRUFEN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Ausf, "", "", QStr_Trenner);
		
			Taetigkeit_Liste->addItem(QStrTemp);
			iTempId = (int) (Taetigkeit_Liste->count() - 1);
		
			eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Ausf, "\0", "\0", AUFRUFEN, T_Setzen, iTempId);
		
			if ( DA_MMDJ_Anker.EL_Erst == NULL ) {
				DA_MMDJ_Anker.EL_Erst = EL_MMDJ_Liste;
			}
		}
		
	/* Immer das letzte hinzugef�gte Element setzt das Ende des Ankerpunkts von Doppelanker */
	DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
	} /* ------------------------ Aktion hinzuf�gen endet hier -------------------------------- */

	else { /* ------------------------ Aktion anpassen zur�ckschreiben startet hier -------------------------------- */
			QLWI_Aendern = Taetigkeit_Liste->item( iTaetigkeitId );
			E_Anzupassen = eingabeliste_Suche( EL_MMDJ_Liste, iTaetigkeitId );
			
			/* Start der Bedingung ob Kopieren */
			if ( strlen(str_Von) != 0 && strlen(str_Nach) != 0 ) {
				QStrTemp = CreateListEntry(QString( str_C_KOPIEREN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Von, QStr_Nach, "", QStr_Trenner);
				if (E_Anzupassen->TAT_Funktion == KOPIEREN) {
					QLWI_Aendern->setText( QStrTemp );
					Taetigkeit_Liste->editItem(QLWI_Aendern);
					eingabeliste_EingabeAnpassen( &EL_MMDJ_Liste, str_Von, str_Nach, "\0", KOPIEREN, T_Setzen, iTaetigkeitId );
				}
				else { /* Wenn nicht �ndern, aber trotzdem Inhalt, dann ans Ende der Liste anf�gen, dann Liste wieder auf bisherigen Punkt setzen */
					EINGABELISTE *EL_Merker = EL_MMDJ_Liste;
					EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Letzt;
					Taetigkeit_Liste->addItem(QStrTemp);
					iTempId = (int) (Taetigkeit_Liste->count() - 1);
					eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Von, str_Nach, "\0", KOPIEREN, T_Setzen, iTempId);
					DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
					EL_MMDJ_Liste = EL_Merker;
				}
			}
			/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
			else if ( (strlen(str_Von) != 0 && strlen(str_Nach) == 0) || (strlen(str_Von) == 0 && strlen(str_Nach) != 0) ){
				QMessageBox::about(this, tr("Fehler beim Erfassen"),
										tr("VON und NACH m�ssen beide gef�llt sein!"));	
			}
			/* Start der Bedingung ob �ndern */
			if( strlen(str_Aend) != 0 && strlen(str_Sort) != 0 ) {
				QStrTemp = CreateListEntry(QString( str_C_AENDERN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Aend, "", QStr_Sort, QStr_Trenner);
				if (E_Anzupassen->TAT_Funktion == AENDERN) {
					QLWI_Aendern->setText( QStrTemp );
					Taetigkeit_Liste->editItem(QLWI_Aendern);
					eingabeliste_EingabeAnpassen( &EL_MMDJ_Liste, str_Aend, "\0", str_Sort, AENDERN, T_Setzen, iTaetigkeitId );
				}
				else { /* Wenn nicht �ndern, aber trotzdem Inhalt, dann ans Ende der Liste anf�gen, dann Liste wieder auf bisherigen Punkt setzen */
					EINGABELISTE *EL_Merker = EL_MMDJ_Liste;
					EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Letzt;
					Taetigkeit_Liste->addItem(QStrTemp);
					iTempId = (int) (Taetigkeit_Liste->count() - 1);
					eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Aend, "\0", str_Sort, AENDERN, T_Setzen, iTempId);
					DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
					EL_MMDJ_Liste = EL_Merker;
				}
			}
			/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
			else if ( (strlen(str_Aend) != 0 && strlen(str_Sort) == 0) || (strlen(str_Aend) == 0 && strlen(str_Sort) != 0) ) {				
				QMessageBox::about(this, tr("Fehler beim Erfassen"),
										tr("�NDERN und Sortierschema m�ssen beide gef�llt sein!"));	
			}
			/* Start der Bedingung ob L�schen */
			if( strlen(str_Loesch) != 0 ) {
				QStrTemp = CreateListEntry( QString( str_C_LOESCHEN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Loesch, "", "", QStr_Trenner);
				if (E_Anzupassen->TAT_Funktion == LOESCHEN) {
					QLWI_Aendern->setText( QStrTemp );
					Taetigkeit_Liste->editItem(QLWI_Aendern);
					eingabeliste_EingabeAnpassen( &EL_MMDJ_Liste, str_Loesch, "\0", "\0", LOESCHEN, T_Setzen, iTaetigkeitId );
				}
				else { /* Wenn nicht �ndern, aber trotzdem Inhalt, dann ans Ende der Liste anf�gen, dann Liste wieder auf bisherigen Punkt setzen */
					EINGABELISTE *EL_Merker = EL_MMDJ_Liste;
					EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Letzt;
					Taetigkeit_Liste->addItem(QStrTemp);
					iTempId = (int) (Taetigkeit_Liste->count() - 1);
					eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Loesch, "\0", "\0", LOESCHEN, T_Setzen, iTempId);
					DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
					EL_MMDJ_Liste = EL_Merker;
				}
			}
			/* Start der Bedingung ob Ausf�hren */
			if ( strlen(str_Ausf) != 0 ) {
				QStrTemp = CreateListEntry(QString( str_C_AUFRUFEN[0] ), QStrDatum, QStrZeit, QStrRegelTemp, QStr_Ausf, "", "", QStr_Trenner);
				if (E_Anzupassen->TAT_Funktion == AUFRUFEN) {
					QLWI_Aendern->setText( QStrTemp );
					Taetigkeit_Liste->editItem(QLWI_Aendern);
					eingabeliste_EingabeAnpassen( &EL_MMDJ_Liste, str_Ausf, "\0", "\0", AUFRUFEN, T_Setzen, iTaetigkeitId );
				}
				else { /* Wenn nicht �ndern, aber trotzdem Inhalt, dann ans Ende der Liste anf�gen, dann Liste wieder auf bisherigen Punkt setzen */
					EINGABELISTE *EL_Merker = EL_MMDJ_Liste;
					EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Letzt;
					Taetigkeit_Liste->addItem(QStrTemp);
					iTempId = (int) (Taetigkeit_Liste->count() - 1);
					eingabeliste_Einfuegen(&EL_MMDJ_Liste, str_Ausf, "\0", "\0", AUFRUFEN, T_Setzen, iTempId);
					DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
					EL_MMDJ_Liste = EL_Merker;
				}
			}	
		/* Ab hier wieder auf Standard-Ansicht umstellen */
		iAnpassenFlag = 0;
		SetEnOrDisable(iAnpassenFlag, QStrBuCaption, QStrModBuCaption);
			
	} /* ------------------------ Aktion anpassen zur�ckschreiben endet hier -------------------------------- */
}
/* ------------------------------------------------------ ENDE T�tigkeit hinzuf�gen --------------------------------------------------------------- */


/* ------------------------------------------------------ START T�tigkeit entfernen --------------------------------------------------------------- */
/**
* Funktionsbeschreibung: Entfernen der ausgewaehlten Taetigkeit aus der Liste.  <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::TaetigkeitEntfernen() {
	int iRetCode;
	int iTaetigkeitId = (int) Taetigkeit_Liste->currentRow();

	EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Erst;
	
	if (iTaetigkeitId == 0 && DA_MMDJ_Anker.EL_Erst != NULL) {
		DA_MMDJ_Anker.EL_Erst = DA_MMDJ_Anker.EL_Erst->EL_Naechste;
	}
	
	if ( (iTaetigkeitId == Taetigkeit_Liste->count() -1) &&  DA_MMDJ_Anker.EL_Letzt!= NULL ) {
		DA_MMDJ_Anker.EL_Letzt = DA_MMDJ_Anker.EL_Letzt->EL_Vorherige;
	}
	
	/* Wenn kein Element in der Liste ausgew�hlt wurde, soll nachgefragt werden, ob die komplette Liste geleert werden soll. */
	if ( iTaetigkeitId < 0 && Taetigkeit_Liste->count() > 0 && EL_MMDJ_Liste != NULL ) {		
		iRetCode = QMessageBox::warning(this, tr("Achtung!"),
										tr("Wollen Sie die komplette Liste leeren?"),
										QMessageBox::Yes | QMessageBox::No);
		if (iRetCode == QMessageBox::Yes) {
			eingabeliste_Loeschen(&EL_MMDJ_Liste);
			Taetigkeit_Liste->clear();
			DA_MMDJ_Anker.EL_Erst  = NULL;
			DA_MMDJ_Anker.EL_Letzt = NULL;
		}
	}
	/* Ansonsten pr�fen, ob Element ausgew�hlt wurde. Wenn gar nichts gew�hlt wurde, dann soll auch nichts gel�scht bzw. getan werden. */
	else if  (iTaetigkeitId >= 0 && EL_MMDJ_Liste != NULL) {
		eingabeliste_element_Loeschen(&EL_MMDJ_Liste, iTaetigkeitId);
		delete Taetigkeit_Liste->currentItem();
	}	
	
	/* Auswahl zur�cksetzen auf keine */
	Taetigkeit_Liste->setCurrentRow( -1 );
}
/* ------------------------------------------------------ ENDE T�tigkeit entfernen --------------------------------------------------------------- */



/* ------------------------------------------------------ START T�tigkeit anpassen --------------------------------------------------------------- */
/**
* Funktionsbeschreibung: Ausgewaehlte Taetigkeit im Editierbereich anzeigen lassen und Umgebung anpassen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::TaetigkeitAnpassen() {
	QTime   QT_ZeitAend;
	QDate   QD_DatumAend;
	int iTaetigkeitId     = (int) Taetigkeit_Liste->currentRow();
	EINGABE *E_Anpassen   = NULL;
	EL_MMDJ_Liste         = DA_MMDJ_Anker.EL_Erst;
	
	if (EL_MMDJ_Liste == NULL || iTaetigkeitId < 0 || Taetigkeit_Liste->count() <= 0) {
		return;
	}
	
	else { /* Beim Anpassen sollen die Buttons entfernen und anpassen ausgeschaltet werden, ebenso wie die Liste,
			   damit das gew�hlte angepasst werden kann und nicht andere Sachen nebenher gemacht werden! */
		iAnpassenFlag = 1;
		SetEnOrDisable(iAnpassenFlag, QStrBuCaption, QStrModBuCaption);
		
		E_Anpassen = eingabeliste_Suche( EL_MMDJ_Liste, iTaetigkeitId );
		
		QT_ZeitAend.setHMS( E_Anpassen->T_Termin.Z_Zeit.iStunde, E_Anpassen->T_Termin.Z_Zeit.iMinute, E_Anpassen->T_Termin.Z_Zeit.iSekunde );
		QD_DatumAend.setDate( E_Anpassen->T_Termin.D_Datum.iJahr, E_Anpassen->T_Termin.D_Datum.iMonat, E_Anpassen->T_Termin.D_Datum.iTag );
		Kalender->setSelectedDate( QD_DatumAend );
		ZeitAenderung->setTime(QT_ZeitAend);
		DatumsAenderung->setDate(QD_DatumAend);
		
		taeglich->setCheckState( Qt::Unchecked );
		woechentlich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );	
		switch (E_Anpassen->T_Termin.R_Regelmaessigkeit) {
			case TAEGLICH:
				taeglich->setCheckState( Qt::Checked );
				break;
			case WOECHENTLICH:
				woechentlich->setCheckState( Qt::Checked );
				break;
			case MONATLICH: 
				monatlich->setCheckState( Qt::Checked );
				break;
			default:
				taeglich->setCheckState( Qt::Unchecked );
				woechentlich->setCheckState( Qt::Unchecked );
				monatlich->setCheckState( Qt::Unchecked );	
				break;
		}
		
		ClearDropDowns();
		switch(E_Anpassen->TAT_Funktion) {
			case KOPIEREN:
				DropDown_Von->setEditText( QString(E_Anpassen->strQuelle));
				DropDown_Nach->setEditText( QString(E_Anpassen->strZiel));
				break;
			case AENDERN:
				DropDown_Aendern->setEditText ( QString(E_Anpassen->strQuelle) );
				Sortierung->setText ( QString(E_Anpassen->strSchema) );
				break;
			case LOESCHEN:
				DropDown_Loeschen->setEditText ( QString(E_Anpassen->strQuelle) );
				break;
			case AUFRUFEN:
				DropDown_Ausfuehren->setEditText ( QString(E_Anpassen->strQuelle) );
				break;
			default:	/* Wenn keine T�tigkeit geladen werden konnte, dann muss auch nix angepasst werden -> wieder zum Ursprungszustand */
				iAnpassenFlag = 0;
				SetEnOrDisable(iAnpassenFlag, QStrBuCaption, QStrModBuCaption);
				break;
		}	
	}
}
/* ------------------------------------------------------ ENDE T�tigkeit anpassen --------------------------------------------------------------- */


/**
* Funktionsbeschreibung:Anwendung beenden. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::slotBeenden()
{
	close();
}


/**
* Funktionsbeschreibung: Neue MathoMadaja-Konfigurationsdatei setzen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::neueDatei()
 {
     if (vielleichtSpeichern() == ERFOLG) {
         textEdit->clear();
         aktuelleDatei("einstellungen.mmdj");
     }
 }

/**
* Funktionsbeschreibung: Speichern Unter Dialog aufrufen <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::Speichern()
 {
     if (curFile.isEmpty()) {
         Speichern_unter();
     } else {
         speichernDatei(curFile);
     }
 }

/**
* Funktionsbeschreibung: Speichern Unter Dialog aufrufen <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::Speichern_unter()
 {
     
     QString fileName = QFileDialog::getSaveFileName(this, 
			tr("Speichern unter"),
            "",
			tr("MathoMadaja Datei (*.mmdj)")); 

	if (fileName.isEmpty()) {
         return;
	}
	
	else {
     speichernDatei(fileName);
	}
 }

/**
* Funktionsbeschreibung:  About-Dialog fuer Informationen zum Programm <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::Ueber()
 {
    QMessageBox::about(this, tr("�ber die Anwendung"),
             tr("<b>MathoMadaja</b> ist ein Programm welches<br>"
				" im Rahmen des Informatik 2 Projektes entstand.<br>"
				" MathoMadaja Version 1.0<br>"
				"---------------------------------------------------<br>"
				"� 2008 MathoMadaja Team"));
 }

 void MathoMadaja::Dokument_wurde_geaendert()
 {
     setWindowModified(textEdit->document()->isModified());
 }

/**
* Funktionsbeschreibung:  Wenn noch nicht gespeicherte Konfiguration, dann soll nachgefragt werden. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
STATUS MathoMadaja::vielleichtSpeichern() {
     if (textEdit->document()->isModified()) {
         QMessageBox::StandardButton ret;
         ret = QMessageBox::warning(this, tr("Anwendung"),
                      tr("Das Dokument wurde ver�ndert.\n"
                         "M�chten Sie Ihre Einstellungen speichern?"),
                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         if (ret == QMessageBox::Save) {
            Speichern();
			return ERFOLG;
		}
         else {
             return SFEHLER;
		}
     }
	 return ERFOLG;
 }

 
/**
* Funktionsbeschreibung:  Konfigurationsdatei nach Nachfragen laden. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::Oeffnen() {
QMessageBox::StandardButton ret = QMessageBox::No;
     if (vielleichtSpeichern() == ERFOLG) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Datei �ffnen"), "", tr("MathoMadaja Datei (*.mmdj)"));
         if (!fileName.isEmpty()) {
				ret = QMessageBox::warning(this, tr("Anwendung"),
                      tr("Liste muss geleert werden.\n"
                         "Wirklich von Datei laden?"),
                      QMessageBox::Yes | QMessageBox::No );
				if (ret == QMessageBox::No) {
					return;
				}
				else {
					ladenDatei(fileName);
				}
		}
    }
 }
 
/**
* Funktionsbeschreibung:  Konfigurationsdatei laden und anhand dieser Liste fuellen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::ladenDatei(const QString &fileName) { 
	/*  Umwandlung der QStrings in Standard C-Strings */
	QByteArray Qba  = fileName.toLatin1();  
	char *str_Datei = (char *) Qba.data();
	STATUS S; 
	
	if (Taetigkeit_Liste->count() > 0 ) {
			Taetigkeit_Liste->clear();
			EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Erst;
			eingabeliste_Loeschen(&EL_MMDJ_Liste);
	}
	
	S = eingabeliste_Laden(&EL_MMDJ_Liste, str_Datei);	
	DA_MMDJ_Anker.EL_Erst = EL_MMDJ_Liste;
	
	if (S == ERFOLG) {
		fuelleTaetigkeitenListe();
		aktuelleDatei(fileName);
		statusBar()->showMessage(tr("Datei geladen"), 2000);
	}
	else {
		statusBar()->showMessage(tr("Datei konnte nicht geladen werden"), 2000);
	}
		
 }

 
/**
* Funktionsbeschreibung:  Komplette Eingabeliste in ausgewaehlte Konfigurationsdatei speichern <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::speichernDatei(const QString &fileName)
 {
	/*  Umwandlung der QStrings in Standard C-Strings */
	QByteArray Qba  = fileName.toLatin1();  
	char *str_Datei = (char *) Qba.data();
	STATUS S; 
	 
	EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Erst;
	
	S = eingabeliste_Sichern(EL_MMDJ_Liste, str_Datei);

    if (S == ERFOLG) {
		aktuelleDatei(fileName);
		statusBar()->showMessage(tr("Datei gespeichert"), 2000);
	}
	else {
		statusBar()->showMessage(tr("Datei konnte nicht gespeichert werden"), 2000);
	}
 }

 
/**
* Funktionsbeschreibung:  Aktuelle Konfigurationsdatei in Klasse merken und im Window-Titel anzeigen. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::aktuelleDatei(const QString &fileName)
 {
     curFile = fileName;
     textEdit->document()->setModified(false);
     setWindowModified(false);

     QString shownName;
     if (curFile.isEmpty())
         shownName = "Unbenannt.mmdj";
     else
         shownName = strippedName(curFile);

     setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("MathoMadaja")));
 }

/**
* Funktionsbeschreibung:  Statt komplettem Pfad soll nur der Dateiname angezeigt werden. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 QString MathoMadaja::strippedName(const QString &fullFileName)
 {
     return QFileInfo(fullFileName).fileName();
 } 

 
/**
* Funktionsbeschreibung:  Abgleich zwischen Kalender und Datum-Feld schaffen <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::Kalender_Anzeige()
 {
    DatumsAenderung->setDate(Kalender->selectedDate());
 }


/**
* Funktionsbeschreibung:  Abgleich zwischen Kalender und Datum-Feld schaffen <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
 void MathoMadaja::ausgewaehltes_Datum_wurde_geaendert()
 {
     DatumsAenderung->setDate(Kalender->selectedDate());
 } 

 
/**
* Funktionsbeschreibung:  Abgleich der Checkboxen untereinander. Es soll immer nur eins anwaehlbar bzw. keins anwaehlbar sein. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::CheckBoxen_taeglich( )
 {
	 if ( taeglich->checkState( ) == Qt::Checked )
	{
		woechentlich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );	
	} 
	else
	{
		taeglich->setCheckState( Qt::Unchecked );
		woechentlich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );
	}

 }

 
/**
* Funktionsbeschreibung:  Abgleich der Checkboxen untereinander. Es soll immer nur eins anwaehlbar bzw. keins anwaehlbar sein. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::CheckBoxen_woechentlich()
{
	if ( woechentlich->checkState( ) == Qt::Checked )
	{
		taeglich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );
	}
	else
	{
		taeglich->setCheckState( Qt::Unchecked );
		woechentlich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );
	}

}


/**
* Funktionsbeschreibung:  Abgleich der Checkboxen untereinander. Es soll immer nur eins anwaehlbar bzw. keins anwaehlbar sein. <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::CheckBoxen_monatlich()
{
	if ( monatlich->checkState( ) == Qt::Checked )
	{
		taeglich->setCheckState( Qt::Unchecked );
		woechentlich->setCheckState( Qt::Unchecked );
	}
	else
	{
		taeglich->setCheckState( Qt::Unchecked );
		woechentlich->setCheckState( Qt::Unchecked );
		monatlich->setCheckState( Qt::Unchecked );
	}
}



/**
* Funktionsbeschreibung: Liest aus den Eingabefeldern die Zeichenketten aus, konvertiert diese in C-Strings  <br>
*			            und f�hrt dann die entsprechenden Funktionen aus. <br>
*  <br>
* Eingabeparameter: Keine <br>
* <br>
* R�ckgabe: Keine <br>
*/
void MathoMadaja::slotManuellerStart() {
	STATUS S_Loesch=ERFOLG, S_Aufruf=ERFOLG, S_Kopieren=ERFOLG, S_Aendern=ERFOLG;
	/* F�r jedes Dropdown Feld ein QByteArray, damit C-Strings korrekt erzeugt werden k�nnen! */
	QByteArray Qba1, Qba2, Qba3, Qba4, Qba5, Qba6; 
	QString QStr_Von     = DropDown_Von->currentText();
    char *str_Von  = NULL;
	QString QStr_Nach    = DropDown_Nach->currentText();
	char *str_Nach = NULL;
	QString QStr_Aend    = DropDown_Aendern->currentText();
	char *str_Aend = NULL;
	QString QStr_Sort    = Sortierung->text();
	char *str_Sort = NULL;
	QString QStr_Loesch  = DropDown_Loeschen->currentText();
	char *str_Loesch     = NULL;
	QString QStr_Ausf    = DropDown_Ausfuehren->currentText();
	char *str_Ausf = NULL;
	
	/*  Umwandlung der QStrings in Standard C-Strings */
	Qba1        = QStr_Von.toLatin1();
	str_Von     = (char *) Qba1.data();
	Qba2        = QStr_Nach.toLatin1();
	str_Nach    = (char *) Qba2.data(); 
	Qba3        = QStr_Aend.toLatin1();
	str_Aend   = (char *) Qba3.data();
	Qba4        = QStr_Sort.toLatin1();
	str_Sort   = (char *) Qba4.data();
	Qba5        = QStr_Loesch.toLatin1();
	str_Loesch = (char *) Qba5.data();
	Qba6        = QStr_Ausf.toLatin1();
	str_Ausf   = (char *) Qba6.data();
	
	/* Pr�fung, ob die Strings leer sind oder gef�llt, wenn mehrere gef�llt, wird einfach eins nach dem anderen als Eingabe in der Eingabeliste erfasst! */
		if( strlen(str_Von) != 0 && strlen(str_Nach) != 0 ) {
			S_Kopieren = kopieren( str_Von, str_Nach );
		}
		/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
		else if ( (strlen(str_Von) != 0 && strlen(str_Nach) == 0) || (strlen(str_Von) == 0 && strlen(str_Nach) != 0) ){
			QMessageBox::about(this, tr("Fehler beim manuellen Start"),
									tr("VON und NACH m�ssen beide gef�llt sein!"));	
		}
	
		if( strlen(str_Aend) != 0 && strlen(str_Sort) != 0 ) {
			S_Aendern = aendern( str_Aend, str_Sort);
			return;
		}
		/* Wenn nur eins von beiden gef�llt muss eine Fehlermeldung erscheinen! */
		else if ( (strlen(str_Aend) != 0 && strlen(str_Sort) == 0) || (strlen(str_Aend) == 0 && strlen(str_Sort) != 0) ) {				
			QMessageBox::about(this, tr("Fehler beim manuellen Start"),
									tr("�NDERN und Sortierschema m�ssen beide gef�llt sein!"));	
		}
	
		if( strlen(str_Loesch) != 0 ) {
			S_Loesch = loeschen( str_Loesch );
		}
	
		if ( strlen(str_Ausf) != 0 ) {
			S_Aufruf = aufrufen( str_Ausf );
		}
	
		if (S_Kopieren == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim Kopieren"),
									tr("Der Kopiervorgang konnte nicht erfolgreich ausgef�hrt werden!<br>"
									   "Bitte pr�fen Sie Pfade und Dateinamen der Quelle und des Ziels."));	
		}
		
		if (S_Aendern == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim �ndern"),
									tr("Der �ndern-Vorgang konnte nicht erfolgreich ausgef�hrt werden!<br>"
									   "Bitte pr�fen Sie Pfade, Dateinamen und �nderungsmuster."));	
		}
		
		if (S_Loesch == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim L�schen"),
									tr("Der L�schvorgang konnte nicht erfolgreich ausgef�hrt werden!<br>"
									   "Bitte pr�fen Sie Pfad und Dateinamen."));	
		}
		
		if (S_Aufruf == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim Ausf�hren"),
									tr("Die Datei oder der Pfad konnte nicht aufgerufen werden!<br>"
									   "Bitte pr�fen Sie Pfad und Dateinamen."));	
		}			
}


/**
* Funktionsbeschreibung:  Anhand Eingaben im Editier-Bereich bzw. Eingaben aus der C-Struct Eingabeliste <br>
*				   wird hier ein schoen formatierte QString zur Anzeige in der QtList erzeugt. <br>
* <br>
* Eingabeparameter:  Titel (also welche Taetigkeit), Datum, Zeit, Regelmaessigkeit, (Quell-) Pfad/Datei, Zielpfad/datei (KOPIEREN), <br>
*		  	      Aenderungsschema, Trennzeichenkette <br>
* <br>
* Rueckgabe: Formatierter QString mit allen uebergebenen Informationen <br>
* <br>
*/
QString MathoMadaja::CreateListEntry(QString QStrTitle, QString QStrDate, QString QStrTime, QString QStrReg, 
									     QString QStrSource, QString QStrDest, QString QStrSort, QString QStrSep ) {
	QString QStrMerge; /* Rauskommen sollte sowas: KOPIEREN - 01.01.2000 - 12:12:12 - TAEGLICH - Von:/asdsa/asdasd - Nach:/asdsad/asdsad - Bild#001 */
	QStrMerge.append(QStrTitle);
    QStrMerge.append(QStrSep);
	QStrMerge.append(QStrDate);
    QStrMerge.append(QStrSep);
	QStrMerge.append(QStrTime);
	QStrMerge.append(QStrSep);
	QStrMerge.append(QStrReg);
	QStrMerge.append(QStrSep);
	QStrMerge.append(QStrSource);
	QStrMerge.append(QStrSep);
	QStrMerge.append(QStrDest);
	QStrMerge.append(QStrSep);
	QStrMerge.append(QStrSort);

	return QStrMerge;
}


/**
* Funktionsbeschreibung:  Aktiviert bzw. Deaktiviert die Buttons und Liste nach Betaetigen von Taetigkeit anpassen <br>
* <br>
* Eingabeparameter:  Flag ob Aktiviert oder Deaktiviert werden soll, Originalbezeichnung des Buttons (Taetigkeit hinzufuegen), <br>
*			     Modifizierte Bezeichnung (Taetigkeit aendern) <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::SetEnOrDisable( int iEnDisFlag , QString QStr_Orig, QString QStr_Mod) {
	
	if (iEnDisFlag == 0) {
		Taetigkeit_anpassen->setEnabled( true );
		Taetigkeit_entfernen->setEnabled( true );
		Taetigkeit_Liste->setEnabled( true );
		Taetigkeit_anlegen->setText( QStr_Orig );
	}
	
	else {
		Taetigkeit_anpassen->setEnabled( false );
		Taetigkeit_entfernen->setEnabled( false );
		Taetigkeit_Liste->setEnabled( false );
		Taetigkeit_anlegen->setText( QStr_Mod );
	}
}

/* BEGINN: Men�funktionen zur Anzeige der Logdatei und zum Entfernen der Logdatei */
/**
* Funktionsbeschreibung:  Menuefunktion zur Anzeige der Logdatei.  <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::ShowLogFile() {
	STATUS S_Aufruf;
	S_Aufruf = aufrufen( strLogdatei );
	if (S_Aufruf == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim Ausf�hren"),
									tr("Logdatei konnte nicht aufgerufen werden.<br>"
									   "Bitte pr�fen Sie, ob die Logdatei im selben Verzeichnis vorhanden ist."));	
	}	
}

/**
* Funktionsbeschreibung:  Menuefunktion zur Anzeige der Hilfe.  <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::ShowHelpFile() {
	STATUS S_Aufruf;
	S_Aufruf = aufrufen( strHilfedatei );
	if (S_Aufruf == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim Ausf�hren"),
									tr("Hilfe konnte nicht aufgerufen werden.<br>"
									   "Bitte pr�fen Sie, ob die Hilfedatei hilfe.chm im selben Verzeichnis vorhanden ist."));	
	}	
}


/**
* Funktionsbeschreibung:  Menuefunktion um Logdatei zu loeschen.  <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::DelLogFile() {
	STATUS S_Loeschen;
	S_Loeschen = loeschen( strLogdatei );
	if (S_Loeschen == SFEHLER) {
			QMessageBox::warning(this, tr("Fehler beim L�schen"),
									tr("Logdatei konnte nicht gel�scht werden.<br>"
									   "Bitte pr�fen Sie, ob die Logdatei im selben Verzeichnis vorhanden ist."));	
	}
}
/* ENDE: Men�funktionen zur Anzeige der Logdatei und zum Entfernen der Logdatei */


/**
* Funktionsbeschreibung:  Alle Edit-Felder und ComboBoxen leeren  <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::ClearDropDowns( ) {	
	DropDown_Von->clearEditText();
	DropDown_Nach->clearEditText();
	DropDown_Aendern->clearEditText();
	Sortierung->setText( "" );
	DropDown_Loeschen->clearEditText();
	DropDown_Ausfuehren->clearEditText();
}


/**
* Funktionsbeschreibung:  Eintrag in der Qt-Liste hinzufuegen und daraus die aktuelle Id fuer die verkettete Liste erzeugen und zuweisen <br>
* <br>
* Eingabeparameter:  Keine <br>
* <br>
* Rueckgabe: Keine <br>
* <br>
*/
void MathoMadaja::fuelleTaetigkeitenListe() {
	QString QStr_Entry, QStr_Zeit, QStr_Datum, QStr_RegelTemp, QStr_Tat;
	QTime QT_Zeit;
	QDate QD_Datum;
	int iTempId;
	
	//EL_MMDJ_Liste = DA_MMDJ_Anker.EL_Erst;
	while (EL_MMDJ_Liste != NULL) {
		QT_Zeit.setHMS( EL_MMDJ_Liste->E_Taetigkeit->T_Termin.Z_Zeit.iStunde, EL_MMDJ_Liste->E_Taetigkeit->T_Termin.Z_Zeit.iMinute, 
						 EL_MMDJ_Liste->E_Taetigkeit->T_Termin.Z_Zeit.iSekunde );
		QD_Datum.setDate( EL_MMDJ_Liste->E_Taetigkeit->T_Termin.D_Datum.iJahr, EL_MMDJ_Liste->E_Taetigkeit->T_Termin.D_Datum.iMonat, 
						   EL_MMDJ_Liste->E_Taetigkeit->T_Termin.D_Datum.iTag);
		QStr_Zeit  = QT_Zeit.toString( "hh:mm:ss" );
		QStr_Datum = QD_Datum.toString( "dd.MM.yyyy" );
		
		/* Regelm��igkeit rausfiltern und dann entsprechenden String zur Anzeige in der Listbox erstellen. */
		switch (EL_MMDJ_Liste->E_Taetigkeit->T_Termin.R_Regelmaessigkeit) {
			case TAEGLICH:
				QStr_RegelTemp = QString ( str_C_TAEGLICH[0] );
				break;
			case WOECHENTLICH:
				QStr_RegelTemp = QString ( str_C_WOECHENTLICH[0] );
				break;
			case MONATLICH:
				QStr_RegelTemp = QString ( str_C_MONATLICH[0] );
				break;
			default:
				QStr_RegelTemp = QString ( str_C_KEINE[0] );
				break;
			}
		
		switch (EL_MMDJ_Liste->E_Taetigkeit->TAT_Funktion) {	
			
			case KOPIEREN:
				QStr_Tat = QString ( str_C_KOPIEREN[0] );
				break;
			case AENDERN:
				QStr_Tat = QString ( str_C_AENDERN[0] );
				break;
			case LOESCHEN:		
				QStr_Tat = QString ( str_C_LOESCHEN[0] );
				break;
			case AUFRUFEN:
				QStr_Tat = QString ( str_C_AUFRUFEN[0] );
				break;
			default:
				QStr_Tat = QString ( str_C_KEINE[0] );
				break;
		}	
		QStr_Entry = CreateListEntry( QStr_Tat, QStr_Datum, QStr_Zeit, QStr_RegelTemp, QString (EL_MMDJ_Liste->E_Taetigkeit->strQuelle), 
									  QString (EL_MMDJ_Liste->E_Taetigkeit->strZiel), QString (EL_MMDJ_Liste->E_Taetigkeit->strSchema), QStr_Trenner );
		
		Taetigkeit_Liste->addItem(QStr_Entry);
		iTempId = (int) (Taetigkeit_Liste->count() - 1);
		EL_MMDJ_Liste->E_Taetigkeit->i_Id = iTempId;
		DA_MMDJ_Anker.EL_Letzt = EL_MMDJ_Liste;
		EL_MMDJ_Liste = EL_MMDJ_Liste->EL_Naechste;
	}	
}

/*mathomadaja.cpp Ende*/




