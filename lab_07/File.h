#pragma once
#include <iostream>
#include <string>
using namespace std;

// klasa bazowa File
class File {

	public:

	// konstruktor ustawia pole name na n
	File(string n): name(n){}

	// metoda zwracająca nazwę obiektu
	string getName() const { return name; }

	// wirtualna fukcja wypisująca do strumienia nazwę obiektu
	virtual ostream & print(ostream & out, int spaces = 0) const;

	// metoda zwracająca wskaźnik na siebie, jeżeli obiekt posiada nazwę podaną jako argument, w przeciwnym wypadku zwraca nullptr
	virtual const File * get (string n) const;

	//destruktor wirtualny
	virtual ~File(){}

	protected:

	// pole przechowujące nazwę obiektu
	string name;

};

// funkcja operatorowa wypisująca dane do strumienia
ostream & operator << (ostream & out, const File & f);