/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Modelisation.hh"
#include "include/ContrainteAbstraite.hh"

namespace MokituSolver { namespace model {

// Chargement de la classe-mère avec les dimensions et la taille du domaine,
// qui correspond au nombre de lettres, différente entre elles, du mot initial.
Modelisation::Modelisation(const int& partRow, const int& partCol, const int& tailleDomaine) :
		EspaceAbstrait(*this, partRow, partCol, tailleDomaine) {
}

void Modelisation::branchement() {
	// Brancher les contraintes à l'espace de résolution.
	Gecode::branch(*this,
					_solution,
					Gecode::INT_VAR_SIZE_MIN(),
					Gecode::INT_VAL_SPLIT_MIN());
}

void
Modelisation::ajouterContrainte(ContrainteAbstraite& contrainte) {
	// Poster la contrainte proposée sur l'espace actuel.
	contrainte.posterContrainte(*this);
}

std::shared_ptr<std::vector<int> >
Modelisation::resoudre(void) {
	// Rechercher les solutions via la technique de
	// "Deep-First-Search" de Gecode.
	Gecode::DFS<Modelisation> ensembleSolution( this );
	// Réccupération de la solution itérée.
	Modelisation * m = ensembleSolution.next();
	// Renvoi de la lecture de la solution trouvée.
	return m->lireSolution();
}

std::shared_ptr<std::vector<int> >
Modelisation::lireSolution(void) {
	// Initialisation d'un vecteur d'entiers
	std::vector<int> vec;
	for(int i=0; i<_solution.size(); i++) {
		// Enregistrement de la valeur dans le vecteur
		vec.push_back( _solution[i].val() );
	};
	// Encapsulation du vecteur dans un pointeur
	std::shared_ptr<std::vector<int> > res(new std::vector<int>(vec));
	// Renvoyer le pointeur
	return res;
}

Gecode::Space * Modelisation::copy(bool share) {
	// Construction d'un clone pour l'arbre de recherche
	// de Gecode.
	return new Modelisation(share, *this);
}

// Constructeur pour le clonage de l'espace de résolution Gecode.
// On appel ici le constructeur de la classe-mère, qui appelera le
// constructeur de Gecode::Space.
Modelisation::Modelisation(bool share, Modelisation& p) :
		EspaceAbstrait(share, p) {
}

}}
