/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/BtnAbout.hh"

namespace MokituSolver { namespace view {

// Enregistrement du bouton dans la table des êvenements
BEGIN_EVENT_TABLE(BtnAbout, wxButton)
	EVT_BUTTON(wxID_ANY, BtnAbout::OnClick)
END_EVENT_TABLE()

// Constructeur du bouton
BtnAbout::BtnAbout(wxFrame& wxf) :
	wxButton(&wxf,
			 wxID_ANY,
			 _T("À Propos..."),
			 wxPoint(5, 5),
			 wxSize(120, 30)
			 ) {
}

void
BtnAbout::OnClick(wxCommandEvent& event) {
	// Action
	wxMessageBox(wxT("Mokitu Solver - Alexis LE GOADEC, Master 1 Informatique DECIM\r\n\r\nProgrammation par contraintes - 2013/2014."));
}

}}
