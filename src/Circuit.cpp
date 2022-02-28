/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-tekspice-geraud.deltour
** File description:
** Circuit
*/

#include "Circuit.hpp"



nts::Circuit::Circuit()
{
    _command["loop"] = &loop;
    _command["simulate"] = &simulate;
    _command["dump"] = &dump;
    _command["exit"] = &stop;
    _command["display"] = &display;
}

nts::Circuit::~Circuit()
{

}

void nts::Circuit::display()
{

}

void nts::Circuit::simulate()
{

}

void nts::Circuit::stop()
{

}

void nts::Circuit::loop()
{
    
}

void nts::Circuit::dump()
{
    
}

void nts::Circuit::set_value()
{
    
}