/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** False
*/

#include "False.hpp"

nts::False::False(const std::string& name) : Input(name)
{
    _value = nts::Tristate::False;
	_before = nts::Tristate::False;
}

void nts::False::setValue(Tristate value)
{
	std::cout << "Input error: False value cannot be changed." << std::endl;
}

void nts::False::dump() const
{
	std::cout << _name << ": [False] " << "<" << (this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pin.dump();
}

nts::Tristate nts::False::reset()
{
	return (_value);
}

void nts::False::display() const
{
}