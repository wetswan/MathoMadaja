/*Beeinhaltet die GUI Darstellung, 
also hier ist das ganze Interface definiert
*
* Datei: main.cpp Autor: David Garus
* Datum: 01.05.2008
*
* Historie: Entwicklungsphase, d.h. andauernde Änderungen
*/
#include <QApplication>
#include "MathoMadaja.h"


int main( int argc, char * argv[] )
{
        QApplication a( argc , argv );
        MathoMadaja w;
        w.show();

        return a.exec();
}

//--- main.cpp end ---