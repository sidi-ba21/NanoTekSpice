/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

namespace nts {

class Pin {
    public:
        Pin(IComponent *component, std::size_t pin);
        Pin(Pin &&) = default;
        Pin &operator=(Pin &&) = default;
        Pin(Pin const &) = delete;
        Pin &operator=(Pin const &) = delete;

        virtual void link(IComponent &other, std::size_t otherPin) = 0;
        virtual Tristate compute() = 0;
        void dump() const;
        bool linkExists(IComponent &other, std::size_t otherPin) const;
        bool isLinked() const;
        bool isSelf(IComponent &other, std::size_t otherPin) const;
        virtual void reset() = 0;
         ~Pin() = default;

    protected:
        std::size_t _pin;
        IComponent &_component;
        std::vector<Link> _links;
};

}

#endif /* !PIN_HPP_ */
