#pragma once
#include <iostream>
#include <list>
#include <functional>
#include <initializer_list>

template <typename T>
class QKolejka {

	public:

	//Deklaracje typów zmiennych dla odpowiednich iteratowór
	using const_reverse_iterator = typename std::list<T>::const_reverse_iterator;
	using const_iterator = typename std::list<T>::const_iterator;

	//konstruktor przyjmujący funkcję porównującą do kolejki priorytetowej
	QKolejka(std::function<int(T)> c ): _compare(c){}

	//metoda dodaje elementy zgodnie z priorytetem
	void dodaj(const T & el) {
		if (_list.empty()) {
			_list.push_back(el);
		}
		else {
			for (auto l = _list.begin(); l != _list.end(); ++l) {
				if (_compare(*l) > _compare(el)) {
					_list.insert(l,el);
					return;
				}
			}
			_list.push_back(el);
		}
	}

	//metoda dodająca listę obiektów do kolejki
	void dodaj(std::initializer_list<T> li) {
		for (auto & el: li)
			dodaj(el);
	}

	//zwraca iterator do początku listy
	const_iterator begin() const {
		return _list.begin();
	}

	//zwraca iterator do końca listy
	const_iterator end() const {
		return _list.end();
	}

	//zwraca odwrócone iteratory
	const_reverse_iterator rbegin() const {
		return _list.rbegin();
	}
	const_reverse_iterator rend() const {
		return _list.rend();
	}

	private:

	// funkcja porównująca elementy
	std::function <int(T)> _compare;

	// lista przechowująca obiekty w kolejce
	std::list<T> _list;

};