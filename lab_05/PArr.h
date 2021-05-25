#pragma once
#include <iostream>

// wrapper
class Wrapper {

	public:
	Wrapper() = default;
	virtual Wrapper * cpyObject() const = 0;
	virtual void print(std::ostream & out) const = 0;
	virtual ~Wrapper() = default;

};

class PArr {
	public:

	PArr(int n): _size(n){
		_tab = new Wrapper * [n]; 
	}

  ~PArr()
  {
      for (int i = 0; i < _size; ++i)
        delete _tab[i];
    delete [] _tab;
  }

	PArr(const PArr & cpy):PArr(cpy._size) {
		for (int i = 0; i < _size; i++){
			_tab[i] = cpy._tab[i]->cpyObject();
		}
	}

	PArr(PArr && other) {
		_size = other._size;
		_tab = other._tab;
		other._tab = nullptr;
		other._size = 0;
	}

	void operator = (const PArr & other) {

    for (int i = 0; i < _size; ++i)
      delete _tab[i];
    delete [] _tab;
		_tab = new Wrapper *[other._size];
    _size = other._size;

		for (int i = 0; i < _size; i++){
			_tab[i] = other._tab[i]->cpyObject();
		}
	}

	Wrapper *& operator[] (int index) {
		return _tab[index];
	}

  const Wrapper * operator[](int index) const {
    return _tab[index];
  }
	Wrapper ** _tab;
	int _size;


};

std::ostream & operator << (std::ostream & out, const PArr & p) {
	for (int i = 0; i < p._size; i++) {
		p._tab[i]->print(out);
	}
	return out;
}
