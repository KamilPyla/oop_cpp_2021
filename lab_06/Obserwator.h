#pragma once

//Klasa Bazowa zawierająca czystą metodę wirtualną czynność
class Obserwator {
  public:
  virtual void czynnosc(int n) = 0;
};

//Klasa sumująca warości obiektów obserwowanych
class ObserwatorLicznik: public Obserwator{

  public:
  //metoda licząca sumę podanych warotści
  void czynnosc(int n);
  //wzraca przechowywaną sumę elementów
  int suma()const;
  private:
  //pole przechowujące wartość sumy
  int su = 0;

};
//klasa wypisująca wartości obiektów obserwowanych
class ObserwatorWypisywacz: public Obserwator{
  public:
  //wypisuje na ekran podaną wartość
  void czynnosc(int n);


};