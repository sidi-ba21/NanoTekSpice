/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"



nts::Circuit::Circuit()
{
    _command["loop"] = &loop;
    _command["simulate"] = &simulate;
    _command["dump"] = &dump;
    _command["exit"] = &stop;
    _command["display"] = &display;
}

void nts::Circuit::display()
{
    for (auto const &input : _inputs) {
		input.lock()->display();
	}
	for (auto const &output : _outputs) {
		output.lock()->display();
	}
}

void nts::Circuit::simulate()
{
    for (auto const &output : _outputs) {
		output.lock()->compute();
	}
}

void nts::Circuit::stop()
{

}

void nts::Circuit::loop()
{
    
}

void nts::Circuit::dump()
{
    
}

void nts::Circuit::set_value()
{
    
}

void nts::Circuit::execute(const std::string &name)
{
    if (_command.find(name) == _command.end())
        throw std::runtime_error("Unknown command");
  // _command[name]();
}