//
// EPITECH PROJECT, 2018
// 201yams
// File description:
// operand class
//

#ifndef OPERAND_HPP_
# define OPERAND_HPP_

#include <vector>
#include <iostream>

class	Operand
{
public:
	Operand(char **, std::vector<std::string>);
	~Operand();

	void	exec();
	int	*get_dice(char **);
	int	checkTimes(int);
	double	same(int);
	double	straight();
	double	full();
	double	binomiale(int, int);

private:
	int				*_dice;
	std::vector<std::string>	_cmd;
};

#endif
