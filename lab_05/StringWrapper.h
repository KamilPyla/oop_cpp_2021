#pragma once
#include "PArr.h"
#include <cstring>


class StringWrapper : public Wrapper {

	public:
	StringWrapper(const char * str) {
		_sizeStr = strlen(str) + 1;
		_str = new char[_sizeStr];
    strcpy(_str, str);
	}

	Wrapper * cpyObject()const {
		return new StringWrapper(_str);
	}

	virtual void print(std::ostream & out) const {
		out << _str << " ";
	}

	~StringWrapper() {
		delete _str;
	}

	private:
	
	char * _str;
	int _sizeStr;
};