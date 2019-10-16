#ifndef DD
#define DD
#pragma once

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
#include <gtkmm/comboboxtext.h>
using namespace std;

/****************************************************************************************************************************************************************/

class Personnage;
class Race;
class Classe;
class Fenetre;
class win_fille;
//class AboutWindow;

class Race
{
protected:

public:
	Race();
	string getRace(string dataHTML);
};

class Personnage
{
protected:
	
	
public:
	Personnage();
	string LectureHTML(string, string, string);	/// Lecture simple du fichier HTML
	string EnleveBalises(string);
	string LectureRecup(string, string, string);
	string ExtractDragonborn();
	string AbilityScoreCalc();
};


class Classe : public Personnage // comme ca il accede au public de Personnage
{
	protected:
		
	
	public:
		Classe();
		string ExtractDruid();
		
};

class win_fille : public Gtk::Window
{
public:
  win_fille();
  virtual ~win_fille();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Child widgets:
  Gtk::Button button1;
};


class Fenetre
{
	public:
	Gtk::Window window;
	Fenetre();
	virtual ~Fenetre();
	
	protected:
	// Child widgets:
	Gtk::ComboBoxText m_Combo1, m_Combo2, m_Combo3, m_Combo4, m_Combo5;
	Gtk::Grid mainGrid;
	Gtk::ComboBoxText m_Combo;
	Gtk::Button button1;
	void on_button_clicked();
	void on_combo_changed();
	void on_entry_activate();
	bool on_entry_focus_out_event(GdkEventFocus* event);

	//Signal connection:
	sigc::connection m_ConnectionFocusOut;
	
	//On créer la fenêtre fille ici !!!
	win_fille my_win_fille;

	
};


#endif
