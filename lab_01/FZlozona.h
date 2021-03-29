#pragma once


class Fun;
class FZlozona: public Op1 {
  public:
  FZlozona(Fun * f): fx(f){};
  
  double w (double x) const {
    return fx->wartosc(fun->wartosc(x)); 
  }

  private:
  Fun * fx;

};