//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// main class
//

#ifndef TEKSPICE_HPP_
# define TESKPICE_HPP_

#include <map>
#include <unordered_map>
#include <iostream>
#include <functional>
#include <memory>
#include "Parser.hpp"

class	TekSpice
{
public:
	TekSpice(int, char **);
	~TekSpice();

	using	compMap = std::map<std::string, std::unique_ptr<nts::IComponent>>;
	void		run();
	int		changeValue(const std::string);
	static void	receiveSigint(int);
	static int	display(compMap &);
	static int	simulate(compMap &);
	static int	exit(compMap &);
	static int	loop(compMap &);
	static int	dump(compMap &);
private:
	std::string							_filename;
	std::map<std::string, std::string>				_inputValue;
        compMap								_component;
	std::unique_ptr<Parser>						_parser;
	std::unordered_map<std::string, std::function<int(compMap &)>>	_loopFunc;
};

#endif
