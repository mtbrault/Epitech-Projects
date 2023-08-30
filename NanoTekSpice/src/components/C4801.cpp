//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4801 method
//

#include "C4801.hpp"

C4801::C4801(const std::string &value)
	: _maxPin(14), _type("C4801")
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin.push_back(NULL);
		_otherPin.push_back(0);
	}
}

C4801::~C4801()
{
}

std::string	getType() const
{
	return _type;
}

nts::Tristate	getValue() const
{
	return _value;
}

int	C4801::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4801::compute(std::size_t pin)
{
	(void) pin;
	return nts::Tristate::UNDEFINED;
}

void	C4801::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	C4801::dump() const
{
}
