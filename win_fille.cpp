#include "DD.h"

win_fille::win_fille()
{
 //Fenêtre avec un seul bouton "Fermer"
  button1.add_pixlabel("giscardsex.jpg", "Fermer");

  set_title("win_fille!");
  set_border_width(10);

  button1.signal_clicked().connect( sigc::mem_fun(*this,
              &win_fille::on_button_clicked) );

  add(button1);

  show_all_children();  //et non show_all sinon la fenêtre fille vas s'afficher tout de suite
}

win_fille::~win_fille()
{
}

void win_fille::on_button_clicked()
{
   //quand on clique sur le bouton on ferme la fenêtre fille pour redonner le focus à la fenêtre mère
    hide();
}
