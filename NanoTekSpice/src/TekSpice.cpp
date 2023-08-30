//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// tekspice method
//

#include <string>
#include <signal.h>
#include "TekSpice.hpp"
#include "Error.hpp"

bool	sigint = false;

TekSpice::TekSpice(int ac, char **av)
	: _filename(av[1]), _parser(std::make_unique<Parser>(_filename, _component))
{
	std::string	name;
	std::string	val;
	std::string	tmp;
	std::size_t	index = 0;

	for (int i = 2; i < ac; i++) {
		tmp = av[i];
		index = tmp.find_first_of("=");
		if (index == std::string::npos)
			throw NanoError("Invalid arguments");
		name = tmp.substr(0, index);
		try {
			val = tmp.substr(index + 1);
			if (std::stoi(val) < 0 || std::stoi(val) > 1)
				throw NanoError("Input value must be 0 or 1");
		} catch (std::exception error) {
			throw NanoError("Bad input value");
		}
		_inputValue[name] = val;
	}
	_loopFunc["display"] = display;
	_loopFunc["simulate"] = simulate;
	_loopFunc["exit"] = exit;
	_loopFunc["loop"] = loop;
	_loopFunc["dump"] = dump;
	signal(SIGINT, receiveSigint);
}

TekSpice::~TekSpice()
{
}

void	TekSpice::receiveSigint(int signal)
{
	(void) signal;
	sigint = false;
}

int	TekSpice::changeValue(const std::string cmd)
{
        size_t		index = 0;
	std::string	comp;
	std::string	value;

	index = cmd.find_first_of("=");
	if (index == std::string::npos)
		return -1;
	comp = cmd.substr(0, index);
	value = cmd.substr(index + 1);
	if (!_component[comp] || _component[comp]->getType() == "output")
		return -1;
	try {
		if (std::stoi(value) < 0 || std::stoi(value) > 1)
			return -1;
	        _component[comp]->setValue(std::stoi(value));
	} catch (const std::exception error) {
		return -1;
	}
	return 0;
}

int	TekSpice::display(std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
        for (auto i = map.begin(); i != map.end(); i++) {
		if (i->second->getType() == "output") {
			std::cout << i->first << "=";
			if (i->second->compute() == nts::Tristate::UNDEFINED)
				std::cout << "U" << std::endl;
			else
				std::cout << i->second->compute() << std::endl;
		}
	}
	return 0;
}

int	TekSpice::exit(std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
        (void) map;
	return 1;
}

int	TekSpice::loop(std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
	sigint = true;
	while (sigint == true) {
		simulate(map);
	}
	return 0;
}

int	TekSpice::simulate(std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
	for (auto i = map.begin(); i != map.end(); i++) {
		if (i->second->getType() == "output")
			i->second->setValue(0);
	}
	for (auto i = map.begin(); i != map.end(); i++) {
		if (i->second->getType() == "clock")
			i->second->setValue(nts::Tristate::UNDEFINED);
	}
	return 0;
}

int	TekSpice::dump(std::map<std::string, std::unique_ptr<nts::IComponent>> &map)
{
	for (auto i = map.begin(); i != map.end(); i++) {
		std::cout << i->first << ":" << std::endl;
		i->second->dump();
	}
	return 0;
}

void	TekSpice::run()
{
	std::string	cmd;

	_parser->set_MapArgs(_inputValue);
	try {
		_parser->parsing_manager();
		simulate(_component);
		display(_component);
	} catch (const NanoError error) {
		throw error;
	}
	std::cout << "> ";
	while (std::cin >> cmd) {
		if (!_loopFunc[cmd]) {
			if (changeValue(cmd) == -1)
				std::cerr << "Command \"" << cmd << "\" is invalid" << std::endl;
		}
	        else
			if (_loopFunc[cmd](_component) == 1)
				break ;
		std::cout << "> ";
	}
}
