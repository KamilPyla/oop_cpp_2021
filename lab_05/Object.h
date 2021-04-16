#pragma once
#include <string>

class Object {
  public:

  Object(std::string s):type(s){}

  virtual Object * getVal() const = 0;

  virtual void print()const =0;

  private:

  std::string type;
  
};