//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Output file
//

#include <iostream>
#include <string>
#include "Output.hpp"
#include "Error.hpp"

Output::Output(const std::string &value)
	: _maxPin(1), _component(NULL), _value(nts::Tristate::UNDEFINED), _type("output")
{
	(void)value;
}

Output::~Output()
{
}

nts::Tristate	Output::compute(size_t pin)
{
	(void)pin;
	return _value;
}

void	Output::setLink(size_t pin, nts::IComponent &comp, size_t otherPin)
{
	if (_component == NULL) {
		_component = &comp;
		_otherPin = otherPin;
		comp.setLink(otherPin, *this, pin);
	}
}

size_t	Output::getMaxPin() const
{
	return _maxPin;
}

std::string	Output::getType() const
{
	return _type;
}

void	Output::dump() const
{
	std::cout << "  " << getType() << " - Output: " << _value << std::endl;
}

void	Output::setValue(const size_t value)
{
	if (_component == NULL)
		throw NanoError("An output is not linked");
	(void) value;
	_value = _component->compute(_otherPin);
}
