#pragma once
#include "Object.h"


class FloatWrapper: public Object {
  public:

    FloatWrapper(float f): Object("float"), val(f){}

    FloatWrapper * getVal() const override {return new FloatWrapper(val);};

    void  print()const override {std::cout<<val;}

  private:
    float val;

};