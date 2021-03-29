#pragma once

class Fun {
  public: 
  virtual double wartosc(double x)const = 0;
  virtual ~Fun(){}
  double operator() (double x)const {
    return wartosc(x);
  }
};