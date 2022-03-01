/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** CircuitPin
*/

#include "CircuitPin.hpp"
#include <cassert>

nts::Tristate nts::CircuitPin::compute(std::size_t pin)
{
    return _pins[pin]->compute();
}

nts::Tristate nts::CircuitPin::compute(gate::GateFct_2_link gate, 
                            std::size_t pinA, std::size_t pinB)
{
    return gate(_pins[pinA]->compute(), _pins[pinB]->compute());
}

nts::Tristate nts::CircuitPin::compute(gate::GateFct_1_link gate,
                                        std::size_t pin)
{
    return gate(_pins[pin]->compute());
}

void nts::CircuitPin::addInput(IComponent *component, std::size_t pin)
{
    assert(component != nullptr);
    _pins[pin] = std::make_unique<InPin>(component, pin);
}

void nts::CircuitPin::addOutput(IComponent *component, std::size_t pin)
{
    assert(component != nullptr);
    _pins[pin] = std::make_unique<OutPin>(component, pin);
}

bool nts::CircuitPin::isLinked(std::size_t pin) const
{
    auto const tmp{ _pins.find(pin) };

    if (tmp != _pins.end())
        return tmp->second->isLinked();
    return false;
}


void nts::CircuitPin::dump() const
{
    for (auto const &pin : _pins)
        pin.second->dump();
}

void nts::CircuitPin::reset()
{
    for (auto &pin : _pins)
        pin.second->reset();
}

void nts::CircuitPin::link(std::size_t pin, IComponent &other, std::size_t otherPin)
{
	_pins[pin]->link(other, otherPin);
}