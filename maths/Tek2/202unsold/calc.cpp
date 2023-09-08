//
// EPITECH PROJECT, 2018
// 202unsold
// File description:
// calc method
//

#include <math.h>
#include "calc.hpp"

Calc::Calc(int a, int b)
	: _a(a), _b(b), _expectX(0), _expectY(0), _expectZ(0), _varianceX(0), _varianceY(0), _varianceZ(0)
{
	for (int i = 10; i <= 50; i += 10) {
		_resultX[i] = 0;
		_resultY[i] = 0;
	}
	for (int i = 20; i <= 100; i += 10)
		_z[i] = 0;
}

Calc::~Calc()
{
}

void	Calc::displayArrayXY()
{
	float	result;
	float	sum;
	
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;
	for (int y = 10; y < 60; y += 10) {
		std::cout << "Y=" << y << "\t";
		sum = 0;
		for (int x = 10; x < 60; x += 10) {
			result = (_a - x) * (_b - y);
			result /= (5 * _a - 150) * (5 * _b - 150);
			_z[x + y] += result;
			_resultX[x] += result;
			printf("%.3f\t", result);
			sum += result;
		}
		_resultY[y] = sum;
		_expectY += sum * y;
		printf("%.3f\n", sum);
	}
	std::cout << "X law\t";
	for (auto i = _resultX.begin(); i != _resultX.end(); i++) {
		printf("%.3f\t", i->second);
		_expectX += i->second * i->first;
	}
	std::cout << "1" << std::endl;
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	Calc::displayArrayZ()
{
	float	sum = 0;

	std::cout << "z\t";
	for (int i = 20; i <= 100; i += 10)
		std::cout << i << "\t";
	std::cout << "total" << std::endl << "p(Z=z)\t";
	for (auto i = _z.begin(); i != _z.end(); i++) {
		_expectZ += i->first * i->second;
		sum += i->second;
		printf("%.3f\t", i->second);
	}
	printf("%.0f\n", sum);
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	Calc::expectedValue()
{
	for (auto i = _resultX.begin(); i != _resultX.end(); i++)
		_varianceX += (i->second * pow(i->first, 2));
	_varianceX = _varianceX - pow(_expectX, 2);
	for (auto i = _resultY.begin(); i != _resultY.end(); i++)
		_varianceY += (i->second * pow(i->first, 2));
	_varianceY = _varianceY - pow(_expectY, 2);
	for (auto i = _z.begin(); i != _z.end(); i++)
		_varianceZ += (i->second * pow(i->first, 2));
	_varianceZ = _varianceZ - pow(_expectZ, 2);
        printf("expected value of X:\t%.1f\n", _expectX);
	printf("variance of X:\t\t%.1f\n", _varianceX);
	printf("expected value of Y:\t%.1f\n", _expectY);
	printf("variance of Y:\t\t%.1f\n", _varianceY);
	printf("expected value of Z:\t%.1f\n", _expectZ);
	printf("variance of Z:\t\t%.1f\n", _varianceZ);
	for (int i = 0; i < 60; i++)
		std::cout << "-";
	std::cout << std::endl;
}
