/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** 4030
*/

#include "4030.hpp"

nts::C4030::C4030(const std::string &name) : _name(name)
{
    _pins.addInput(this, 8, 1, 2, 5, 6, 8, 9, 12, 13);
    _pins.addOutput(this, 4, 3, 4, 10, 11);
}

void nts::C4030::dump() const
{
    std::cout << _name << ": [4030] " << "<" << (this) << ">"<< std::endl;
	_pins.dump();
}

void nts::C4030::setLink(std::size_t pin, IComponent &other, 
                        std::size_t otherPin)
{
	_pins.link(pin, other, otherPin);
}

nts::Tristate nts::C4030::compute(std::size_t pin)
{
    switch (pin) {
	case 3:
		return _pins.compute(gate::Xor, 1, 2);
	case 4:
		return _pins.compute(gate::Xor, 5, 6);
	case 10:
		return _pins.compute(gate::Xor, 8, 9);
	case 11:
		return _pins.compute(gate::Xor, 12, 13);
	default:
		return _pins.compute(pin);
	}
}

nts::Tristate nts::C4030::reset()
{
    _pins.reset();
    return (Tristate::Undefined);
}