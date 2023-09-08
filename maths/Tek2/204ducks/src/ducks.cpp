//
// EPITECH PROJECT, 2018
// 204ducks
// File description:
// ducks method
//

#include <math.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include "ducks.hpp"

Ducks::Ducks(double a)
	:_a(a)
{
}

Ducks::~Ducks()
{
}

static double   F(double a, double t)
{
	double	result;

	result = a * exp(-t);
        result += (4 - (3 * a)) * exp(-2 * t);
        result += (2 * a - 4) * exp(-4 * t);
	return result;
}

static double	derivate(double a, double t)
{
	double	result;

	result = -a * exp(-t);
	result -= (4 - 3 * a) / 2 * exp(-2 * t);
	result -= (2 * a -4) / 4 * exp(-4 * t);
	return result;
}

static double	getTimeBack(int percent, double a)
{
	double	result = 0.0;
	double	t = 0.0;

        while (result < (percent - 0.01)) {
		result += F(a, t / 100);
		t += 1;
	}
	return t / 100;
}

static void	printIntToTime(double val, std::string sentence)
{
	printf("%s: %d", sentence.c_str(), (int)val);
	printf("m ");
	while (val > 1)
		val -= 1;
	if (val * 60 < 10)
		printf("0");
	printf("%d", (sentence != "average return time") ? (int)(val * 60) : (int)(val * 60 + 1));
	printf("s\n");
}

void	Ducks::average_time()
{
	double	result = 0;
	double	t = 0.001;
	double	dev = 0;

	while (F(_a, t) != 0) {
		result += (F(_a, t) / 10) * t;
		t += 0.001;
	}
	result /= 100;
	result += 1/60;
	printIntToTime(result, "average return time");
	while (t > 0) {
		dev += pow(t - result, 2) * (F(_a, t) / 10);
		t -= 0.001;
	}
	dev /= 100;
	printf("standard deviation: %.3f\n", sqrt(dev));
}

void	Ducks::time_back()
{
	printIntToTime(getTimeBack(50, _a), "time after which 50% of the ducks come back");
	printIntToTime(getTimeBack(99, _a), "time after which 99% of the ducks come back");
}

void	Ducks::percentage_back()
{
	double	minute1 = derivate(_a, 1) - derivate(_a, 0);
	double	minute2 = derivate(_a, 2) - derivate(_a, 0);

	printf("percentage of ducks back after 1 minute: %.1lf%%\n", minute1 * 100);
	printf("percentage of ducks back after 2 minutes: %.1lf%%\n", minute2 * 100);
}
