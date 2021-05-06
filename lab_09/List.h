#pragma once
#include <iostream>

//struktura przechowująca wartość elementu oraz wzkaźnik do kolejnego elementu w liście przechowuje elementy dowolnego typu
template <class T> struct Node {

	Node(T v): _val(v){}

	Node<T> * _next = nullptr;
	T _val;

};

// Klasa obsługująca listę jednokierunkową
template <class T> class List {

	public:

		// konstruktor domyślny
		List() = default;

		//konstruktor przenoszący - usuwa zawartość poprzedniej listy
		List( List<T> && m ){

			_head = m._head;
			_tail = m._tail;

			m._head = nullptr;
			m._tail = nullptr;

		}

		// konstruktor kopiujący - tworzy twardą kopię podanej listy
		List (const List<T> & cpy ){

			Node<T> * el = cpy._head;

			while ( el != cpy._tail ){

				add(el->_val);
				el = el->_next;

			}
			add(el->_val);
		}

		//sprawdza czy dany element znajduje się w liście, jeśli tak wzraca true jeśli nie wzraca false
		bool contains(T val) const {

			Node<T> * el = _head;

			while (el != _tail)  {

				if (el->_val == val)
					return true;

				el = el->_next;
			}

				if (el->_val == val)
					return true;

				else return false;

		}

		// dodaje element na koniec listy zwraca referencję do samej siebie, możliwe jest wywołanie jej kilkukrotnie
		List & add(T v) {

			Node<T> * el = new Node<T>(v);

			if (_head == nullptr){

				_head = el;
				_tail = el; 

			}
			else{

				_tail->_next = el;
				_tail = el;

			}

			return *this;
		}

		// fukncja wypisująca dane listy do strumienia, jeżeli lista jest pusta wzraca pusty strumień
		std::ostream & print(std::ostream & out) const {

			Node<T> * el = _head;

			if(el){

				while (el != _tail){

					out << el->_val << " ";
					el = el->_next;

				}
				out << el->_val;

				}
			return out;
		}

		// destruktor - zwalnia pamięć po alokowanych elementach listy
		~List(){

			Node<T> * el = _head;

			while( el != _tail ){

				el = el->_next;
				delete _head;
				_head = el;

			}
			delete el;
		}

		Node<T> * _head = nullptr;
		Node<T> * _tail = nullptr;

};


template<class T>std::ostream & operator << (std::ostream & out, const List<T> & l) {
	return l.print(out);
}