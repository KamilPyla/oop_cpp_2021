#pragma once
#include "Suma.h"

class Pierwiastek: public Algo {
public:
//wzraca obiekt klasy argumeny zawierający pierwiastek z każdego elementu znajdującego się w klasie podanej jako argument
  const Argumenty wykonaj(const Argumenty & arg)const;

//Zwraca nowy wskaźnik na obiekt Pierwiastek
  Pierwiastek * sklonuj()const{return new Pierwiastek();}
  ~Pierwiastek(){}
};