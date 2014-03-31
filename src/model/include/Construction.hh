/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONSTRUCTION_HH_
#define CONSTRUCTION_HH_

#include <gecode/int.hh>
#include <gecode/driver.hh>
#include <gecode/search.hh>

#include <vector>
#include <memory>

#include "EspaceAbstrait.hh"
#include "ContrainteAbstraite.hh"

namespace MokituSolver { namespace model {

/**
 * Classe modélisant la construction d'une grille valide
 * en fonction du mot indiqué dans la matrice passée
 * en paramètre.
 */
class Construction : public EspaceAbstrait {

protected:

	/**
	 * Matrice initiale devant être la base de
	 * construction d'une grille valide, à l'aide du
	 * mot pré-inclut.
	 */
	std::vector<std::vector<int> > _initialMatrice;

public:

	Construction * memory;

public:

	/**
	 * Enlever une lettre de la grille sans modifier la
	 * grille initiale.
	 */
	std::vector<std::vector<int> >
	enleverCase(std::vector<std::vector<int> > statique, std::vector<std::vector<int> > variable);

	/**
	 * Constructeur initialisant la grille contenant
	 * le mot placé, puis paramètrage des dimensions.
	 */
	Construction(
			std::vector<std::vector<int> > initialMatrice,
			const int& partRow,
			const int& partCol,
			const int& tailleDomaine
		);

	/**
	 * Ajouter une contrainte.
	 */
	void ajouterContrainte(ContrainteAbstraite& contrainte);

	/**
	 * Réaliser le branchement des contraintes
	 * postées sur l'espace.
	 */
	void branchement(void);

	/**
	 * Procédure de construction de la grille
	 * de Mokitu valide.
	 */
	void constructionMokitu(void);

	/**
	 * Récupérer la solution.
	 */
	std::shared_ptr<std::vector<int> > lireSolution(void) const;

	/**
	 * Cloneur de l'espace.
	 */
	Construction(bool share, Construction& p);

	/**
	 * Clonage de l'espace pour l'exploration
	 * des solutions.
	 */
	virtual Gecode::Space * copy(bool share);

	/**
	 * Viderla mémoire.
	 */
	~Construction();

};

}}

#endif /* CONSTRUCTION_HH_ */
