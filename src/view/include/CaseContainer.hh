/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CASECONTAINER_HH_
#define CASECONTAINER_HH_

#include <wx/wx.h>
#include <vector>
#include <memory>

#include "CaseValue.hh"

namespace MokituSolver { namespace view {

/**
 * Gestion de l'ensemble des cellules de la grille.
 */
class CaseContainer {

protected:

	/**
	 * Nombre de lignes de la grille.
	 */
	int _partRow;

	/**
	 * Nombre de colonnes de la grille.
	 */
	int _partCol;

	int _n;

	/**
	 * Conteneur séquenciel des cases de la grille.
	 */
	std::vector<std::vector<std::shared_ptr<CaseValue> > > _listeCase;


public:

	/**
	 * Constructeur.
	 */
	CaseContainer(int partRow, int partCol, int n);

	/**
	 * Construction de la grille dans la vue.
	 */
	void construireGrille(wxFrame& wxf);

	/**
	 * Retourne la référence d'une case de la grille.
	 */
	std::shared_ptr<CaseValue>& lireCaseValue(int x, int y);

	/**
	 * Écrire une valeur dans une case
	 */
	void ecrireCaseValue(int x, int y, char value);

};

}}


#endif /* CASECONTAINER_HH_ */
