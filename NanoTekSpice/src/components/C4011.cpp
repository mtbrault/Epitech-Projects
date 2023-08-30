//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4011 method
//

#include "Error.hpp"
#include "C4011.hpp"

C4011::C4011(const std::string &value)
	: _maxPin(14), _type("C4011")
{
	(void) value;
	for (int i = 0; i < 14; i++) {
	        _pin[i] = NULL;
		_otherPin.push_back(0);
	}
	_pair[3] = std::make_pair(1, 2);
	_pair[4] = std::make_pair(5, 6);
	_pair[10] = std::make_pair(8, 9);
	_pair[11] = std::make_pair(12, 13);
}

C4011::~C4011()
{
}

std::string	C4011::getType() const
{
	return _type;
}

void	C4011::setValue(const size_t value)
{
	(void) value;
	std::cout << "Can't change value of this component" << std::endl;
}

size_t	C4011::getMaxPin() const
{
	return _maxPin;
}

nts::Tristate	C4011::input(size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	return _pin[pin - 1]->compute(_otherPin[pin - 1]);
}

nts::Tristate	C4011::output(size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	return (nts::Tristate)(!(compute(_pair[pin].first) && compute(_pair[pin].second)));
}

nts::Tristate	C4011::compute(std::size_t pin)
{
	if (_pin[pin - 1] == NULL)
		return nts::Tristate::UNDEFINED;
	else if (_pair.find(pin) == _pair.end()) {
		return input(pin);
	}
	return output(pin);
}

void	C4011::setLink(std::size_t pin, nts::IComponent &comp,
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

void	C4011::dump() const
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
