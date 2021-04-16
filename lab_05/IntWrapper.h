#pragma once
#include "Object.h"
#include <string>


class IntWrapper: public Object {
  public:
  IntWrapper(int i):Object("int"), val(i){}

  IntWrapper * getVal()const override {return new IntWrapper(val);}

  void  print()const override {std::cout<<"  " << val << "  ";}


  private:

  int val;

};