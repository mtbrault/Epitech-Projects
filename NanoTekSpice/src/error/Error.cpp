//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NanoError file
//

#include "Error.hpp"

NanoError::NanoError(const std::string &message)
	: _message(message)
{
}

NanoError::~NanoError() throw()
{
}

const char	*NanoError::what() const noexcept
{
	return _message.c_str();
}
