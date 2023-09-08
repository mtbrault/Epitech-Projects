//
// EPITECH PROJECT, 2018
// 201yams
// File description:
// main file
//

#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include "operand.hpp"

static int	isNan(const char *str, int option)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return 1;
	}
	if (option == 1)
		if (atoi(str) < 1 || atoi(str) > 6)
			return 1;
	return 0;
}

static int	error_handling(int ac, char **av)
{
	if (ac != 7) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	for (int i = 1; i <= 5; i++) {
		if (isNan(av[i], 0) == 1) {
			std::cerr << "Arguments " << av[i] << " is not a number\n";
			return 1;
		}
		else if (atoi(av[i]) < 0 || atoi(av[i]) > 6) {
			std::cerr << "A dice value is not correct\n";
			return 1;
		}
	}
	return 0;
}

std::vector<std::string>		wordtab(std::string str, char c)
{
	std::vector<std::string>	array;
	std::string			tmp;
	std::replace(str.begin(), str.end(), c, ' ');
	std::stringstream		ss(str);
	while (ss >> tmp)
		array.push_back(tmp);
	return array;
}

int	display_help()
{
	std::string	line;
	std::ifstream	file("./help");

	if (file) {
		while (getline(file, line))
			std::cout << line << std::endl;
	}
	else
		return 84;
	return 0;
}

int	main(int ac, char **av)
{
	std::vector<std::string>	cmd;

	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return display_help();
	if (error_handling(ac, av) == 1)
		return 84;
	cmd = wordtab(av[6], '_');
	if (cmd[0] == "full" && cmd.size() != 3) {
		std::cerr << "Full need 2 arguments" << std::endl;
		return 84;
	}
	else if (cmd.size() != 2 && cmd[0] != "full") {
		std::cerr << "Invalid arguments" << std::endl;
		return 84;
	}
	else if (isNan(cmd[1].c_str(), 1) != 0 || (cmd[0] == "full" && isNan(cmd[2].c_str(), 1) != 0)) {
		std::cerr << "Please, select a correct command" << std::endl;
		return 84;
	}
	else if (cmd[0] == "full" && stoi(cmd[1]) == stoi(cmd[2])) {
		std::cerr << "Same argument for full" << std::endl;
		return 84;
	}
	Operand	calc(av, cmd);
	try {
		calc.exec();
	} catch (std::exception &ex) {
		std::cerr << ex.what();
		return 84;
	}
	return 0;
}
