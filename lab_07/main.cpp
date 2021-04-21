/*
 * Celem zadania jest napisanie hierarchi klas opisujacej skladniki systemu plikow.
 * Skladnikami tymi sa miedzy innymi katalog (klasa Dir) i plik (klasa File). 
 * Jaka jest hierarchia? Czy wystepuja w niej tylko te dwie klasy?
 * Nalezy przewidziec ze beda to jeszcze jakies inne obiekty. Np. Link?
 * Prosze uniemozliwic dziedziczenie po klasie Dir, bez tego (-2pkt).
 * Prosze napisaca w dokumentacji jak i dlaczego nie bedzie mozna po klasie Dir dziedziczyc.
 *
 *
 * UWAGA: Aby zapewnic ladne wypisywanie, klasy te powinny psiadac metode print z argumentem informujacym 
 *        ile spacji potrzeba wypisac przed nazwa (indentacja). operator<< powinien wywolac te metode dla Dir a ona rekursywnie metody print dla skladowych zwiekszajac liczbe spacji.
 * UWAGA: W rozwiazaniu nalezy uzyc dynamicznego rozpoznania typow (wazne, upraszcza implementacje nieco!)
 * UWAGA: Prosze zauwazyc ze Dir zarzada pamiecia dla przechowywanych obiektow. To znaczy musi jes skasowac. 
 *        W implementcji mozna uzyc czego sie chce. Jak ktos umie std::vector to b. prosze. 
 *        Moze byc takze tablica na 10 elementow lub PArr z poprzedniego zadania. 
 * UWAGA: W implementacji klasy Dir nie mozna uzyc dwoch "tablic" jedna na pliki a druga na katalogi bo jest to 
 *        a) nierozszerzalne b) nie da sie zachowac kolejnosci dodawania do katalogu.
 */

#include "Dir.h"
#include "File.h"


int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  *home += new File("proj.files.repo");
  *home += new Dir("adam");
  
  std::cout << (const Dir&)*top << std::endl;

  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("auto1.jpg");
  *ewa += new File("auto2.jpg");
  *ewa += new File("auto3.jpg");
  top->findDir("ewa")->add( new Dir("work") );


  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(ewa->get("work"));
  std::cout << *(top->get("proj.descr"));

  delete top;
}
/* wynik 
. (DIR)
  home (DIR)
    ewa (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      auto1.jpg (FILE)
      auto2.jpg (FILE)
      auto3.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
--------------
work (DIR)
proj.descr (FILE)
Deleting Dir: .
About to delete home
Deleting Dir: home
About to delete ewa
Deleting Dir: ewa
About to delete Desk
Deleting Dir: Desk
About to delete auto1.jpg
About to delete auto2.jpg
About to delete auto3.jpg
About to delete work
Deleting Dir: work
About to delete proj.descr
About to delete proj.files.repo
About to delete adam
Deleting Dir: adam
 */
