//
// EPITECH PROJECT, 2018
// 202unsold
// File description:
// calc class
//

#include <iostream>
#include <map>

class	Calc
{
public:
	Calc(int, int);
	~Calc();

	void	displayArrayXY();
	void	displayArrayZ();
	void	expectedValue();

private:
	int			_a;
	int			_b;
	std::map<int, float>	_resultX;
	std::map<int, float>	_resultY;
	std::map<int, float>	_z;
	float			_expectX;
	float			_expectY;
	float			_expectZ;
	float			_varianceX;
	float			_varianceY;
	float			_varianceZ;
};
