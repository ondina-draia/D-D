// Projet_DD_Draia-Nicolau_Ondina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include "DD.h"
#include <gtkmm/application.h>
#include <bits/stdc++.h> 

// using namespace std; deja appelé dans DD.h

int main(int argc, char* argv[])
{	
	//initialisation de la multimap
	multimap<string,string> data; //j'avais envie d'en utiliser une mais au final je m'en sert pas vraiment
	Personnage p; 
	Race r;
	Classe c;
	string DesDragonborn = r.ExtractDragonborn(); //Des Pour description
	pair<string,string> race("Race",DesDragonborn);
	data.insert(race);
	vector<int> AbilityScores = p.AbilityScoreCalc();
	vector<string> WeaponDruid = p.ExtractWeaponDruid(); //Decupere les armes du druide 
	p.printstring(WeaponDruid); //imprime les armes issues de druide
		
	//Recuperation donnees classes (druid et warlock)
	string DesDruid = c.ExtractDruid();
	pair <string, string> classe("Classe", DesDruid);
	data.insert(classe);
		
	// Initialisation de gtkmm
	auto app = Gtk::Application::create(argc, argv);
	//Faire des if en fonction de la classe chosie  pour la description / background
	//f.ajout_description(DesDruid); //est censé remplir description personnage sur la fenetre 
	
	// itere dans la multimap *sert pour test*
	/*for(std::multimap<string, string>::iterator it = data.begin(); it != data.end(); it++)
		std::cout<<it->first<<" :: "<<it->second<<std::endl; */
	Fenetre f;
	f.set_ability_points(AbilityScores);
	app -> run(f.window);
	
	return 0;
}
