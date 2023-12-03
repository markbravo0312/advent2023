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


void gear_of_number(std::set<std::pair<long long, long long>>& gears, long long i, long long j, std::vector<std::string> input)
{
    for(long long a = i - 1; a <= i + 1; ++a)
    {

        for(long long b = j - 1; b <= j + 1; ++b)
        {

            if(input[a][b] == '*')
            {
                gears.insert({a, b});
            }
        }
    }
}

long long part1(std::vector<std::string> input)
{
    long long row_size = input[0].size();
    long long sum = 0;

    input.insert(input.begin(), std::string(row_size, '.'));
    input.push_back(std::string(row_size, '.'));

    for(long long i = 0; i < input.size(); ++i)
    {
        input[i].insert(input[i].begin(), '.');
    }

    for(long long i = 0; i < input.size(); ++i)
    {
        input[i].push_back('.');
    }

    for(long long i = 1; i < input.size() - 1; ++i)
    {
        std::string number;
        bool is_part_number = false;

        for(long long j = 1; j < input[i].size() - 1; ++j)
        {
            int character = input[i][j];

            bool top_left = is_symbol(input[i - 1][j - 1]);
            bool top_center = is_symbol(input[i - 1][j]);
            bool top_right = is_symbol(input[i - 1][j + 1]);
            bool middle_left = is_symbol(input[i][j - 1]);
            bool middle_right = is_symbol(input[i][j + 1]);
            bool bottom_left = is_symbol(input[i + 1][j - 1]);
            bool bottom_center = is_symbol(input[i + 1][j]);
            bool bottom_right = is_symbol(input[i + 1][j + 1]);

            if(isdigit(character))
            {
                number += character;

                if(top_left || top_center || top_right || middle_left || middle_right || bottom_left || bottom_center || bottom_right)
                    is_part_number = true;
            }
            if(!isdigit(character) || j == row_size )
            {

                if(is_part_number && !number.empty() )
                {
                    sum += std::stol(number);
                }
                number.clear();
                is_part_number = false;

            }
        }
    }
    return sum;
}




long part2 (std::vector<std::string> input) {
    long long row_size = input[0].size();
    long long sum = 0;

    input.insert(input.begin(), std::string(row_size, '.'));
    input.push_back(std::string(row_size, '.'));

    for(long long i = 0; i < input.size(); ++i)
    {
        input[i].insert(input[i].begin(), '.');
    }

    for(long long i = 0; i < input.size(); ++i)
    {
        input[i].push_back('.');
    }
    std::set<std::pair<long long, long long>> gears;

    std::map<std::pair<long long, long long>, std::vector<long long>> gear_to_number;
    for(long long i = 1; i < input.size() - 1; ++i)
    {
        std::string number;

        for(long long j = 1; j < input[i].size() - 1; ++j)
        {
            int character = input[i][j];
            if(isdigit(character))
            {
                number += character;
                gear_of_number(gears, i, j, input);
            }

            if(!isdigit(character) || j == row_size )
            {
                //std::cout << number << '\n';
                if (!number.empty() && !gears.empty())
                {
                    for(auto p : gears)
                    {
                        gear_to_number[p].push_back(std::stoi(number));
                    }
                }
                gears.clear();
                number.clear();
            }
        }
    }

    for(auto p : gear_to_number)
    {
        if(!p.second.empty())
        {
            if(p.second.size() >= 2)
            {
                long long mutiple = 1;

                for(auto i : p.second)
                {
                    mutiple *= i;
                }
                sum += mutiple;
            }
        }
    }
    return sum;
}

int main () {

    auto inp = Parser::readLines("../input.txt");
    std::cout << "result part 1: " << part1(inp) << std::endl;
    std::cout << "result part 2: " << part2(inp) << std::endl;
}