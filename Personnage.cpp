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
	//bool trouve = false; //booleen defini si pos1 trouve ou non 
	int cpt; //compteur de lignes 
	//string tc = "Trouve a la position: "; //va stocker la ligne ou la position est trouvee 
	if (file.is_open()) // boucle qui verifie bien si le fichier est ouvert 
	{
		while (getline(file, line)) //tant qu'on utilise getline pour lire un fichier ligne a ligne et stocker ces lignes dans la variables line:
		{	
			/*cpt++;
			if ((line.find(pos1) != string::npos)) 
			{
				trouve = true; // s'ils trouvent la ligne, trouve devient vrai // bon je ne peux visiblement pas lire des lignes et faire des operations efficacement dessus
				tc = to_string(cpt);
			}*/
			toutfile.append(line);
			/*if (line.find(pos2)) break; */
		}
		
		file.close();
	}	
	else cout << "Impossible d'ouvrir le fichier"; //sinon, il a ete impossible a ouvrir
	
	// maintenant qu'on a tout dans toutfile (lol), on peut chercher ce qui nous interesse grace a pos1 et pos2 dans le fichier! Mais comment?
	// besoin d'une boucle qui a partir d'une position, lit tout et stocke dans un string jusqu'a la fin indiquée
	
	size_t found1 = toutfile.find(pos1);
	size_t found2 = toutfile.find(pos2);
	/*if (found1!=std::string::npos) // permet de trouver la premiere position
    cout << "first pos found at: " << found1 << '\n';
    if (found2!=std::string::npos) // permet de trouver la premiere position
    cout << "second pos found at: " << found2 << '\n'; */
    int taille;
    taille = int(found1) - int(found2);
    trouve1 = toutfile.substr(found1, abs(taille)); //part de la premiere position jusqu'a la taille de la difference de caracteres entre la position 1 et la 2
    //trouve2 = trouve1.substr(found2); //prend le string defini a partir de la premiere position et lit a partir de la position2
    //trouve.erase(found2);
    

	//maintenant qu'on a tout, il manque plus qu'a enlever les balises hein? 
	/*bool inside = false;
	string SeqRecherche; // sequence recherchee dans le html
	for (char c : trouve1) {
		if (c == '>')
			inside = true;
		else if (c == '<')
			inside = false;
		else if (inside)
			SeqRecherche.push_back(c);
	}*/
	
	return trouve1; //retourne tout avec les balises
	

} 

void Personnage::setRace(string s)
{
	choixRace = s;
}

