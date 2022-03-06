/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** True
*/

#include "True.hpp"

nts::True::True(const std::string& name) : Input(name)
{
    _value = nts::Tristate::True;
	_before = nts::Tristate::True;
}

void nts::True::setValue(Tristate value)
{
	std::cout << "Input error: True value cannot be changed." << std::endl;
}

void nts::True::dump() const
{
	std::cout << _name << ": [True] " << "<" << &(*this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pin.dump();
}

nts::Tristate nts::True::reset()
{
	return (_value);
}

void nts::True::display() const
{
}