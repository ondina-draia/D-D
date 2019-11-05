#include "DD.h"
//#include <gtkmm/messagedialog.h>
//#include <gtkmm/main.h>


Fenetre::Fenetre() : m_Combo(true /* a une entree saisie */), Age(true), Str(true), Dex(true), Const(true), Int(true), Wis(true), Chr(true) //a ne pas oublier sinon pas de entry box
{
	window.set_title("Creation de personnage");
	window.resize(800, 800); //largeur, hauteur
	window.set_position(Gtk::WIN_POS_CENTER);
	window.set_border_width(50); //Ajouter une bordure (invisible) de 10px à la fenêtre
	window.set_icon_from_file("DD.png");
	
	CreerPerso.set_markup("<b>Creez votre personnage Dungeons et Dragons:</b>");
	mainGrid.attach(CreerPerso, 1, 0, 4, 1);
	
	NomNiv.set_markup("Nom, Niveau, Sexe et Alignement :");
	mainGrid.attach(NomNiv, 2, 1, 2, 1);
	
	//Fill the combo:
	m_Combo.append("Arjhan");
	m_Combo.append("Mishann");
	m_Combo.append("Giscard d'Estaing");
	m_Combo.set_active(0);
	mainGrid.attach(m_Combo, 0, 2, 1 ,1);
	
	//Niveau
	Level.append("Level");
	Level.append("1");
	Level.append("2");
	Level.append("3");
	Level.append("4");
	Level.append("5");
	Level.append("6");
	Level.append("7");
	Level.append("8");
	Level.append("9");
	Level.append("10");
	Level.append("11");
	Level.append("12");
	Level.append("13");
	Level.append("14");
	Level.append("15");
	Level.append("16");
	Level.append("17");
	Level.append("18");
	Level.append("19");
	Level.append("20");
	Level.set_active(0);
	mainGrid.attach(Level, 1, 2, 1 ,1);
	
	//Combo sexe
	m_Combo2.append("Sexe");
	m_Combo2.append("Femme");
	m_Combo2.append("Homme");
	m_Combo2.append("Les deux");
	m_Combo2.append("Non-binaire");
	m_Combo2.set_active(0);
	mainGrid.attach(m_Combo2, 2, 2, 1 ,1);
	
	//Alignement
	Alignement.append("Alignement");
	Alignement.append("Lawful good");
	Alignement.append("Lawful neutral");
	Alignement.append("Lawful evil");
	Alignement.append("Neutral good");
	Alignement.append("True neutral");
	Alignement.append("Neutral evil");
	Alignement.append("Chaotic good");
	Alignement.append("Chaotic neutral");
	Alignement.append("Chaotic evil");
	Alignement.set_active(0);
	mainGrid.attach(Alignement, 3, 2, 1, 1);
	
	//Label caracteristiques
	Caract.set_markup("La race, la classe, l'age, l'armure et l'equipement de votre personnage: ");
	mainGrid.attach(Caract, 1, 3, 4, 1);
	
	//Combo races
	Races.append("Race");
	Races.append("Rock Gnome");
	Races.append("Dragonborn");
	Races.set_active(0); //affiche premiere entree en tant qu'entree active
	mainGrid.attach(Races, 0, 4, 1, 1);
	
	//Combo classe
	m_Combo1.append("Classe");
	m_Combo1.append("Druid");
	m_Combo1.append("Warlock");
	m_Combo1.set_active(0);
	mainGrid.attach(m_Combo1, 1, 4, 1, 1); //definit le positionnement de la combo box
	
	//Combo age
	Age.append("Age");
	Age.append("vieux");
	Age.set_active(0);
	mainGrid.attach(Age, 2, 4, 1 ,1);
	auto age = Age.get_entry(); //recupere l'age
	
	//Combo classes
	m_Combo4.append("Armure ");
	m_Combo4.append("Armure");
	m_Combo4.set_active(0);
	mainGrid.attach(m_Combo4, 3, 4, 1 ,1);
	
	//Combo classes
	m_Combo5.append("Equipement");
	m_Combo5.append("Equipement");
	m_Combo5.set_active(0);
	mainGrid.attach(m_Combo5, 4, 4, 1 ,1);
	
	//Attributs label
	Attr.set_markup("Points d'attributs à distribuer:");
	mainGrid.attach(Attr, 2, 5, 2, 1);
	
	//Combo Ability score /
	//Force
	Str.append("Force");
	Str.append("15");
	Str.set_active(0);
	mainGrid.attach(Str, 0, 6, 1, 1);
	auto str = Str.get_entry();
	
	//Dexterite
	Dex.append("Dexterite");
	Dex.append("14");
	Dex.set_active(0);
	mainGrid.attach(Dex, 1, 6, 1, 1);
	auto dex = Dex.get_entry(); 
	
	Const.append("Constitution");
	Const.append("13");
	Const.set_active(0);
	mainGrid.attach(Const, 2, 6, 1, 1);
	auto cons = Const.get_entry();
	
	Int.append("Intelligence");
	Int.append("12");
	Int.set_active(0);
	mainGrid.attach(Int, 3, 6, 1, 1);
	auto inte = Int.get_entry();
	
	Wis.append("Sagesse");
	Wis.append("10");
	Wis.set_active(0);
	mainGrid.attach(Wis, 4, 6, 1, 1);
	auto wis = Wis.get_entry();
	
	Chr.append("Charisme");
	Chr.append("8");
	Chr.set_active(0);
	mainGrid.attach(Chr, 5, 6, 1 ,1);
	auto chr = Chr.get_entry();
	
	Vals.append("Valeurs possibles");
	Vals.set_active(0);
	mainGrid.attach(Vals, 0, 8, 1 ,1);
	
	/****************************************************************************************************************************************************************/
	
	// Button qui ouvre la fenetre fille
	button1.add_pixlabel("dragon_res.png", "Mon Personnage");
	button1.signal_clicked().connect( sigc::mem_fun(*this,
              &Fenetre::on_button_clicked) );
	mainGrid.attach(button1, 2, 8, 2, 1);
	
	mainGrid.set_row_spacing(15);
	mainGrid.set_column_spacing(10);
	
	/****************************************************************************************************************************************************************/
	
	//ajout de l'image decorative
	image.set("alt_W1_res.png");
	mainGrid.attach(image, 2, 9, 2, 2);
	
	MonNom.set_markup("© 2019, Draia-Nicolau Ondina");
	mainGrid.attach(MonNom, 5, 18, 1, 1);
	
	/****************************************************************************************************************************************************************/
	
	//Connecte les signal handlers a la combo boxe du nom:
	auto entry_name = m_Combo.get_entry(); //stocke ce qui est entre dans m_combo
	// Se connecter a entry->signal_changed() pour le nom
	//m_Combo.signal_changed().connect(sigc::mem_fun(*this, //lorsque le signal est changé (voir fonction) sur cette combobox, faire les operations suivantes
	//	&Fenetre::on_combo_changed) );
	if (entry_name) //s'il existe une entry_name
	{
		// L'entree receivoit des focus-out events.
		entry_name->add_events(Gdk::FOCUS_CHANGE_MASK); //Receive focus change events. 
		//entry_name->signal_activate().connect(sigc::mem_fun(*this, //signal active 
		//&Fenetre::on_entry_activate) );
		//m_ConnectionFocusOut = entry_name->signal_focus_out_event().
		//connect(sigc::mem_fun(*this, &Fenetre::on_entry_focus_out_event) );
	}
	else
		std::cout << "No Entry ???" << std::endl;
	
	m_Combo.property_has_frame() = false;
	
	/****************************************************************************************************************************************************************/
	
	mainGrid.show_all();
	window.add(mainGrid);
	window.show_all_children();
	
}

