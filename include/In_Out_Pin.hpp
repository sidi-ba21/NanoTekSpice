/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** In_Out_Pin
*/

#ifndef IN_OUT_PIN_HPP_
#define IN_OUT_PIN_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts {

class InPin final : public Pin {
    public:
        InPin(IComponent *component, std::size_t pin);
        Tristate compute() override;
        void link(IComponent &other, std::size_t otherPin) override;
        void reset() override;
        ~InPin() = default;

    private:
        bool _computed;
        Tristate _state;
};

class OutPin final : public Pin {
    public:
        OutPin(IComponent *component, std::size_t pin);
        Tristate compute() override {
            return Tristate::Undefined;
        }
        void link(IComponent &other, std::size_t otherPin) override;
        void reset() override {
        }
        ~OutPin() = default;
};

}

#endif /* !IN_OUT_PIN_HPP_ */
