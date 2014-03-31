/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Modelisation.hh"
#include "include/ContrainteFilled.hh"
#include <gecode/int.hh>

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

// Initialiser les informations de base de la contrainte.
ContrainteFilled::ContrainteFilled(int partRow,
										int partCol,
										std::string& nomContrainte,
										std::vector<std::vector<int> > fill) :
		ContrainteAbstraite(partRow, partCol, nomContrainte),
		_fill(fill) {
}

void ContrainteFilled::posterContrainte(EspaceAbstrait& m) {
	// On transforme le vecteur des valeurs en une matrice.
	Gecode::Matrix<Gecode::IntVarArray>
	mContrainte(m._solution, (_partRow * _partCol), (_partRow * _partCol));
	// Pour chaque case de la matrice, on fixe la valeur initiale (répertoriée
	// dans '_fill', à l'aide d'une relation d'équité.
	for(int i=0; i<(_partRow * _partCol); i++) {
		for(int j=0; j<(_partRow * _partCol); j++) {
			if( _fill[i][j]!=0 ) {
				// Geler la valeur pré-remplie de la case.
				Gecode::rel(m,
							mContrainte(i, j),
							Gecode::IRT_EQ, _fill[i][j]
						);
			};
		};
	};
}

}}
