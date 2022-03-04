/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** 4081
*/

#pragma once

#include "IComponent.hpp"
#include "CircuitPin.hpp"
#include <string>

namespace nts
{
class C4081 : public IComponent {
	public:
		C4081(std::string const &);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		void simulate(std::size_t tick) override {};
		Tristate compute(std::size_t pin = 1) override;
        Tristate reset();
		~C4081() = default;
	private:
        const std::string _name;
		CircuitPin _pins;
};

}
