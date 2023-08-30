//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4017 method
//

#include "C4017.hpp"

C4017::C4017(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4017::~C4017()
{
}

int	C4017::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4017::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4017::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4017::dump() const
{
}
