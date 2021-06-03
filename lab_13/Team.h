#pragma once
#include "Member.h"
#include <algorithm>
#include <set>
#include <functional>
#include <iostream>


class Team {
	public:

	//konstruktor domyślny
	Team() = default;

	//metoda dodająca członka drużyny, dzięki użyniu std::set oraz zdefiniowania operatora < w struktrurze
	//Member dodaje tylko unikalnych członków oraz dodaje w porządku alfabetycznym
	void add(const Member & m);

	//funkcja wypisująca do strumienia członków drużyny, konieczne jest aby w strukturze Member był zdefiniowany operator << wypisujący do strumienia
	std::ostream & print(std::ostream & out) const;

	// usuwa członków zespołu nie spełniających danego kryterium, kryterium jest podane jako funkcja wzracanąca bool
	// korzysta z algorytmy std::remove_if
	void kill(std::function<bool(const Member &)> f);

	// Funkcja zwraca drużynę składanącą się z tylko tych członków którzy należą jednocześnie do obudwóch zespołów
	// korzysta z metody std::set_intersection

	Team operator - (const Team  & t)const;
	// Funkcja zwraca połączoną drużynę, w której członkowie są unikalni
	// korzysta z metody std::set_union
	Team operator + (const Team & t)const;

	private:
	// pole przechowujące członków drużyny
	std::set<Member> _crew;
};

// operator wypisuje członków zespołu do strumienia
std::ostream & operator << (std::ostream & out, const Team & t);