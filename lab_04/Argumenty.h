#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::string;

class Argumenty {
public:

//Konstruktor ostawiawjący rozmiar tablicy argumentów na n, alokuje pamięć na _array
  Argumenty(int n);
//Konstruktor kopiujący
Argumenty(const Argumenty & arg);
//wzraca rozmiar tablicy
  const int getSize()const {return vec.size();}

//Wypisuje zawartość tablicy
  std::ostream & print(string line = "", std::ostream & o = std::cout)const;

// dodaje wartość val, do elementu talbicy o indeksie index
  Argumenty & operator()(int index, double val);

  double operator[](int i)const{return vec[i];}

  double& operator[](int i){return vec[i];}

  static Argumenty pojedynczy(double x){
    Argumenty a(1);
    a(0,x);
    return a;

  }

  private:
//rozmiar tablicy
  int size;
//tablica wartośći
  std::vector <double> vec;

};

std::ostream & operator << (std::ostream & o,const Argumenty & arg);