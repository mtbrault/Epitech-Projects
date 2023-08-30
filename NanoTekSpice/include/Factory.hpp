//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// factory class
//

#ifndef FACTORY_HPP_
# define FACTORY_HPP_

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include "IComponent.hpp"
#include "C2716.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4011.hpp"
#include "C4013.hpp"
#include "C4017.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "C4094.hpp"
#include "C4514.hpp"
#include "C4801.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"

template<typename Type>
std::unique_ptr<nts::IComponent>	newComp(const std::string &value)
{
	return std::make_unique<Type>(value);
}

class	Factory
{
public:
	Factory();
	~Factory();
	
	std::unique_ptr<nts::IComponent> createComponent(const std::string &,
							 const std::string &);
	
private:
	using ptrFunc = std::function<std::unique_ptr<nts::IComponent>(const std::string &)>;
	std::unordered_map<std::string, ptrFunc>	_map;
};

#endif
