//
// EPITECH PROJECT, 2018
// 202unsold
// File description:
// main file
//

#include <iostream>
#include <stdlib.h>
#include "calc.hpp"

int	display_help()
{
	std::cout << "Help" << std::endl;
	return 0;
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac == 2 && (std::string)av[1] == "-h")
		return display_help();
	else if (ac != 3) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 84;
	}
	a = atoi(av[1]);
	b = atoi(av[2]);
	if (a <= 50 || b <= 50) {
		std::cerr << "a and b must be higher than 50" << std::endl;
		return 84;
	}
	Calc	calc(a, b);
	calc.displayArrayXY();
	calc.displayArrayZ();
	calc.expectedValue();
	return 0;
}
