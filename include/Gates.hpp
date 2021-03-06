/*
** EPITECH PROJECT, 2022
** OOP
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "IComponent.hpp"

namespace gate
{
	nts::Tristate And(nts::Tristate a, nts::Tristate b);
	nts::Tristate Nand(nts::Tristate a, nts::Tristate b);
	nts::Tristate Or(nts::Tristate a, nts::Tristate b);
	nts::Tristate Nor(nts::Tristate a, nts::Tristate b);
	nts::Tristate Xor(nts::Tristate a, nts::Tristate b);
	nts::Tristate Xnor(nts::Tristate a, nts::Tristate b);
	nts::Tristate Not(nts::Tristate val);
	std::string stateToString(nts::Tristate value);

	using GateFct_1_link = std::function<nts::Tristate(nts::Tristate)>;
	using GateFct_2_link = std::function
		<nts::Tristate(nts::Tristate, nts::Tristate)>;
}

#endif /* !GATES_HPP_ */
