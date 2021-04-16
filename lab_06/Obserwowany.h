#pragma once
#include "Obserwator.h"
#include <vector>
using namespace std;

class Obserwowany {
  public:

  //wykonuje operacje obserwatorów na podanej wartości 
  void noweDaneNadeszly(int n);
  //dodaje wskaźnik do obserwatora do pola Obs
  void dodajObserwatora(Obserwator * o);

  protected:
  //pole przechowujące wskaźniki na obserwatorów
  vector<Obserwator *> Obs;
};