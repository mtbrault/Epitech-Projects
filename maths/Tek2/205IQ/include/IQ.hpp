//
// EPITECH PROJECT, 2018
// 205IQ
// File description:
// IQ class
//

#ifndef IQ_HPP_
# define IQ_HPP_

#include <map>

class	IQ
{
public:
	IQ(int, int, int, int);
	~IQ();
	
	void	exportGnuplot();
	void	oneIQ();
	void	twoIQ();
	
private:
	int		_mean;
	int		_dev;
	int		_iq1;
	int		_iq2;
};

#endif
