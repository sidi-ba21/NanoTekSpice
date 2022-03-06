/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** OutPin
*/

#include "In_Out_Pin.hpp"

nts::OutPin::OutPin(IComponent *component, std::size_t pin) :
    Pin(component, pin)
{
}

void nts::OutPin::link(IComponent &other, std::size_t otherPin)
{
    if (isSelf(other, otherPin))
        throw LinkError("link himself", "OutPin::link");
    if (!linkExists(other, otherPin)) {
        _links.emplace_back(other, otherPin);
	    other.setLink(otherPin, _component, _pin);
    }
}