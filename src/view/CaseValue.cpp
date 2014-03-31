/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/CaseValue.hh"

namespace MokituSolver { namespace view {

// Construction d'une case de l'interface aux coordonnées
CaseValue::CaseValue(wxFrame& wxf, int x, int y) :
		wxTextCtrl(&wxf,
				   wxID_ANY,
				   wxEmptyString,
				   wxPoint(x, y),
				   wxSize(20, 5),
				   (long) 0,
				   wxDefaultValidator,
				   wxTextCtrlNameStr
				   ),
		_x(x),
		_y(y) {

}

char
CaseValue::lireValeur(void) const {
	// Lire la premièrelettre de l'entrée
	wxString currentValue(GetLineText(0));
	std::string s(currentValue.ToStdString());
	// Si la taille est nulle, retourner un point
	if( s.size()==0 ) return '.';
	// Sinon retourner la valeur en tant que caractère
	return s.at(0);
}

}}
