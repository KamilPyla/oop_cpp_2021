#include "PArr.h"

  PArr::PArr (int n){
    size = n;
    vec = new Object * [size];
  }

  PArr::PArr (PArr & copy){
    size = copy.size;
    vec = new Object * [size];
    for (int i = 0; i < size; i ++)  {
      vec[i] = copy[i]->getVal();
    }
  }

  PArr::PArr (PArr && m){
    
  }


  std::ostream & operator<<(std::ostream & o, const PArr & p){
    for (int i = 0; i < p.size; i++) {
      p[i]->print();
    } 
    return o;
  }

  void PArr::operator = (const PArr & p){

  }