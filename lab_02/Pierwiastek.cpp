#include "Pierwiastek.h"
#include "Argumenty.h"
#include "Suma.h"
#include <cmath>

 const Argumenty Pierwiastek::wykonaj(const Argumenty & arg)const{
   Argumenty a(arg.size);
   for (int i = 0; i < a.size; i++){
     a(i, sqrt(arg._array[i]));
   }
  return a;
 }