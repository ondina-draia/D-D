// Projet_DD_Draia-Nicolau_Ondina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Etapes:
// Recuperation des informations des fichiers HTML donnes

#include "DD.h"
#include <gtkmm/application.h>
#include <bits/stdc++.h> 

// using namespace std; deja appelé dans DD.h

int main(int argc, char* argv[])
{	
	//initialisation de la multimap
	multimap<string,string> data;

	Personnage p;
	Race r;
	string DesDragonborn = r.ExtractDragonborn(); //Des Pour description
	pair<string,string> race("Race",DesDragonborn);
	data.insert(race);
	vector<int> AbilityScores = p.AbilityScoreCalc();
	p.print(AbilityScores); // a mettre dans la class de l'interface graphique
	
		
	//Recuperation donnees classes (druid et warlock)
	Classe c;
	string DesDruid = c.ExtractDruid();
	pair <string, string> classe("Classe", DesDruid);
	data.insert(classe);
	
	// itere dans la multimap *sert pour test*
	/*for(std::multimap<string, string>::iterator it = data.begin(); it != data.end(); it++)
		std::cout<<it->first<<" :: "<<it->second<<std::endl; */
		
	// Initialize gtkmm
	auto app = Gtk::Application::create(argc, argv);
	// Create the window
	Fenetre f;
	// Start main loop
	//~ Gtk::Main::run(f.window); 
	
	//Faire des if en fonction de la classe chosie  pour la description / background
	//f.ajout_description(DesDruid);
	f.set_ability_points(AbilityScores);
	app -> run(f.window);
	
	return 0;
}
