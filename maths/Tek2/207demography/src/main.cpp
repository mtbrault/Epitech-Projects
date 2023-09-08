//
// EPITECH PROJECT, 2018
// 207demography
// File description:
// main
//

#include <iostream>
#include <string.h>
#include "demograph.hpp"

int main(int ac, char **av)
{
	if (ac == 1) {
		std::cerr << "Invalid number of argument" << std::endl;
		return 84;
	}
        for (int i = 0; i < ac; i++) {
            for (int s = 0; s < ac; s++)
                if (strcmp(av[i], av[s]) == 0 && i != s) {
                    std::cerr << "2 times the same country\n";
                    return 84;
                }                    
        }
	Demograph demo(ac, av);
	try {
		demo.loadCountry();
                demo.calcFit1();
                demo.calcFit2();
                demo.corelation();
	} catch (std::overflow_error &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
        return 0;
}
