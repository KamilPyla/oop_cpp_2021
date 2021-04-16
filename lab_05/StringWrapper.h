#pragma once
#include "Object.h"
#include <cstring>
#include <iostream>


class StringWrapper: public Object {
  public:
    StringWrapper(const char * s);

    StringWrapper * getVal() const override {return new StringWrapper(str);}

    ~StringWrapper(){if (str) delete [] str;}

    void print()const override {std::cout<<str;}
    
  private:
    char * str;
    int size;
};