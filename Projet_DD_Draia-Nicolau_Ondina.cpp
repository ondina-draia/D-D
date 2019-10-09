// Projet_DD_Draia-Nicolau_Ondina.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Etapes:
// Recuperation des informations des fichiers HTML donnes

#include<iostream>
#include<fstream>
#include<string>

// using namespace std; deja appelé dans DD.h

int main(int argc, char* argv[])
{
	string dataHTML;
	Personnage p;
	//recuperation donnees
	//dataHTML = p.LectureHTML("C:/Users/castr/OneDrive/Documents/Master 2 Bioinformatique/Cours/CPP/Projet-DD/Projet-D&D/Races.html");	/// Lecture du fichier Classe.html
	Race r;
	r.extractDragonBorn(dataHTML);
	return 0;
}