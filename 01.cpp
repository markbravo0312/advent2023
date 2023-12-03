#include <unordered_set>
#include "Parser.h"
#include <vector> 
#include <unordered_map>
#include <cctype> 



int parseForDigit (size_t index, const std::string& line) {

    static std::unordered_map<std::string,int> map = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
     {"seven", 7}, {"eight", 8}, {"nine", 9}, {"zero", 0}};
    
    if (index >= line.size()) {
        return -1;
    }

    for (int len = 3; len <= 5; ++len) { // Assuming the longest word is "three" with 5 letters
        if (index + len > line.size()) break;

        std::string word = line.substr(index, len);
        auto it = map.find(word);
        if (it != map.end()) {
            return it->second;
        }
    }

    return -1;
}


int main () {
	std::vector<std::string> vec(Parser::readLines("../input.txt"));

    



    std::unordered_set<char> chars = {'o', 't', 'f', 's', 'e', 'n', 'z'};

    char first;
    char last;
     
    size_t total = 0;

    for (const auto& a : vec) {
        first = 0;
        last = 0;
        for (size_t i = 0; i < a.size(); i++) {
            if (chars.contains(a[i])) {
                int num = parseForDigit(i, a);
                if (num >= 0) {
                    if (first == 0) {
                        first = last = (num + '0');
                    } else {
                        last = num + '0';
                    }
                }
            }

            if (isdigit(a[i])) {
                if (first == 0) {
                    first = last = a[i];
                } else {
                    last = a[i];
                }
            }
        }
        

        std::string num_as_string;
        num_as_string += first;
        num_as_string += last;
        std::cout<< num_as_string << std::endl;
        total += std::stoi(num_as_string);
    }

    std::cout << "result is: " << total << std::endl;
    
}	