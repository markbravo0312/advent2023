#include "Parser.h"
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

#define bignum unsigned long long

std::set<bignum> seeds{};





void part(int part)
{
  std::set<std::pair<long, long>> cur, keep, next;  
  std::ifstream f("../input.txt");
  if (!f.is_open()) { return; }
  
  std::string line;
  std::getline(f, line);
  std::istringstream line_stream(line);
  std::string seed_start, seed_len;
  std::getline(line_stream, seed_start, ' ');  
  while(std::getline(line_stream, seed_start, ' '))
  {
    if (part == 1) 
    {
      cur.insert({std::stol(seed_start), 1});
    }
    else  
    {
      std::getline(line_stream, seed_len, ' ');
      cur.insert({std::stol(seed_start), std::stol(seed_len)});
    }
  }
  
  while (std::getline(f, line))
  {
    if (line.empty()) 
    {
      cur.insert(next.begin(), next.end());
      next.clear();
      std::getline(f, line);  
      continue;
    }
    long pipe_dest, pipe_start, pipe_len;
    line_stream.clear(); 
    line_stream.str(line);
    line_stream >> pipe_dest >> pipe_start >> pipe_len;
    for (auto [range_start, range_len] : cur)
    {
      long lower = std::max(range_start, pipe_start);
      long upper = std::min(range_start + range_len, pipe_start + pipe_len);
      if (upper > lower)
      {
        next.insert({pipe_dest - pipe_start + lower, upper - lower});
        if (range_start + range_len > pipe_start + pipe_len) {
          keep.insert({pipe_start + pipe_len, range_start + range_len - pipe_start - pipe_len});
        }
        if (range_start < pipe_start)
        {
          keep.insert({range_start, pipe_start - range_start});
        }
      }
      else  
      {
        keep.insert({range_start, range_len});
      }
    }
    cur.swap(keep);
    keep.clear();
  }
  cur.insert(next.begin(), next.end()); 
  f.close();
  std::cout << "Part " << part << ": " << cur.begin()->first << std::endl;
}




int main () {

    auto lines = Parser::readLines("../input.txt");
    
    part(1);
    part(2);

}