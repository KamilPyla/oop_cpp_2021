#include "Dir.h"

///////////// wypisywanie ///////////////////////

ostream & Dir::print(ostream & out, int spaces)const{
	for ( int i = 0; i < spaces; i++ )
		out << " ";
	out << getName() << " (DIR)" << "\n";

	for ( auto el: vec ) {
		 el -> print(out, spaces + 2);
	}
	return out;
}

//////////  dodawanie danych do katalogu  ///////////////////////

void Dir::operator += (File * f){
	vec.push_back(f);
}

void Dir::add(File * f){
	*this += f;
}

//////////////////  metody wyszukujące obiektów  ///////////////// 

Dir * Dir::findDir ( string n ) const {

	for ( auto el: vec ) {

		Dir * d = dynamic_cast<Dir *>(el);
		if( el->getName() == n )
			return d;
		if ( d )
			return d -> findDir(n);
	}
	return nullptr;
}

const File * Dir::get( string n ) const {

	for ( auto el: vec ) {

		if( n == el->getName() )
			return el;

		else if ( el -> get(n) )
			return el -> get(n);

	}
	return nullptr;
}

/////////////  destruktor  ////////////////////////////

Dir::~Dir () {
	cout << "Deleting Dir: " << name << endl;
	for ( auto el: vec ){
		cout << "About to delete " << el->getName() << endl;
		delete el;
	}
}
