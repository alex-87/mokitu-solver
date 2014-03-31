/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CASEVALUE_HH_
#define CASEVALUE_HH_

#include <wx/wx.h>

namespace MokituSolver { namespace view {

/**
 * Modélisation d'une cellule de
 * la matrice de l'interface graphique.
 */
class CaseValue : public wxTextCtrl {

protected:

	/**
	 * Coordonnée de l'élément.
	 */
	int _x;

	/**
	 * Coordonnée de l'élément.
	 */
	int _y;

public:

	/**
	 * Constructeur.
	 */
	CaseValue(wxFrame& wxf, int x, int y);

	/**
	 * Obtenir la valeur entrée.
	 */
	char lireValeur() const;

};

}}

#endif /* CASEVALUE_HH_ */
