/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts {

class Output : IComponent {
    public:
        Output(const std::string&);
        ~Output() = default;

        Tristate compute(std::size_t pin = 1) override;
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
		void dump() const override;
		virtual void display() const;

    protected:
        Tristate _value{ Tristate::Undefined };
        const std::string _name;
        
};

}

#endif /* !OUTPUT_HPP_ */
