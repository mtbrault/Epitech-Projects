//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4013 method
//

#include "C4013.hpp"

C4013::C4013(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4013::~C4013()
{
}

int	C4013::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4013::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4013::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4013::dump() const
{
}
