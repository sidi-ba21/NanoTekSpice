/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** InPin
*/

#include "In_Out_Pin.hpp"

nts::InPin::InPin(IComponent *component, std::size_t pin) :
	Pin(component, pin), _state(Tristate::Undefined), _computed(false)
{

}

nts::Tristate nts::InPin::compute()
{
    if (!isLinked())
        return Tristate::Undefined;
    if (!_computed) {
        _state = _links[0].first.get().compute(_links[0].second);
        _computed = true;
    }
    return _state;
}

void nts::InPin::link(IComponent &other, std::size_t otherPin)
{
    if (isSelf(other, otherPin))
        throw LinkError("link himself", "InPin::link");
     if (!linkExists(other, otherPin)) {
         if (isLinked())
            throw LinkError("Pin linked several times", "InPin::link");
        _links.emplace_back(other, otherPin);
        other.setLink(otherPin, _component, _pin);
    }
}

void nts::InPin::reset()
{
	_computed = false;
}