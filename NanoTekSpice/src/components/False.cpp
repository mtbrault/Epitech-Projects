//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// False file
//

#include <iostream>
#include <string>
#include "False.hpp"

False::False(const std::string &value)
	: _maxPin(1), _component(nullptr), _value(nts::Tristate::FALSE), _type("false")
{
	(void) value;
}

False::~False()
{
}

nts::Tristate	False::compute(size_t pin)
{
	(void)pin;
	return _value;
}

void	False::setValue(const size_t value)
{
	(void) value;
	std::cout << "False's value can't be change" << std::endl;
}

void	False::setLink(size_t pin, nts::IComponent &comp, size_t otherPin)
{
	if (_component == nullptr) {
		_component = &comp;
		_otherPin = otherPin;
		comp.setLink(otherPin, *this, pin);
	}
}

void	False::dump() const
{
	std::cout << "  " << getType() << " - Value: " << _value << std::endl;
}

size_t	False::getMaxPin() const
{
	return _maxPin;
}

std::string	False::getType() const
{
	return _type;
}
