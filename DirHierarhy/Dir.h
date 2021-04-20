#pragma once
#include <iostream>
#include "File.h"
#include <vector>

using namespace std;

class Dir final: public File {

    public:

    Dir(string n): File(n){}

    void operator +=(File * o);

    ostream & print(ostream &out)const;

    Dir* findDir(string n) const;

    void add(File * o);

    File* get(string n);

    ~Dir();

    private:

        vector <File*> vec;

};