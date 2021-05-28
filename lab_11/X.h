#pragma once
#include <iostream>


class X {

	public:

	X() = default;
	X(std::string n): _name(n){}

	//metoda wzracająca nazwę obiektu
	std::string getName()const {return _name ;}

	//destruktor wypisujący nazwę usuwanego elementu
	virtual ~X() {
		std::cout <<"deleting X "<< _name << std::endl;
	}

	protected:

	std::string _name;

};

class Y: public X {

	public:
	Y() = default;
	Y(std::string name): X(name){}

	virtual ~Y() {

		std::cout <<"deleting Y "<< _name << std::endl;
	}
};

//operator << wypisujący do strumienia nazwę obiektu
std::ostream & operator << (std::ostream & out, const X & ob) {
	
	out << ob.getName();
	return out; 
}