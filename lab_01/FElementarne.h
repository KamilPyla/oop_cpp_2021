#pragma once

class Liniowa: public Fun {
public:

  static Liniowa* utworz(){
    return new Liniowa();
  }

  double wartosc(double x) const{
    return _a*x + _b;
  }

  Liniowa * a(double aa){
    _a = aa;
    return this;
  }
  Liniowa * b(double bb){
    _b = bb;
    return this;
  }

private:

  double _a;
  double _b;

};

class Kwadratowa: public Fun {
  public:

  Kwadratowa(): _a(1), _b(0), _c(0){}

  static Kwadratowa * utworz(){
    return new Kwadratowa();
  }

  Kwadratowa * a(double aa){
    _a = aa;
    return this;
  }
  Kwadratowa * b(double bb){
    _b = bb;
    return this;
  }
  Kwadratowa * c(double cc){
    _c = cc;
    return this;
  }

  double wartosc (double x) const{
    return _a*x*x + _b*x + _c;
  }

private:
  double _a;
  double _b;
  double _c;

};