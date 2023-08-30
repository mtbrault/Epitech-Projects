//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// False header
//

#include <iostream>
#include "IComponent.hpp"

class	False : public nts::IComponent
{
public:
	False(const std::string &);
        ~False();

	nts::Tristate	compute(size_t = 1);
	void		setLink(size_t, nts::IComponent &, size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	std::string	getType() const;
	void		setValue(const size_t);
private:
	size_t			_maxPin;
        nts::IComponent		*_component;
	size_t			_otherPin;
	nts::Tristate		_value;
	std::string		_type;
};
