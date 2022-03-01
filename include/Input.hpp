/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Pin.hpp"
#include "In_Out_Pin.hpp"

namespace nts {

class Input : public IComponent {
    public:
        Input(const std::string&);
        ~Input() = default;
        Tristate compute(std::size_t pin = 1) override final;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override final;
        void dump() const override;
		virtual void setValue(Tristate value);
        virtual void setValue(std::string const &value) final;
        virtual void display() const;

    protected:
        Tristate _value{ Tristate::Undefined };
        const std::string _name;
        OutPin _pin;
};

}   
#endif /* !INPUT_HPP_ */
