//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4069 method
//

#include "Error.hpp"
#include "C4069.hpp"

C4069::C4069(const std::string &value)
	: _maxPin(14), _type("C4069")
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin[i] = NULL;
		_otherPin.push_back(0);
	}
	_pair[2] = 1;
	_pair[4] = 3;
	_pair[6] = 5;
	_pair[8] = 9;
	_pair[10] = 11;
	_pair[12] = 13;
}

C4069::~C4069()
{
}

std::string	C4069::getType() const
{
	return _type;
}

void	C4069::setValue(const size_t value)
{
	(void) value;
	std::cout << "Can't change value of this component" << std::endl;
}

size_t	C4069::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4069::input(size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	return _pin[pin - 1]->compute(_otherPin[pin - 1]);
}

nts::Tristate	C4069::output(size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	return (nts::Tristate)(!(compute(_pair[pin])));
}

nts::Tristate	C4069::compute(std::size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	else if (_pair.find(pin) == _pair.end()) {
		return input(pin);
	}
	return output(pin);
}

void	C4069::setLink(std::size_t pin, nts::IComponent &comp,
		       std::size_t otherPin)
{
	if (pin == 7 || pin == 14)
		throw NanoError("Try to compute a VSS or VDD pin");
	if (_pin[pin - 1] == NULL) {
		_otherPin[pin - 1] = otherPin;
		_pin[pin - 1] = &comp;
		comp.setLink(otherPin, *this, pin);
	}
}

void	C4069::dump() const
{
	std::cout << "  " << getType() << " value:" << std::endl;
	for (int i = 0; i < 14; i++) {
		std::cout << "\tPin " << (i + 1) << ": ";
		if (_pin[i])
			std::cout << _pin[i]->compute(_otherPin[i]) << std::endl;
		else
			std::cout << "U" << std::endl;
	}
}
