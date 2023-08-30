//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser file
//

#include <sstream>
#include <stdio.h>
#include "Error.hpp"
#include "Parser.hpp"

Parser::Parser(const std::string &fname, std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
	: _fname(fname), _component(map)
{
}

Parser::~Parser()
{
}

void	Parser::set_MapArgs(std::map<std::string, std::string> input_args)
{
	_input_args = input_args;
}

void	epur(std::string &s)
{
	bool space = false;

	auto p = s.begin();
	for (auto ch : s)
		if (std::isspace(ch)) {
			space = p != s.begin();
		} else {
			if (space) *p++ = ' ';
			*p++ = ch;
			space = false; }
	s.erase(p, s.end());
}

void	Parser::parsing_chipsets(std::vector<std::string> chipsets)
{
	std::string	type;
	std::string	name;
        std::size_t	index = 0;
	Factory		f;

	for (auto i = chipsets.begin(); i != chipsets.end(); ++i) {
	        epur(*i);
		index = (*i).find_first_of(' ');
	        name = (*i).substr(index + 1);
	        type = (*i).substr(0, index);
		if (_component[name])
			throw NanoError(name + ": 2 components share this name");
		if (type == "input" || type == "clock") {
			if (_input_args.find(name) == _input_args.end())
				throw NanoError("Component " + name + " is not initialized");
		}
		if ((_component[name] = f.createComponent(type, _input_args[name])) == NULL)
			throw NanoError(type + "is an invalid type");
	}
}

void	split_str(std::string part1, std::string &comp, std::string &pin, char c)
{
	std::size_t	index = 0;

	index = part1.find_first_of(c);
	if (index == std::string::npos)
		throw NanoError("Bad links");
	pin = part1.substr(index + 1);
        comp = part1.substr(0, index);
}

void	Parser::parsing_links(std::vector<std::string> links)
{	
	std::string     part1;
	std::string     part2;
	std::string	comp;
	std::string	pin;
	std::string	comp2;
	std::string	pin2;
	std::size_t	index = 0;

	for (auto i = links.begin(); i != links.end(); ++i) {
		epur(*i);
		index = (*i).find_first_of(' ');
	        part1 = (*i).substr(index + 1);
	        part2 = (*i).substr(0, index);
		split_str(part1, comp, pin, ':');
		split_str(part2, comp2, pin2, ':');
		if (_component.find(comp2) == _component.end())
			throw NanoError("Component " + comp2 + " is not initialized");
		if (_component.find(comp) == _component.end())
			throw NanoError("Component " + comp + " is not initialized");
		try {
			if ((size_t)std::stoi(pin2) > _component[comp2]->getMaxPin() || (size_t)std::stoi(pin2) <= 0)
				throw NanoError("Pin is to high");
			if ((size_t)std::stoi(pin) > _component[comp]->getMaxPin() || (size_t)std::stoi(pin) <= 0)
				throw NanoError("Pin is to high");
		} catch (std::exception &ex) {
			throw NanoError("Pin is invalid");
		}
		try {
			_component[comp2]->setLink((size_t) std::stoi(pin2), *_component[comp],(size_t) std::stoi(pin));
		} catch (const NanoError exception) {
			throw exception;
		}
	}
	
}

void	Parser::parsing_manager()
{
	std::ifstream	File(_fname);
	std::string	line;
        bool	cpy_chipsets = false;
	bool	cpy_links = false;
	std::vector<std::string> chipsets;
	std::vector<std::string> links;

	if (!File.is_open()) {
		throw NanoError("File cannot be open");
	}
	while (getline(File, line)) {
		if (line.length() != 0) {
			if ((line.at(0) != '#' and line != ".chipsets:" and line.at(0) != '\n' and line == ".links:") and cpy_chipsets != true)
				throw NanoError("Syntax error : " + line);
			if (line == ".chipsets:")
				cpy_chipsets = true;
			if (line == ".links:")
				cpy_links = true;
			if (cpy_chipsets == true && cpy_links == false && line != ".chipsets:" && line != ".links:")
				chipsets.push_back(line);
			if (cpy_chipsets == true && cpy_links == true && line != ".chipsets:" && line != ".links:")
				links.push_back(line);
		}
	}
	if (chipsets.size() == 0)
		throw NanoError("Bad file");
	parsing_chipsets(chipsets);
	parsing_links(links);
}
