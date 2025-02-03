#include "Parser.h"
#include <iostream> 




void part1(const std::vector<std::string>& lines) {
  std::vector<std::string> times_as_string = split(lines[0], ' ');
  std::vector<std::string> distances_as_string = split(lines[1], ' ');
  std::vector<int> times{};
  std::vector<int> distances{};
  for (int i = 1; i < times_as_string.size() ; ++i) {
    times.push_back(std::stoi(times_as_string[i]));
    distances.push_back(std::stoi(distances_as_string[i]));
  }
  std::cout << times.size() << std::endl;
  int total = 1;
  for (int i = 0; i < times.size(); ++i) {
    int sum{0};
    for (int t = 1; t <= times[i]; ++t) {
      int seconds_racing = times[i] - t;
      int distance = t * seconds_racing;
      if (distance > distances[i]) {
        sum++;
      }
    }
    total *= sum;
  }

  std::cout << "Result part1 is: " << total << std::endl;
}
  

void part2(const std::vector<std::string>& lines) {
  std::vector<std::string> times_as_string = split(lines[0], ' ');
  std::vector<std::string> distances_as_string = split(lines[1], ' ');

  std::string time_as_string{};
  std::string distance_as_string{};
  
  for (int i = 1; i < times_as_string.size(); ++i) {
    time_as_string += times_as_string[i];
    distance_as_string += distances_as_string[i];
  }

  //std::cout << time_as_string << std::endl;

  long time = std::stol(time_as_string);
  long distance = std::stol(distance_as_string);
  long total{0};
  for (long i = 1; i <= time; ++i) {
      if ( i * (time - i) > distance ) {
        total++;
    }
  }
  
  std::cout << "Result part2 is: " << total << std::endl;
}

int main() {
  auto lines = Parser::readLines("../input.txt");
  part1(lines);
  part2(lines);
  
}
