/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** main
*/

#include "IComponent.hpp"
#include "Gates.hpp"
#include "Parser.hpp"
#include <fstream>

int main(int ac, char **av)
{
    basic_error(ac, av);
    load_file_in_mem(av[1]);
/*
    std::string a = "a";
    std::string b = "b";
    std::string out = "out";
    nts::_pins[a] = nts::Tristate::False;
    nts::_pins[b] = nts::Tristate::False;
    nts::_pins[out] = nts::Tristate::Undefined;
    nts::_link[0] = std::make_tuple(nts::_pins[a], nts::_pins[b], nts::_pins[out], nts::Gates::Xor);
    std::get<2>(nts::_link[0]) = gate::Or(std::get<0>(nts::_link[0]), std::get<1>(nts::_link[0]));
    if (std::get<2>(nts::_link[0]) == nts::Tristate::True)
        std::cout << "True" << std::endl;
    else if (std::get<2>(nts::_link[0]) == nts::Tristate::False)
        std::cout << "False" << std::endl;
    else
        std::cout << "Undefined" << std::endl;*/
    return (0);
}