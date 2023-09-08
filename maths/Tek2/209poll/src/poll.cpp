//
// EPITECH PROJECT, 2018
// 209poll
// File description:
// poll method
//

#include <math.h>
#include <iostream>
#include "poll.hpp"

Poll::Poll(int pop, int sam, char *percent)
	:_pop(pop), _sam(sam), _textPercent(percent), _percent(std::stof(percent))
{
	if (sam > pop)
		throw std::overflow_error("Sample is higher than population");
	else if (_percent > 100)
		throw std::overflow_error("Percent is higher than 100");
	else if (_pop == 1)
		throw std::overflow_error("Pop can't be equal to 1");
}

Poll::~Poll()
{
}

void	Poll::calc_data()
{
	double	p = _percent / 100;
	double	varPop = (p * (1 - p)) / _sam;
	double	var = varPop * ((_pop - _sam) / (_pop - 1));
	double	amp95 = (2 * 1.96 * sqrt(var)) / 2 * 100;
	double	amp99 = (2 * 2.58 * sqrt(var)) / 2 * 100;

	_variance = var;
	_95 = std::make_pair(_percent - amp95, _percent + amp95);
	_99 = std::make_pair(_percent - amp99, _percent + amp99);
}

void	Poll::run()
{
	std::cout << "population size:\t\t" << _pop << std::endl;
	std::cout << "sample size:\t\t\t" << _sam << std::endl;
	std::cout << "voting intentions:\t\t" << (std::string)_textPercent << "%\n";
	calc_data();
	printf("variance:\t\t\t%.6lf\n", _variance);
	printf("95%% confidence interval:\t[%.2lf%% ; %.2lf%%]\n", (_95.first < 0) ? 0 : _95.first, (_95.second > 100) ? 100 : _95.second);
	printf("99%% confidence interval:\t[%.2lf%% ; %.2lf%%]\n", (_99.first < 0) ? 0 : _99.first, (_99.second > 100) ? 100 : _99.second);
}
