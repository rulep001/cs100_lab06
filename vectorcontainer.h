#ifndef VECTORCONT_H
#define VECTORCONT_H

#include "container.h"
#include <vector>

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
