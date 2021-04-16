#include "Obserwowany.h"

void Obserwowany::dodajObserwatora(Obserwator *o){
  Obs.push_back(o);
}
void Obserwowany::noweDaneNadeszly(int n){
  for (auto el: Obs){
    el->czynnosc(n);
  }
  
}