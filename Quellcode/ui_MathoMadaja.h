/********************************************************************************
** Form generated from reading ui file 'MathoMadaja.ui'
**
** Created: Fri 6. Jun 21:48:27 2008
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MATHOMADAJA_H
#define UI_MATHOMADAJA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_MathoMadaja
{
public:
    QAction *actionBeenden;
    QAction *actionNeu;
    QAction *actionSpeichern;
    QAction *actionSpeichern_unter;
    QAction *actionLaden;
    QAction *actionBeenden_2;
    QAction *actionHilfe_aufrufen;
    QAction *actionUeber;
    QAction *actionOeffnen;
    QAction *action_ber;
    QAction *actionLogEntfernen;
    QAction *actionLogAnzeigen;
    QWidget *centralwidget;
    QCalendarWidget *Kalender;
    QTimeEdit *ZeitAenderung;
    QDateEdit *DatumsAenderung;
    QPushButton *Laden;
    QLabel *Kopieren;
    QLabel *Von;
    QLabel *Nach;
    QLabel *Aendern;
    QLineEdit *Sortierung;
    QPushButton *ManuellerStart;
    QLabel *Loeschen;
    QLabel *Ausfuehren;
    QComboBox *DropDown_Von;
    QComboBox *DropDown_Nach;
    QComboBox *DropDown_Aendern;
    QComboBox *DropDown_Loeschen;
    QComboBox *DropDown_Ausfuehren;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QToolButton *Durchsuchen_Ausfuehren;
    QLabel *Regelmigkeit;
    QFrame *line_4;
    QListWidget *Taetigkeit_Liste;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QCheckBox *taeglich;
    QCheckBox *woechentlich;
    QCheckBox *monatlich;
    QPushButton *buVonVerz;
    QPushButton *buVonDat;
    QPushButton *buNachVerz;
    QPushButton *buNachDat;
    QPushButton *buAendVerz;
    QPushButton *buAendDat;
    QPushButton *buLoeschVerz;
    QPushButton *buLoeschDat;
    QWidget *layoutWidget1;
    QVBoxLayout *vboxLayout1;
    QPushButton *Taetigkeit_anpassen;
    QPushButton *Taetigkeit_entfernen;
    QFrame *line_5;
    QLabel *Ausfuehren_2;
    QPushButton *Taetigkeit_anlegen;
    QFrame *line_6;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuHilfe;
    QMenu *menuLog_Datei;

    void setupUi(QMainWindow *MathoMadaja)
    {
    if (MathoMadaja->objectName().isEmpty())
        MathoMadaja->setObjectName(QString::fromUtf8("MathoMadaja"));
    MathoMadaja->resize(640, 600);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MathoMadaja->sizePolicy().hasHeightForWidth());
    MathoMadaja->setSizePolicy(sizePolicy);
    MathoMadaja->setMinimumSize(QSize(640, 600));
    MathoMadaja->setMaximumSize(QSize(640, 600));
    MathoMadaja->setWindowIcon(QIcon());
    actionBeenden = new QAction(MathoMadaja);
    actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
    actionNeu = new QAction(MathoMadaja);
    actionNeu->setObjectName(QString::fromUtf8("actionNeu"));
    actionSpeichern = new QAction(MathoMadaja);
    actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
    actionSpeichern_unter = new QAction(MathoMadaja);
    actionSpeichern_unter->setObjectName(QString::fromUtf8("actionSpeichern_unter"));
    actionLaden = new QAction(MathoMadaja);
    actionLaden->setObjectName(QString::fromUtf8("actionLaden"));
    actionBeenden_2 = new QAction(MathoMadaja);
    actionBeenden_2->setObjectName(QString::fromUtf8("actionBeenden_2"));
    actionHilfe_aufrufen = new QAction(MathoMadaja);
    actionHilfe_aufrufen->setObjectName(QString::fromUtf8("actionHilfe_aufrufen"));
    actionUeber = new QAction(MathoMadaja);
    actionUeber->setObjectName(QString::fromUtf8("actionUeber"));
    actionOeffnen = new QAction(MathoMadaja);
    actionOeffnen->setObjectName(QString::fromUtf8("actionOeffnen"));
    action_ber = new QAction(MathoMadaja);
    action_ber->setObjectName(QString::fromUtf8("action_ber"));
    actionLogEntfernen = new QAction(MathoMadaja);
    actionLogEntfernen->setObjectName(QString::fromUtf8("actionLogEntfernen"));
    actionLogAnzeigen = new QAction(MathoMadaja);
    actionLogAnzeigen->setObjectName(QString::fromUtf8("actionLogAnzeigen"));
    centralwidget = new QWidget(MathoMadaja);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    Kalender = new QCalendarWidget(centralwidget);
    Kalender->setObjectName(QString::fromUtf8("Kalender"));
    Kalender->setGeometry(QRect(420, 10, 200, 151));
    ZeitAenderung = new QTimeEdit(centralwidget);
    ZeitAenderung->setObjectName(QString::fromUtf8("ZeitAenderung"));
    ZeitAenderung->setGeometry(QRect(420, 170, 81, 22));
    DatumsAenderung = new QDateEdit(centralwidget);
    DatumsAenderung->setObjectName(QString::fromUtf8("DatumsAenderung"));
    DatumsAenderung->setGeometry(QRect(530, 170, 91, 22));
    Laden = new QPushButton(centralwidget);
    Laden->setObjectName(QString::fromUtf8("Laden"));
    Laden->setGeometry(QRect(546, 209, 75, 31));
    Kopieren = new QLabel(centralwidget);
    Kopieren->setObjectName(QString::fromUtf8("Kopieren"));
    Kopieren->setGeometry(QRect(20, 10, 61, 16));
    Von = new QLabel(centralwidget);
    Von->setObjectName(QString::fromUtf8("Von"));
    Von->setGeometry(QRect(20, 32, 24, 16));
    Nach = new QLabel(centralwidget);
    Nach->setObjectName(QString::fromUtf8("Nach"));
    Nach->setGeometry(QRect(200, 32, 31, 16));
    Aendern = new QLabel(centralwidget);
    Aendern->setObjectName(QString::fromUtf8("Aendern"));
    Aendern->setGeometry(QRect(20, 126, 46, 16));
    Sortierung = new QLineEdit(centralwidget);
    Sortierung->setObjectName(QString::fromUtf8("Sortierung"));
    Sortierung->setGeometry(QRect(240, 148, 113, 20));
    Sortierung->setMaxLength(12);
    ManuellerStart = new QPushButton(centralwidget);
    ManuellerStart->setObjectName(QString::fromUtf8("ManuellerStart"));
    ManuellerStart->setGeometry(QRect(420, 209, 101, 31));
    Loeschen = new QLabel(centralwidget);
    Loeschen->setObjectName(QString::fromUtf8("Loeschen"));
    Loeschen->setGeometry(QRect(18, 235, 46, 16));
    Ausfuehren = new QLabel(centralwidget);
    Ausfuehren->setObjectName(QString::fromUtf8("Ausfuehren"));
    Ausfuehren->setGeometry(QRect(18, 344, 65, 16));
    DropDown_Von = new QComboBox(centralwidget);
    DropDown_Von->setObjectName(QString::fromUtf8("DropDown_Von"));
    DropDown_Von->setGeometry(QRect(46, 30, 140, 22));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(DropDown_Von->sizePolicy().hasHeightForWidth());
    DropDown_Von->setSizePolicy(sizePolicy1);
    DropDown_Von->setSizeIncrement(QSize(0, 0));
    DropDown_Von->setEditable(true);
    DropDown_Nach = new QComboBox(centralwidget);
    DropDown_Nach->setObjectName(QString::fromUtf8("DropDown_Nach"));
    DropDown_Nach->setGeometry(QRect(234, 30, 140, 22));
    DropDown_Nach->setEditable(true);
    DropDown_Aendern = new QComboBox(centralwidget);
    DropDown_Aendern->setObjectName(QString::fromUtf8("DropDown_Aendern"));
    DropDown_Aendern->setGeometry(QRect(46, 146, 140, 22));
    DropDown_Aendern->setEditable(true);
    DropDown_Loeschen = new QComboBox(centralwidget);
    DropDown_Loeschen->setObjectName(QString::fromUtf8("DropDown_Loeschen"));
    DropDown_Loeschen->setGeometry(QRect(46, 255, 140, 22));
    DropDown_Loeschen->setEditable(true);
    DropDown_Ausfuehren = new QComboBox(centralwidget);
    DropDown_Ausfuehren->setObjectName(QString::fromUtf8("DropDown_Ausfuehren"));
    DropDown_Ausfuehren->setGeometry(QRect(46, 364, 140, 22));
    DropDown_Ausfuehren->setEditable(true);
    line = new QFrame(centralwidget);
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(-2, 327, 401, 16));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line_2 = new QFrame(centralwidget);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setGeometry(QRect(0, 220, 401, 16));
    line_2->setFrameShape(QFrame::HLine);
    line_2->setFrameShadow(QFrame::Sunken);
    line_3 = new QFrame(centralwidget);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setGeometry(QRect(-2, 106, 401, 16));
    line_3->setFrameShape(QFrame::HLine);
    line_3->setFrameShadow(QFrame::Sunken);
    Durchsuchen_Ausfuehren = new QToolButton(centralwidget);
    Durchsuchen_Ausfuehren->setObjectName(QString::fromUtf8("Durchsuchen_Ausfuehren"));
    Durchsuchen_Ausfuehren->setGeometry(QRect(190, 361, 29, 25));
    Regelmigkeit = new QLabel(centralwidget);
    Regelmigkeit->setObjectName(QString::fromUtf8("Regelmigkeit"));
    Regelmigkeit->setGeometry(QRect(478, 270, 95, 16));
    line_4 = new QFrame(centralwidget);
    line_4->setObjectName(QString::fromUtf8("line_4"));
    line_4->setGeometry(QRect(421, 247, 201, 20));
    line_4->setFrameShape(QFrame::HLine);
    line_4->setFrameShadow(QFrame::Sunken);
    Taetigkeit_Liste = new QListWidget(centralwidget);
    Taetigkeit_Liste->setObjectName(QString::fromUtf8("Taetigkeit_Liste"));
    Taetigkeit_Liste->setGeometry(QRect(140, 480, 481, 77));
    QFont font;
    Taetigkeit_Liste->setFont(font);
    layoutWidget = new QWidget(centralwidget);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(484, 300, 82, 68));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    taeglich = new QCheckBox(layoutWidget);
    taeglich->setObjectName(QString::fromUtf8("taeglich"));

    vboxLayout->addWidget(taeglich);

    woechentlich = new QCheckBox(layoutWidget);
    woechentlich->setObjectName(QString::fromUtf8("woechentlich"));

    vboxLayout->addWidget(woechentlich);

    monatlich = new QCheckBox(layoutWidget);
    monatlich->setObjectName(QString::fromUtf8("monatlich"));

    vboxLayout->addWidget(monatlich);

    buVonVerz = new QPushButton(centralwidget);
    buVonVerz->setObjectName(QString::fromUtf8("buVonVerz"));
    buVonVerz->setGeometry(QRect(47, 56, 140, 23));
    buVonDat = new QPushButton(centralwidget);
    buVonDat->setObjectName(QString::fromUtf8("buVonDat"));
    buVonDat->setGeometry(QRect(47, 82, 140, 23));
    buNachVerz = new QPushButton(centralwidget);
    buNachVerz->setObjectName(QString::fromUtf8("buNachVerz"));
    buNachVerz->setGeometry(QRect(235, 56, 140, 23));
    buNachDat = new QPushButton(centralwidget);
    buNachDat->setObjectName(QString::fromUtf8("buNachDat"));
    buNachDat->setGeometry(QRect(235, 82, 140, 23));
    buAendVerz = new QPushButton(centralwidget);
    buAendVerz->setObjectName(QString::fromUtf8("buAendVerz"));
    buAendVerz->setGeometry(QRect(45, 172, 140, 23));
    buAendDat = new QPushButton(centralwidget);
    buAendDat->setObjectName(QString::fromUtf8("buAendDat"));
    buAendDat->setGeometry(QRect(45, 198, 140, 23));
    buLoeschVerz = new QPushButton(centralwidget);
    buLoeschVerz->setObjectName(QString::fromUtf8("buLoeschVerz"));
    buLoeschVerz->setGeometry(QRect(45, 281, 140, 23));
    buLoeschDat = new QPushButton(centralwidget);
    buLoeschDat->setObjectName(QString::fromUtf8("buLoeschDat"));
    buLoeschDat->setGeometry(QRect(45, 307, 140, 23));
    layoutWidget1 = new QWidget(centralwidget);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    layoutWidget1->setGeometry(QRect(10, 476, 118, 83));
    vboxLayout1 = new QVBoxLayout(layoutWidget1);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(0, 0, 0, 0);
    Taetigkeit_anpassen = new QPushButton(layoutWidget1);
    Taetigkeit_anpassen->setObjectName(QString::fromUtf8("Taetigkeit_anpassen"));

    vboxLayout1->addWidget(Taetigkeit_anpassen);

    Taetigkeit_entfernen = new QPushButton(layoutWidget1);
    Taetigkeit_entfernen->setObjectName(QString::fromUtf8("Taetigkeit_entfernen"));

    vboxLayout1->addWidget(Taetigkeit_entfernen);

    line_5 = new QFrame(centralwidget);
    line_5->setObjectName(QString::fromUtf8("line_5"));
    line_5->setGeometry(QRect(0, 397, 641, 16));
    line_5->setFrameShape(QFrame::HLine);
    line_5->setFrameShadow(QFrame::Sunken);
    Ausfuehren_2 = new QLabel(centralwidget);
    Ausfuehren_2->setObjectName(QString::fromUtf8("Ausfuehren_2"));
    Ausfuehren_2->setGeometry(QRect(20, 420, 65, 16));
    Taetigkeit_anlegen = new QPushButton(centralwidget);
    Taetigkeit_anlegen->setObjectName(QString::fromUtf8("Taetigkeit_anlegen"));
    Taetigkeit_anlegen->setGeometry(QRect(180, 430, 401, 41));
    line_6 = new QFrame(centralwidget);
    line_6->setObjectName(QString::fromUtf8("line_6"));
    line_6->setGeometry(QRect(400, 13, 20, 381));
    line_6->setFrameShape(QFrame::VLine);
    line_6->setFrameShadow(QFrame::Sunken);
    MathoMadaja->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MathoMadaja);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 640, 21));
    menuDatei = new QMenu(menubar);
    menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
    menuHilfe = new QMenu(menubar);
    menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
    menuLog_Datei = new QMenu(menubar);
    menuLog_Datei->setObjectName(QString::fromUtf8("menuLog_Datei"));
    MathoMadaja->setMenuBar(menubar);

    menubar->addAction(menuDatei->menuAction());
    menubar->addAction(menuLog_Datei->menuAction());
    menubar->addAction(menuHilfe->menuAction());
    menuDatei->addAction(actionNeu);
    menuDatei->addAction(actionOeffnen);
    menuDatei->addAction(actionSpeichern);
    menuDatei->addAction(actionSpeichern_unter);
    menuDatei->addSeparator();
    menuDatei->addAction(actionBeenden_2);
    menuHilfe->addAction(actionHilfe_aufrufen);
    menuHilfe->addAction(action_ber);
    menuLog_Datei->addAction(actionLogAnzeigen);
    menuLog_Datei->addAction(actionLogEntfernen);

    retranslateUi(MathoMadaja);

    QMetaObject::connectSlotsByName(MathoMadaja);
    } // setupUi

    void retranslateUi(QMainWindow *MathoMadaja)
    {
    MathoMadaja->setWindowTitle(QApplication::translate("MathoMadaja", "MathoMadaja", 0, QApplication::UnicodeUTF8));
    MathoMadaja->setStyleSheet(QApplication::translate("MathoMadaja", "QMainWindow { background-image: url(bilder/background.png);\n"
"						width: 640px; height: 600px;\n"
"						min-width: 640px; min-height: 600px;\n"
"						max-width: 640px; max-height: 600px; \n"
"						background-position: middle center;\n"
"						border: 0px solid #fff4b0;\n"
"						font-family:Verdana;\n"
"						text-decoration:none;\n"
"						font-size:10pt;}\n"
"\n"
"QMenuBar { background-color: #fff4b0;\n"
"					color: black;\n"
"					font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;}\n"
"\n"
"QTimeEdit{	font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;}\n"
"\n"
"QLineEdit{	font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:7pt;\n"
"					color:#9e9e9e;}\n"
"\n"
"QDateEdit{	font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;;}\n"
"\n"
"QPushButton{	font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;}\n"
"\n"
"/*QPushButton:hover{	font-family:Verdana;\n"
"					text-decoration:none;\n"
"	"
        "				font-size:8pt;}*/\n"
