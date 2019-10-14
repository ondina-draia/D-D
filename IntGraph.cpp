#include "DD.h"
#include <gtkmm/messagedialog.h>
#include <gtkmm/main.h>


Fenetre::Fenetre()
{
	window.set_title("Creation de personnage");
	window.resize(800, 800); //largeur, hauteur
	window.set_position(Gtk::WIN_POS_CENTER);
	window.set_border_width(50); //Ajouter une bordure (invisible) de 10px à la fenêtre
	window.set_icon_from_file("DD.png");
	
	// First buttton
	button1.add_label("Button 1");
	button1.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::on_button_clicked));
	mainGrid.attach(button1, 0, 0, 1, 1);
	
	//Combo races
	m_Combo.append("Dragonborn");
	m_Combo.append("Rock Gnome");
	m_Combo.set_active(0);
	mainGrid.attach(m_Combo, 0, 1, 1, 1); //definit le positionnement de la combo box
	
	//Combo classes
	m_Combo.append("Druid");
	m_Combo.append("Warlock");
	m_Combo.set_active(0);
	mainGrid.add(m_Combo);
	
	mainGrid.show_all();
	window.add(mainGrid);
	window.show_all_children();
	//~ window.add(button1);
	//~ button1.show();
	
	//zone de texte
	//set_size_request(200, 100);
	//set_title("Gtk::Entry");

	//add(m_VBox);
	//mainGrid.attach(zoneTexte, 0, 2, 1 ,1);
	
}

Fenetre::~Fenetre() {}

void Fenetre::on_button_clicked() {
	Glib::ustring s1 = m_Combo.get_active_text();
	Gtk::MessageDialog dialog(window, "<u>My</u> <b>DD class</b> <i>is</i>", true,
	Gtk::MESSAGE_OTHER);
	dialog.set_secondary_text(s1,true);
	dialog.run();
}


