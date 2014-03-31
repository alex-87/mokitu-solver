/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Presenter.hh"

#include <iostream>

namespace MokituSolver { namespace presenter {

// Configuration du Presenter à l'aide des dimensions de la grille.
Presenter::Presenter(int partRow, int partCol) :
		_partRow(partRow),
		_partCol(partCol) {

	// Chargement de la vue
	vue = new MokituSolver::view::View(*this);
	// Initialisation des widgets de celle-ci
	vue->initialiser();
}

void Presenter::enregistrerGrilleInitiale(std::vector<std::vector<char> >& u) {
	// Effacer la grille
	_grilleInitiale.clear();
	for(unsigned int i=0; i<(_partRow * _partCol); i++) {
		// Vecteur de ligne temporaire
		std::vector<int> tmp;
		for(unsigned int j=0; j<(_partRow * _partCol); j++) {
			// Lire les cases, remplacer les points par la valeur nulle
			if(u[i][j]=='.') {
				tmp.push_back( 0 );
			} else {
				// Sinon, remplacer par la correspondance
				// numérique du caractère
				tmp.push_back(
						cm->lireValeur(u[i][j])
					);
			};
		};
		// Enregistrer la ligne
		_grilleInitiale.push_back( tmp );
		// Nettoyer le vecteur
		tmp.clear();
	};
}

void Presenter::chargerCharMapper() {
	// Construire le mapper
	cm = new CharMapper(_word);
	// Construire les dictionnaires
	cm->buildMapper();
	// Lire la taille du domaine
	_tailleDomaine = cm->lireTailleDomaine();
}

void Presenter::chargerModelisationResolution() {
	// Chargement du module de résolution.
	m = new MokituSolver::model::Modelisation(_partRow, _partCol, _tailleDomaine);

	// Nom des contraintes
	std::map<int, std::string> nomContrainte;
	nomContrainte[0] = "Contrainte des colonnes";
	nomContrainte[1] = "Contrainte des lignes";
	nomContrainte[2] = "Contrainte des blocs";
	nomContrainte[3] = "Contrainte de remplissage";

	// Construction des contraintes

	// Contrainte des colonnes
	MokituSolver::model::ContrainteColonne * cCol =
			new MokituSolver::model::ContrainteColonne(
					_partRow, _partCol, nomContrainte[0]
				);
	// Contrainte des lignes
	MokituSolver::model::ContrainteLigne * cLigne =
			new MokituSolver::model::ContrainteLigne(
					_partRow, _partCol, nomContrainte[1]
				);
	// Contrainte des blocs
	MokituSolver::model::ContrainteBloc * cBloc =
			new MokituSolver::model::ContrainteBloc(
					_partRow, _partCol, nomContrainte[2]
				);
	// Contrainte des valeurs pré-remplies
	MokituSolver::model::ContrainteFilled * cFilled =
			new MokituSolver::model::ContrainteFilled(
					_partRow, _partCol, nomContrainte[3], _grilleInitiale
				);

	// Ajout des contraintes
	m->ajouterContrainte(*cCol);
	m->ajouterContrainte(*cLigne);
	m->ajouterContrainte(*cBloc);
	m->ajouterContrainte(*cFilled);

	// Branchement de l'ensemble
	m->branchement();
}

void Presenter::resolution() {
	// Obtenir le vecteur à une dimension du résultat de
	// la résolution de la grille.
	std::shared_ptr<std::vector<int> > s(m->resoudre());
	// Envoyer le résultat dans la grille de l'interface
	envoyerResultat(s);
	// Effacer l'objet du modèle
	delete( m );
}

void Presenter::chargerModelisationContruction() {

	// Chargement du module de construction.
	c = new MokituSolver::model::Construction(_grilleInitiale, _partRow, _partCol, _tailleDomaine);

	// Nom des contraintes
	std::map<int, std::string> nomContrainte;
	nomContrainte[0] = "Contrainte des colonnes";
	nomContrainte[1] = "Contrainte des lignes";
	nomContrainte[2] = "Contrainte des blocs";
	nomContrainte[3] = "Contrainte de remplissage";

	// Construction des contraintes

	// Contrainte des colonnes
	MokituSolver::model::ContrainteColonne * cCol =
			new MokituSolver::model::ContrainteColonne(
					_partRow, _partCol, nomContrainte[0]
				);
	// Contrainte des lignes
	MokituSolver::model::ContrainteLigne * cLigne =
			new MokituSolver::model::ContrainteLigne(
					_partRow, _partCol, nomContrainte[1]
				);
	// Contrainte des colonnes
	MokituSolver::model::ContrainteBloc * cBloc =
			new MokituSolver::model::ContrainteBloc(
					_partRow, _partCol, nomContrainte[2]
				);
	// Contrainte des valeurs pré-remplies
	MokituSolver::model::ContrainteFilled * cFilled =
			new MokituSolver::model::ContrainteFilled(
					_partRow, _partCol, nomContrainte[3], _grilleInitiale
				);

	// Ajout des contraintes
	c->ajouterContrainte(*cCol);
	c->ajouterContrainte(*cLigne);
	c->ajouterContrainte(*cBloc);
	c->ajouterContrainte(*cFilled);

	// Branchement de l'ensemble
	c->branchement();
}

void Presenter::construction() {
	// Construction d'une grille valide à remplir
	c->constructionMokitu();
	// Obtenir le vecteur à une dimension du résultat de
	// la résolution de la grille.
	std::shared_ptr<std::vector<int> > s(c->lireSolution());
	// Envoyer le résultat dans la grille de l'interface
	envoyerResultat(s);
	// Effacer l'objet
	delete( c );
}

void Presenter::envoyerResultat(std::shared_ptr<std::vector<int> > r) {
	// Parcours du vecteur
	for(int i=0; i < _partRow * _partCol; i++) {
		for(int j=0; j < _partRow * _partCol; j++) {
			// Écrire les valeurs  retrnscrites en caractères
			// dans chacune des cases de l'interface
			vue->_caseContainer->ecrireCaseValue(
					i,
					j,
					cm->lireCaractere(
							r->at(
									(j * _partRow * _partCol) + i )
						 	 )
					);
		};
	};
}

int
Presenter::lirePartCol() const {
	// Lire la taille d'une colonne d'un bloc
	return _partCol;
}

int
Presenter::lirePartRow() const {
	// Lire la taille d'une ligne d'un bloc
	return _partRow;
}

void
Presenter::syncActionConstruction(std::string word, std::vector<std::vector<char> >& u) {
	// Enregistrer le mot entré
	_word = word;
	// Construire le mapper à l'aide du mot
	chargerCharMapper();
	// Enregistrer la grille
	enregistrerGrilleInitiale(u);
	// Charger le modèle de la construction
	chargerModelisationContruction();
	// Construire une grille valide
	construction();
}

void
Presenter::syncActionModelisation(std::string word, std::vector<std::vector<char> >& u) {
	// Enregistrer le mot entré
	_word = word;
	// Construire le mapper à l'aide du mot
	chargerCharMapper();
	// Enregistrer la grille
	enregistrerGrilleInitiale(u);
	// Charger le modèle de résolution
	chargerModelisationResolution();
	// Résoudre
	resolution();
}

Presenter::~Presenter() {
	// Vider la mémoire
	delete( vue );
	delete( c );
	delete( m );
	delete( cm );
}

}}
