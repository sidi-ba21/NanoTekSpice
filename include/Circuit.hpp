/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include <functional>
#include <unordered_map>
#include <memory>

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
            void nts::Circuit::execute(const std::string &name);
        protected:
            std::unordered_map<std::string, std::function<void(Circuit &)>> _command;
            std::size_t _tick;
            std::vector<std::weak_ptr<nts::Input>> _inputs;
            std::vector<std::weak_ptr<nts::Output>> _outputs;
    }; 

}

#endif /* !CIRCUIT_HPP_ */
