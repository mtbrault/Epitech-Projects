//
// EPITECH PROJECT, 2018
// 205IQ
// File description:
// IQ method
//

#include <stdio.h>
#include <math.h>
#include "IQ.hpp"

IQ::IQ(int mean, int dev, int iq1, int iq2)
	: _mean(mean), _dev(dev), _iq1(iq1), _iq2(iq2)
{
}

IQ::~IQ()
{
}

static double	Gauss(int mu, int lambda, float t)
{
	double	first = 1 / (lambda * sqrt(2 * M_PI));
	double	second;

	second = pow((t - mu), 2) / (2 * pow(lambda, 2));
	return ((first * exp(-second)));
}

void	IQ::exportGnuplot()
{
	for (int t = 0; t <= 200; t++) {
		printf("%d %.2lf\n", t, Gauss(_mean, _dev, t) * 100);
	}
}

void	IQ::oneIQ()
{
	double	result = 0;

	for (float i = 0; i < _iq1; i += 0.01) {
		result += Gauss(_mean, _dev, i);
	}
	printf("%.1f%% of people have an IQ inferior to %d\n", result, _iq1);
}

void	IQ::twoIQ()
{
	double	result = 0;

	for (float i = _iq1; i < _iq2; i += 0.01) {
		result += Gauss(_mean, _dev, i);
	}
	printf("%.1f%% of people have an IQ between %d and %d\n", result, _iq1, _iq2);
}