// Fonctions de Fenetre : 

Fenetre::~Fenetre() {}


void Fenetre::on_button_clicked() {
    //my_win_fille.set_modal(true);  //pour que la fenêtre fille soit modale, d'autres fenetres ne sont pas utilisables quand celle la est ouverte 
    my_win_fille.show();  //affiche la fenêtre fille
    my_win_fille.resize(800,800);
    
	//nom du personnage
	string name = m_Combo.get_active_text();
	my_win_fille.nom.set_markup("Nom:  " + name);
	
	//niveau du personnage
	string level = Level.get_active_text();
	my_win_fille.level.set_markup("Niveau:  " + level);
	
	//alignement
	string alignement = Alignement.get_active_text();
	my_win_fille.ali.set_markup("Alignement:  " + alignement);
	
	//sexe du personnage
	string sexe = m_Combo2.get_active_text();
	my_win_fille.sexe.set_markup("Sexe:  " + sexe);
	
	//race du personnage
	string race = Races.get_active_text();
	my_win_fille.race.set_markup("Race:  " + race);
	
	//classe du personnage
	string classe = m_Combo1.get_active_text();
	my_win_fille.classe.set_markup("Classe:  " + classe);
	
	//age du personnage
    string age = Age.get_active_text();
    my_win_fille.age.set_markup("Age: " + age);
    
    //ability points du personnage
    string str = Str.get_active_text();
    my_win_fille.s.set_markup("Force : " + str);
    
    string dex = Dex.get_active_text();
    my_win_fille.d.set_markup("Dexterité :" + dex);
    
    string inte = Int.get_active_text();
    my_win_fille.i.set_markup("Intelligence :" + inte);
    
    string sag = Wis.get_active_text();
    my_win_fille.w.set_markup("Sagesse: " + sag);
    
    string cons = Const.get_active_text();
    my_win_fille.co.set_markup("Constitution: " + cons);
    
    string chr = Chr.get_active_text();
    my_win_fille.cr.set_markup("Charisme :" + chr);
    
    /**********************************************************************************************************/
    
    int r = Races.get_active_row_number();
    int c = m_Combo1.get_active_row_number(); // 1: druid 2: warlock
    int s = m_Combo2.get_active_row_number(); //sexe, 1:f 2:h 3:les deux 4:nonbin
    
    
    // Affichage de l'image du perso par rapport a la Race sur la fenetre fille + controle de l'age
    int a = atoi(age.c_str()); //transformation du string de l'age en int
    if (r == 1) //race rock gnome
    {
		if (a > 600)
		{
			my_win_fille.age.set_markup("600 (MAX)");
		}
		else if (a < 0)
		{
			my_win_fille.age.set_markup("Pas encore né, rentre chez toi");
		}
		if(c == 1) //classe druide
		{
			if(s == 2) //homme 
			{
				my_win_fille.perso.set("rockgnome_male_druid.jpg");
			}
			else if (s ==1) //femme
			{
				my_win_fille.perso.set("rockgnome_femelle_druid.jpg");
			}
		}
		else if (c == 2) //classe warlock
		{
			if(s == 2) //homme 
			{
				my_win_fille.perso.set("rockgnome_male_warlock.jpg");
			}
			else if (s ==1) //femme
			{
				my_win_fille.perso.set("rockgnome_femelle_warlock.jpg");
			}
		}
	}
	
	else if (r == 2)
	{
		if (a > 120)
		{
			my_win_fille.age.set_markup("120 (MAX)");
		}
		else if (a < 0)
		{
			my_win_fille.age.set_markup("Pas encore né, rentre chez toi");
		}
		if(c == 1) //classe druide
		{
			if(s == 2) //homme 
			{
				my_win_fille.perso.set("dragonborn_male_druid.jpg");
			}
			else if (s ==1) //femme
			{
				my_win_fille.perso.set("dragonborn_femelle_druid.jpg");
			}
		}
		else if (c == 2) //classe warlock
		{
			if(s == 2) //homme 
			{
				my_win_fille.perso.set("dragonborn_male_warlock.jpg");
			}
			else if (s ==1) //femme
			{
				my_win_fille.perso.set("dragonborn_femelle_warlock.jpg");
			}
		}
	}
	
}

