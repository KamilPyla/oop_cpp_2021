#include "MyString.h"
#include <iostream>
#include <cstring>


  //zapisuje napis do klasy, ustawia pole _size na ilość znaków w napisie
  MyString::MyString (const char * napis): MyString()  {

    _size = strlen(napis);
    _str = new char[_size+1];
    strcpy(_str,napis);


  }

  //konstruktor przenoszący
  MyString::MyString (MyString && move ){
    _size = move._size;
    _str = move._str;
    next = move.next;
    move._size = 0;
    move._str = nullptr;
    move.next = nullptr;
  }

  //Metoda zwracająca ilość znaków w napisie
  int MyString::size()const{
  
    int len = 0;
    const MyString * temp = this;
    while(temp->next) {
      len += temp->_size;
      temp = temp->next;
    }
    len += temp->_size ;
    return len;
  }

  //Metoda zwracająca ilość podlinkowanych obiektów MyString
  int MyString::fragments()const{
    const MyString *temp = this;
    int count = 0;
    while(temp->next){
      temp = temp->next;
      count ++;
    }
    return ++ count;
    
  }

  //wzraca i-ty obiekt MyString w liście
  const MyString & MyString::fragment(int i)const{

    const MyString * temp = this;
    for (int j = 0; j < i; j++)
        temp = temp->next;
    return *temp;
  }

  MyString * MyString::last() {
    MyString * temp = this;
    while(temp->next){
      temp = temp->next;
    }
    return temp;

  }

  //Metoda zwraca napis w danym fragmencie
  const char * MyString::str() const{
    return _str;
  }

  //operator dodaje do listy kolejne napisy
  void MyString::operator +=(const char * next_str){
    MyString * newstr = new MyString(next_str);
    MyString * temp = last();
    temp->next = newstr;

  }

  void MyString::operator +=(MyString && m){
    next = &m;
  }


  void MyString::operator = (MyString && move){
    _size = move._size;
    _str = move._str;
    next = move.next;
    move._size = 0;
    move._str = nullptr;
    move.next = nullptr;
  }


  MyString::~MyString(){
    if (_str)
     delete [] _str;

  }

	std::ostream & operator << (std::ostream & o ,const MyString & s ){
  if (s.size() > 0){

    for (int i = 0; i < s.fragments(); i++){
      o << s.fragment(i).str();
    }
    return o;
  }
  else 
    return o;
}

