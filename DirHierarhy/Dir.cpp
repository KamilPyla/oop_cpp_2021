#include "Dir.h"

    void Dir::operator += (File * o){
        o->space(spaces);
        vec.push_back(o);
    }


    ostream & Dir::print(ostream &out)const  {

        for (int i = 0; i < spaces; i++)
            out<<" ";
        out << name << "\n";

        for (auto el: vec)
            el->print(out);
        return out;
    }


    Dir* Dir::findDir(string n) const {

        for (auto el: vec) {

            if (el->getName() == n)
                return dynamic_cast<Dir*>(el);

            if (dynamic_cast<Dir*>(el))
               return dynamic_cast<Dir*>(el)->findDir(n);

            }
            return nullptr;
        }

    void Dir::add(File * o) {
        *this += o;
    }


    File* Dir::get(string n) {

        for ( auto el: vec){
            if ( el->getName() == n )
                return el;
            
            else if ( el->get(n) )
                return el -> get(n);    
        }
        return nullptr;
    }

    Dir::~Dir(){
        cout << "Deleting:" <<name<<endl;

        for (auto el: vec){
            cout << "About deleting " << el->getName()<<endl;
            delete el;
        }
    }
    