//
// EPITECH PROJECT, 2018
// 206neutrinos
// File description:
// main file
//

#include <stdlib.h>
#include <iostream>
#include "neutrinos.hpp"

int	check_is_num(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return 1;
	}
	return 0;
}

int	main(int ac, char **av)
{
	if (ac != 5) {
		std::cerr << "Invalid number of arguments" << std::endl;
		return 84;
	}
	for (int i = 1; i < ac; i++) {
		if (check_is_num(av[i]) == 1) {
			std::cerr << "Arguments must be integer" << std::endl;
			return 84;
		}
	}
	Neutrinos	neutrinos(atof(av[1]), atof(av[2]), atof(av[3]), atof(av[4]));
	return neutrinos.run();

}
