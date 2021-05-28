#pragma once
#include <iostream>

class Person {
	public:
	
	//konstruktor 
	Person(bool isW, std::string name): _isWoman(isW), _name(name){}

	//onstruktor nazwany
	static Person kobieta(std::string name){
		return Person(true, name);
	}
	static Person mezczyzna(std::string name){
		return Person(false, name);
	}

	// zwraca zawartość pola _isWoman
	bool isWoman() const { return _isWoman; }

	// funkcja wypisująca do strumienia
	std::ostream & print(std::ostream & out) const {
			out << _name << " ";
		 _isWoman ? out << "K": out << "M";
		 return out;
	}

	private:

	const bool _isWoman;
	std::string _name;
};

// operator wypisujący do strumienia
std::ostream & operator << (std::ostream & out, const Person & p) {
	return p.print(out);
}