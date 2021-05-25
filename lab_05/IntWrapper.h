#pragma once
#include "PArr.h"

class IntWrapper : public Wrapper {

	public:
	IntWrapper(int num): _val(num){}

	Wrapper * cpyObject()const {
		return new IntWrapper(_val);
	}

	virtual void print(std::ostream & out) const {
		out << _val << " ";
	}

	~IntWrapper() = default;

	private:
	
	int _val;

};

