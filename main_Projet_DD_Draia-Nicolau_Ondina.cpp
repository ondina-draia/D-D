// Projet_DD_Draia-Nicolau_Ondina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Etapes:
// Recuperation des informations des fichiers HTML donnes

#include "DD.h"
#include <gtkmm/application.h>

// using namespace std; deja appelé dans DD.h

int main(int argc, char* argv[])
{	
	string nom_html; //declaration du string qui va accueillir le chemin du fichier html qu'on donnera
	cout << "Comment s'appelle votre fichier contenant les donnes des races? " << endl; //ne pas oublier endl
	cin >> nom_html; // recuperation du chemin du fichier html
	
	//Le on recupere des infos sur le personnage
	// perso, j'ai Dragonborn et Rock Gnome en tant que Races
	int chx; //chx pour choix
	cout <<  "Races disponibles: Dragonborn & Rock Gnome. Pour Dragonborn, écrire 1, pour Rock Gnome, écrire 2" << endl;
	cin >> chx;
	if (chx == 1)
	{
		cout << "Vous avez choisi Dragonborn \n"  ;
	}
	else if (chx == 2)
	{
		cout << "Vous avez choisi Rock Gnome \n" ; //Donc 1 == Dragonborn et 2 == Rock Gnome, c'est simple hein?
	}
	
	// On va donc creer notre personnage en commencant par sa description 
	// On va extraire des donnees du fichier contenant les races, deja la description
	if (chx == 1)
	{
		// on va recuperer dans un fichier toute la description de notre race puis travailler sur ce fichier 
		string description; // 
		string pos1 = "fe8c33fe-4d48-47fb-bb5f-cee048076e18\">Dragonborn</h2>"; //pos1 et pos2 vont donc varier suivant les boucles
		string pos2 = ".</p>"; //biensur, comme cette balise se trouve partout, il faut un code qui lit au fur et a mesure et s'arrete au niveau de cette balise et finit sa boucle la dessus 
		Personnage p;
		string file_html = "/home/ondy/Documents/C++/" + nom_html;
		description = p.LectureHTML(file_html, pos1 ,pos2); //rajouter apres une fonction qui verifie que c'est bien un format de chemin de fichier, mais plus tard 
		cout << description; //description stocke les informations de la description du personnage
		p.setRace("Dragonborn");	
		
	}
	
	// Initialize gtkmm
	auto app = Gtk::Application::create(argc, argv);
	// Create the window
	Fenetre f;
	// Start main loop
	//~ Gtk::Main::run(f.window); grosse merde de ligne
	app -> run(f.window);
	return 0;
}
