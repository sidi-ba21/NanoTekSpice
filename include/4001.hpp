/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** 4001
*/

#pragma once

#include "IComponent.hpp"
#include "CircuitPin.hpp"
#include <string>

namespace nts
{
class C4001 : public IComponent {
	public:
		C4001(std::string const &);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		void simulate(std::size_t tick) override {};
		Tristate compute(std::size_t pin = 1) override;
        Tristate reset();
		~C4001() = default;
	private:
        const std::string _name;
		CircuitPin _pins;
};

}