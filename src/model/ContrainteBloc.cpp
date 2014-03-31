/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/ContrainteBloc.hh"
#include <gecode/int.hh>

namespace MokituSolver { namespace model {

// Initialiser les informations de base de la contrainte.
ContrainteBloc::ContrainteBloc(int partRow, int partCol, std::string& nomContrainte) :
		ContrainteAbstraite(partRow, partCol, nomContrainte) {
}

void ContrainteBloc::posterContrainte(EspaceAbstrait& m) {

	// Dans le cadre d'une contrainte d'un bloc, on modélise le
	// veteur des valeurs en une matrice.
	Gecode::Matrix<Gecode::IntVarArray>
	mContrainte(m._solution, (_partRow * _partCol), (_partRow * _partCol));

	// Pour chaque bloc, on indique une contrainte de type ALL_DIFERENT
	// pour chacun des blocs de la matrice.
	for (int i=0; i<(_partCol); i++) {
		for (int j=0; j<(_partRow); j++) {
			distinct(m,
					  mContrainte.slice(j * _partCol,
							  	  	    j * _partCol + _partCol,
							  	  	    i * _partRow,
							  	  	    i * _partRow + _partRow));
		}
	}
}

}}
