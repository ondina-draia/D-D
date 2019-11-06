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
	string TextRace = LectureHTML(file_html_Races, "<p class=\"Core-Styles_Core-Body\" data-content-chunk-id=\"ec6cb3be-236e-43a8-93f0-9677f532fe13\">", "Shaped by draconic");
	TextRace = EnleveBalises(TextRace);
	return TextRace;
}

string Race::ExtractRockGnome()
{
	string file_html_Races = "Races.html";
	string TextRace = LectureHTML(file_html_Races, "<p class=\"Core-Styles_Core-Body\" data-content-chunk-id=\"6fe5790b-371f-41ef-837b-fe999a0188f0\">", ", including the tinker gnomes of the Dr");
	TextRace = EnleveBalises(TextRace);
	return TextRace;
}
