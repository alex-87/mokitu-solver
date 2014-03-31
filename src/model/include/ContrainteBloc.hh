/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CONTRAINTEBLOC_HH_
#define CONTRAINTEBLOC_HH_

#include "ContrainteAbstraite.hh"

// Encapsulation dans le package 'model'
namespace MokituSolver { namespace model {

/**
 * Classe modéliant un bloc "c * c", sous la contrainte
 * que chacune des valeurs appartenant au bloc est unique
 * à l'interieur de ce bloc.
 */
class ContrainteBloc : public ContrainteAbstraite {

protected:

public:

	ContrainteBloc(int partRow, int partCol, std::string& nomContrainte);

	void posterContrainte(EspaceAbstrait& m);

};

}}

#endif /* CONTRAINTEBLOC_HH_ */
