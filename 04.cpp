
#include "Parser.h"
#include <unordered_set>

#define NUMCARDS 208
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
// 1: 3 matches, 1 card
// 2: 2 matches, 1 card                 ->  2 matches, 2 cards
// 3: 1 match, 1 card                   ->  1 match, 2 cards -> 1 match, 3 cards
// 4: 0 matches                     
void part2(const std::vector<std::string> & lines) {
    int points{0};
    std::array<int, NUMCARDS> counter{};
    counter.fill(1);
    int cards{NUMCARDS};
    for (int i = 0; i < lines.size(); ++i) {
        
        bool mycards = false;
        std::vector<std::string> splitted = split(lines[i], ' ');
        std::unordered_set<std::string> set{};
        int matches {0};
        for (auto a : splitted) {
            if (a == "|") {
                mycards = true;
            }

            if (!mycards) {
                set.insert(a);
            } else {
                if (set.find(a) != set.end()) {
                    matches++;
                }
            }
        } 

        
        int summand = counter[i] * matches;
       

        for (int k = 0;  k < matches && ((i + 1 + k) < counter.size()); ++k) {
            counter[i + 1 + k] += counter[i];
        }

        cards += summand;
        mycards =  false;
    }

    std::cout << "Result part2:" << cards << std::endl;
}


int main()  {

    auto lines = Parser::readLines("../input.txt");
    part1(lines);
    part2(lines);



}