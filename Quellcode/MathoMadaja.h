
/*Beeinhaltet die GUI Darstellung, 
also hier ist das ganze Interface definiert
*
* Datei: mathomadaja.h Autor: David Garus
* Datum: 01.05.2008
*
* Historie: Entwicklungsphase, d.h. andauernde Änderungen
*/
#ifndef MATHOMADAJA_H
#define MATHOMADAJA_H
#define ANZ_LOGDATEI 13
#define ANZ_ENDDATEI 12
#define ANZ_HILFEDATEI 10

#include "ui_MathoMadaja.h"
#include <QtGui>		/*Beeinhaltet ALLE Header von QT 
						somit muss man sich keine gedanken mehr machen,
						ob man einen Header vergessen hat*/
						
/* C-Header-Files, die den Kern des Programms darstellen (Listenverwaltung, Sortierung, Funktionalitäten) */
#include "logdatei.h"
#include "eingabeliste.h"
#include "sortieren.h"
#include "zeitstempel.h"
#include "globaldefs.h"
#include <string.h>

class MathoMadaja : public QMainWindow, public Ui::MathoMadaja
{ 
	 Q_OBJECT

public:
        MathoMadaja (QMainWindow *parent = 0);
        ~MathoMadaja();
		STATUS vielleichtSpeichern();
		void speichernDatei(const QString &fileName);
		void aktuelleDatei(const QString &fileName);
		void LogDateiError();
		QString CreateListEntry(QString QStrTitle, QString QStrDate, QString QStrTime, QString QStrReg, 
									QString QStrSource, QString QStrDest, QString QStrSort, QString QStrSep );
		void SetEnOrDisable( int iEnDisFlag, QString QStr_Orig, QString QStr_Mod);
		void ClearDropDowns( );
		void fuelleTaetigkeitenListe( );
		
		void OpenFile(const QString &QStrBuName);
		void OpenDir(const QString &QStrBuName);

 private slots:
	 void slotBeenden();
     void neueDatei();
     void Oeffnen();
     void Speichern();
     void Speichern_unter();
     void Ueber();
     void Dokument_wurde_geaendert();
	 void ausgewaehltes_Datum_wurde_geaendert();
	 void CheckBoxen_taeglich();
	 void CheckBoxen_woechentlich();
	 void CheckBoxen_monatlich();
	 void OpenFile_Durchsuchen_Von();
	 void OpenFile_Durchsuchen_Nach();
	 void OpenFile_Durchsuchen_Aendern();
	 void OpenFile_Durchsuchen_Loeschen();
	 void OpenFile_Durchsuchen_Ausfuehren();
	 void OpenDir_Durchsuchen_Von();
	 void OpenDir_Durchsuchen_Nach();
	 void OpenDir_Durchsuchen_Aendern();
	 void OpenDir_Durchsuchen_Loeschen();
	 void ShowLogFile();
	 void DelLogFile();
	 void ShowHelpFile();
	 
	 void TimerUpdate();
	 
	 void NeueTaetigkeitHinzu();
	 void TaetigkeitEntfernen();
	 void TaetigkeitAnpassen();
	 
	 void slotManuellerStart();

 private:
     
     void ladenDatei(const QString &fileName);
     QString strippedName(const QString &fullFileName);

     QTextEdit *textEdit;
     QString curFile;

	 void Kalender_Anzeige();
	 void ChangeDropdown(const QString &objectName);
	 void OpenDirAndFile(const QString &Path);
	 
	 EINGABELISTE *EL_MMDJ_Liste;
	 DOPPELANKER  DA_MMDJ_Anker;
	 /* logdatei.csv + Nullzeichen = 13 Zeichen für ANZ_LOGDATEI */
	 char strLogdatei[ANZ_LOGDATEI];
	 char strEndedatei[ANZ_ENDDATEI];
	 char strHilfedatei[ANZ_HILFEDATEI];
	 QString QStrBuCaption;
	 QString QStrModBuCaption;
	 QString QStr_Trenner;
	 
	 /* AnpassenFlag wird auf 1 gesetzt, wenn in der GUI auf "Tätigkeit anpassen" geklickt wird.
	        Damit kann dann auch später beim Button Tätigkeit hinzufügen bzw. zurückschreiben das Flag 
		überprüft werden und entsprechend geandelt werden. 
	 */
	 int iAnpassenFlag;
		
 };
#endif


/*mathomadaja.h Ende*/




