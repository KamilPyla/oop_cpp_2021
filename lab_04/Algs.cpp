#include "Algs.h"
#include <cmath>

//fukcja wzracająca najmniejszą wartość z listy argumentów
Argumenty minimum(const Argumenty & arg){
  double min = arg[0];
  for ( int i = 0; i < arg.getSize(); ++i){
    if (min > arg[i])
      min = arg[i];
  } 
  return Argumenty::pojedynczy(min);

}

//funkcja wzracająca sumę argumentów
Argumenty sum (const Argumenty & a){
  double sum = 0;
  for(int i = 0; i < a.getSize(); ++i){
    sum += a[i];
  }
  return Argumenty::pojedynczy(sum);
}

//funkcja zwracająca listę argumentów składający się z pierwiastków argumentów podanych jako argument funkcji
Argumenty sq (const Argumenty & a){
  Argumenty a1(a.getSize());
  for (int i = 0; i < a1.getSize(); ++i){
    a1(i,sqrt(a[i]));
  }
  return a1;

}