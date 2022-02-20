/*
** EPITECH PROJECT, 2022
**  
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <array>
#include <map>
#include <utility>

namespace nts
{
	enum class Tristate
	{
		Undefined = (-true),
		True = true,
		False = false
	};

	class IComponent
	{
	public:
		IComponent() = default;
		virtual ~IComponent() = default;

		IComponent(IComponent const &) = delete;
		IComponent(IComponent &&) = default;

		IComponent &operator=(IComponent const &) = delete;
		IComponent &operator=(IComponent &&) = default;
		virtual void simulate(std::size_t tick) = 0;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	};
}

std::ostream &operator<<(std::ostream &out, nts::Tristate state);

#endif /* !ICOMPONENT_HPP_ */
