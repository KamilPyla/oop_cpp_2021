#pragma once 
#include <iostream>
#include <string>

using namespace std;

struct Policy {

	// funkcja zwracająca nazwę polityki
	virtual string policyName() const = 0;

};

struct CachePolicy : Policy {

	// zapamietuje warosc obliczenia dla argumentu
    virtual void cacheValueForArgument( double arg, double val ) const = 0; 

	// zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;

	// zapamietana wartosc dla argumentu
    virtual double getCached(double arg) const = 0;

		virtual string policyName() const {return "";}		

};

struct NoCache: CachePolicy {


	virtual void cacheValueForArgument( double arg, double val ) const {  } 

    virtual bool hasCacheFor( double arg ) const { return false; }

    virtual double getCached(double arg) const { return 0.0; }

	virtual string policyName() const { return "NoCache"; }	

};


struct OneCallCache: CachePolicy {

	virtual void cacheValueForArgument( double arg, double val ) const { _cacheArg = arg; _cacheVal = val; }

    virtual bool hasCacheFor( double arg ) const { return _cacheArg == arg;}  

    virtual double getCached(double arg) const {return _cacheVal;} 

	virtual string policyName() const { return "OneCallCache"; }	

	// pole przechowujące wcześniejszy argument
	mutable double _cacheArg = 0;

	// pole przechowujące wartość dla argument
	mutable double _cacheVal = 0;
};


struct VerbosityPolicy : Policy {

	// wypisuje na stdout argument i wynik dzialania na tym argumencie
    virtual void printArgAndResult( double arg, double val) const = 0;

	virtual string policyName() const {return "";}
};


struct Silent: VerbosityPolicy {

	virtual void printArgAndResult( double arg, double val) const {}

	virtual string policyName() const {return "Silent";}

};

struct Verbose: public VerbosityPolicy {

	virtual void printArgAndResult( double arg, double val) const { cout << "f(" << arg << ") = " << val << endl; } 

	virtual string policyName() const { return "Verbose"; }

};

