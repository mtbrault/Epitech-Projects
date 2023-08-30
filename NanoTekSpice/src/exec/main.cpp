//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Main file
//

#include "Parser.hpp"
#include "Input.hpp"

int	main(int argc, char **argv)
{
	(void) argv;
	
	if (argc < 2) {
		std::cerr << "Bad argument" << std::endl;
	} else {
		try {
			nanotekspice(argv);
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
			return 84;
		}
		return 0;
	}
}
