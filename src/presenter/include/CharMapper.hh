/*
 * MokituSolver - PPC
 *
 * Alexis LE GOADEC
 * M1 Informatique - DECIM
 *
 */

#ifndef CHARMAPPER_HH_
#define CHARMAPPER_HH_

#include <string>
#include <map>

namespace MokituSolver { namespace presenter {

/**
 * Classe de traduction des valeurs et
 * caractères.
 */
class CharMapper {


protected:

	/**
	 * Mot dont l'ensemble des lettres forme
	 * l'alphabet de l'instance de Mokitu.
	 */
	std::string& _word;

	/**
	 * Correspondance valeur-caractèrre
	 */
	std::map<int, char> _valueToChar;

	/**
	 * Correspondance caractère-valeur
	 */
	std::map<char, int> _charToValue;

public:

	/**
	 * Constructeur configurant les caractères.
	 */
	CharMapper(std::string& word);

	/**
	 * Construire les tables de correspondance.
	 */
	void buildMapper();

	/**
	 * Obtenir le caractère en fonction
	 * de la valeur numérique.
	 */
	char lireCaractere(int& valeur);

	/**
	 * Obtenir la valeur numérique en fonction
	 * du caractère.
	 */
	int lireValeur(char& caractere);

	/**
	 * Obtenir la taille de l'alphabet.
	 */
	int lireTailleDomaine() const;

};

}}

#endif /* CHARMAPPER_HH_ */
