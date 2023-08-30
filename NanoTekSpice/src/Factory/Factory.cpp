//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// factory method
//

#include "IComponent.hpp"
#include "Factory.hpp"

Factory::Factory()
{
//	_map["2716"] = newComp<C2716>;
	_map["4001"] = newComp<C4001>;
//	_map["4008"] = newComp<C4008>;
	_map["4011"] = newComp<C4011>;
//	_map["4013"] = newComp<C4013>;
//	_map["4017"] = newComp<C4017>;
	_map["4030"] = newComp<C4030>;
//	_map["4040"] = newComp<C4040>;
	_map["4069"] = newComp<C4069>;
	_map["4071"] = newComp<C4071>;
	_map["4081"] = newComp<C4081>;
//	_map["4094"] = newComp<C4094>;
//	_map["4514"] = newComp<C4514>;
	_map["input"] = newComp<Input>;
	_map["output"] = newComp<Output>;
	_map["true"] = newComp<True>;
	_map["false"] = newComp<False>;
	_map["clock"] = newComp<Clock>;
}

Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent>	Factory::createComponent(const std::string &type,
							 const std::string &value)
{
	if (!_map[type])
		return NULL;
	return _map[type](value);
}
