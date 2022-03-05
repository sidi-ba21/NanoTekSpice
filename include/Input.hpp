/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"
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
        void simulate(std::size_t tick) override {};
        virtual void setValue(std::string const &value) final;
        virtual void display() const;
        const std::string &getName();
        void set_compute();
        virtual nts::Tristate reset() override;
    protected:
        Tristate _value{ Tristate::Undefined };
        Tristate _before { Tristate::Undefined };
        const std::string _name;
        bool _compute {false};
        OutPin _pin;
};

}   
#endif /* !INPUT_HPP_ */
