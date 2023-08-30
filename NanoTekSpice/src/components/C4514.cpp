//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4514 method
//

#include "C4514.hpp"

C4514::C4514(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4514::~C4514()
{
}

int	C4514::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4514::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4514::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4514::dump() const
{
}
