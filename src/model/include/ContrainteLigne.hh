/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONTRAINTELIGNE_HH_
#define CONTRAINTELIGNE_HH_

#include "ContrainteAbstraite.hh"

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

/**
 * Modélisation de la contrainte d'une valeur
 * unique par ligne.
 */
class ContrainteLigne : public ContrainteAbstraite {

protected:

public:

	ContrainteLigne(int partRow, int partCol, std::string& nomContrainte);

	void posterContrainte(EspaceAbstrait& m);

};

}}

#endif /* CONTRAINTELIGNE_HH_ */
