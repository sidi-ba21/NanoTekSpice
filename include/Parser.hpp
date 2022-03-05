/*
** EPITECH PROJECT, 2022
** Parsing
** File description:
** Parsing
*/

#include <algorithm>
#include <cassert>
#include <cctype>
#include <locale>
#include "IComponent.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#ifndef PARSERG_HPP_
#define PARSERG_HPP_

//struct chipset {
//  std::string type;
//  std::string name;
//};

struct link {
    std::string name;
    std::size_t pin;
};

using chipset = std::pair<std::string, std::string>;
using links = std::pair<link, link>;

namespace nts {
    
}

class Parser {
    public:
        Parser(const char *filepath);
        ~Parser();
        int load_file_in_mem(const char *file);
        void clean_buffer();
        void fill_array();
        int disp();
        bool if_right_arg(const std::string &section);
        std::vector<chipset> getChipsets();
        std::vector<links> getLinks();
    private:
        const char *_filepath;
        std::string _str;
        std::stringstream _buff;
        std::vector<chipset> _chipsets;
        std::vector<links> _links;
};

#endif /* !PARSER_HPP_ */
