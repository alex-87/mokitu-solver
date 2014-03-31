/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONTRAINTEABSTRAITE_HH_
#define CONTRAINTEABSTRAITE_HH_

#include <string>
#include <gecode/driver.hh>

#include "EspaceAbstrait.hh"


// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

/**
 * Classe abstraite de modélisation des
 * contraintes à poster dans l'espace de
 * résolution.
 */
class ContrainteAbstraite {

protected:

	/**
	 * Taille de la ligne d'un compartiment.
	 */
	int _partRow;

	/**
	 * Taille de la colonne d'un compartiment.
	 */
	int _partCol;

	/**
	 * Nom de la contrainte.
	 */
	std::string _nomContrainte;

public:

	/**
	 * Constructeur paramétré.
	 */
	ContrainteAbstraite(int partRow, int partcol, std::string& nomContrainte);

	/**
	 * Obtenir le nom de la contrainte.
	 */
	std::string lireNomContrainte() const;

	/**
	 * Modifie la taille.
	 */
	void ecrireTaille(int partRow, int partCol);

	/**
	 * Retourne la taille.
	 */
	int lireTaile() const;

	/**
	 * Poster la contrainte dans l'espace de
	 * résolution.
	 */
	virtual void posterContrainte(EspaceAbstrait& m) = 0;

	/**
	 * Destructeur virtuel.
	 */
	virtual ~ContrainteAbstraite();
};

}}

#endif /* CONTRAINTEABSTRAITE_HH_ */
