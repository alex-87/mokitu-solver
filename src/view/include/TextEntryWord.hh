/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef TEXTENTRYWORD_HH_
#define TEXTENTRYWORD_HH_

#include <wx/wx.h>

namespace MokituSolver { namespace view {

class TextEntryWord : public wxTextCtrl {

protected:

	/**
	 * Coordonnée.
	 */
	int _x;

	/**
	 * Coordonnée.
	 */
	int _y;

public:

	/**
	 * Constructeur.
	 */
	TextEntryWord(wxFrame& wxf, int x, int y);

	std::string lireMot() const;

};

}}

#endif /* TEXTENTRYWORD_HH_ */
