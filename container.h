#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdexcept>
#include <stdlib.h>
#include "Base.h"
#include "sort.h"

class Sort;

class Container {
    protected:
	Sort* sort_function;

    public:
	Container() : sort_function(NULL) { };
	Container(Sort* function) : sort_function(function) { };
	void set_sort_function(Sort* sort_function) {
		this->sort_function = sort_function;
	}
	virtual void add_element(Base* element) = 0;
	virtual void print() = 0;
	virtual void sort() = 0;
	// switch tree locations
	virtual void swap(int i, int j) = 0;
	// get top ptr of tree at index i
	virtual Base* at(int i) = 0;
	// return container size
	virtual int size() = 0;
};

class ListContainer : public Container {
    protected:
        list<Base*> listcont;
    public:
        ListContainer() { };
        ListContainer(Sort* sort_function) : Container(sort_function) { };
        void add_element(Base* element);
        void print();
        void sort();
        void swap(int i, int j);
        Base* at(int i);
        int size();
};

class VectorContainer : public Container {
    protected:
        vector<Base*> vectcont;
    public:
        VectorContainer();
        VectorContainer(Sort* sort_function);
        void add_element(Base* element);
        void print();
        void sort();
        void swap(int i, int j);
        Base* at(int i);
        int size();
};

#endif
