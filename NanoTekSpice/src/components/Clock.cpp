//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Clock file
//

#include <iostream>
#include <string>
#include "Clock.hpp"

Clock::Clock(const std::string &value)
	: _maxPin(1), _component(nullptr), _type("clock")
{
	_value = (std::stoi(value) == 0) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}

Clock::~Clock()
{
}

nts::Tristate	Clock::compute(size_t pin)
{
	(void)pin;
	return _value;
}

void	Clock::setLink(size_t pin, nts::IComponent &comp, size_t otherPin)
{
	if (_component == nullptr) {
		_component = &comp;
		_otherPin = otherPin;
		comp.setLink(otherPin, *this, pin);
	}
}

void	Clock::dump() const
{
	std::cout << "  " << getType() << " - Value " << _value << std::endl;
}

size_t	Clock::getMaxPin() const
{
	return _maxPin;
}

void	Clock::setValue(const size_t value)
{
	(void) value;
	_value = (_value == nts::Tristate::TRUE) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}

std::string	Clock::getType() const
{
	return _type;
}

nts::Tristate	Clock::getValue() const
{
	return _value;
}
