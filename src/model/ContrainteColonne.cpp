/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/ContrainteColonne.hh"
#include <gecode/int.hh>

namespace MokituSolver { namespace model {

// Initialiser les informations de base de la contrainte.
ContrainteColonne::ContrainteColonne(int partRow, int partCol, std::string& nomContrainte) :
		ContrainteAbstraite(partRow, partCol, nomContrainte) {
}

void ContrainteColonne::posterContrainte(EspaceAbstrait& m) {
	// On transforme le vecteur des valeurs en une matrice afin de
	// pouvoir traiter les colonnes avec une contraine de colonne.
	Gecode::Matrix<Gecode::IntVarArray>
	mContrainte(m._solution, (_partRow * _partCol), (_partRow * _partCol));
	for(int i=0; i < (_partRow * _partCol); i++) {
		// On pose la contrainte pour la colonne 'i'.
		Gecode::distinct(m, mContrainte.col(i));
	};
}

}}
