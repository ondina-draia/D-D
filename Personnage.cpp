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
	string trouve1;
	string trouve2;
	int cpt; //compteur de lignes 
	if (file.is_open()) // boucle qui verifie bien si le fichier est ouvert 
	{
		while (getline(file, line)) //tant qu'on utilise getline pour lire un fichier ligne a ligne et stocker ces lignes dans la variables line:
		{	
			toutfile.append(line);
		}
		
		file.close();
	}	
	else cout << "Impossible d'ouvrir le fichier"; //sinon, il a ete impossible a ouvrir
	
	// maintenant qu'on a tout dans toutfile (lol), on peut chercher ce qui nous interesse grace a pos1 et pos2 dans le fichier! Mais comment?
	// besoin d'une boucle qui a partir d'une position, lit tout et stocke dans un string jusqu'a la fin indiquée
	
	size_t found1 = toutfile.find(pos1); //trouve la premiere position et stocke le nombre correspondant dans found1
	size_t found2 = toutfile.find(pos2); //pareil pour la deuxieme position et la stocke dans found2
    int taille;
    taille = int(found1) - int(found2);
    trouve1 = toutfile.substr(found1, abs(taille)); //part de la premiere position jusqu'a la taille de la difference de caracteres entre la position 1 et la 2
    

	//maintenant qu'on a tout, il manque plus qu'a enlever les balises hein? Mais il vaut mieux le faire dans une autre fonction afin d'avoir une fonction plus specialisee
	
	return trouve1; //retourne tout avec les balises	
} 

string Personnage::LectureRecup(string HTML, string pos1,string pos2) //recupere que ce qui nous interesse
{
	string trouve;
	size_t found1 = HTML.find(pos1); //trouve la premiere position et stocke le nombre correspondant dans found1
	size_t found2 = HTML.find(pos2); //pareil pour la deuxieme position et la stocke dans found2
    int taille;
    taille = int(found1) - int(found2);
    trouve = HTML.substr(found1, abs(taille)); //part de la premiere position jusqu'a la taille de la difference de caracteres entre la position 1 et la 2
    return trouve;
}

string Personnage::EnleveBalises(string HTML) //permet d'enlever les balises d'un string contenant du html et autre
{
	string SeqRecherche; // sequence recherchee dans le html
	bool inside = false;
	for (char c : HTML) {
		if (c == '>')
			inside = true;
		else if (c == '<')
			inside = false;
		else if (inside)
			SeqRecherche.push_back(c);
		}
	
	/*for (char c : HTML) {
		if (c == '&')
			inside = true;
		else if (c == ';')
			inside = false;
		else if (inside)
			SeqRecherche.push_back(c);
		
	}*/
	return SeqRecherche;
}


void Personnage::setRace(string s)
{
	choixRace = s;
}

