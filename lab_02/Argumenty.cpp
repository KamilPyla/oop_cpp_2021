#include "Argumenty.h"
#include <iostream>

using std::cout;
using std::endl;

Argumenty::Argumenty(int n):size(n){
  _array = new double[size];
}
Argumenty::Argumenty (Argumenty & cpy):Argumenty(cpy.size){
  for (int i = 0; i < size; i++){
    _array[i] = cpy._array[i];
  }
}

Argumenty::~Argumenty(){
  delete [] _array;
}

void Argumenty::print(string line, std::ostream & o)const{
  cout<<line<<" ";
  for (int i = 0; i<size; i ++){
    cout<<_array[i]<<"  ";
  }
  cout<<endl;
}

Argumenty & Argumenty::operator()(int index, double val){
  _array[index] = val;
  return *this;
}