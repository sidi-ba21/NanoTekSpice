/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** CircuitPin
*/

#include "CircuitPin.hpp"
#include "Components.hpp"
#include <cassert>
#include <cstdarg>

nts::Tristate nts::CircuitPin::compute(std::size_t pin)
{
    return _pins[pin]->compute();
}

nts::Tristate nts::CircuitPin::compute(gate::GateFct_1_link gate,
                                        std::size_t pin)
{
    return gate(_pins[pin]->compute());
}

nts::Tristate nts::CircuitPin::compute(gate::GateFct_2_link gate, 
                            std::size_t pinA, std::size_t pinB)
{
    return gate(_pins[pinA]->compute(), _pins[pinB]->compute());
}

void nts::CircuitPin::addInput(IComponent *component, 
                    std::size_t size, std::size_t pin, ...)
{
    va_list arg;
    size_t y = 0;
    assert(component != nullptr);
    for (va_start(arg, pin); y < size; pin = va_arg(arg, size_t), y++)
        _pins[pin] = std::make_unique<InPin>(component, pin);
}

void nts::CircuitPin::addOutput(IComponent *component,
                    std::size_t size, std::size_t pin, ...)
{
    va_list arg;
    size_t y = 0;
    assert(component != nullptr);
    for (va_start(arg, pin); y < size; pin = va_arg(arg, size_t), y++)
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