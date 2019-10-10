#include "DD.h"

Personnage::Personnage()
{

}

string Personnage::LectureHTML(string myfile, string pos1, string pos2) //prend en argument un chemin vers un fichier de type string
{
	// Va lire une partie du fichier html donné tout en le stockant dans une variable de type string
	// Va realiser ca en partant d'une position donnée, lire ce qui est interessant et s'arreter a une position donnée
	string toutfile;
	string line; //va servir a stocker chaque ligne a la lecture
	ifstream file(myfile); //on se sert de ifstream pour lire des fichiers
	if (file.is_open()) // boucle qui verifie bien si le fichier est ouvert 
	{
		while (getline(file, line)) //tant qu'on utilise getline pour lire un fichier ligne a ligne et stocker ces lignes dans la variables line:
		{
			if ((line.find(pos1) != string::npos)) //&& (line.find(pos2) == string::npos))
			{
				toutfile.append(line); //stocke ces lignes dans la variable toutfile
				if (line.find(pos2)) break;
			}
			
		}
		file.close();
	}
	else cout << "Impossible d'ouvrir le fichier"; //sinon, il a ete impossible a ouvrir
	
	// maintenant qu'on a tout dans toutfile (lol), on peut chercher ce qui nous interesse grace a pos1 et pos2 dans le fichier! Mais comment?
	// besoin d'une boucle qui a partir d'une position, lit tout et stocke dans un string jusqu'a la fin indiquée

	//maintenant qu'on a tout, il manque plus qu'a enlever les balises hein? 
	bool inside = false;
	string toutfileb;
	for (char c : toutfile) {
		if (c == '>')
			inside = true;
		else if (c == '<')
			inside = false;
		else if (inside)
			toutfileb.push_back(c);
	}
	
	return toutfileb;
	

} 

void Personnage::setRace(string s)
{
	choixRace = s;
}

