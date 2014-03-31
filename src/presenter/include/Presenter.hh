/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef PRESENTER_HH_
#define PRESENTER_HH_

#include <string>
#include <vector>

#include "CharMapper.hh"

#include "../../model/include/ContrainteLigne.hh"
#include "../../model/include/ContrainteColonne.hh"
#include "../../model/include/ContrainteBloc.hh"
#include "../../model/include/ContrainteFilled.hh"
#include "../../model/include/Modelisation.hh"
#include "../../model/include/Construction.hh"

#include "../../view/include/View.hh"


namespace MokituSolver { namespace presenter {

/**
 * Modélisation du Presenter de l'application MVP.
 */
class Presenter {

protected:

	/**
	 * Objet de la vue.
	 */
	MokituSolver::view::View * vue;

	/**
	 * Objet de résolution d'une grille.
	 */
	MokituSolver::model::Modelisation * m;

	/**
	 * Objet de construction d'une grille.
	 */
	MokituSolver::model::Construction * c;

	/**
	 * Mapper entre les nombres et
	 * les lettres.
	 */
	CharMapper * cm;

	/**
	 * La taille de l'alphabet.
	 */
	int _tailleDomaine;

	/**
	 * Ensemble des lettres.
	 */
	std::string _word;

	/**
	 * Grille initiale.
	 */
	std::vector<std::vector< int> > _grilleInitiale;

	/**
	 * Taille de la ligne d'un bloc de la grille.
	 */
	int _partRow;

	/**
	 * Taille de la colonne d'un bloc de la grille.
	 */
	int _partCol;

protected:

	/**
	 * Charger le mapper.
	 */
	void chargerCharMapper();

	/**
	 * Enregistre la grille initiale. Par convention, lorsqu'il
	 * y a un point ('.'), c'est une case à compléter, et un
	 * zéro dans la matrice initiale.
	 */
	void enregistrerGrilleInitiale(std::vector<std::vector<char> >& u);

	/**
	 * Injecter le resultat vers la grille de l'interface.
	 */
	void envoyerResultat(std::shared_ptr<std::vector<int> > r);

public:

	/**
	 * Lire la taille de la ligne d'un bloc de la grille.
	 */
	int lirePartRow() const;

	/**
	 * Lire la taille de la colonne d'un bloc de la grilel.
	 */
	int lirePartCol() const;


public:

	/**
	 * Constructeur par défaut.
	 */
	Presenter(int partRow, int partCol);

	/**
	 * Charger le modèle de résolution d'une grille de
	 * Mokitu.
	 */
	void chargerModelisationResolution();

	/**
	 * Résoudre la grille de Mokitu chargée.
	 */
	void resolution();

	/**
	 * Charger le modèle de construction d'une grille
	 * de Mokitu valide.
	 */
	void chargerModelisationContruction();

	/**
	 * Construire la grille.
	 */
	void construction();

	/**
	 * Action de la vue lors de l'appuie sur "Construction".
	 */
	void syncActionConstruction(std::string word, std::vector<std::vector<char> >& u);

	/**
	 * Action de la vue lors de l'appuie sur "Modelisation".
	 */
	void syncActionModelisation(std::string word, std::vector<std::vector<char> >& u);

	/**
	 * Vider la mémoire.
	 */
	~Presenter();
};

}}

#endif /* PRESENTER_HH_ */
