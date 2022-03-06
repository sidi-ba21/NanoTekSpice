/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** main
*/

#include "IComponent.hpp"
#include "Circuit.hpp"
#include "Gates.hpp"
#include "Parser.hpp"
#include <fstream>

void basic_error(int ac, char **av)
{
    if (ac != 2)
        throw FileWrongError("Nanoteksptice: Usage: ./nanotekspice file.nts");
}

int main(int ac, char **av)
{
    try {
        basic_error(ac, av);
        nts::Circuit circuit(av[1]);
        circuit.run();
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return (0);
}