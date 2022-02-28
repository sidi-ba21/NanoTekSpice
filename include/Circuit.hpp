/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include <functional>

namespace nts {

    class Circuit {
        public:
            Circuit();
            ~Circuit();
            void display();
            void simulate();
            void stop();
            void loop();
            void dump();
            void set_value();
        protected:
            std::map<std::string, std::function<void(Circuit &)>> _command;
            std::size_t _tick;
    }; 

}

#endif /* !CIRCUIT_HPP_ */
