/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Construction.hh"


namespace MokituSolver { namespace model {

// Ce constructeur charge la classe-mère ainsi que la matrice
// initiale (celle contenant le mot fixé).
Construction::Construction(std::vector<std::vector<int> > initialMatrice,
						   	  const int& partRow,
						   	  const int& partCol,
						   	  const int& tailleDomaine) :
		EspaceAbstrait(*this, partRow, partCol, tailleDomaine),
		_initialMatrice(initialMatrice) {
}

void Construction::branchement() {
	// Brancher les contraintes à l'espace de résolution.
	Gecode::branch(*this, _solution,
					Gecode::INT_VAR_SIZE_MIN(),
					Gecode::INT_VAL_SPLIT_MIN());
}

void Construction::constructionMokitu() {

	// Rechercher les solutions via la technique de
	// "Deep-First-Search" de Gecode.
	Gecode::DFS<Construction> p(this);

	// Mémoriser la solution précédente. Ce procédé permet de
	// garder en mémoire la grille en construction de façon à ne
	// réccupérer que celle avant que la solution finale soit trouvée.
	// Ainsi, cette grille est donc une grille de Mokitu valide à remplir.
	// On l'insert donc en mémoire dans l'avant dernier objet créé par l'arbre
	// de recherche, et on y accède ensuite pour le renvoyer dans la grille
	// de l'interface.
	_solution = p.next()->memory->_solution;
}

void
Construction::ajouterContrainte(ContrainteAbstraite& contrainte) {
	// Poster la contrainte proposée sur l'espace actuel.
	contrainte.posterContrainte(*this);
}

std::shared_ptr<std::vector<int> >
Construction::lireSolution(void) const {
	// Initialisation d'un vecteur
	std::vector<int> vec;
	// Bouclage sur le vecteur des valeurs de la solution
	for(int i=0; i<_solution.size(); i++) {
		// On test s'il s'agit d'une solution (taille à 1),
		// ou bien d'une case vide à remplir par le joueur.
		if( _solution[i].size() == 1 ) {
			// Enregistrement de la valeur
			vec.push_back( _solution[i].val() );
		} else {
			// Enregistrement d'une case vide.
			vec.push_back(0);
		};
	};
	// Encapsulation du vecteur dans un pointeur
	std::shared_ptr<std::vector<int> > res(new std::vector<int>(vec));
	// Renvoyer le pointeur
	return res;
}

Gecode::Space * Construction::copy(bool share) {
	// Construction d'un clone pour l'arbre de recherche
	// de Gecode.
	Construction * c = new Construction(share, *this);
	// Enregistrement d'une grille avant le noeud suivant.
	memory = c;
	// Retourner l'objet cloné
	return c;
}

// Constructeur pour le clonage de l'espace de résolution Gecode.
// On appel ici le constructeur de la classe-mère, qui appelera le
// constructeur de Gecode::Space.
Construction::Construction(bool share, Construction& p) :
		EspaceAbstrait(share, p) {
}

Construction::~Construction() {
}

}}
