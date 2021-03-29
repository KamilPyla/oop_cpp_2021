#pragma once
#include "Argumenty.h"

//Klasa bazowa
class Algo {
public:
//Metoda virtualna charakterystyczna dla każdej klasy pochodnej, jako argumenty przyjmuje klasę Argumenty, wzraca klasę typu argumenty
  virtual const Argumenty wykonaj(const Argumenty & arg)const = 0;
//Virtualna metoda sklonuj, wzraca wstaźnik do klasy na krótej została wykonana
  virtual Algo * sklonuj()const = 0;
  virtual~Algo(){}

};

class Suma: public Algo {
//zwraca sumę podanych argumentów znajdującej się w klasie klasa
  virtual const Argumenty wykonaj(const Argumenty & arg)const;
//zwraca nowy wskaźnik do klasy Suma
  virtual Suma * sklonuj() const{return new Suma();}
  ~Suma(){}

};