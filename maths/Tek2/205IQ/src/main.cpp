//
// EPITECH PROJECT, 2018
// 205IQ
// File description:
// main file
//

#include <fstream>
#include <iostream>
#include <math.h>
#include "IQ.hpp"

int	display_usage()
{
	std::ifstream	file("usage.txt");
	std::string	line;

	if (file) {
		while (getline(file, line))
			std::cout << line << std::endl;
	}
	return 0;
}

int	verif_integer(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		for(int s = 0; av[i][s] != '\0'; s++) {
			if (av[i][s] < '0' || av[i][s] > '9')
				return 1;
		}
	}
	return 0;
}

int	main(int ac, char **av)
{
	int	mean;
	int	deviation;
	int	iq1;
	int	iq2;
	
	if (ac < 3 || ac > 5) {
		if (ac == 2 && (std::string)av[1] == "-h") {
			return display_usage();
		}
		std::cerr << "Invalid number of arguments" << std::endl;
		return 84;
	}
	else if (verif_integer(ac, av) == 1) {
		std::cerr << "Arguments must be integer" << std::endl;
		return 84;
	}
	mean = atoi(av[1]);
	deviation = atoi(av[2]);
	if (mean <= 0 || deviation <= 0) {
		std::cerr << "Mean and deviation must be higher than 0" << std::endl;
		return 84;
	}
	if (ac == 3) {
		IQ	iq(mean, deviation, 0, 0);
		iq.exportGnuplot();
	}
	else if (ac == 4) {
		iq1 = atoi(av[3]);
		if (iq1 < 0 || iq1 > 200) {
			std::cerr << "IQs must be between 0 and 200" << std::endl;
			return 84;
		}
		IQ	iq(mean, deviation, iq1, 0);
		iq.oneIQ();
	}
	else {
		iq1 = atoi(av[3]);
		iq2 = atoi(av[4]);
		if (iq1 < 0 || iq2 < 0 || iq1 > 200 || iq2 > 200 || iq2 < iq1) {
			std::cerr << "IQs must be between 0 and 200" << std::endl;
			return 84;
		}
		IQ	iq(mean, deviation, iq1, iq2);
		iq.twoIQ();
	}
	return 0;
}
