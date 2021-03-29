/*
Nalezy zaimplementowac klase "MyString" pozwalajacą na wysoko zoptymalizowana konkatenacje.
Mianowice, obiekty MyString poza tablica znakow musza posiadac wskaznik na kolejny obiekt MyString (itd. jak w liscie polaczonej) i w przypadku konkatenacji nie dochodzi do rozszerzania tablicy a do doloznia kolejnego MyString(u) na koncu listy. To oczywiście  jest tyko polowa sukcesu.
Zasadnicza optymalizacja zachodzi przy przesuwaniu gdzie nie potrzebna jest zadna alokacja.

Funkcjonalnosci klasy MyString
MyString::size zwraca olisc znakow w napisie (lacznie z dlugoscia w "podlinkowanych" napisach).
MyString::fragments zwraca ilosc fragmentow (dlugosc listy)
MyString::fragment(i) zwraca MyString z listy polaczonej (0 to jej poczatek itd.)
MyString::str() zwraca znaki (const char*) zlozone w danym fragmencie.

W implementacji tej klasy musi byc uzyta zwyczajna tablica char i ew. mona sobie zapisac rozmiar.

UWAGA: Zgodnie ze standardem nie musimy "sprzatac" obiektow przesuwanych. Tu jednak, dla zachowania czytelnosci przykladu to robimy. Upraszcza sie tez zarzadzanie pamiecia.

UWAGA: Liste prosze zaimplementowac w najlprostszy mozliwy sposob (jednokierunkowa). 

UWAGA: Operator strumieniowy najlatwiej zaimplementowac poprzez dodanie odpowiedniej metody do klasy MyString i jej wywolanie.

UWAGA: Prosze pamietac o konwersjach, to duza oszczednosc na kodzie do napisania.
*/

#include <iostream>
#include <utility>


#include "MyString.h"



int main() {
    MyString m("Hello");
    m += " World!";
    m += " Is anyone";
    m += " there?";
    std::cout << "size " << m.size() << " " << m.fragments() <<  " " << m << std::endl;

    MyString mm(std::move(m));
    std::cout << "m (after move) size " << m.size() <<  " " << m << std::endl;
    std::cout << "mm size " << mm.size() << " " << mm.fragments() <<  " " << mm << std::endl;

    MyString n("Again. ");
    n += std::move(mm);
    std::cout << "n: " << n << std::endl;

    MyString k;
    k = std::move(n);
    std::cout << "n (after move): " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    const MyString kk(std::move(k));
    std::cout << "kk: " << kk.size() << " " << kk.fragments() << std::endl;
    std::cout << kk.fragment(2).str() << std::endl;
}
/* wynik
size 29 4 Hello World! Is anyone there?
m (after move) size 0
mm size 29 4 Hello World! Is anyone there?
n: Again. Hello World! Is anyone there?
n (after move):
k: Again. Hello World! Is anyone there?
kk: 29 5
 World!
*/
