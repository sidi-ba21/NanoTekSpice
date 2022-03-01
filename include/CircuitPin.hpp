/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** CircuitPin
*/

#include "Pin.hpp"
#include "In_Out_Pin.hpp"
#include "Gates.hpp"
#include <memory>

namespace nts
{

class CircuitPin {
    public:
        CircuitPin() = default;
        CircuitPin(CircuitPin const &) = delete;
        CircuitPin &operator=(CircuitPin const &) = delete;
        CircuitPin(CircuitPin &&) = default;
        CircuitPin &operator=(CircuitPin &&) = default;

        void addInput(IComponent *component, std::size_t pin);
        void addOutput(IComponent *component, std::size_t pin);
        Tristate compute(std::size_t pin);
        Tristate compute(gate::GateFct_2_link gate,
                                            std::size_t pinA, std::size_t pinB);
        Tristate compute(gate::GateFct_1_link gate, std::size_t pin);
        bool isLinked(std::size_t pin) const;
        void link(std::size_t pin, IComponent &other, std::size_t otherPin);
        void dump() const;
        void reset();
        ~CircuitPin() = default;

    private:
        std::map<std::size_t, std::unique_ptr<Pin>> _pins;
};

}