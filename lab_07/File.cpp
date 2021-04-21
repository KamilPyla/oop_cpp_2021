#include "File.h"

///////  wypisywanie ///////////////////

ostream & File::print(ostream & out,int spaces) const {
	for ( int i = 0; i < spaces; i++ )
		out << " ";
	out << name << " (FILE)" <<"\n";
	return out;
}

///////// wyszukiwanie  ////////////////

const File * File::get (string n) const {
	if ( n == name )
		return this;
	else
		return nullptr;
}

//////////  funkjca wypisująca do strumienia  ///////////////

ostream & operator << (ostream & out, const File & f) {
	return f.print(out);
}
