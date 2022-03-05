/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include "Components.hpp"

namespace nts {

class Factory {
    public:
        Factory();
        Factory(Factory &&) = default;
		Factory &operator=(Factory &&) = default;
        Factory(Factory const &) = delete;
		Factory &operator=(Factory const &) = delete;
        ~Factory() = default;
        std::unique_ptr<IComponent> createComponent(std::string const &type, std::string const &value) const;
		std::unique_ptr<Input> createInput(std::string const &value) const;
		std::unique_ptr<True> createTrue(std::string const &value) const;
		std::unique_ptr<False> createFalse(std::string const &value) const;
		std::unique_ptr<Clock> createClock(std::string const &value) const;
		std::unique_ptr<Output> createOutput(std::string const &value) const;
		//std::unique_ptr<Logger> createLogger(std::string const &value) const;

    private:
        using fct = std::function<std::unique_ptr<IComponent>
            (Factory const &, std::string const &)>;
        std::unordered_map<std::string, fct> _components;
        std::unique_ptr<IComponent> create4001(std::string const &value) const;
		std::unique_ptr<IComponent> create4008(std::string const &value) const;
		std::unique_ptr<IComponent> create4011(std::string const &value) const;
		std::unique_ptr<IComponent> create4013(std::string const &value) const;
		std::unique_ptr<IComponent> create4017(std::string const &value) const;
		std::unique_ptr<IComponent> create4030(std::string const &value) const;
		std::unique_ptr<IComponent> create4040(std::string const &value) const;
		std::unique_ptr<IComponent> create4069(std::string const &value) const;
		std::unique_ptr<IComponent> create4071(std::string const &value) const;
		std::unique_ptr<IComponent> create4081(std::string const &value) const;
		std::unique_ptr<IComponent> create4094(std::string const &value) const;
		std::unique_ptr<IComponent> create4514(std::string const &value) const;
};

}

#endif /* !FACTORY_HPP_ */
