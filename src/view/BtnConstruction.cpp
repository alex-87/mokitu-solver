/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/BtnConstruction.hh"
#include "../presenter/include/Presenter.hh"

namespace MokituSolver { namespace view {

// Enregistrement du bouton dans la table des êvenements
BEGIN_EVENT_TABLE(BtnConstruction, wxButton)
	EVT_BUTTON(wxID_ANY, BtnConstruction::OnClick)
END_EVENT_TABLE()

// Construction du bouton dans l'interface
BtnConstruction::BtnConstruction(wxFrame& wxf, View& view) :
	wxButton(&wxf,
			 wxID_ANY,
			 _T("Construction"),
			 wxPoint(5, 5),
			 wxSize(120, 30)
			 ),
	_view(view) {
}

void
BtnConstruction::OnClick(wxCommandEvent& event) {

	// Enregistrement de la matrice
	std::vector<std::vector<char> > matrice;
	// Calcul de la taille d'un côté de la grille
	int taille = _view._presenter.lirePartRow() * _view._presenter.lirePartCol();
	for(int i=0; i < taille ; i++ ) {
		// Vecteur temporaire de ligne
		std::vector<char> tmp;
		for(int j=0; j < taille ; j++) {
			// Enregistrement de la valeur dans la matrice
			tmp.push_back(
						_view._caseContainer->lireCaseValue(i, j)->lireValeur()
					);
		};
		// Enregistrement de la ligne
		matrice.push_back(tmp);
	};

	// Procédure de lancement
	_view._presenter.syncActionConstruction(_view._textEntryWord->lireMot(), matrice);
}

}}
