//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Output header
//

#include <iostream>
#include "IComponent.hpp"

class	Output : public nts::IComponent
{
public:
	Output(const std::string &);
        ~Output();

	nts::Tristate	compute(size_t = 1);
	void		setLink(size_t, nts::IComponent &, size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	std::string	getType() const;
	void		setValue(const size_t);
private:
	size_t			_maxPin;
	size_t			_otherPin;
	nts::IComponent		*_component;
	nts::Tristate		_value;
	std::string		_type;
};
