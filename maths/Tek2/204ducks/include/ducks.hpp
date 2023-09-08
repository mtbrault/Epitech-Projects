//
// EPITECH PROJECT, 2018
// 204ducks
// File description:
// ducks class
//

#include <iostream>
#include <map>

class	Ducks
{
public:
	Ducks(double);
	~Ducks();

	void	average_time();
	void	time_back();
	void	percentage_back();

private:
	double			_a;
	std::map<int, float>	_map;
	double			_average;
};
