#pragma once
#include "Op.h"

class ProstaRozniczka: public Op1{

public:

ProstaRozniczka(double krok): h(krok){}

double w(double x)const {
  return (this->fun->wartosc(x + h) - this->fun->wartosc(x - h)) / (2*h);
}

private:
double h;

};