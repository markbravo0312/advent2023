#include "Parser.h"
#include <cctype>
#include <iostream>

#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>
#include <map>

bool is_symbol(char c)
{
    return (c != '.' && !isdigit(c));
}


void get_gear(size_t i, size_t j, std::vector<std::string> input, std::set<std::pair<size_t, size_t>>& gears) {
    for(size_t k = i - 1; k <= i + 1; ++k)
    {

        for(size_t r = j - 1; r <= j + 1; ++r)
        {

            if(input[k][r] == '*')
            {
                gears.insert({k, r});
            }
        }
    }
}

size_t part1(std::vector<std::string> input)
{
    size_t rows = input[0].size();
    size_t total = 0;

    input.insert(input.begin(), std::string(rows, '.'));
    input.push_back(std::string(rows, '.'));

    for(size_t i = 0; i < input.size(); ++i)
    {
        input[i].insert(input[i].begin(), '.');
    }

    for(size_t i = 0; i < input.size(); ++i)
    {
        input[i].push_back('.');
    }

    for(size_t i = 1; i < input.size() - 1; ++i) {
        std::string number;
        bool is_part_number = false;

        for(size_t j = 1; j < input[i].size() - 1; ++j){
            int character = input[i][j];

            bool tl = is_symbol(input[i - 1][j - 1]);
            bool tc = is_symbol(input[i - 1][j]);
            bool tr = is_symbol(input[i - 1][j + 1]);
            bool ml = is_symbol(input[i][j - 1]);
            bool mr = is_symbol(input[i][j + 1]);
            bool bl = is_symbol(input[i + 1][j - 1]);
            bool bc = is_symbol(input[i + 1][j]);
            bool br = is_symbol(input[i + 1][j + 1]);

            if(isdigit(character))
            {
                number += character;

                if(tl || tc || tr || ml || mr || bl || bc || br)
                    is_part_number = true;
            }
            if(!isdigit(character) || j == rows )
            {

                if(is_part_number && !number.empty() )
                {
                    total += std::stol(number);
                }
                number.clear();
                is_part_number = false;

            }
        }
    }
    return total;
}




size_t part2 (std::vector<std::string> input) {
    size_t rows = input[0].size();
    size_t total = 0;

    input.insert(input.begin(), std::string(rows, '.'));
    input.push_back(std::string(rows, '.'));

    for(size_t i = 0; i < input.size(); ++i) {
        input[i].insert(input[i].begin(), '.');
    }

    for(size_t i = 0; i < input.size(); ++i) {
        input[i].push_back('.');
    }
    std::set<std::pair<size_t, size_t>> gears;

    std::map<std::pair<size_t, size_t>, std::vector<size_t>> gtn;

    for(size_t i = 1; i < input.size() - 1; ++i) {
        std::string number;

        for(size_t j = 1; j < input[i].size() - 1; ++j) {
            int character = input[i][j];
            if(isdigit(character)) {
                number += character;
                get_gear(i, j, input, gears);
            }

            if(!isdigit(character) || j == rows ) {
                if (!number.empty() && !gears.empty()) {
                    for(auto p : gears) {
                        gtn[p].push_back(std::stoi(number));
                    }
                }
                gears.clear();
                number.clear();
            }
        }
    }

    for(auto p : gtn) {
        if(!p.second.empty()) {
            if(p.second.size() >= 2) {
                size_t mutiple = 1;
                for(auto i : p.second) {
                    mutiple *= i;
                }
                total += mutiple;
            }
        }
    }
    return total;
}

int main () {

    auto inp = Parser::readLines("../input.txt");
    std::cout << "result part 1: " << part1(inp) << std::endl;
    std::cout << "result part 2: " << part2(inp) << std::endl;
}