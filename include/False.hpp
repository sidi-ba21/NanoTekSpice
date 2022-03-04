/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Input.hpp"

namespace nts {

class False final : public Input {
    public:
        False(const std::string& name);
        ~False() = default;
		void setValue(Tristate value) override;
        void dump() const override;
        nts::Tristate reset() override;
};

}

#endif /* !FALSE_HPP_ */
