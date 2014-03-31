/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#include "include/CharMapper.hh"
#include <iostream>

namespace MokituSolver { namespace presenter {

// Initialisation à l'aide du mot
CharMapper::CharMapper(std::string& word) : _word(word) {
}

void
CharMapper::buildMapper() {
	// Une case nulle est un point
	_valueToChar[0] = '.';
	// Parcours des lettres du mot
	for(unsigned int i=0; i < _word.size(); i++) {
		// Remplissage du dictionnaire
		_charToValue[_word.at(i)] = (i + 1);
		// Remplissage du dictionnaire réciproque
		_valueToChar[(i + 1)] = _word.at(i);
	};
}

char
CharMapper::lireCaractere(int& valeur) {
	// Retourner le caractère correspondant
	return _valueToChar[valeur];
}

int
CharMapper::lireValeur(char& caractere) {
	// Retourner la valeur correspondante
	return _charToValue[caractere];
}

int
CharMapper::lireTailleDomaine() const {
	// Retourner la taille du domaine
	return _charToValue.size();
}

}}
