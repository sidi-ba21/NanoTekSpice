/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(IComponent *component, std::size_t pin) : 
    _component (*component), _pin(pin)
{
}

void nts::Pin::dump() const
{
	std::size_t i(1);

    if (_links.size() == 0) {
		std::cout << "\tPin[" << _pin << "] = Not Linked" << std::endl;
		return;
	}
    if (_links.size() == 1) {
		std::cout << "\tPin[" << _pin << "] = Linked to ";
		std::cout << "<" << &_links[0].first.get() << ">"
        << "[" << std::to_string(_links[0].second) << "]" << std::endl;
		return;
	}
	for (auto const &tmp : _links) {
		std::cout << "\tPin[" << _pin << "] (" << i++ << ") = Linked to ";
		std::cout << "<" << &tmp.first.get() << ">"
        << "[" << std::to_string(tmp.second) << "]" << std::endl;
	}
}

bool nts::Pin::isSelf(IComponent &other, std::size_t otherPin) const
{
	return &_component == &other && _pin == otherPin;
}

bool nts::Pin::linkExists(IComponent &other, std::size_t otherPin) const
{
	for (auto const &tmp : _links) {
		if (&tmp.first.get() == &other && tmp.second == otherPin)
			return true;
	}
	return false;
}

bool nts::Pin::isLinked() const
{
	return _links.size() > 0;
}