/**
 * Celem zadania jest napisanie plimorficznej tablicy/
 * W tablicy tym trzymac bedziemy wskazniki do obiektow pewnej hierarchii klas.
 * Trudnoscia w zadaniu jest znalezienie hierarchii klas i zapewnienie jej kopiowalnosci.
 * 
 * zagadnienia: dziedziczenie, kopiowalnosc, operatory
 * 
 * UWAGA w operatorze przypisania = konieczne jest zrobienie kopii obiektow zlozonych w tablicy
 * UWAGA implementacj tablicy wskaznikow w PArr musi byc dynamiczna, nie mozemy zlalozyc ze gorny limit na ilosc elementow np. 10
 * UWAGA w klasie StringWrapper nie mozna uzyc std::string
 * Kompilowac z flagami -Wall -g
 */

#include <iostream>
#include <string>
#include "PArr.h"
#include "FloatWrapper.h"
#include "IntWrapper.h"
#include "StringWrapper.h"

int main() {  
  PArr a(3); // 3 elementowa
  a[0] = new FloatWrapper(0.1);
  char carr[80];
  strcpy(carr, "nothing");
  a[1] = new StringWrapper(carr); // nie mozna przechowac wskaznika, trzeba skopiowac zawartosc do pamieci
  bzero(carr, sizeof(carr));
  a[2] = new IntWrapper(-1);
  std::cout << a << std::endl;
  {
    PArr b(4); // 4 elementowa
    b[0] = new FloatWrapper(11.2);
    b[1] = new StringWrapper("hello");
    b[2] = new IntWrapper(-76);
    b[3] = new StringWrapper("world");
    
    std::cout << " przed przepisaniem " << b << std::endl;  
    a = b;
    std::cout << " po przepisaniu     " << b << std::endl;  
  }
  std::cout << (const PArr&)a << std::endl;			 

  PArr c(std::move(a));
  std::cout << "a " <<  (const PArr&)a << std::endl;			 
  std::cout << "c " << (const PArr&)c << std::endl;			 
  
  // UWAGA na potencjalny wyciek pamieci
}
/* wynik
0.1 nothing -1
 przed przepisaniem 11.2 hello -76 world
 po przepisaniu     11.2 hello -76 world
11.2 hello -76 world
a
c 11.2 hello -76 world
*/
