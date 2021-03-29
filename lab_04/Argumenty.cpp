#include "Argumenty.h"
#include <iostream>

using std::cout;
using std::endl;

Argumenty::Argumenty(int n):size(n){
  for (int i = 0; i < size; ++i)
    vec.push_back(0);
}

Argumenty::Argumenty(const Argumenty & arg){
  for (double i : arg.vec){
    vec.push_back(i);
  size = arg.size;
  }
}

std::ostream & Argumenty::print(string line, std::ostream & o)const{
  o<<line<<" ";
  for (int i = 0; i<size; i ++){
    o<<vec[i]<<"  ";
  }
  o<<endl;
  return o;
}

Argumenty & Argumenty::operator()(int index, double val){
  vec[index] = val;
  return *this;
}

std::ostream &  operator << (std::ostream & o,const Argumenty & arg){

  return arg.print("",o);
}