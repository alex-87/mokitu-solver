/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/Client.hh"

wxIMPLEMENT_APP(Client);

void Client::afficherAide(wxString chemin) const {
	// Afficher le message d'aide à l'entrée des paramêtres.
	wxMessageBox("Mokitu Solver - Alexis LE GOADEC\r\n\r\nUsage: " + chemin + " <partCol> <partRow>",
				 "Mokitu Solver - usage",
				 wxOK | wxICON_INFORMATION );
}

bool Client::OnInit(void) {

	// Tester le nombre d'arguments.
	if( argc != 3 || !argv[1].IsNumber() || !argv[2].IsNumber() ) {
		afficherAide(argv[0]);
		// Ne pas ouvrir la fenêtre principale (quitter).
		return false;
	};

	// Initialiser les variables correspondant
	// au nombre de lignes et de colonnes
	// PAR BLOCS !
	long partRow = 0;
	long partCol = 0;

	// Réccupération et traduction des paramêtres
	// en nombre.
	argv[1].ToLong(&partRow, 10);
	argv[2].ToLong(&partCol, 10);

	// Charger le module Presenter de l'application.
	_presenter = new MokituSolver::presenter::Presenter((int)partRow, (int)partCol);

	// Retourner la valeur True afin d'indiquer au programme
	// que le lancement de la fenêtre principale peut
	// s'effectuer.
	return true;
}
