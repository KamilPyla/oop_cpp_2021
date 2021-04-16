#pragma once
#include "Object.h"
#include <iostream>


class PArr {
  public:

  friend std::ostream & operator<<(std::ostream & o, const PArr & p);

  PArr (int n);

  PArr (PArr & copy);

  PArr (PArr && m);

  Object * operator[] (int i)const {return vec[i];}

  Object *& operator[] (int i) {return vec[i];}

  void operator = (const PArr & p);


  private:

  int size;

  Object ** vec;



};

std::ostream & operator<<(std::ostream & o, const PArr & p);