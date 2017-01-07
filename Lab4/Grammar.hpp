#ifndef ___GRAMMAR___
#define ___GRAMMAR___

#include <vector>
#include <map>
#include <regex>
#include <sstream>
#include <iostream>
#include <set>

class Grammar
{

public:

	//Use e as epsilon.
	Grammar();

	void addNonterminal(char f_nonterminal);

	void addTerminal(char f_terminal);

	void addProduction(std::string f_production);

	void addStartingSymbol(char f_startingSymbol);

	std::string getNonterminals();

	std::string getTerminals();

	std::string getProductions();

	std::string getStartingSymbol();

	std::string getProduction(char f_nonterminal);

	~Grammar();

private:

	void split(std::string f_string, char f_delimitator, std::vector<std::string>& f_result);
	bool isNonterminal(char f_symbol);

	std::vector<char> m_nonterminals;
	std::vector<char> m_terminals;
	std::map<char, std::string> m_productions;
	char m_startingSymbol;

};

#endif