/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Gates
*/

#include "Gates.hpp"

nts::Tristate gate::And(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::Tristate::True && b == nts::Tristate::True) {
		return nts::Tristate::True;
	}
	else if (a == nts::Tristate::False || b == nts::Tristate::False) {
		return nts::Tristate::False;
	}
	return nts::Tristate::Undefined;
}

nts::Tristate gate::Nand(nts::Tristate a, nts::Tristate b)
{
	return Not(And(a, b));
}

nts::Tristate gate::Or(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::Tristate::True || b == nts::Tristate::True) {
		return nts::Tristate::True;
	}
	else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
		return nts::Tristate::Undefined;
	}
	return nts::Tristate::False;
}

nts::Tristate gate::Nor(nts::Tristate a, nts::Tristate b)
{
	return Not(Or(a, b));
}

nts::Tristate gate::Xor(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
		return nts::Tristate::Undefined;
	}
	else if (a != b) {
		return nts::Tristate::True;
	}
	return nts::Tristate::False;
}

nts::Tristate gate::Xnor(nts::Tristate a, nts::Tristate b)
{
	return Not(Xor(a, b));
}

nts::Tristate gate::Not(nts::Tristate val)
{
	if (val == nts::Tristate::True) {
		return nts::Tristate::False;
	}
	else if (val == nts::Tristate::False) {
		return nts::Tristate::True;
	}
	return nts::Tristate::Undefined;
}