#pragma once
class Fun;

class Op1{
  public:

  virtual ~Op1(){}

  Op1 * z (Fun * f){
    fun = f;
    return this;
  }

  Op1 * operator() (Fun * f){
    fun = f;
    return this;
  } 

  virtual double w (double x) const = 0;
  protected:
  Fun * fun;
};