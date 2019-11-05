#include "DD.h"

/*---------------------------------------------------------------------------------------------------------------------------*/
// Constructeur de la classe Race

Race::Race()
{

}

/*---------------------------------------------------------------------------------------------------------------------------*/

string Race::ExtractDragonborn()
{
	string file_html_Races = "Races.html";
	string TextRace = LectureHTML(file_html_Races, "<h2 id=\"Dragonborn\" class=\"compendium-header-banner-heading\" data-content-chunk-id=\"fe8c33fe-4d48-47fb-bb5f-cee048076e18\">Dragonborn</h2>", "Gnome</h2>");
	TextRace = EnleveBalises(TextRace);
	return TextRace;
}
