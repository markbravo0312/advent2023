#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string_view>






class Parser {
    public:


    // each vector element corresponds to line of string
    static std::vector<std::string> readLines(std::string_view filename);
    
};




    std::vector<std::string> Parser::readLines(std::string_view filename) {
        std::string file{filename};
        std::ifstream inputFile(file);
    
    
        if (!inputFile.is_open()) {
            throw std::runtime_error("error opening file");
        }

        std::vector<std::string> fileLines;
        std::string line;
        while (std::getline(inputFile, line)) {
            fileLines.push_back(line);
        }

        inputFile.close();
    
    return fileLines;
}




// end of Parser.h