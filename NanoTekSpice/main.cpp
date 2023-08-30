//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// main file
//

#include <iostream>
#include "Error.hpp"
#include "TekSpice.hpp"

int	main(int ac, char **av)
{
	if (ac == 1) {
		std::cerr << "Please enter a file name\n";
		return 84;
	}
	try {
		TekSpice	tekspice(ac, av);
		tekspice.run();
	} catch (const NanoError error) {
		std::cerr << error.what() << std::endl;
		return 84;
	}
	return 0;
}
