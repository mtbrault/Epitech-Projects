//
// EPITECH PROJECT, 2018
// 206neutrinos
// File description:
// class
//

#ifndef NEUTRINOS_HPP_
# define NEUTRINOS_HPP_

class	Neutrinos
{
public:
	Neutrinos(int, int, int, int);
	~Neutrinos();
	int	run();
	void	sd(double, double);
	void	aritm(double);
	void	kvadra(double, double);
	void	harmo(double);

private:
	double	_nb;
	double	_aritmetic;
	double	_harmonic;
	double	_sd;
};

int	check_is_num(const char *);

#endif
