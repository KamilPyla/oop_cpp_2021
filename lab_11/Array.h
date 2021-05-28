#pragma once
#include <iostream>
#include <array>
#include <memory>


//szablon klasy przechowującej dowolne obiekty
template <int size, typename T>
class Array {
	public:

	Array() = default;

	//metoda wypisująca obiekty do strumienia pod warunkiem, że w danej klasie jest zdefiniowany operator <<
	std::ostream & print(std::ostream & out) const {
		for (auto & el: arr) {
			out << el << " ";
		}
		out << "\n";
		return out;
	}

	// operator [] jako argument przyjmuje index na który chcemy przypisać daną wartość, jeżeli index jest zbyt duży przypisze do ostatniego elementu 
	T & operator[](int index) {
		if (index < size)
			return arr[index];
		return arr[size -1];
	}


	private:
// tablica przechowująca obiekty
std::array<T, size> arr = {};

};

//operator wypisujący do strumienia zawartośc tablicy
template <int size, typename T>
std::ostream & operator << (std::ostream & out, const Array<size,T> & ar) {
	return ar.print(out);
}


///////////////////////////////////////////////////////////////////////

// szablon klasy przechowujący wskaźniki na obiekty
template <int size, typename T>
class Array<size, T*> {
	public:

	Array() = default;

	std::ostream & print(std::ostream & out) const {
		for (auto el: arr) {
			if (el)
				out << *el << " ";
		}
		out << "\n";
		return out;
	}

	// operator [] jako argument przyjmuje index na który chcemy przypisać daną wartość, jeżeli index jest zbyt duży przypisze do ostatniego elementu 
	T*& operator[](int index) {
		if (index < size)
			return arr[index];
		return arr[size -1];
	}

	// destruktor, zwalnia pamięć po wskaźnikach
	~Array() {
		for (auto el: arr) {
			delete el;
		}
	}

	private:
	//Tablida przechowująca wskaźniki
	std::array<T*, size> arr = {};

};


template <int size, typename T>
std::ostream & operator << (std::ostream & out, const Array<size,T*> & ar) {
	return ar.print(out);
}


