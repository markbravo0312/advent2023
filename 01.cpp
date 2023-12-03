#include <unordered_set>
#include "Parser.h"
#include <vector> 
#include <unordered_map>






int main () {
	std::vector<std::string> vec(Parser::readLines("../input.txt"));

    std::unordered_map<std::string,int> map = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
     {"seven", 7}, {"eight", 8}, {"nine", 9}};\



    

    char first;
    char last;
     
    size_t total = 0;

    for (const auto& a : vec) {
        first = 0;
        last = 0;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == 'z' ) {
                
            }

            if (a[i] >= '0' && a[i] <= '9') {
                if (first == 0) {
                    first = a[i];
                } else {
                    last = a[i];
                }
            }
        }
        if (last == 0) {
            last = first;
        }

        std::string num_as_string;
        num_as_string += first;
        num_as_string += last;
        std::cout<< num_as_string << std::endl;
        total += std::stoi(num_as_string);
    }

    std::cout << "result is: " << total << std::endl;
    
}	