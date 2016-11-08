// Ryan Ulep
// Michael Pare

#ifndef BASE_H
#define BASE_H
#include <iostream>

using namespace std;

// Base

class Base {
    public:
	/* Constructors */
	Base () { };

	/* Pure Virtual Functions */
	virtual double evaluate() = 0;
};

// Leafs

class Op : public Base {
    protected:
	double num;
    public:
	Op() : num(0) { }
	Op(double number) : num(number) { }
	double evaluate() {
	    return num;
	}
};

class singleOp : public Op {
    protected:
	Base *singleChild;
    public:
	singleOp() : singleChild(0) { }
	singleOp(Base *single) : singleChild(single) { }
};

class doubleOp : public Op {
    protected:
	Base *left;
	Base *right;
    public:
	doubleOp() : left(0), right(0) { }
	doubleOp(Base *l, Base *r) : left(l), right(r) { }
};

// Composite

class Add : public doubleOp {
    public:   
        Add() : doubleOp() { } 
        Add(Base *l, Base *r) : doubleOp(l, r)	{ }
        double evaluate() {
            return left->evaluate() + right->evaluate();
        }
};

class Sub : public doubleOp {
    public:   
        Sub() : doubleOp() { } 
        Sub(Base *l, Base *r) : doubleOp(l, r)	{ }
        double evaluate() {
            return left->evaluate() - right->evaluate();
        }
};

class Mult : public doubleOp {
    public:
	Mult() : doubleOp() { }
	Mult(Base *l, Base *r) : doubleOp(l, r) { }
	double evaluate() {
	    return left->evaluate() * right->evaluate();
	}
};

class Div : public doubleOp {
    public:   
        Div() : doubleOp() { } 
        Div(Base *l, Base *r) : doubleOp(l, r)	{ }
        double evaluate() {
            return left->evaluate() / right->evaluate();
        }
};

class Sqr : public singleOp {
    public:
        Sqr() : singleOp() { } 
        Sqr(Base *single) : singleOp(single) { }
        double evaluate() {
            return singleChild->evaluate() * singleChild->evaluate();
        }
};

#endif
