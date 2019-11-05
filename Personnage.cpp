#include "DD.h"

Personnage::Personnage()
{
	// creation du personnage avec les differentes variables qu'il faut stocker grace au .h
	// recupere donnes de la fenetre et du html

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
    
	return trouve1;
	//maintenant qu'on a tout, il manque plus qu'a enlever les balises hein? Mais il vaut mieux le faire dans une autre fonction afin d'avoir une fonction plus specialisee
	
	//return trouve1; //retourne tout avec les balises	
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
	string Seq;
	bool inside = false;
	for (char c : HTML) {
		if (c == '>')
			inside = true;
		else if (c == '<')
			inside = false;
		else if (inside)
			SeqRecherche.push_back(c);
	}
	return SeqRecherche;
}


vector<int> Personnage::AbilityScoreCalc()
/* Information:
 * You generate your character’s six ability scores randomly. Roll four 6-sided dice and record the total of the highest three dice on a piece of scratch paper. Do this five more times,
 *  so that you have six numbers. If you want to save time or don’t like the idea of randomly determining ability scores, you can use the following scores instead: 15, 14, 13, 12, 10, 8.
	Now take your six numbers and write each number beside one of your character’s six abilities to assign scores to Strength, Dexterity, Constitution, Intelligence, Wisdom, and Charisma.
	Afterward, make any changes to your ability scores as a result of your race choice. */
{
	//double Strength, Dexterity, Ability, Constitution, Intelligence, Wisdom, Charisma;
	int i = 0;
	vector <int> AbilityScore; //stocke les sommes des jets
	//vector <int> NbTir; //stocke les 4 tirs des 6 rounds de tirs
	//srand(time(0)); //initialise la vitesse du random	
	/*for (int j = 0; j<7; j++)
	{
		//on doit faire ca 5 fois
		while(i<4) //permet de tirer au hasard 4 nombres et les stocker dans un tableau NbTir 
		{
			NbTir.push_back(rand() % 6 + 1);
			i++;
		}
		sort(NbTir.begin(), NbTir.end()); 
		vector<int> Nb = vector<int>(NbTir.begin() +1, NbTir.end()); //Vecteur contenant uniquement les 3 meilleurs tirs
		int sum = accumulate(Nb.begin(),Nb.end(), 0); //accumulate(first_index, last_index, initial value of sum);
		AbilityScore.push_back(sum);
	}*/
	while(i<6)
	{
		AbilityScore.push_back(rand() % 18 + 3);
		i ++;
	}
	// si on a la somme de 3 jets de des de 6, minimum c'est 3*1 et le maximum c'est 3*6= 18
	return AbilityScore;
}

void Personnage::print(std::vector<int> const &input) //print vector method 
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}
		

	
		
		
	
	
		

