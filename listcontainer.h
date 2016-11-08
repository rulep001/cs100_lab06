#ifndef LISTCONT_H
#define LISTCONT_H

#include <iostream>
#include "container.h"
#include <list>

using namespace std;

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

#endif
