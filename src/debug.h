#ifndef DEBUG_H
#define DEBUG_H

#include <string>

namespace Debug{

  extern bool debugEnabled;

  void Init(bool Active);
  
  void print(std::string str);
  void printf(std::string str);
}

#endif
