/*
* Hier ist die Loeschen-Funktion definiert
*
* Datei: Loeschen.cpp Autor: David Garus
* Datum: 01.06.2008
*
* Historie: 03.06.2008 
* -Kommentare hinzugefügt 
* -Funktionsprototyp erstellt
* 06.06.2008
* - new TCHAR ( ) durch new TCHAR [ ]  ersetzt!
* - Marco Bezzon: Zugriff auf Konvertierungsfunktion aus globalfunctions.h
*/
#include "loeschen.h"

/**
* Funktionsbeschreibung: Diese Funktion loescht die am Pfadende befindlichen Objekte.  <br>
* Dabei wird der Pfad vom Benutzer selbst eingegeben.<br>
* <br>
* Eingabeparameter: char *strVerweis <br>
* <br>
* Rueckgabe: Bei erfolgreichem Loeschen wird der STATUS ERFOLG zurueckgegeben. <br>
* Falls das Loeschen nicht erfolgreich war, so wird der STATUS SFEHLER zurueckgegeben. <br>
* <br>
* Besonderes: Zum Umwandeln in einen LPCTSTR wird der Befehl MultiByteToWideChar() verwendet,  <br>
* dieser stammt aus der WINAPI <br>
*/
STATUS loeschen(char *strVerweis) {
	/** String, der nachher aus \\ statt / bestehen sollen */
  char strConvVerweis[MAX_PATH];
  
  TCHAR T_strUnicode[MAX_PATH];
  int iWandlung;

  /** Umwandlung des Strings */
  convSlashToBackslash(strConvVerweis, strVerweis);
  
  /**
  *Hier wird nun char in einen WCHAR konvertiert
  */
  iWandlung = MultiByteToWideChar( CP_ACP, 0, strConvVerweis, MAX_PATH, T_strUnicode, MAX_PATH);
  
  int len = wcslen(T_strUnicode);
  TCHAR *pszFrom = new TCHAR[ len+2 ];
  wcscpy(pszFrom, T_strUnicode);
  pszFrom[len] = 0;
  pszFrom[len+1] = 0;
  /**
  * bool noRecycleBin wird auf den boolschen Wert true gesetzt
  * damit die gelöschten Elemente nicht in den Papierkorb verschoben werden.
  */
  bool noRecycleBin = true;
  
  SHFILEOPSTRUCT fileop;
  fileop.hwnd   = NULL; 
  fileop.wFunc  = FO_DELETE;
  fileop.pFrom  = pszFrom; 
  fileop.pTo    = NULL;  
  fileop.fFlags = FOF_NOCONFIRMATION|FOF_SILENT;  
  
  if(!noRecycleBin) {
    fileop.fFlags |= FOF_ALLOWUNDO;
  }
  
  fileop.fAnyOperationsAborted = FALSE;
  fileop.lpszProgressTitle     = NULL;
  fileop.hNameMappings         = NULL;

  int ret = SHFileOperation(&fileop);
  delete [] pszFrom;  
  /**
  * Hier wird geprüft ob das Verzeichnis entweder vorhanden oder nicht vorhanden ist 
  * bzw. ob das Element/Objekt erfolgreich gelöscht wurde oder der Löschvorgang nicht erfolgreich
  * abgeschlossen wurde. Hierbei wird für ein erfolgreiches Löschen der STATUS ERFOLG zurückgegeben und 
  * für eine nicht erfolgreiches Löschen der STATUS SFEHLER zurückgegeben.
  */
  if(ret == 0 && iWandlung != 0)
  {
	  return ERFOLG;
  }
  else
  {
	  return SFEHLER;
  }
}
