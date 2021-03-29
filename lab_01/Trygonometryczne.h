#pragma once
#include <cmath>
class Fun;

class Sinus: public Fun {

  double wartosc (double x)const{
    return sin(x);
  }
};