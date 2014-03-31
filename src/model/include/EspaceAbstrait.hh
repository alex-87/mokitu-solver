/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef ESPACEABSTRAIT_HH
#define ESPACEABSTRAIT_HH

#include <gecode/int.hh>
#include <gecode/search.hh>

namespace MokituSolver { namespace model {

/**
 * Modélisation commune du problème de résolution
 * et de construction d'une grille de Mokitu.
 */
class EspaceAbstrait : public Gecode::Space {

protected:

	/**
	 * Taille de la ligne d'un bloc de la grille.
	 */
	int _partRow;

	/**
	 * Taille de la colonne d'un bloc de la grille.
	 */
	int _partCol;

	/**
	 * La taille de l'alphabet, qui correspond
	 * ici à la taille du domaine de chacune des
	 * variables de la grille du Mokitu.
	 */
	int _tailleDomaine;


public:

	/**
	 * Sortie de la solution.
	 */
	Gecode::IntVarArray _solution;

public:

	EspaceAbstrait(Gecode::Space& s,
				     const int& partRow,
				     const int& partCol,
				     const int& tailleDomaine);
	/**
	 * Constructeur de copie.
	 */
	EspaceAbstrait(bool share, EspaceAbstrait& p);
};

}}

#endif
