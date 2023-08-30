//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser header
//

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "Factory.hpp"

class	Parser {
public:
	using	compMap = std::map<std::string, std::unique_ptr<nts::IComponent>> &;
	Parser(const std::string &fname, compMap);
	virtual ~Parser();

	void	parsing_manager();
	void	parsing_chipsets(std::vector<std::string> chipsets);
	void	parsing_links(std::vector<std::string> links);
	void	set_MapArgs(std::map<std::string, std::string> input_args);

protected:
	std::string _fname;
	std::map<std::string, std::string> _input_args;
        compMap	_component;
};
