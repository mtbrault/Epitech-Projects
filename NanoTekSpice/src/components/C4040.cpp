//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4040 method
//

#include "C4040.hpp"

C4040::C4040(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4040::~C4040()
{
}

int	C4040::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4040::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4040::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4040::dump() const
{
}
