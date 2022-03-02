/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"



nts::Circuit::Circuit(char *av)
{
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
	for (auto const &output : _outputs) {
		output.lock()->compute();
	}
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

void nts::Circuit::run()
{
    std::string cmd;

    std::cout << "> " << std::flush;
    while (std::getline(std::cin, cmd) && cmd.compare("exit")) {
        if (cmd.compare("") != 0)
           execute(cmd);
        std::cout << "> " << std::flush;
    }
}

void nts::Circuit::execute(const std::string &name)
{
    auto it = _command.find(name);
    if (it == _command.end()) {
        std::cout << "Unknown command" << std::endl;
        return;
    }
    it->second(*this);
}