/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONTRAINTECOLONNE_HH_
#define CONTRAINTECOLONNE_HH_

#include "ContrainteAbstraite.hh"

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

/**
 * Modélisation de la contrainte d'une valeur
 * unique par colonne.
 */
class ContrainteColonne : public ContrainteAbstraite {

protected:

public:

	ContrainteColonne(int partRow, int partCol, std::string& nomContrainte);

	void posterContrainte(EspaceAbstrait& m);

};

}}

#endif /* CONTRAINTECOLONNE_HH_ */
