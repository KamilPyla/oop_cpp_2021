#pragma once
#include <string>
#include <iostream>
using std::string;

class Argumenty {
public:
//Konstruktor ostawiawjący rozmiar tablicy argumentów na n, alokuje pamięć na _array
  Argumenty(int n);
//Konstruktor kopiujący
  Argumenty (Argumenty & cpy);
//detruktor, czyści pamięć po alokacji _array
  ~Argumenty();
//wzraca rozmiar tablicy
  const int getSize()const {return size;}

//Wypisuje zawartość tablicy
  void print(string line, std::ostream & o = std::cout)const;

// dodaje wartość val, do elementu talbicy o indeksie index
  Argumenty & operator()(int index, double val);
//rozmiar tablicy
  int size;
//tablica wartośći
  double * _array;

};