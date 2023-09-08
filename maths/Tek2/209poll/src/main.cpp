//
// EPITECH PROJECT, 2018
// 209poll
// File description:
// main file
//

#include <iostream>
#include "poll.hpp"

int	check_is_number(char *str, int s)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			if (str[i] != '.' || s != 3)
				return 1;
		}
	}
	return 0;
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Invalid number of arguments" << std::endl;
		return 84;
	}
	for (int i = 1; i < ac; i++) {
		if (check_is_number(av[i], i) == 1) {
			std::cerr << "Please select numbers" << std::endl;
			return 84;
		}
	}
	try {
		Poll	poll(std::stoi(av[1]), std::stoi(av[2]), av[3]);
		poll.run();
	} catch (std::exception &ex) {
		std::cerr << ex.what() << std::endl;
		return 84;
	}
}
