#pragma once
#include "File.h"
#include <iostream>
#include <vector>

using namespace std;

// blokujemy możliwość dziedziczenia po klasie Dir, ponieważ nie istnieje wyższy typ niż katalog
class Dir final: public File {
	public:

	// konstruktor ustawia pole name (string) na n
	Dir(string n): File(n){}

	// funkcja wypisująca zawartość katalogu, wraz w odpowiednią ilością spacji, wraz z poziomem zagłębiania zwiększa ilość spacji o 2
	virtual ostream & print(ostream & out, int spaces = 0)const override;

	// metoda wyszukuje czy w danym katalogu występuje katalog o podanej nazwie jeśli tak, wzraca wskaźnik do niego, jeśli nie ma takiego katalogu zwraca nullptr  ( korzysta z mechanizku RTTI )
	Dir * findDir( string n ) const;

	// metoda operatorowa dodaje obiekty na koniec pola vec, który przechowuje wszystkie obiekty zawarte w katalogu
	void operator += (File * f);

	// metoda dodaje obiekty na koniec pola vec, który przechowuje wszystkie obiekty zawarte w katalogu
	void add(File * f);

	// metoda sprawdza czy obiekt o danej nazwie znajduje się w katalogu, jeśli tak zwraca wskaźnik do niego, jeśli nie zwraca nullptr
	virtual const File * get( string n ) const override;

	// destruktor - zwalnia pamięc po danym katalogu, oraz jego zawartości, wypisuje nazwy obiektów po których zwalnia pamięć
	virtual ~Dir() override;

	private:

	// wektor przechowujący wskaźniki do zawartości katalogu
	vector <File *> vec;

};