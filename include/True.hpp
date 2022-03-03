/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Input.hpp"

namespace nts {

class True final : public Input {
    public:
        True();
        ~True() = default;
		void setValue(Tristate value) override;
        void dump() const override;
};

}

#endif /* !TRUE_HPP_ */
