#ifndef DD
#define DD
#pragma once

#include <string>
#include <map> 
#include <vector>
#include <regex>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <time.h>
#include <gtkmm.h>
#include <chrono>
#include <thread>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>
#include <string>
#include <gtkmm/box.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/image.h>
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/messagedialog.h>
using namespace std; //selon openclassrooms, il est nefaste d'utiliser cette directive dans le .h, je vais voir comment il reagit pour savoir si je le supprime ou pas 

/****************************************************************************************************************************************************************/

class Personnage;
class Race;
class Classe;
class Fenetre;
class win_fille;


/****************************************************************************************************************************************************************/

class Personnage
{
protected:
	string nom;
	bool sexe;
	int age;
	string classe;
	int niveau;
	string alignement;
	string race;
	double pointsExp;
	
public:
	Personnage(); //constructeur 
	string LectureHTML(string, string, string);	/// Lecture simple du fichier HTML
	string EnleveBalises(string);
	string LectureRecup(string, string, string);
	vector<int> AbilityScoreCalc();
	void print(std::vector<int> const &input);
};

/****************************************************************************************************************************************************************/

class Race : public Personnage //heritage pour acceder a la classe Personnage
{
protected:

public:
	Race();
	string ExtractDragonborn();
};

/****************************************************************************************************************************************************************/

class Classe : public Personnage // comme ca il accede au public de Personnage
{
	protected:
		
	public:
		Classe();
		string ExtractDruid();
		string ExtractWarlock();
		
};

/****************************************************************************************************************************************************************/


class win_fille : public Gtk::Window, public Personnage
{
	public: //je peux les laisser en public, c'est une classe qu'on voit uniquement apres avoir lancé une autre
	Gtk::Window window;
	win_fille();
	virtual ~win_fille();
	Gtk::Image perso;
	Gtk::Grid Grid;
	Gtk::Button button1, button2;
	Gtk::Label MonPerso, nom, level, sexe, race, classe, age, description, ali, s, d, i, w, cr, co;

	protected:
	//Signal handlers:
	void on_button_clicked();
	
};

/****************************************************************************************************************************************************************/

class Fenetre 
{
	public:
	Gtk::Window window;
	Fenetre(); //constructeur fenetre
	virtual ~Fenetre(); //destructeur de fenetre 
	//On créer la fenêtre fille ici, qui va permettre l'affichage des informations 
	win_fille my_win_fille;
	void ajout_description(string des);
	void set_ability_points(std::vector<int> const &input);
	
	protected:
	// Child widgets:
	Gtk::ComboBoxText m_Combo1, m_Combo2, m_Combo4, m_Combo5, Str, Dex, Const, Int, Wis, Chr, Level, Races, Alignement, Vals; // differents combobox
	Gtk::Grid mainGrid; //le grid principal qui organise la fenetre 
	Gtk::ComboBoxText m_Combo, Age; //creation combobox avec entree
	Gtk::Button button1; //boutons
	Gtk::Label CreerPerso, NomNiv, MonNom, Caract, Attr; 
	Gtk::Image image;
	void on_button_clicked(); //fonction qui realise des actions lorsque le bouton est appuye
	void fermer();
	
	//Ont servi uniquement pour des tests d'affichage
	void on_combo_changed(); // fonction qui reagit lorsque les combobox sont modifies
	void on_entry_activate(); //fonction qui reagit lorsqu'on entre quelque chose dans l'espace d'entree d'informations
	bool on_entry_focus_out_event(GdkEventFocus* event); 

	//Signal connection:
	sigc::connection m_ConnectionFocusOut;
};


#endif
