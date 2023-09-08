//
// EPITECH PROJECT, 2018
// 201yams
// File description:
// operand method
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "operand.hpp"

Operand::Operand(char **av, std::vector<std::string> array)
	: _dice(get_dice(av)), _cmd(array)
{	
}

Operand::~Operand()
{
}

int	Operand::checkTimes(int	value)
{
	int	s = 0;
	for (int i = 0; i <= 5; i++) {
		if (value == _dice[i])
			s++;
	}
	return s;
}

static int	fact(int value)
{
	int	res = 1;
	
        for (int i = value ; i >= 1; i--) {
		res *= i;
	}
	return res;
}

double	Operand::binomiale(int n, int k)
{
	double first = powf((1.0 / 6.0), k);
	double second = powf((1 - (1.0 / 6.0)), n - k);
	double bernouilli = fact(n) / (fact(k) * fact(n - k));

	return first * second * bernouilli;
}

double	Operand::same(int value)
{
	int times = checkTimes(std::stoi(_cmd[1]));
	if (times >= value)
		return 100;
	double n = 5 - times;
	double k = value - times;
	double res = 0;

        while (k <= n) {
		res += binomiale (n, k);
		k += 1;
	}
	return res * 100;
}

double	Operand::straight()
{
	int	times = 0;
	int	n;

	if (checkTimes(2) >= 1)
		times++;
	if (checkTimes(3) >= 1)
		times++;
	if (checkTimes(4) >= 1)
		times++;
	if (checkTimes(5) >= 1)
		times++;
	if (std::stoi(_cmd[1]) == 5) { 
		if (checkTimes(1) >= 1)
			times++;
	}
	else if (std::stoi(_cmd[1]) == 6) {
		if (checkTimes(6) >= 1)
			times++;
	}
	n = 5 - times;
	return (fact(n) / pow(6, n) * 100);
}

double	Operand::full()
{
	double	nbPair = checkTimes(std::stoi(_cmd[2]));
	double	nbBrelan = checkTimes(std::stoi(_cmd[1]));
	double	bernBrelan;

	if (nbPair > 2)
		nbPair = 2;
	if (nbBrelan > 3)
		nbBrelan = 3;
	if (nbPair == 2 && nbBrelan == 3)
		return 100;
	bernBrelan = fact(5 - nbBrelan - nbPair) / (fact(3 - nbBrelan) * fact((5 - nbBrelan - nbPair) - (3 - nbBrelan)));
	return bernBrelan / powf(6, 5 - nbBrelan - nbPair) * 100;
}

void	Operand::exec()
{
	if (_cmd[0] == "pair")
	        printf("chances to get a %d pair: %.2f%%\n", std::stoi(_cmd[1]), same(2));
	else if (_cmd[0] == "three")
		printf("chances to get a %d three-of-a-kind: %.2f%%\n", std::stoi(_cmd[1]), same(3));
	else if (_cmd[0] == "four")
		printf("chances to get a %d four-of-a-kind: %.2f%%\n", std::stoi(_cmd[1]), same(4));
	else if (_cmd[0] == "yams")
		printf("chances to get a %d yams: %.2f%%\n", std::stoi(_cmd[1]), same(5));
	else if (_cmd[0] == "full")
		printf("chances to get a %d full of %d: %.2f%%\n", std::stoi(_cmd[1]), std::stoi(_cmd[2]), full());
	else if (_cmd[0] == "straight") { 
		if (std::stoi(_cmd[1]) < 5)
			throw std::overflow_error("Select a straight of 5 or 6 only\n");
		printf("chances to get a %d straight: %.2f%%\n", std::stoi(_cmd[1]), (float)straight());
	}
	else
	        throw std::overflow_error("The combinaison is invalid\n");
}

int	*Operand::get_dice(char **av)
{
	int	*tab = new int[5];

	for (int i = 0; i < 5; i++)
		tab[i] = atoi(av[i + 1]);
	return tab;
}
