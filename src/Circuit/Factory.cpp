/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
	_components["input"] = &Factory::createInput;
	_components["output"] = &Factory::createOutput;
	_components["true"] = &Factory::createTrue;
	_components["false"] = &Factory::createFalse;
	_components["clock"] = &Factory::createClock;
//	_components["logger"] = &Factory::createLogger;

	_components["4001"] = &Factory::create4001;
//	_components["4008"] = &Factory::create4008;
	_components["4011"] = &Factory::create4011;
//	_components["4013"] = &Factory::create4013;
//	_components["4017"] = &Factory::create4017;
	_components["4030"] = &Factory::create4030;
//	_components["4040"] = &Factory::create4040;
	_components["4069"] = &Factory::create4069;
	_components["4071"] = &Factory::create4071;
	_components["4081"] = &Factory::create4081;
//	_components["4094"] = &Factory::create4094;
//	_components["4514"] = &Factory::create4514;
}

std::unique_ptr<nts::IComponent>
    nts::Factory::createComponent(std::string const &type,
    std::string const &value) const
{
	auto it{ _components.find(type) };

	if (it != _components.end()) {
		return it->second(*this, value);
	}
	throw ComponentError("Unknown component type", "Factory::createComponent");
}

std::unique_ptr<nts::Input>
    nts::Factory::createInput(std::string const &value) const
{
	return std::make_unique<Input>(value);
}

std::unique_ptr<nts::Output>
    nts::Factory::createOutput(std::string const &value) const
{
	return std::make_unique<Output>(value);
}

std::unique_ptr<nts::True>
    nts::Factory::createTrue(std::string const &value) const
{
	return std::make_unique<True>(value);
}

std::unique_ptr<nts::False>
    nts::Factory::createFalse(std::string const &value) const
{
	return std::make_unique<False>(value);
}

std::unique_ptr<nts::Clock>
    nts::Factory::createClock(std::string const &value) const
{
	return std::make_unique<Clock>(value);
}
/*
std::unique_ptr<nts::Logger> nts::Factory::createLogger(std::string const &value) const
{
	return std::make_unique<Logger>(value);
}*/

std::unique_ptr<nts::IComponent>
    nts::Factory::create4001(std::string const &value) const
{
	return std::make_unique<C4001>(value);
}

/*
std::unique_ptr<nts::IComponent>
    nts::Factory::create4008(std::string const &value) const
{
	return std::make_unique<C4008>(value);
}*/

std::unique_ptr<nts::IComponent>
    nts::Factory::create4011(std::string const &value) const
{
	return std::make_unique<C4011>(value);
}

/*
std::unique_ptr<nts::IComponent>
    nts::Factory::create4013(std::string const &value) const
{
	return std::make_unique<C4013>(value);
}
*/
/*
std::unique_ptr<nts::IComponent>
    nts::Factory::create4017(std::string const &value) const
{
	return std::make_unique<C4017>(value);
}
*/

std::unique_ptr<nts::IComponent>
    nts::Factory::create4030(std::string const &value) const
{
	return std::make_unique<C4030>(value);
}
/*
std::unique_ptr<nts::IComponent>
    nts::Factory::create4040(std::string const &value) const
{
	return std::make_unique<C4040>(value);
}
*/
std::unique_ptr<nts::IComponent>
    nts::Factory::create4069(std::string const &value) const
{
	return std::make_unique<C4069>(value);
}

std::unique_ptr<nts::IComponent>
    nts::Factory::create4071(std::string const &value) const
{
	return std::make_unique<C4071>(value);
}

std::unique_ptr<nts::IComponent>
    nts::Factory::create4081(std::string const &value) const
{
	return std::make_unique<C4081>(value);
}
/*
std::unique_ptr<nts::IComponent>
    nts::Factory::create4094(std::string const &value) const
{
	return std::make_unique<C4094>(value);
}

std::unique_ptr<nts::IComponent>
    nts::Factory::create4514(std::string const &value) const
{
	return std::make_unique<C4514>(value);
}*/