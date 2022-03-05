/*
** EPITECH PROJECT, 2022
** parsing
** File description:
** parsing
*/

#include "Parser.hpp"
#include "Error.hpp"

bool is_number(const std::string &s)
{
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

Parser::Parser(const char *filepath)
: _filepath(filepath)
{
    load_file_in_mem(filepath);
    fill_array();
}

Parser::~Parser()
{

}

void Parser::clean_buffer()
{
    std::regex space_re("[(\\s):]");

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
    std::string tmp;
    bool check = false;

    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, _str)) {
        clean_buffer();
        if (_str[0] == ':' || (_str[0] == '.' && 
            (_str.compare(".chipsets:") != 0 && _str.compare(".links:") != 0)))
            throw std::exception();
        if (check && !if_right_arg(tmp))
            throw std::exception();
        if (_str.compare(".chipsets:") == 0 || _str.compare(".links:") == 0) {
            check = true;
            tmp = _str;
        }
    }
    _str = _buff.str();
    return 0;
}

void Parser::fill_array()
{
    std::string tmp;
    std::string tmp2;
    std::string pin1;
    std::string pin2;
    std::size_t count = 0;

    _buff >> tmp;
    if (tmp.compare(".chipsets") != 0)
        throw std::exception();
    while (_buff >> tmp && tmp.compare(".links") != 0 && _buff >> tmp2) {
        _chipsets.push_back((chipset){tmp, tmp2});
        count++;
    }
    if (tmp.compare(".links") != 0 || count == 0)
        throw std::exception();
    count = 0;
    while (_buff >> tmp >> pin1 && _buff >> tmp2 >> pin2) {
        if (!is_number(pin1) || !is_number(pin2))
            throw std::exception();
        _links.push_back((links){(link){tmp, (std::size_t)std::stoi(pin1)},
            (link){tmp2, (std::size_t)std::stoi(pin2)}});
        count++;
    }
    if (count == 0)
        throw std::exception();
}

int Parser::disp()
{
    std::cout << _str << std::endl;
    return 0;
}

bool Parser::if_right_arg(const std::string &section)
{
    std::regex space_re("[(\\s):]");
    std::stringstream temp;
    std::string arg;
    std::size_t i = 0;

    temp << std::regex_replace(_str, space_re, " ") << std::endl;
    while (std::getline(temp, arg, ' ')) {
		if (arg.size() > 0)
            i++;
	}
    if (section.compare(".chipsets:") == 0) {
        if (i != 2 && arg.compare("\n") != 0)
            return false;
    }
    if (section.compare(".links:") == 0 &&
    temp.str().compare(0, 6,".links") != 0) {
        if (i != 4 && arg.compare("\n") != 0)
            return false;
    }
    return true;
}

std::vector<chipset> Parser::getChipsets()
{
    sort(_chipsets.begin(), _chipsets.end());
    return (_chipsets);
}

std::vector<links> Parser::getLinks()
{
    return (_links);
}