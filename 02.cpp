#include "Parser.h"
#include <iterator> 
#include <sstream> 

#define BLUE 14
#define RED 12
#define GREEN 13



template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


void part1() {
    std::vector<std::string> lines = Parser::readLines("../input.txt");

    int total{0};
    for (const auto& line: lines) {
        std::vector<std::string> vec = split(line, ' ');

        // for (const auto& item: vec) {
        //     std::cout << item << std::endl;
        // }
        // break;
        std::string gameid = vec[1];
        gameid.pop_back();
        int id = std::stoi(gameid);
        

        for (long unsigned int i = 2; i < vec.size() - 1; i += 2) {
            


            if (vec[i + 1].find("red") != std::string::npos) {
                std::cout <<  "red: " << vec[i] << std::endl;
                int red = std::stoi(vec[i]);
                if (red > RED) {
                    break;
                }
            } else if (vec[i + 1].find("blue") != std::string::npos) {
                std::cout <<  "blue: " << vec[i] << std::endl;
                int blue = std::stoi(vec[i]);
                if (blue > BLUE) {
                    break;
                }
            } else {
                std::cout <<  "green: " << vec[i] << std::endl;
                int green = std::stoi(vec[i]);
                if (green > GREEN) {
                    break;
                }
            }

            if (i == vec.size() - 2) {
                total += id;
            }
        }


    }

    std::cout << total << std::endl;
}

void part2 () {
    std::vector<std::string> lines = Parser::readLines("../input.txt");

    int total{0};
    for (const auto& line: lines) {
        std::vector<std::string> vec = split(line, ' ');
        size_t min_red{0};
        size_t min_blue{0};
        size_t min_green{0};

        for (long unsigned int i = 2; i < vec.size() - 1; i += 2) {
            


            if (vec[i + 1].find("red") != std::string::npos) {
                std::cout <<  "red: " << vec[i] << std::endl;
                int red = std::stoi(vec[i]);
                
                if (red > min_red) {
                    min_red = red;
                }
                
            } else if (vec[i + 1].find("blue") != std::string::npos) {
                std::cout <<  "blue: " << vec[i] << std::endl;
                int blue = std::stoi(vec[i]);
                if (blue > min_blue) {
                    min_blue = blue;
                }
                
            } else {
                std::cout <<  "green: " << vec[i] << std::endl;
                int green = std::stoi(vec[i]);
                if (green > min_green) {
                    min_green = green;
                }
                
            }

            if (i == vec.size() - 2) {
                total += (min_blue * min_red * min_green);
                min_blue = 0;
                min_green = 0;
                min_red = 0;
            }
        }
    }
    std::cout << total << std::endl;
}

int main () {
    part2();
    
    return 0;
}