/* Ont servi uniquement pour des tests d'affichage */

void Fenetre::on_combo_changed()
{
  std::cout << "on_combo_changed(): Row=" << m_Combo.get_active_row_number()
    << ", Text=" << m_Combo.get_active_text() << std::endl;
}

void Fenetre::on_entry_activate()
{
  std::cout << "on_entry_activate(): Row=" << m_Combo.get_active_row_number()
    << ", Text=" << m_Combo.get_active_text() << std::endl;
}

bool Fenetre::on_entry_focus_out_event(GdkEventFocus* /* event */)
{
  std::cout << "on_entry_focus_out_event(): Row=" << m_Combo.get_active_row_number()
    << ", Text=" << m_Combo.get_active_text() << std::endl;
  return true;
}

void Fenetre::ajout_description(string des)
{
	//Description du personnage qui va devoir etre piochée dans la map du main
	my_win_fille.description.set_markup(des);
}


void Fenetre::set_ability_points(std::vector<int> const &input)
{
	//recupere vecteur, le set dans les combobox des ability points
	for (int i = 0; i < input.size(); i++) {
		string tmp(to_string(input[i]));
		Vals.append(tmp);
	}	
	//, enleve a chaque fois qu'une valeur est chosie, cette valeur des autres combobox
	
}
