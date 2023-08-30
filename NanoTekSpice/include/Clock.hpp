//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Clock header
//

#include <iostream>
#include "IComponent.hpp"

class	Clock : public nts::IComponent
{
public:
	Clock(const std::string &);
        ~Clock();

	nts::Tristate	compute(size_t = 1);
	void		setLink(size_t, nts::IComponent &, size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	std::string	getType() const;
	nts::Tristate	getValue() const;
	void		setValue(const size_t);
	
private:
	size_t			_maxPin;
	nts::IComponent		*_component;
        size_t			_otherPin;
	nts::Tristate		_value;
	std::string		_type;
};
