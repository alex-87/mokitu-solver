/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/View.hh"
#include "include/BtnAbout.hh"
#include "include/BtnConstruction.hh"
#include "include/BtnModelisation.hh"
#include "include/CaseContainer.hh"

#include "../presenter/include/Presenter.hh"


namespace MokituSolver { namespace view {

// Construction de la vue, en ayant le Presenter en passage d'attribut
View::View(MokituSolver::presenter::Presenter& presenter) :
	wxFrame(NULL, wxID_ANY, _T("Mokitu Solver - Alexis LE GOADEC")),
	_presenter(presenter) {

	// Charger le conteneur de cases de la grille
	_caseContainer = new CaseContainer(_presenter.lirePartRow(),
									   _presenter.lirePartCol(),
									   3);
}

void View::initialiser(void) {

	// Charger les boutons de l'interface
	BtnAbout * abt = new BtnAbout(*this);
	BtnConstruction * ctr = new BtnConstruction(*this, *this);
	BtnModelisation * mod = new BtnModelisation(*this, *this);

	// Placement de ceux-ci
	abt->Move(5, 5);
	ctr->Move(130, 5);
	mod->Move(255, 5);

	// Chargée l'entrée texte
	_textEntryWord = new TextEntryWord(*this, 0, 0);
	// Placement
	_textEntryWord->Move(90, 50);

	// Chargement du label texte
	new wxStaticText(this, wxID_ANY, _T("Mot / lettre:"), wxPoint(5, 55), wxDefaultSize, (long) 0, wxStaticTextNameStr);

	// Construction de la grille
	_caseContainer->construireGrille(*this);

	// Affichage de la fenêtre
	Show();
}

View::~View() {
	// Effacer les composants de la mémoire
	delete( _caseContainer );
	delete( _textEntryWord );
}

}}
