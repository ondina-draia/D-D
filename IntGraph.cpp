#include "DD.h"
#include <gtkmm/messagedialog.h>
#include <gtkmm/main.h>


Fenetre::Fenetre() : m_Combo(true /* a une entree saisie */)
{
	window.set_title("Creation de personnage");
	window.resize(800, 800); //largeur, hauteur
	window.set_position(Gtk::WIN_POS_CENTER);
	window.set_border_width(50); //Ajouter une bordure (invisible) de 10px à la fenêtre
	window.set_icon_from_file("DD.png");
	
	//Fill the combo:
	m_Combo.append("Arjhan");
	m_Combo.append("Mishann");
	m_Combo.append("Michel Forever");
	m_Combo.set_active(0);
	mainGrid.attach(m_Combo, 0, 0, 1 ,1);
	
	//Combo races
	m_Combo1.append("Dragonborn");
	m_Combo1.append("Rock Gnome");
	m_Combo1.set_active(0);
	mainGrid.attach(m_Combo1, 0, 1, 1, 1); //definit le positionnement de la combo box
	
	//Combo classes
	m_Combo2.append("Baton de cypres");
	m_Combo2.append("Warlock");
	m_Combo2.set_active(0);
	mainGrid.attach(m_Combo2, 1, 1, 1 ,1);
	
	//Combo classes
	m_Combo3.append("Potion de sante mentale");
	m_Combo3.append("Warlock");
	m_Combo3.set_active(0);
	mainGrid.attach(m_Combo3, 2, 1, 1 ,1);
	
	//Combo classes
	m_Combo4.append("Michel Drucker's theme");
	m_Combo4.append("Warlock");
	m_Combo4.set_active(0);
	mainGrid.attach(m_Combo4, 3, 1, 1 ,1);
	
	//Combo classes
	m_Combo5.append("Druid");
	m_Combo5.append("Warlock");
	m_Combo5.set_active(0);
	mainGrid.attach(m_Combo5, 4, 1, 1 ,1);
	
	// Button
	button1.add_label("Create");
	button1.signal_clicked().connect(sigc::mem_fun(*this, &Fenetre::on_button_clicked));
	mainGrid.attach(button1, 5, 0, 1, 1);

	//Connect signal handlers:
	auto entry = m_Combo.get_entry();
	// Alternatively you can connect to entry->signal_changed().
	m_Combo.signal_changed().connect(sigc::mem_fun(*this,
		&Fenetre::on_combo_changed) );
	if (entry)
	{
		// The Entry shall receive focus-out events.
		entry->add_events(Gdk::FOCUS_CHANGE_MASK);
		entry->signal_activate().connect(sigc::mem_fun(*this,
		&Fenetre::on_entry_activate) );
		m_ConnectionFocusOut = entry->signal_focus_out_event().
		connect(sigc::mem_fun(*this, &Fenetre::on_entry_focus_out_event) );
	}
	else
		std::cout << "No Entry ???" << std::endl;

	m_Combo.property_has_frame() = false;
	
	
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
void Fenetre::on_button_clicked() {
	//Glib::ustring s1 = m_Combo1.get_active_text();
	Gtk::MessageDialog dialog(window, "<u>My</u> <b>DD class</b> <i>is</i>", true,
	Gtk::MESSAGE_OTHER);
	//dialog.set_secondary_text(s1,true);
	dialog.run();
}


