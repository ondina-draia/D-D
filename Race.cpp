#include "DD.h"

/*---------------------------------------------------------------------------------------------------------------------------*/
// Constructeur de la classe Race

Race::Race()
{

}

/*---------------------------------------------------------------------------------------------------------------------------*/

// Fonction qui extrait les donnees pour les elfes
string Race::ExtractDragonBorn(string dataHTML)
{

	string race;
	// An object of regex for pattern to be searched 
	regex r("[^A-Za-z0-9]+");

	// flag type for determining the matching behavior 
	// here it is for matches on 'string' objects 
	smatch m;

	// regex_search() for searching the regex pattern 
	// 'r' in the string 's'. 'm' is flag for determining 
	// matching behavior. 
	regex_search(dataHTML, m, r);

	// for each loop 
	for (auto x : m)
		race.append(x);
	
	return race;
}
