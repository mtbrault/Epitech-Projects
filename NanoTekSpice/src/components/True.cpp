//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// True file
//

#include <iostream>
#include <string>
#include "True.hpp"

True::True(const std::string &value)
	: _maxPin(1), _component(nullptr), _value(nts::Tristate::TRUE), _type("true")
{
	(void)value;
}

True::~True()
{
}

nts::Tristate	True::compute(size_t pin)
{
	(void)pin;
	return _value;
}

void	True::setLink(size_t pin, nts::IComponent &comp, size_t otherPin)
{
	if (_component == NULL) {
		_component = &comp;
		_otherPin = otherPin;
		comp.setLink(otherPin, *this, pin);
	}
}

void	True::setValue(const size_t value)
{
	(void)value;
	std::cout << "True component's value can't be edit" << std::endl;
}

void	True::dump() const
{
	std::cout << "  " << getType() << " - Value: " << _value << std::endl;
}

size_t	True::getMaxPin() const
{
	return _maxPin;
}

std::string	True::getType() const
{
	return _type;
}

nts::Tristate	True::getValue() const
{
	return _value;
}
