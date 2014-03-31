/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONTRAINTEFILLED_HH_
#define CONTRAINTEFILLED_HH_

#include "ContrainteAbstraite.hh"

#include <vector>

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

/**
 * Modélise la contrainte indiquant de ne pas
 * modifier les valeurs déjà présente dans la grille.
 */
class ContrainteFilled : public ContrainteAbstraite {

protected:

	std::vector<std::vector< int> > _fill;

public:

	ContrainteFilled(int partRow,
						int partCol,
						std::string& nomContrainte,
						std::vector<std::vector<int> > fill);

	void posterContrainte(EspaceAbstrait& m);

};

}}

#endif /* CONTRAINTEFILLED_HH_ */
