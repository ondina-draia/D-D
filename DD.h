#ifndef DD
#define DD

#include <string>
#include <map>
#include <vector>
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/****************************************************************************************************************************************************************/

class Personnage;
class Race;
class Classe;

class Race
{
protected:

public:
	Race();
	string ExtractDragonBorn(string dataHTML);
};


class Classe
{
	protected:
		
	
	public:
		Classe();
		string ExtractDruid(string dataHTML);
		
};

class Personnage : public Race, public Classe
{
protected:
	string choixRace;

public:
	Personnage();
	string LectureHTML(string, string, string);	/// Lecture simple du fichier HTML
	void setRace(string);
};

#endif
