#pragma once 
#include <iostream>
#include <string>
using namespace std;

class File {
    public:

    File(string n): name(n){}

    string getName()const {return name;}

    void space(int n){spaces = n + 2;}

    virtual File* get(string n);

    virtual ostream & print(ostream &out)const;

    virtual ~File(){}

 ////////////////////////////////////////////////////////

    protected:

    string name;

    int spaces = 0;

};

ostream & operator << (ostream & o, const File & f);
