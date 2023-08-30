//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NanoError header
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <iostream>

class	NanoError : std::exception
{
public:
	NanoError(const std::string &);
	virtual ~NanoError() throw();

	const char	*what() const noexcept;
private:
	std::string	_message;
};

#endif	/* !ERROR_HPP_ */

