//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Input file
//

#include <iostream>
#include <string>
#include "Input.hpp"

Input::Input(const std::string &value)
	: _maxPin(1), _component(nullptr),  _type("input")
{
	_value = (std::stoi(value) == 0) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}

Input::~Input()
{
}

nts::Tristate	Input::compute(size_t pin)
{
	(void)pin;
	return _value;
}

void	Input::setLink(size_t pin, nts::IComponent &comp, size_t otherPin)
{
	if (_component == nullptr) {
		_component = &comp;
		_otherPin = otherPin;
		comp.setLink(otherPin, *this, pin);
	}
}

void	Input::setValue(const size_t value)
{
	_value = (value == 0) ? nts::Tristate::FALSE : nts::Tristate::TRUE;
}

void	Input::dump() const
{
	std::cout << "  " << getType() << " - Value: " << _value << std::endl;
}

size_t	Input::getMaxPin() const
{
	return _maxPin;
}

std::string	Input::getType() const
{
	return _type;
}
