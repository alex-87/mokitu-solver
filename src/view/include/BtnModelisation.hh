/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef BTNMODELISATION_HH_
#define BTNMODELISATION_HH_

#include <wx/wx.h>
#include "View.hh"

namespace MokituSolver { namespace view {

/**
 * Bouton "Modélisation".
 */
class BtnModelisation : public wxButton {

protected:

	/**
	 * Vue en cours.
	 */
	View& _view;

public:

	BtnModelisation(wxFrame& wxf, View& view);

	void OnClick(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()

};

}}

#endif /* BTNMODELISATION_HH_ */