"\n"
"QProgressBar{		font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;}\n"
"\n"
"QLabel{		font-family:Verdana;\n"
"					text-decoration:none;\n"
"					font-size:8pt;}\n"
"", 0, QApplication::UnicodeUTF8));
    actionBeenden->setText(QApplication::translate("MathoMadaja", "Beenden", 0, QApplication::UnicodeUTF8));
    actionNeu->setText(QApplication::translate("MathoMadaja", "Neu", 0, QApplication::UnicodeUTF8));
    actionSpeichern->setText(QApplication::translate("MathoMadaja", "Speichern", 0, QApplication::UnicodeUTF8));
    actionSpeichern_unter->setText(QApplication::translate("MathoMadaja", "Speichern unter", 0, QApplication::UnicodeUTF8));
    actionLaden->setText(QApplication::translate("MathoMadaja", "Laden", 0, QApplication::UnicodeUTF8));
    actionBeenden_2->setText(QApplication::translate("MathoMadaja", "Beenden", 0, QApplication::UnicodeUTF8));
    actionHilfe_aufrufen->setText(QApplication::translate("MathoMadaja", "Hilfe aufrufen", 0, QApplication::UnicodeUTF8));
    actionUeber->setText(QApplication::translate("MathoMadaja", "MathoMadaja", 0, QApplication::UnicodeUTF8));
    actionOeffnen->setText(QApplication::translate("MathoMadaja", "\303\226ffnen", 0, QApplication::UnicodeUTF8));
    action_ber->setText(QApplication::translate("MathoMadaja", "\303\234ber", 0, QApplication::UnicodeUTF8));
    actionLogEntfernen->setText(QApplication::translate("MathoMadaja", "Entfernen", 0, QApplication::UnicodeUTF8));
    actionLogAnzeigen->setText(QApplication::translate("MathoMadaja", "Anzeigen", 0, QApplication::UnicodeUTF8));
    Kalender->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hier k\303\266nnen Sie durch das klicken auf ein Element das Datum festlegen, an dem eine T\303\244tigkeit ausgef\303\274hrt werden soll. Das Datum wird dann zus\303\244tzlich unten in der Box angezeigt</p></body></html>", 0, QApplication::UnicodeUTF8));
    ZeitAenderung->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hier k\303\266nnen sie die Zeit festlegen, falls n\303\266tig so ist auch eine Sekunden Angabe enthalten</p></body></html>", 0, QApplication::UnicodeUTF8));
    DatumsAenderung->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hier k\303\266nnen Sie das Datum an dem die T\303\244tigkeit ausgef\303\274hrt werden soll festlegen. Dies ist m\303\266glich in dem sie das Datum von Hand eintippen oder auf einen Tag im Kalender dar\303\274ber anklicken</p></body></html>", 0, QApplication::UnicodeUTF8));
    Laden->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Andere Konfigurationsdatei (*.mmdj) laden</p></body></html>", 0, QApplication::UnicodeUTF8));
    Laden->setText(QApplication::translate("MathoMadaja", "Laden", 0, QApplication::UnicodeUTF8));
    Kopieren->setText(QApplication::translate("MathoMadaja", "Kopieren", 0, QApplication::UnicodeUTF8));
    Von->setText(QApplication::translate("MathoMadaja", "Von: ", 0, QApplication::UnicodeUTF8));
    Nach->setText(QApplication::translate("MathoMadaja", "Nach: ", 0, QApplication::UnicodeUTF8));
    Aendern->setText(QApplication::translate("MathoMadaja", "\303\204ndern", 0, QApplication::UnicodeUTF8));
    Sortierung->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\">Hier k\303\266nnen Sie die Durchnummerierung festlegen.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><span style=\" font-weight:600; color:#0000ff;\">#</span> f\303\274r Zahlen von 1 bis Anzahl Dateien im Verzeichnis</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\">Bsp.: bilder#.jpg </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-le"
        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\">Beachten sie das sie, Dateiendung und Punkt mitgez\303\244hlt, nur max 12 Zeichen eingeben k\303\266nnen!</p></body></html>", 0, QApplication::UnicodeUTF8));
    ManuellerStart->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Startet die vorgenommenen Eingaben in den Textfeldern sofort</p></body></html>", 0, QApplication::UnicodeUTF8));
    ManuellerStart->setText(QApplication::translate("MathoMadaja", "Manueller Start", 0, QApplication::UnicodeUTF8));
    Loeschen->setText(QApplication::translate("MathoMadaja", "L\303\266schen", 0, QApplication::UnicodeUTF8));
    Ausfuehren->setText(QApplication::translate("MathoMadaja", "Ausf\303\274hren", 0, QApplication::UnicodeUTF8));
    DropDown_Von->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Bitte geben Sie Pfadangaben mit einem <span style=\" font-weight:600; color:#0000ff;\">/</span> ein. </p></body></html>", 0, QApplication::UnicodeUTF8));
    DropDown_Nach->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Bitte geben Sie Pfadangaben mit einem <span style=\" font-weight:600; color:#0000ff;\">/</span> ein. </p></body></html>", 0, QApplication::UnicodeUTF8));
    DropDown_Aendern->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Bitte geben Sie Pfadangaben mit einem <span style=\" font-weight:600; color:#0000ff;\">/</span> ein.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Geben Sie nach dem letzten / die Einschr\303\244nkung der Dateien ein.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Bsp.: * f\303\274r alle Dateien</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">*.txt f\303\274"
        "r Textdateien usw. </p></body></html>", 0, QApplication::UnicodeUTF8));
    DropDown_Loeschen->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Bitte geben Sie Pfadangaben mit einem <span style=\" font-weight:600; color:#0000ff;\">/</span> ein. </p></body></html>", 0, QApplication::UnicodeUTF8));
    DropDown_Ausfuehren->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Bitte geben Sie Pfadangaben mit einem <span style=\" font-weight:600; color:#0000ff;\">/</span> ein. </p></body></html>", 0, QApplication::UnicodeUTF8));
    Durchsuchen_Ausfuehren->setText(QApplication::translate("MathoMadaja", "...", 0, QApplication::UnicodeUTF8));
    Regelmigkeit->setText(QApplication::translate("MathoMadaja", "Regelm\303\244\303\237igkeit", 0, QApplication::UnicodeUTF8));
    taeglich->setText(QApplication::translate("MathoMadaja", "t\303\244glich", 0, QApplication::UnicodeUTF8));
    woechentlich->setText(QApplication::translate("MathoMadaja", "w\303\266chentlich", 0, QApplication::UnicodeUTF8));
    monatlich->setText(QApplication::translate("MathoMadaja", "monatlich", 0, QApplication::UnicodeUTF8));
    buVonVerz->setText(QApplication::translate("MathoMadaja", "Verzeichnis", 0, QApplication::UnicodeUTF8));
    buVonDat->setText(QApplication::translate("MathoMadaja", "Datei", 0, QApplication::UnicodeUTF8));
    buNachVerz->setText(QApplication::translate("MathoMadaja", "Verzeichnis", 0, QApplication::UnicodeUTF8));
    buNachDat->setText(QApplication::translate("MathoMadaja", "Datei", 0, QApplication::UnicodeUTF8));
    buAendVerz->setText(QApplication::translate("MathoMadaja", "Verzeichnis", 0, QApplication::UnicodeUTF8));
    buAendDat->setText(QApplication::translate("MathoMadaja", "Datei", 0, QApplication::UnicodeUTF8));
    buLoeschVerz->setText(QApplication::translate("MathoMadaja", "Verzeichnis", 0, QApplication::UnicodeUTF8));
    buLoeschDat->setText(QApplication::translate("MathoMadaja", "Datei", 0, QApplication::UnicodeUTF8));
    Taetigkeit_anpassen->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ausgew\303\244hlte Eingabe anpassen</p></body></html>", 0, QApplication::UnicodeUTF8));
    Taetigkeit_anpassen->setText(QApplication::translate("MathoMadaja", "T\303\244tigkeit anpassen", 0, QApplication::UnicodeUTF8));
    Taetigkeit_entfernen->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ausgew\303\244hlte Eingabe aus Liste entfernen</p></body></html>", 0, QApplication::UnicodeUTF8));
    Taetigkeit_entfernen->setText(QApplication::translate("MathoMadaja", "T\303\244tigkeit entfernen", 0, QApplication::UnicodeUTF8));
    Ausfuehren_2->setText(QApplication::translate("MathoMadaja", "T\303\244tigkeiten", 0, QApplication::UnicodeUTF8));
    Taetigkeit_anlegen->setToolTip(QApplication::translate("MathoMadaja", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Verdana'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Eingaben in Liste speichern</p></body></html>", 0, QApplication::UnicodeUTF8));
    Taetigkeit_anlegen->setText(QApplication::translate("MathoMadaja", "T\303\244tigkeit anlegen", 0, QApplication::UnicodeUTF8));
    menuDatei->setTitle(QApplication::translate("MathoMadaja", "Datei", 0, QApplication::UnicodeUTF8));
    menuHilfe->setTitle(QApplication::translate("MathoMadaja", "?", 0, QApplication::UnicodeUTF8));
    menuLog_Datei->setTitle(QApplication::translate("MathoMadaja", "Log-Datei", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MathoMadaja: public Ui_MathoMadaja {};
} // namespace Ui

#endif // UI_MATHOMADAJA_H
