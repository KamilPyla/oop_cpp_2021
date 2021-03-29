#include "Suma.h"

const Argumenty Suma::wykonaj(const Argumenty & arg)const {
  Argumenty a(1);
  a._array[0] = 0;
  for (int i = 0; i < arg.getSize(); i++){
    a._array[0] += arg._array[i];
  }
  return a;

}