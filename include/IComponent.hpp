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
#include <tuple>
#include <vector>
#include <functional>

namespace nts
{
	enum class Tristate
	{
		Undefined = (-true),
		True = true,
		False = false
	};
	enum class Gates
	{
		And = 0,
		NAnd,
		Or,
		NOr,
		Xor,
		XNor,
		Not,
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
		virtual nts::Tristate reset() = 0;
	};
	
	using Link = std::pair<std::reference_wrapper<IComponent>, std::size_t>;
	/*
	using _map = std::map<std::string, std::unique_ptr<std::tuple<std::string, Tristate>>>;
	//using _unique = std::unique_ptr<> _pins;
	static std::map <int , std::tuple<_map, _map, _map, Gates>> _link;
	*/
}

std::ostream &operator<<(std::ostream &out, nts::Tristate state);

#endif /* !ICOMPONENT_HPP_ */
	