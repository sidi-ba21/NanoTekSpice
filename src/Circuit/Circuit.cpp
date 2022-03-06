/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <algorithm>
#include <csignal>
#include <exception>

static bool _loop;

nts::Circuit::Circuit(char *av) : file(av)
{
    createComponent();
    createLink();
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

void nts::Circuit::simulate(size_t tick)
{
    if (tick != 0) {
        _tick++;
        reset();
    }
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
	while (!_loop) {
		simulate();
        display();
    }
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
    if (value.compare("U") != 0) {
        try {
            std::stoi(value);
        } catch (std::exception const &e) {
            throw ValueReceiveError("Input value must be either 0 or 1 or U.");
        }
    }
    for (auto &comp : _inputs) {
        if (comp.lock()->getName().compare(name) == 0) {
            comp.lock()->setValue(value);
            return;
        }
    }
    throw ValueReceiveError("Input error: Components doesn't exist.");
}

void nts::Circuit::run()
{
    std::string cmd;
    simulate(0);
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
        throw CommandError("Unknown command", "circuit::execute");
    it->second(*this);
}

void nts::Circuit::reset()
{
    for (auto const &comp : _components)
        comp.second.get()->reset();
}