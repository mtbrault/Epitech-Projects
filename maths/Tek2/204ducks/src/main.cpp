//
// EPITECH PROJECT, 2018
// 204ducks
// File description:
// main file
//

#include <fstream>
#include <iostream>
#include "ducks.hpp"

int	display_help()
{
	std::ifstream	file("usage.txt");
	std::string	line;

	if (file) {
		while (getline(file, line))
			std::cout << line << std::endl;
	}
	return 0;
}

int	check_is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			if (str[i] != '.')
				return 1;
		}
	}
	return 0;
}

int	main(int ac, char **av)
{
	double	a;

	if (ac != 2) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 84;
	}
	if ((std::string)av[1] == "-h")
		return display_help();
	if (check_is_number(av[1]) == 1) {
		std::cerr << "The first argument must be a number" << std::endl;
		return 84;
	}
	a = std::stof(av[1]);
	if (a < 0 || a > 2.5) {
		std::cerr << "a must be between 0 and 2.5" << std::endl;
		return 84;
	}
	Ducks	duck(a);
	duck.average_time();
	duck.time_back();
	duck.percentage_back();
	return 0;
}
