/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/ContrainteAbstraite.hh"

namespace MokituSolver { namespace model {

ContrainteAbstraite::~ContrainteAbstraite() {
}

// Initialiser la contrainte à l'aide des dimensions des blocs
// de la grille, en plus du nom de la contrainte.
ContrainteAbstraite::ContrainteAbstraite(int partRow, int partCol,std::string& nomContrainte) :
		_partRow(partRow),
		_partCol(partCol),
		_nomContrainte(nomContrainte) {
}

std::string
ContrainteAbstraite::lireNomContrainte() const {
	// Retourner le nom de la contrainte.
	return _nomContrainte;
}

void ContrainteAbstraite::ecrireTaille(int partRow, int partCol) {
	// Modifier la taille de l'absisse des colonnes d'un bloc.
	_partRow = partRow;
	// Modifier la taille de l'ordonnée des lignes d'un bloc.
	_partCol = partCol;
}

int ContrainteAbstraite::lireTaile() const {
	// Retourner la taille d'un côté de la grille.
	return (_partRow * _partCol);
}

}}
