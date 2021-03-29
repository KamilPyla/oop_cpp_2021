#pragma once
#include <iostream>


class MyString {
  public:

  friend std::ostream & operator << (const MyString & s, std::ostream & o);

  MyString(): _str(nullptr),_size(0), next(nullptr){}

  //zapisuje napis do klasy, ustawia pole _size na ilość znaków w napisie
  MyString (const char * napis);


  //konstruktor przenoszący
  MyString (MyString && move );

  //Metoda zwracająca ilość znaków w napisie
  int size()const;

  //Metoda zwracająca ilość podlinkowanych obiektów MyString
  int fragments()const;

  //wzraca i-ty obiekt MyString w liście
  const MyString & fragment(int i)const;

  //Metoda zwraca napis w danym fragmencie
  const char * str() const;

  //operator dodaje do listy kolejne napisy
  void operator +=(const char *);

  void operator +=(MyString && m);

  void operator = (MyString && move);

  //funkcja wzracająca wskaźnik do ostatniego elementu listy
  MyString * last();

  ~MyString();

  private:

  char * _str;



  //ilość znaków w napisie
  int _size;

  //wskaźnik do następnego fragmentu
   MyString * next;
};

inline std::ostream & operator << (std::ostream & o ,const MyString & s ){
  if (s.size() > 0){

    for (int i = 0; i < s.fragments(); i++){
      o << s.fragment(i).str();
    }
    return o;
  }
  else 
    return o;
}