#ifndef DD
#define DD

#include <string>
#include <map>
#include <vector>
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>
#include <string>
#include <gtkmm/box.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>
using namespace std;

/****************************************************************************************************************************************************************/

class Personnage;
class Race;
class Classe;

class Race
{
protected:

public:
	Race();
	string ExtractDragonBorn(string dataHTML);
};


class Classe
{
	protected:
		
	
	public:
		Classe();
		string ExtractDruid(string dataHTML);
		
};

class Personnage : public Race, public Classe
{
protected:
	string choixRace;

public:
	Personnage();
	string LectureHTML(string, string, string);	/// Lecture simple du fichier HTML
	void setRace(string);
};


class Fenetre
{
	public:
	Gtk::Window window;
	Fenetre();
	virtual ~Fenetre();
	protected:
	// Child widgets:
	Gtk::Button button1; //creation de pointeur sur le bouton
	Gtk::ComboBoxText m_Combo;
	Gtk::Grid mainGrid;
	//Gtk::Entry m_Entry;
	//Signal handlers (run when the button are clicked)
	void on_button_clicked();
};



#endif
