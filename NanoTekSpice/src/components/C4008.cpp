//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4008 method
//

#include "C4008.hpp"

C4008::C4008(const std::string &value)
	: _maxPin(14)
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4008::~C4008()
{
}

int	C4008::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4008::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4008::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	if (_pin[pin - 1] == NULL) {
		_otherPin[pin - 1] = otherPin;
		_pin[pin - 1] = other;
		other.setLink(otherPin, *this, pin);
	}
}

void	C4008::dump() const
{
}
