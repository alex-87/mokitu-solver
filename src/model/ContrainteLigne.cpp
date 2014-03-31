/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Modelisation.hh"
#include "include/ContrainteLigne.hh"
#include <gecode/int.hh>

namespace MokituSolver { namespace model {

// Initialiser les informations de base de la contrainte.
ContrainteLigne::ContrainteLigne(int partRow, int partCol, std::string& nomContrainte) :
		ContrainteAbstraite(partRow, partCol, nomContrainte) {
}

void ContrainteLigne::posterContrainte(EspaceAbstrait& m) {
	// On transforme le vecteur des valeurs en une matrice afin de
	// pouvoir traiter les colonnes avec une contraine de ligne.
	Gecode::Matrix<Gecode::IntVarArray>
	mContrainte(m._solution, (_partRow * _partCol), (_partRow * _partCol));
	for(int i=0; i < (_partRow * _partCol); i++) {
		// On pose la contrainte pour la ligne 'i'.
		Gecode::distinct(m, mContrainte.row(i));
	};
}

}}
