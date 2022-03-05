/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** 4069
*/

#include "4069.hpp"

nts::C4069::C4069(const std::string &name) : _name(name)
{
    _pins.addInput(this, 6, 1, 3, 5, 9, 11, 13);
    _pins.addOutput(this, 6, 2, 4, 6, 8, 10, 12);
}

void nts::C4069::dump() const
{
    std::cout << _name << ": [4069] " << "<" << (this) << ">"<< std::endl;
	_pins.dump();
}

void nts::C4069::setLink(std::size_t pin, IComponent &other, 
                        std::size_t otherPin)
{
	_pins.link(pin, other, otherPin);
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    switch (pin) {
	case 2:
		return _pins.compute(gate::Not, 1);
	case 4:
		return _pins.compute(gate::Not, 3);
	case 6:
		return _pins.compute(gate::Not, 5);
	case 8:
		return _pins.compute(gate::Not, 9);
	case 10:
		return _pins.compute(gate::Not, 11);
	case 12:
		return _pins.compute(gate::Not, 13);
	default:
		return _pins.compute(pin);
	}
}

nts::Tristate nts::C4069::reset()
{
    _pins.reset();
    return (Tristate::Undefined);
}