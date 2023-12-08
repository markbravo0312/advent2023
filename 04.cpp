
#include "Parser.h"
#include <unordered_set>


void part1(const std::vector<std::string> & lines) {
    int points{0};
    for (auto & line : lines) {
        bool mycards = false;
        std::vector<std::string> splitted = split(line, ' ');
        std::unordered_set<std::string> set{};
        int factor {0};
        for (auto a : splitted) {
            if (a == "|") {
                mycards = true;
            }

            if (!mycards) {
                set.insert(a);
            } else {
                if (set.find(a) != set.end()) {
                    if (!factor) {
                        factor = 1;
                    } else {
                        factor *= 2;
                    }
                }
            }


        } 
        points += factor;
        mycards =  false;
    }

    std::cout << "Result part1:" << points << std::endl;
    
}

void part2() {
    
}


int main()  {

    auto lines = Parser::readLines("../input.txt");
    part1(lines);



}