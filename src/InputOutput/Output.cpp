/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output(const std::string& name) : _name(name)
{
    _pins.addInput(this, 1);
}


void nts::Output::dump() const
{
	std::cout << _name << ": [Output] " << "<" << (this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pins.dump();
}

void nts::Output::display() const
{
    std::cout << _name << ": " << _value << std::endl;
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	_value = _pins.compute(1);
	return _value;
}

nts::Tristate nts::Output::reset()
{
	_pins.reset();
	_value = Tristate::Undefined;
	return _value;
}

void nts::Output::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	_pins.link(pin, other, otherPin);
}

const std::string &nts::Output::getName()
{
	return (this->_name);
}