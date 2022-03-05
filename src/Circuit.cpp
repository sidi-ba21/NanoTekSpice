/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include<algorithm>
#include<csignal>
#include <exception>

static bool _loop;

nts::Circuit::Circuit(char *av) : file(av)
{
    createComponent();
    createLink();
    file.disp();
    _command["loop"] = [](Circuit &c) {c.loop();};
    _command["simulate"] = [](Circuit &c) {c.simulate();};
    _command["dump"] = [](Circuit &c) {c.dump();};
    _command["display"] = [](Circuit &c) {c.display();};
}

void nts::Circuit::display()
{
	std::cout << "tick: " << _tick << std::endl;
	std::cout << "input(s):" << std::endl;
	for (auto const &input : _inputs) {
		input.lock()->display();
	}
	std::cout << "output(s):" << std::endl;
	for (auto const &output : _outputs) {
		output.lock()->display();
	}
}

void nts::Circuit::simulate()
{
	_tick++;
    reset();
	for (auto const &output : _outputs) {
		output.lock()->compute();
	}
}

void stops(int)
{
    _loop = true;
}

void nts::Circuit::loop()
{
    _loop = false;
	std::signal(SIGINT, stops);
	while (!_loop)
		simulate();
	std::signal(SIGINT, SIG_DFL);
}

void nts::Circuit::dump()
{
	for (auto const &comp : _components) {
		comp.second.get()->dump();
	}
}

void nts::Circuit::set_value(const std::string &name, const std::string &value)
{
    try {
        std::stoi(value);
    } catch (std::exception const &e) {
        throw std::runtime_error("Input value must be either 0 or 1.");
    }
    for (auto &comp : _inputs) {
        if (comp.lock()->getName().compare(name) == 0) {
            comp.lock()->setValue(value);
            return;
        }
    }
    throw std::runtime_error("Input error: 'a' doesn't exist.");
}

void nts::Circuit::run()
{
    std::string cmd;

    std::cout << "> " << std::flush;
    while (std::getline(std::cin, cmd) && cmd.compare("exit")) {
        try {
        if (cmd.compare("") != 0)
           execute(cmd);
        } catch (std::exception const &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "> " << std::flush;
    }
}

void nts::Circuit::execute(const std::string &name)
{
    std::string tmp = name;
    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
    auto it = _command.find(tmp);
    if (tmp.find('=') != std::string::npos) {
        auto str = tmp.substr(0, tmp.find('='));
        auto value = tmp.substr(tmp.find('=') + 1);
        set_value(str, value);
        return;
    }
    else if (it == _command.end())
        throw std::runtime_error("Unknown command");
    it->second(*this);
}

void nts::Circuit::reset()
{
    for (auto const &comp : _components)
        comp.second.get()->reset();
}

void nts::Circuit::createComponent()
{
    auto tmp = file.getChipsets();
    for (auto const &chipsets : tmp) {
        if (_components.find(chipsets.name) != _components.end()) {
		    throw "Components name already exists.";
	    }
        if (special_create(chipsets.name, chipsets.type));
        else {
            auto component
                (_factories.createComponent(chipsets.type, chipsets.name));
            _components[chipsets.name] = std::move(component);
        }
    }
}

void nts::Circuit::createLink()
{
    auto all_link = file.getLinks();
    for (auto const &tmp : all_link) {
        auto firstcomponent {_components.find(tmp.first.name)};
        if (firstcomponent == _components.end())
            throw "link error: components " + tmp.first.name + " doesn't exist";
        auto secondcomponent {_components.find(tmp.second.name)};
        if (secondcomponent == _components.end())
            throw "link error: components " + tmp.second.name + " doesn't exist";
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
void nts::Circuit::createTerminal(const std::string &name)
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