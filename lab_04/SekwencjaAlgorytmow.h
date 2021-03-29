#pragma once
#include <functional>
#include "Argumenty.h"
#include <vector>

class SekwencjaAlgorytmow {
  public:
  //metoda dodająca funkcję lub funktor do wektora
  void add(std::function<Argumenty(const Argumenty &)> fun){
    vec.push_back(fun);
  }
  //metoda wykonująca po kolei funkcje zapisane w wektorze funkcji na klasie argumenty
  Argumenty procesuj(const Argumenty & arg){
    Argumenty wynik = arg;
    for (auto a : vec){
      wynik = a(wynik);
    }
    return wynik;
  }

  private:
   //wektor przechowujący funkcje
   std::vector<std::function<Argumenty(const Argumenty &)>> vec;

};