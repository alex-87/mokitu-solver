/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/TextEntryWord.hh"

namespace MokituSolver { namespace view {

// Construction de l'entrée de texte dans l'interface
TextEntryWord::TextEntryWord(wxFrame& wxf, int x, int y) :
								 wxTextCtrl(&wxf,
										    wxID_ANY,
										    wxEmptyString,
										    wxPoint(x, y),
										    wxSize(100, 30),
										    (long) 0,
										    wxDefaultValidator,
										    wxTextCtrlNameStr
										    ),
								 _x(x),
								 _y(y) {
}

std::string
TextEntryWord::lireMot() const {
	// Lire le mot entré dans le champs texte
	wxString currentValue(GetLineText(0));
	std::string s(currentValue.ToStdString());
	// Retourner la chaîne
	return s;
}

}}
