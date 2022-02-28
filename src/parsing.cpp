/*
** EPITECH PROJECT, 2022
** parsing
** File description:
** parsing
*/


#include <algorithm>
#include <cassert>
#include <cctype>
#include <locale>

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//#include <bits/stdc++.h>
//#include <iostream>

struct Chipset {
  std::string type;
  std::string name;
};

struct Links {
  std::string name;
  std::string gate;
};

int basic_error(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Nanoteksptice: Usage: ./nanotekspice file.nts" << std::endl;
        exit(84);
    }
    return 0;
}

int find_chipsets(std::string data)
{
    std::size_t chipset;
    std::size_t links;
    std::string wordd;
    std::string word;
    std::vector<Chipset> *tab_chipset = new std::vector<Chipset>[20];
    std::vector<Links> *tab_links = new std::vector<Links>[20];

    chipset = data.find(".chipsets:");
    std::stringstream test = std::stringstream(&data[chipset]);
    
    test >> word;
    std::cout << word << std::endl;
    while (test >> word && word.compare(".links:") != 0 && test >> wordd) {
        tab_chipset->push_back((Chipset){word, wordd}); 
    }
    std::vector<Chipset>::iterator mc;
    for (mc = tab_chipset->begin(); mc != tab_chipset->end(); mc++) {
        std::cout << mc->type << "-> "
             << mc->name << "\n";
    }
    std::cout << word << std::endl;
    while (test >> word && test >> wordd) {
        tab_links->push_back((Links){word, wordd}); 
    }
    std::vector<Links>::iterator ml;
    for (ml = tab_links->begin(); ml != tab_links->end(); ml++) {
        std::cout << ml->name << "-> "
             << ml->gate << "\n";
    }
    //std::map<std::string, std::string>::iterator m;
    //for (m = FW.begin(); m != FW.end(); m++) {
    //    std::cout << m->first << "-> "
    //         << m->second << "\n";
    //}
    //for (int i = 0; i < 10; i++)
    //    tab[i] << test;
    //.insert(std::make_pair("earth", 1));
    //FW[word] = wordd;
    return 0;
}

std::string load_file_in_mem(const char *filepath)
{
    std::string data;
    std::ifstream file(filepath);
    std::stringstream buffer;

    if (!file.is_open()) {
       std::cerr << "Nanotekspice: " << filepath << ": No such file or directory\n";
       return NULL;
    }
    buffer << file.rdbuf();
    data = buffer.str();
    find_chipsets(data);
    return data;
}

//int purge(std::string data)
//{
//    clean_comment(data);
//    clean_space(data);
//}
//
//int clean_comment(std::string data)
//{
//    for (int i = 0; i < )
//        if (data[i] == '#')
//    std::find_if()
//
//}
//
//int clean_space(std::string data)
//{
//
//}
