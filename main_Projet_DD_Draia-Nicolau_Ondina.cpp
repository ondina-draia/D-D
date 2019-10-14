// Projet_DD_Draia-Nicolau_Ondina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Etapes:
// Recuperation des informations des fichiers HTML donnes

#include "DD.h"
#include <gtkmm/application.h>

// using namespace std; deja appelé dans DD.h

int main(int argc, char* argv[])
{	
	Personnage p;
	string DesDragonborn = p.ExtractDragonborn();
	p.setRace("Dragonborn");	
		
	//Recuperation donnees classes (druid et warlock)
	Classe c;
	string DesDruid = c.ExtractDruid();
		
	// Initialize gtkmm
	auto app = Gtk::Application::create(argc, argv);
	// Create the window
	Fenetre f;
	// Start main loop
	//~ Gtk::Main::run(f.window); 
	app -> run(f.window);
	return 0;
}
