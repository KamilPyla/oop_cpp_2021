#include "Obserwator.h"
#include<iostream>
using namespace std;




int ObserwatorLicznik::suma()const{
  return su;
}

void ObserwatorLicznik::czynnosc(int n){
  su += n;
}

void ObserwatorWypisywacz::czynnosc(int n){
  cout<<n<<" ";
}