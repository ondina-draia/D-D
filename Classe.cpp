#include "DD.h"

/*---------------------------------------------------------------------------------------------------------------------------*/
// Constructeur de la classe Classe

Classe::Classe()
{

}

/*---------------------------------------------------------------------------------------------------------------------------*/

// Fonction qui extrait les donnees pour les druides
string Classe::ExtractDruid()
{
	// extrait les informations de la classe druid
	string file_html_Classes = "Classes.html";
	string textclass = LectureHTML(file_html_Classes, "<p class=\"Core-Styles_Core-Body\" data-content-chunk-id=\"ee856172-0055-4a53-9ca3-205eb743bd6e\">", "<h3 id=\"PowerofNature\" class=\"quick-menu-exclude\" data-content-chunk-id=\"10ed6e97-0e57-4ae2-84c2-21a0209b7b77\">");
	textclass = EnleveBalises(textclass);
	textclass = regex_replace(textclass, regex("&rsquo"), "'");
	return textclass;
}

//fonction qui extrait les donnes pour les warlocks

string Classe::ExtractWarlock()
{
	//extrait les informations de la classe warlock 
	string file_html_Classes = "Classes.html";
	return 0;
}

