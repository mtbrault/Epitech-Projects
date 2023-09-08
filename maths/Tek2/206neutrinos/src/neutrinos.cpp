//
// EPITECH PROJECT, 2018
// neutrinos
// File description:
// neutrinos method
//

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "neutrinos.hpp"

Neutrinos::Neutrinos(int nb, int ar, int har, int sd)
	:_nb(nb), _aritmetic(ar), _harmonic(har), _sd(sd)
{
}

Neutrinos::~Neutrinos()
{
}

int	Neutrinos::run()
{
	std::string	line;
	double		val;
	double		stock;

	std::cout << "indtast din vaerdi : ";
	while ((std::cin >> line) && line != "ENDE") {
		_nb++;
		if (check_is_num(line.c_str()) == 1)
			return (84);
		val = atof(line.c_str());
		std::cout << "\tantal mãlinder :\t" << _nb << std::endl;
		stock = _aritmetic;
		aritm(val);
		sd(val, stock);
		std::cout << "\taritmetisk gennemsnit :\t";
		printf("%.2lf\n", _aritmetic);
		std::cout << "\tkvadrastik gennemsnit :\t" << std::endl;
		harmo(val);
		std::cout << std::endl << "indtast din vaerdi : ";
	}
	return (0);
}

void	Neutrinos::sd(double val, double ari)
{
	double	first = (((pow(_sd, 2) + pow(ari, 2)) * (_nb - 1)) + pow(val, 2));

	_sd = sqrt(first / _nb - pow(_aritmetic, 2));
	std::cout << "\tstandardafvilgelse :\t";
	printf("%.2lf\n", _sd);
}

void	Neutrinos::aritm(double val)
{
	_aritmetic = ((_aritmetic * (_nb - 1)) + val) / _nb;
}

void	Neutrinos::harmo(double val)
{
        _harmonic = _nb / ((1 / val) + ((_nb - 1) / _harmonic));
	std::cout << "\tharmonisk gennemsnit :\t";
	printf("%.2lf\n", _harmonic);
}
