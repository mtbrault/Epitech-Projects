//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// 4801 class
//

#ifndef C4801_HPP_
# define C4801_HPP_

#include "IComponent.hpp"

class C4801 : public nts::IComponent
{
public:
	C4801(std::string const &);
	~C4801 ();
	
	nts::Tristate	compute(std::size_t = 1);
	void		setLink(std::size_t, nts::IComponent &,
				std::size_t);
	void		dump() const;
	size_t		getMaxPin() const;
	std::string	getType() const;
	nts::Tristate	getValue() const;
	
private:
	size_t						_maxPin;
	std::vector<std::unique_ptr<IComponent>>	_pin;
	std::vector<size_t>				_otherPin;
	nts::Tristate					_value;
	std::string					_type;
};

#endif
