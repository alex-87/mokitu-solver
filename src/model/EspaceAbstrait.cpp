/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/EspaceAbstrait.hh"

namespace MokituSolver { namespace model {

// Constructeur initialisant les dimensions, la taille du
// domaine (égale au nombre de lettres, différentes entre elles,
// du mot initiale, puis du vecteur porteur des valeurs qui
// détiendra les solutions.
EspaceAbstrait::EspaceAbstrait(Gecode::Space& s,
							   const int& partRow,
							   const int& partCol,
							   const int& tailleDomaine) :
		_partRow(partRow),
		_partCol(partCol),
		_tailleDomaine(tailleDomaine),
		_solution(s ,
				  ((partRow * partCol) * (partRow * partCol)),
				  1,
				  tailleDomaine) {

}

EspaceAbstrait::EspaceAbstrait(bool share, EspaceAbstrait& p) :
		Gecode::Space(share, p) {
	// Mise à jour du vecteur porteur des valeurs de solutions
	// lors du clonage de l'espace de résolution lors de la construction
	// de l'arbre de recherche de Gecode.
	_solution.update(*this, share, p._solution);
}

}}
