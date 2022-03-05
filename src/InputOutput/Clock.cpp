/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock(const std::string& name) : Input(name)
{
}

void nts::Clock::setValue(Tristate value)
{
	_before = value;
}

void nts::Clock::dump() const
{
	std::cout << _name << ": [Clock] " << "<" << (this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pin.dump();
}

void nts::Clock::resetValue()
{
    if (_value == Tristate::False)
		_value = Tristate::True;
	else if (_value == Tristate::True)
		_value = Tristate::False;
}

nts::Tristate nts::Clock::reset()
{
	if (_compute == true)
		resetValue();
	return (_value);
}