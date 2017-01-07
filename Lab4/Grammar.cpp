#include "Grammar.hpp"

Grammar::Grammar()
{
}

void Grammar::addNonterminal(char f_nonterminal)
{
	m_nonterminals.push_back(f_nonterminal);
}

void Grammar::addTerminal(char f_terminal)
{
	m_terminals.push_back(f_terminal);
}

void Grammar::addProduction(std::string f_production)
{
	std::regex l_productionRegex("[A-Z]->(([A-Za-z0-9*()+]*\\|)*[a-zA-Z0-9*()+]*|[0-9a-zA-Z*()+]*)");

	if (std::regex_match(f_production, l_productionRegex))
	{
		if (m_productions.find(f_production[0]) == m_productions.end())
		{
			m_productions.emplace(f_production[0], f_production.substr(3, f_production.size() - 3));
		}
		else
		{
			auto it = m_productions.find(f_production[0]);
			it->second += "|";
			it->second += f_production.substr(3, f_production.size() - 3);
		}
	}
}

void Grammar::addStartingSymbol(char f_startingSymbol)
{
	m_startingSymbol = f_startingSymbol;
}

std::string Grammar::getNonterminals()
{
	std::string l_string = "";

	for (auto it = m_nonterminals.begin(); it != m_nonterminals.end(); ++it)
	{
		l_string += *it;
		l_string += " ";
	}

	return l_string;
}

std::string Grammar::getTerminals()
{
	std::string l_string = "";

	for (auto it = m_terminals.begin(); it != m_terminals.end(); ++it)
	{
		l_string += *it;
		l_string += " ";
	}

	return l_string;
}

std::string Grammar::getProductions()
{
	std::string l_string = "";

	for (auto it = m_productions.begin(); it != m_productions.end(); ++it)
	{
		l_string += it->first;
		l_string += "->";
		l_string += it->second;
		l_string += "\n";
	}

	return l_string;
}

std::string Grammar::getStartingSymbol()
{
	std::string l_string = "";

	l_string += m_startingSymbol;

	return l_string;
}

std::string Grammar::getProduction(char f_nonterminal)
{
	std::string l_string = "";

	l_string += f_nonterminal;
	l_string += "->";
	l_string += m_productions[f_nonterminal];

	return l_string;
}

Grammar::~Grammar()
{
}

void Grammar::split(std::string f_string, char f_delimitator, std::vector<std::string>& f_result)
{
	std::string l_item;
	std::stringstream l_stringStream;
	l_stringStream.str(f_string);

	while (std::getline(l_stringStream, l_item, f_delimitator))
	{
		f_result.push_back(l_item);
	}
}

bool Grammar::isNonterminal(char f_symbol)
{
	for (std::vector<char>::iterator it = m_nonterminals.begin(); it != m_nonterminals.end(); ++it)
	{
		if (f_symbol == *it)
		{
			return true;
		}
	}

	return false;
}