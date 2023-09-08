//
// EPITECH PROJECT, 2018
// 209poll
// File description:
// poll class
//

#ifndef POLL_HPP_
# define POLL_HPP_

#include <utility>

class	Poll
{
public:
	Poll(int, int, char *);
	~Poll();

	void	run();

private:
	void				calc_data();
	double				_pop;
	double				_sam;
	char				*_textPercent;
	double				_percent;
	double				_variance;
	std::pair<double, double>	_95;
	std::pair<double, double>	_99;
};

#endif
