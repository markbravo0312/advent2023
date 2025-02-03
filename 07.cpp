#include <map> 
#include <vector> 
#include <string>
#include "Parser.h"
#include <set> 
#include <algorithm>



enum class types : int {
    FIVE_OF_A_KIND = 7,
    FOUR_OF_A_KIND = 6,
    FULL_HOUSE = 5,
    THREE_OF_A_KIND = 4,
    TWO_PAIR = 3,
    ONE_PAIR = 2,
    HIGH_CARD = 1,
};

std::map<char, int> create_map() {
    std::map<char,int> m;
    m['A'] = 13;
    m['K'] = 12;
    m['Q'] = 11;
    m['J'] = 10;
    m['T'] = 9;
    m['9'] = 8;
    m['8'] = 7;
    m['7'] = 6;
    m['6'] = 5;
    m['5'] = 4;
    m['4'] = 3;
    m['3'] = 2;
    m['2'] = 1;
    return m;
}

std::map<int, char> create_map_2() {
    std::map<int,char> m;
    m[13] = 'A';
    m[12] = 'K';
    m[11] = 'Q';
    m[10] = 'J';
    m[9] = 'T';
    m[8] = '9';
    m[7] = '8';
    m[6] = '7';
    m[5] = '6';
    m[4] = '5';
    m[3] = '4';
    m[2] = '3';
    m[1] = '2';
    return m;
}

std::map<char,int> card_to_val = create_map();

class Hand {
    public:
    types type;
    std::vector<int> vals;
    int bid;
    

    Hand(std::string hand, std::string bid) {
        std::map<char, int> count_of_cards;
        int count_most_frequent = 0;

        for (int i = 0; i < 5; i++) {
            vals.push_back(card_to_val[hand[i]]);

            if (++count_of_cards[hand[i]] > count_most_frequent) {
                count_most_frequent = count_of_cards[hand[i]];
            }

            if (count_most_frequent == 5) {
                type = types::FIVE_OF_A_KIND;
            } else if (count_most_frequent == 4) {
                type = types::FOUR_OF_A_KIND;
            } else if (count_most_frequent == 3) {
            bool has_pair = std::any_of(count_of_cards.begin(), count_of_cards.end(), [](auto& pair) {
                return pair.second == 2;
            });
                if (has_pair) {
                    type = types::FULL_HOUSE;
                } else {
                    type = types::THREE_OF_A_KIND;
                }
            } else if (count_most_frequent == 2) {
                int pair_count = std::count_if(count_of_cards.begin(), count_of_cards.end(), [](auto& pair) {
                    return pair.second == 2;
                });
                if (pair_count == 2) {
                    type = types::TWO_PAIR;
                } else {
                    type = types::ONE_PAIR;
                }
            } else {
                type = types::HIGH_CARD;
            }
        }

        this->bid = stoi(bid);
    }

    
    bool operator<(const Hand& other) const {
        if (this->type != other.type) {
            return this->type < other.type;
        }

        return this->vals < other.vals;
    }

};

int main() {
    std::vector<std::string> lines = Parser::readLines("../input.txt");
    std::vector<Hand> hands;
    for (int i = 0; i < lines.size(); i++) {
        std::vector<std::string> str = split(lines[i], ' ');
        Hand h(str[0], str[1]);
        hands.push_back(h);
    }

    std::sort(hands.begin(), hands.end());

    int rank = 1;
    int total{0};
    std::map<int, char> map = create_map_2();
    for (int i = 0; i < hands.size(); i++, rank++) {
        for (const auto& c : hands[i].vals) {
            std::cout << map[c];
        }
        std::cout << std::endl;
        total += rank * hands[i].bid;
    }


    


    std::cout << "answer to part1 : " << total << std::endl;

}
// K9997
// KT272
// KTTT9
// KTTQ6