/*
** EPITECH PROJECT, 2022
** Circuitcreate
** File description:
** Circuitcreate
*/

#include "Circuit.hpp"
#include <algorithm>
#include <csignal>
#include <exception>

void nts::Circuit::createComponent()
{
    auto tmp = file.getChipsets();
    for (auto const &chipsets : tmp) {
        if (_components.find(chipsets.second) != _components.end())
		    throw ComponentError("Components name already exists.", "create_component");
        if (!special_create(chipsets.second, chipsets.first)) {
            auto component
                (_factories.createComponent(chipsets.first, chipsets.second));
            _components[chipsets.second] = std::move(component);
        }
    }
}

void nts::Circuit::createLink()
{
    auto all_link = file.getLinks();
    for (auto const &tmp : all_link) {
        auto firstcomponent {_components.find(tmp.first.name)};
        if (firstcomponent == _components.end())
            throw LinkError("link error: components " + tmp.first.name + " doesn't exist");
        auto secondcomponent {_components.find(tmp.second.name)};
        if (secondcomponent == _components.end())
            throw LinkError("link error: components " + tmp.second.name + " doesn't exist");
        firstcomponent->second->setLink(tmp.first.pin, *secondcomponent->second, tmp.second.pin);
    }
}

void nts::Circuit::createInput(const std::string &name)
{
	std::shared_ptr<Input> input = std::move(_factories.createInput(name));

	_components[name] = input;
	_inputs.emplace_back(input);
}

void nts::Circuit::createOutput(const std::string &name)
{
	std::shared_ptr<Output> output = std::move(_factories.createOutput(name));

	_components[name] = output;
	_outputs.emplace_back(output);
}

void nts::Circuit::createTrue(const std::string &name)
{
	std::shared_ptr<True> input = std::move(_factories.createTrue(name));

	_components[name] = input;
	_inputs.emplace_back(input);
}

void nts::Circuit::createFalse(const std::string &name)
{
	std::shared_ptr<False> input = std::move(_factories.createFalse(name));

	_components[name] = input;
	_inputs.emplace_back(input);
}

void nts::Circuit::createClock(const std::string &name)
{
	std::shared_ptr<Clock> input = std::move(_factories.createClock(name));

	_components[name] = input;
	_inputs.emplace_back(input);
}
/*
void nts::Circuit::createLogger(const std::string &name)
{
	std::shared_ptr<Logger> logger = std::move(_factories.createLogger(name));

	_components[name] = logger;
	_outputs.emplace_back(logger);
}
*/

bool nts::Circuit::special_create(const std::string &name, const std::string &type)
{
    bool state = false;
    if (type.compare("input") == 0){
        createInput(name);
        state = true;
    }
    else if (type.compare("output") == 0){
        createOutput(name);
        state = true;
    }
    else if (type.compare("true") == 0) {
        createTrue(name);
        state = true;
    }
    else if (type.compare("false") == 0) {
        createFalse(name);
        state = true;
    } 
    else if (type.compare("clock") == 0) {
        createClock(name);
        state = true;
        }
//    if (type.compare("logger"))
//        createLogger(name);
    return (state);
}