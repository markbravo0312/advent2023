#include "Parser.h"
#include <set>


std::set<int> seeds{};


void parseSeeds(const std::string& line) {
    std::vector<std::string> splitted = split(line, ' ');
    for (int i = 1; i < splitted.size(); ++ i) {
        seeds.insert( std::stoi(splitted[i]) );
    }
}

void part1 (const std::vector<std::string>& lines) {

    parseSeeds(lines[0]);
    
    
}



void part2 (const std::vector<std::string>& lines) {
    
}


int main () {

    auto lines = Parser::readLines("../input.txt");
    
    part1(lines);
    part2(lines);

}