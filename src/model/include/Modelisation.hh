/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef MODELISATION_HH
#define MODELISATION_HH

#include <gecode/int.hh>
#include <gecode/driver.hh>
#include <gecode/search.hh>

#include <vector>
#include <memory>

#include "EspaceAbstrait.hh"

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

class ContrainteAbstraite;

/**
 * Classe de modélisation du problème
 * selon la recomputation d'espace de Gecode.
 */
class Modelisation : public EspaceAbstrait {

public:

	/**
	 * Constructeur du problème.
	 */
	Modelisation(const int& partRow,
				   const int& partCol,
				   const int& tailleDomaine);

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
	 * Lancement de la résolution du système.
	 */
	std::shared_ptr<std::vector<int> > resoudre(void);

	/**
	 * Récupérer la solution.
	 */
	std::shared_ptr<std::vector<int> > lireSolution(void);

	/**
	 * Cloneur de l'espace.
	 */
	Modelisation(bool share, Modelisation& p);

	/**
	 * Clonage de l'espace pour l'exploration
	 * des solutions.
	 */
	virtual Gecode::Space * copy(bool share);

};

}}

#endif
