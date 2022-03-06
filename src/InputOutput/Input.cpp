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
	_compute = true;
	_value = _before;
    return _value;
}

void nts::Input::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	if (pin != 1)
		throw LinkError("bad pin != 1", "Input::setlink");
	_pin.link(other, otherPin);
}

void nts::Input::dump() const
{
	std::cout << _name << ": [Input] " << "<" << &(*this) << ">"<< std::endl;
	std::cout << "\tValue = " << _value << std::endl;
	_pin.dump();
}

void nts::Input::setValue(Tristate value)
{
	_compute = false;
	_before = value;
}

void nts::Input::setValue(std::string const &value)
{
	if ((value.compare("U") != 0 && std::stoi(value) != 0 && 
	std::stoi(value) != 1) || value.find('+') != value.npos)
		throw ValueReceiveError("Input value must be either 0 or 1 or U.");
	if (value.compare("1") == 0) {
		setValue(Tristate::True);
	}
	else if (value.compare("0") == 0) {
		setValue(Tristate::False);
	}
	else if (value.compare("U") == 0) {
		setValue(Tristate::Undefined);
	}
}

void nts::Input::display() const
{
    std::cout << "  " << _name << ": " << _value << std::endl;
}

const std::string &nts::Input::getName()
{
	return (this->_name);
}

nts::Tristate nts::Input::reset()
{
	return (_value);
}