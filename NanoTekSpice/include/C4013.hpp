//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4013 class
//

#ifndef C4013_HPP_
# define C4013_HPP_

#include "IComponent.hpp"

class C4013 : public nts::IComponent
{
public:
	C4013(std::string const &);
	~C4013();
	
	nts::Tristate	compute(std::size_t = 1);
	void		setLink(std::size_t, nts::IComponent &,
					std::size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	
private:
	int						_maxPin;
	std::vector<std::unique_ptr<IComponent>>	_pin;
	std::vector<size_t>				_otherPin;
};

#endif
