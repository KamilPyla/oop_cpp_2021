/* Celem zadania jest napisanie klasy fabryki pozwalajacej 
   na konstrukcje/klonowanie obiektow dowolnego typu. 
   Najpierw do fabryki wstrzykujemy metoda add() oryginal. 
   Metoda clone() robi kopie z oryginalu.

   UWAGA: Rozwiaznie z if/switch i typeid nie jest dopuszczalne. Mozna tylko uzyc dynamic_cast. 

   UWAGA: Sama klasa ClonesF nie jest szablonem. Szablonami sa metody: add, clone i replace.

   UWAGA: Kluczem w tym zadaniu jest przypomnienie sobie jaki zrobic 
   kontener polimorficzny. Co musi on przechowywac?

   UWAGA: Poza widocznymi klasami trzeba bedzie wymyslic dodatkowa hierarchie, 
   ktora pozwoli na przechowanie oryginalow obiektow dowolnych klas.

 */


#include <iostream>
#include <string>

#include "ClonesF.h"

// klasy testowe
struct A{
  A(const std::string& m) : msg( m ) {}
  std::string msg;
};

struct B{
  int x;
};

struct C{
  double v;
};

int main() {
  // tu mamy dwa obiekty, ktore sa w stanie produkowac nowe obiekty
  ClonesF cf1;
  A a("Obiekt a");
  A a1("Obiekt a1");  
  cf1.add(a);
  B b;
  b.x = 7;
  cf1.add(b);
  C c;
  c.v = 3.87;
  cf1.add(c);

  ClonesF cf2;
  cf2.add(a1);

  std::cout << cf1.clone<A>().msg << std::endl;
  std::cout << cf1.clone<B>().x << std::endl;
  std::cout << cf2.clone<A>().msg << std::endl;
  cf2.replace(A("Jeszcze cos innego"));
  std::cout << cf2.clone<A>().msg << std::endl;


}
/* wynik
Obiekt a
7
Obiekt a1
Jeszcze cos innego

 */
