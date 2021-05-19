#pragma once

#include <vector>

// struktura abstrakcyjna mogąca zawierać dowolne obiekty
struct ABS {
 	virtual ~ABS()=default;
};

//szablon na przechowywanie dowolnej klasy
template <typename T> 
struct helpTemp: ABS {
	
	helpTemp(T & el): ABS(),value(el){}
	T value;
	T & get() {
		return value;
	}
	~helpTemp()=default;
};



class ClonesF {

	public:

// dodaje obiekty do fabryki 
	template <typename T>
	void add(T & el){
		vec.push_back(new helpTemp<T>(el));
	}

//wzraca kopię obiektu danej klasy
	template <typename T> 
	T & clone() {

		helpTemp<T> * temp = nullptr;
		for (auto el: vec) {
			temp = dynamic_cast<helpTemp<T> *>(el);
			if (temp) {
				return temp->get();
			}
		}
	}


//zamienia przechowywany obiekt danej klasy
	template <typename T>
	void replace(const T & ob){
		helpTemp<T> * temp = nullptr;
		for (auto el: vec) {
			temp = dynamic_cast <helpTemp<T> * >(el);
			if (temp) {
				temp->value = ob;
			}
		}

	}

	~ClonesF() {
		for (auto el: vec) {
			delete el;
		}
	}

	private:
// przechowywuje wskażniki na obiekty klasy ABS które mogą zawierać dowolne obiekty
	std::vector <ABS *> vec;

};