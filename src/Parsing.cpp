/*
** EPITECH PROJECT, 2022
** parsing
** File description:
** parsing
*/

#include "Parser.hpp"
#include "Error.hpp"

int basic_error(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Nanoteksptice: Usage: ./nanotekspice file.nts" << std::endl;
        exit(84);
    }
    return 0;
}

Parser::Parser(const char *filepath)
: _filepath(filepath)
{
    load_file_in_mem(filepath);
}

Parser::~Parser()
{

}

void Parser::clean_buffer()
{
    std::regex space_re("[(\\s+):]");

    auto first{ std::find_if(_str.begin(), _str.end(), [](char c) {
        return c == '#';
    }) };
    _str.erase(first, _str.end());
    if (_str.length() > 0)
        _buff << std::regex_replace(_str, space_re, " ") << std::endl;
}

int Parser::load_file_in_mem(const char *filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, _str)) {
        clean_buffer();
    }
    _str = _buff.str();
    return 0;
}

void Parser::fill_array()
{
    std::string tmp;
    std::string tmp2;
    std::size_t stmp;
    std::size_t stmp2;

    _buff >> tmp;
    if (tmp.compare(".chipsets") != 0)
        throw std::exception();
    while (_buff >> tmp && tmp.compare(".links") != 0 && _buff >> tmp2)
        _chipsets.push_back((chipset){tmp, tmp2});
    if (tmp.compare(".links") != 0)
        throw std::exception();
    while (_buff >> tmp >> stmp && _buff >> tmp2 >> stmp2) {
        if (!isdigit(stmp) || !isdigit(stmp2))
            throw std::exception();
        _links.push_back((links){(link){tmp, stmp},(link){tmp2, stmp2}});
    }
    //std::vector<links>::iterator ml;
    //for (ml = _links.begin(); ml != _links.end(); ml++) {
    //    std::cout << ml->first.name << "-> " << "<---->" << ml->first.pin
    //         << ml->second.name << "->" << ml->second.pin << "\n";
    //}
}

int Parser::disp()
{
    try {
        fill_array();
    } catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
        exit (84);
    }
    return 0;
}
