/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CLIENT_HH_
#define CLIENT_HH_

#include <wx/wx.h>
#include "../../presenter/include/Presenter.hh"

/**
 * Classe principale de l'application.
 */
class Client : public wxApp {

protected:

	/**
	 * Object Presenter.
	 */
	MokituSolver::presenter::Presenter * _presenter;

	/**
	 * Affiche l'aide de la ligne de commande.
	 */
	void afficherAide(wxString chemin) const;

public:

	/**
	 * Initialise l'application.
	 */
	virtual bool OnInit(void);

};

wxDECLARE_APP(Client);

#endif /* CLIENT_HH_ */
