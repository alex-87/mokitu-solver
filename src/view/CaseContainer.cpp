/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/CaseContainer.hh"

namespace MokituSolver { namespace view {

// Construction du conteneur de cases de la grille selon les dimensions
CaseContainer::CaseContainer(int partRow, int partCol, int n) :
		_partRow(partRow),
		_partCol(partCol),
		_n(n) {
}

void
CaseContainer::construireGrille(wxFrame& wxf) {
	// Précision des offsets
	int x_offset = 5;
	int y_offset = 100;
	// Effacer la liste (au cas où).
	_listeCase.clear();
	for(int i=0; i<(_partRow * _partCol); i++) {
		// Vecteur temporaire de ligne
		std::vector<std::shared_ptr<CaseValue> > tmp;
		for(int j=0; j<(_partRow * _partCol); j++) {
			// Création d'une case encapsulée dans un pointeur
			std::shared_ptr<CaseValue> c(
					new CaseValue(wxf, x_offset + (i * 30) , y_offset + (j * 30))
				);
			// Enregistrement du pointeur dans la ligne
			tmp.push_back(
					c
				);
		};
		// Enregistrement de la ligne
		_listeCase.push_back( tmp );
	};
}

std::shared_ptr<CaseValue>&
CaseContainer::lireCaseValue(int x, int y) {
	// Lire une entrée de l'utilisateur
	return _listeCase[x][y];
}

void
CaseContainer::ecrireCaseValue(int x, int y, char value) {
	//Nettoyer la case
	_listeCase[x][y]->Clear();
	// Si ce n'est pas une valeur nulle
	if(value!='.') {
		// Écrire la valeur indiquée dans la case
		*_listeCase[x][y] << value;
	};
}

}}
