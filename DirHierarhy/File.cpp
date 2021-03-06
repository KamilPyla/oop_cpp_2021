#include "File.h"

    ostream & File::print(ostream &out)const  {
        for ( int i = 0; i < spaces; i++)
            out << " ";
        out << name << "\n";
        return out;
    }

    ostream & operator << (ostream & o, const File & f){
    return f.print(o);
}

    File * File::get(string n) {
        if ( name == n )
            return this;
        else return nullptr;
    }