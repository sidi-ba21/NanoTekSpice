/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Components.hpp"
#include "Factory.hpp"
#include <functional>
#include <unordered_map>
#include <memory>

namespace nts {

    class Circuit {
        public:
            Circuit(char *file);
            ~Circuit() = default;
            void display();
            void simulate(size_t tick = 1);
            void loop();
            void dump();
            void run();
            void reset();
            void set_value(const std::string &name, const std::string &value);
            void execute(const std::string &name);
            void createComponent();
            void createLink();
            void createInput(const std::string &name);
		    void createOutput(const std::string &name);
		    void createTrue(const std::string &name);
		    void createFalse(const std::string &name);
		    void createClock(const std::string &name);
		    void createLogger(const std::string &name);
            bool special_create(const std::string &name, const std::string &type);
        protected:
            nts::Factory _factories;
            Parser file;
            std::unordered_map<std::string, std::function<void(Circuit &)>> _command;
            std::size_t _tick {0};
            std::vector<std::weak_ptr<nts::Input>> _inputs;
            std::vector<std::weak_ptr<nts::Output>> _outputs;
            std::map<std::string, std::shared_ptr<IComponent>> _components;
    };

}

#endif /* !CIRCUIT_HPP_ */
