/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef BTNABOUT_HH_
#define BTNABOUT_HH_

#include <wx/wx.h>

namespace MokituSolver { namespace view {

/**
 * Bouton "À Propos".
 */
class BtnAbout : public wxButton {

protected:

public:

	BtnAbout(wxFrame& wxf);

	void OnClick(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()

};

}}


#endif /* BTNABOUT_HH_ */
