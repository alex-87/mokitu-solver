/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef BTNCONSTRUCTION_HH_
#define BTNCONSTRUCTION_HH_

#include <wx/wx.h>
#include "View.hh"

namespace MokituSolver { namespace view {

/**
 * Bouton "Construction".
 */
class BtnConstruction : public wxButton {

protected:

	/**
	 * Vue en cours.
	 */
	View& _view;

public:

	BtnConstruction(wxFrame& wxf, View& view);

	void OnClick(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()

};

}}

#endif /* BTNCONSTRUCTION_HH_ */
