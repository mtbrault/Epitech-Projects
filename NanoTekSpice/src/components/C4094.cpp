//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4094 method
//

#include "C4094.hpp"

C4094::C4094(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4094::~C4094()
{
}

int	C4094::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4094::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4094::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4094::dump() const
{
}
