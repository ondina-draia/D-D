#include "DD.h"

win_fille::win_fille()
{
	
	//Fenêtre 
	MonPerso.set_markup("<b>La fiche de mon personnage</b>");
	Grid.attach(MonPerso, 2, 0, 2, 1); //column, row, width, height
	
	//Nom
	nom.set_markup("X");
	Grid.attach(nom, 0, 1, 2, 1);
	
	//Niveau
	level.set_markup("1");
	Grid.attach(level, 2, 1, 2, 1);
	
	//Sexe
	sexe.set_markup("inconnu");
	Grid.attach(sexe, 4, 1, 2, 1);
	
	//Alignement
	ali.set_markup("alignement");
	Grid.attach(ali, 2, 2, 2, 1);
	
	//Race
	race.set_markup("Pas de race");
	Grid.attach(race, 0, 3, 2, 1);
	
	//Classe
	classe.set_markup("aucune classe");
	Grid.attach(classe, 2, 3, 2, 1);
	
	//Age
	age.set_markup("eternel");
	Grid.attach(age, 4, 3, 2, 1);
	
	//Points d'attribut
	//Force
	s.set_markup("strength");
	Grid.attach(s, 0, 5, 1, 1);
	
	//Dexterité
	d.set_markup("dex");
	Grid.attach(d, 1, 5, 1, 1);
	
	//Intelligence
	i.set_markup("int");
	Grid.attach(i, 2, 5, 1, 1);
	
	//Sagesse
	w.set_markup("wisdom");
	Grid.attach(w, 3, 5, 1, 1);
	
	//Charisme
	cr.set_markup("charisme");
	Grid.attach(cr, 4, 5, 1, 1);
	
	//Constitution
	co.set_markup("const");
	Grid.attach(co, 5, 5, 1, 1);
	
	//description du personnage
	string race;
	description.set_markup("Description du personnage");
	Grid.attach(description, 0, 6, 6, 4);
	
	//image du personnage
	perso.set("dragonborn_male_res.png");
	Grid.attach(perso, 2, 10, 2, 2);
	
	
	//bouton fermer la fenetre
	button1.add_pixlabel("dragon_res.png", "Fermer");
	set_border_width(10);

	button1.signal_clicked().connect( sigc::mem_fun(*this,
              &win_fille::on_button_clicked) );
    Grid.attach(button1, 2, 16, 2, 1);
    
    Grid.set_row_spacing(10);
	Grid.set_column_spacing(10);

	Grid.show_all();
	add(Grid); 
	show_all_children();  //et non show_all sinon la fenêtre fille vas s'afficher tout de suite
}

win_fille::~win_fille()
{ 
}

void win_fille::on_button_clicked() //on clique sur fermer, la fenetre se ferme
{
   //quand on clique sur le bouton on ferme la fenêtre fille pour redonner le focus à la fenêtre mère
    hide();
}

