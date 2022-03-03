/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include<algorithm>

nts::Circuit::Circuit(char *av)
{
    std::shared_ptr<Input> input = std::move(std::make_unique<nts::Input>("In"));
    std::shared_ptr<Output> output = std::move(std::make_unique<nts::Output>("Out"));
    input->setLink(1, *output, 1);
    _inputs.emplace_back(input);
    _outputs.emplace_back(output);
    _components.emplace_back(input);
    _components.emplace_back(output);
    
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

void nts::Circuit::loop()
{

}

void nts::Circuit::dump()
{
	for (auto const &comp : _components) {
		comp->dump();
	}
}

void nts::Circuit::set_value(const std::string &name, const std::string &value)
{
    for (auto &comp : _inputs) {
        if (comp.lock()->getName().compare(name) == 0) {
            comp.lock()->setValue(value);
            return;
        }
    }
    std::cout << "Input error: 'a' doesn't exist." << std::endl;
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
    std::string tmp = name;
    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
    auto it = _command.find(tmp);
    if (tmp.find('=') != std::string::npos) {
        auto str = tmp.substr(0, tmp.find('='));
        auto value = tmp.substr(tmp.find('=') + 1);
        set_value(str, value);
        return;
    }
    else if (it == _command.end()) {
        std::cout << "Unknown command" << std::endl;
        return;
    }
    it->second(*this);
}

void nts::Circuit::reset()
{
    for (auto const &comp : _components)
        comp->reset();
}