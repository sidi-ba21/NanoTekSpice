/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** OutPin
*/

#include "In_Out_Pin.hpp"

nts::OutPin::OutPin(IComponent *component, std::size_t pin) :
    Pin(component, pin)
{}

void nts::OutPin::link(IComponent &other, std::size_t otherPin)
{

}