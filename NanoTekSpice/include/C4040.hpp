//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4040 class
//

#ifndef C4040_HPP_
# define C4040_HPP_

#include "IComponent.hpp"

class C4040 : public nts::IComponent
{
public:
	C4040(std::string const &);
	~C4040();
	
	nts::Tristate	compute(std::size_t = 1);
	void		setLink(std::size_t, nts::IComponent &,
					std::size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	
private:
	size_t						_maxPin;
	std::vector<std::unique_ptr<IComponent>>	_pin;
	std::vector<size_t>				_otherPin;
};

#endif
