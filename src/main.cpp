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

int basic_error(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Nanoteksptice: Usage: ./nanotekspice file.nts" << std::endl;
        exit(84);
    }
    return 0;
}

int main(int ac, char **av)
{
    basic_error(ac, av);
    try {
        nts::Circuit circuit(av[1]);
        circuit.run();
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return (0);
}