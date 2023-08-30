//
// EPITECH PROJECT, 2018
// tekspice
// File description:
// interface
//

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

#include <iostream>
#include <vector>
#include <memory>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent
	{
	public:
		virtual ~IComponent() = default;

	public:
		virtual nts::Tristate	compute(std::size_t = 1) = 0;
		virtual void		setLink(std::size_t, nts::IComponent &,
				     std::size_t) = 0;
		virtual void		dump() const = 0;
		virtual std::string	getType() const = 0;
		virtual size_t		getMaxPin() const = 0;
		virtual void		setValue(size_t value) = 0;
	};
}

#endif
