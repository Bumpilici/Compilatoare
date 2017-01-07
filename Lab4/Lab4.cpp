#include <iostream>
#include <fstream>

#include "Grammar.hpp"

Grammar readGrammarFile()
{
	Grammar l_grammar;
	std::ifstream l_file("grammar.txt");

	if (l_file.is_open())
	{
		std::string l_line;
		int l_number;

		std::getline(l_file, l_line);
		l_number = std::stoi(l_line, nullptr, 10);
		for (int i = 0; i < l_number; i++)
		{
			std::getline(l_file, l_line);
			l_grammar.addNonterminal(l_line[0]);
		}

		std::getline(l_file, l_line);
		l_number = std::stoi(l_line, nullptr, 10);
		for (int i = 0; i < l_number; i++)
		{
			std::getline(l_file, l_line);
			l_grammar.addTerminal(l_line[0]);
		}

		std::getline(l_file, l_line);
		l_number = std::stoi(l_line, nullptr, 10);
		for (int i = 0; i < l_number; i++)
		{
			std::getline(l_file, l_line);
			l_grammar.addProduction(l_line);
		}

		std::getline(l_file, l_line);
		l_grammar.addStartingSymbol(l_line[0]);
	}

	l_file.close();

	return l_grammar;
}

int main()
{
	Grammar l_grammar;
	l_grammar = readGrammarFile();

	std::cout << "Grammar G = (N, M, P, " << l_grammar.getStartingSymbol() << "): " << std::endl;
	std::cout << "N = { " + l_grammar.getNonterminals() + "} " << std::endl;
	std::cout << "M = { " + l_grammar.getTerminals() + "} " << std::endl;
	std::cout << "P: " << std::endl << l_grammar.getProductions() << std::endl;

	return 0;
}