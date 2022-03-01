/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(const std::string& name) : _name(name), _pin(this, 1)
{ 
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    return _value;
}

void nts::Input::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{

}

void nts::Input::dump() const
{
	std::cout << "[Input] " << "<" << (this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pin.dump();
}

void nts::Input::setValue(Tristate value)
{
	_value = value;
}

void nts::Input::setValue(std::string const &value)
{
	if (value.compare("1") == 0) {
		setValue(Tristate::True);
	}
	else if (value.compare("0") == 0) {
		setValue(Tristate::False);
	}
	else {
		setValue(Tristate::Undefined);
	}
}

void nts::Input::display() const
{
    std::cout << _name << ": " << _value << std::endl;
}