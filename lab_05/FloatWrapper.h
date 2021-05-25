#pragma once
#include "PArr.h"
#include <iostream>

class FloatWrapper : public Wrapper {

	public:
	FloatWrapper(float num): _val(num){}

	Wrapper * cpyObject()const {
		return new FloatWrapper(_val);
	}

	virtual void print(std::ostream & out) const {
		out << _val << " ";
	}

	~FloatWrapper() = default;

	private:
	
	float _val;

};