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
#include <stdio.h>
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

//preappelation des differentes classes
class Personnage;
class Race;
class Classe;
class Fenetre;
class win_fille;


/****************************************************************************************************************************************************************/

class Personnage //definition de la classe personnage
{
protected:
	
	
public:
	Personnage(); //constructeur 
	string LectureHTML(string, string, string);	/// Lecture simple du fichier HTML
	string EnleveBalises(string); //fonction qui enleve les balises d'un string donne
	string LectureRecup(string, string, string); //fonction qui recupere que ce qui nous interesse precisement dans un string issu d'un html
	vector<int> AbilityScoreCalc(); //fonction qui calcule les ability scores
	void print(std::vector<int> const &input); //fonction servant a print des vecteurs contenant des int dans le terminal 
	void printstring(std::vector<string> const &input); //fonction servant a print des vecteurs contenant des string dans le terminal 
	vector<std::string> ExtractWeaponDruid(); //fonction qui extrait les armes possibles pour un druide 
	void SplitString(std::string const &str, const char delim, std::vector<std::string> &out); //fonction que separe des strings en fonction d'un delimiteur et cree un vecteur a partir de ca
};

/****************************************************************************************************************************************************************/

class Race : public Personnage //heritage pour acceder a la classe Personnage
{
protected:

public:
	Race(); 
	string ExtractDragonborn(); //fonction qui extrait les informations de la race dragonborn
	string ExtractRockGnome(); //fonction qui extrait les informations de la race rockgnome
};

/****************************************************************************************************************************************************************/

class Classe : public Personnage // comme ca il accede au public de Personnage
{
	protected:
		
	public:
		Classe();
		string ExtractDruid(); //fonction qui extrait les informations de la classe druide
		string ExtractWarlock(); //fonction qui extrait les informations de la classe warlock
		
};

/****************************************************************************************************************************************************************/


class win_fille : public Gtk::Window, public Personnage //herite des methodes de Gtk::Window et de personnage
{
	public: //je peux les laisser en public, c'est une classe qu'on voit uniquement apres avoir lancé une autre
	Gtk::Window window; //creation d'une window
	win_fille(); 
	virtual ~win_fille();
	Gtk::Image perso; //initialisation d'un widget ajoutant une image a la fenetre fille
	Gtk::Grid Grid; //initialisation d'une grille pour organiser la fenetre fille
	Gtk::Button button1, button2; //initialisation de deux boutons
	Gtk::Label MonPerso, nom, level, sexe, race, classe, age, description, ali, s, d, i, w, cr, co, arme, armure; //initialisation des labels 

	protected:
	//Signal handlers:
	void on_button_clicked(); //initialisation d'une fonction qui va fermer la fenetre quand on clicke sur un bouton
	
};

/****************************************************************************************************************************************************************/

class Fenetre : public Race
{
	public:
	Gtk::Window window; //initialisation de la fenetre
	Fenetre(); //constructeur fenetre
	virtual ~Fenetre(); //destructeur de fenetre 
	//On créer la fenêtre fille ici, qui va permettre l'affichage des informations 
	win_fille my_win_fille; //creation de la fenetre fille a l'interieur de la mere
	void ajout_description(string des); //initialisation d'une fonction qui ajoute la description du personnage dans la fenetre fille
	void set_ability_points(std::vector<int> const &input); //initialisation d'une fonction qui met les ability points extraits 
	
	protected:
	// Child widgets:
	Gtk::ComboBoxText m_Combo1, m_Combo2, m_Combo4, m_Combo5, Str, Dex, Const, Int, Wis, Chr, Level, Races, Alignement, Vals; // differents combobox
	Gtk::Grid mainGrid; //le grid principal qui organise la fenetre 
	Gtk::ComboBoxText m_Combo, Age; //creation combobox avec entree
	Gtk::Button button1; //boutons
	Gtk::Label CreerPerso, NomNiv, MonNom, Caract, Attr; //labels utilises
	Gtk::Image image; //image utilisee
	void on_button_clicked(); //fonction qui realise des actions lorsque le bouton est appuye
	void fermer();
	
	//Ont servi uniquement pour des tests d'affichage
	void on_combo_changed(); // fonction qui reagit lorsque les combobox sont modifies
	void on_entry_activate(); //fonction qui reagit lorsqu'on entre quelque chose dans l'espace d'entree d'informations
	bool on_entry_focus_out_event(GdkEventFocus* event); //permet de montrer ce qu'il se passe dans la fenetre activement dans le terminal

	//Signal connection:
	sigc::connection m_ConnectionFocusOut;
};

#endif
