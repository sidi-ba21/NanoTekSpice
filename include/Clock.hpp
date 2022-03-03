/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Input.hpp"

namespace nts {

class Clock final : public Input {
    public:
        Clock(const std::string& name);
        ~Clock() = default;
		void setValue(Tristate value) override;
        void resetValue();
        void dump() const override;
};

}

#endif /* !CLOCK_HPP_ */
