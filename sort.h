#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "container.h"

class Container;

using namespace std;

class Sort {
    public:
	// Sort();
	virtual void sort(Container* container) = 0;
};


class BubbleSort : public Sort {
    public:
	BubbleSort();
	void sort(Container* container);
};


class SelectionSort : public Sort {
    public:
	SelectionSort();
	void sort(Container* container);
};

#endif
