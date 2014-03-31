/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef VIEW_HH
#define VIEW_HH

#include <wx/wx.h>

#include "CaseContainer.hh"
#include "TextEntryWord.hh"

namespace MokituSolver { namespace presenter { class Presenter; }}
namespace MokituSolver { namespace view {


/**
 * Vue de l'application.
 */
class View : public wxFrame {

protected:

	/**
	 * Accès aux membres de la vue.
	 */
	friend class BtnConstruction;

	/**
	 * Accès aux membres de la vue.
	 */
	friend class BtnModelisation;

	/**
	 * Accès aux membres de la vue.
	 */
	friend class MokituSolver::presenter::Presenter;

	/**
	 * Conteneur des éléments graphiques des
	 * cases de la grille.
	 */
	CaseContainer * _caseContainer;

	/**
	 * Conteneur du mot ou des lettres
	 * du Mokitu.
	 */
	TextEntryWord * _textEntryWord;

	/**
	 * Référence du Presenter.
	 */
	MokituSolver::presenter::Presenter& _presenter;

public:

	/**
	 * Constructeur par défault.
	 */
	View(MokituSolver::presenter::Presenter& presenter);

	/**
	 * Charger les éléments de l'interface.
	 */
	void initialiser();

	/**
	 * Construire une grille valide.
	 */
	void lancerConstruction(void);

	/**
	 * Résoudre le problème.
	 */
	void lancerResolution(void);

	/**
	 * Effacer la grille.
	 */
	void clean(void);

	/**
	 * Charger la grille (construire celle-ci).
	 */
	void chargerGrille(int partCol, int partRow);

	/**
	 * Vider la mémoire.
	 */
	~View();

};

}}

#endif //View.hh
