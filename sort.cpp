#include <iostream>
#include "Base.h"
#include "sort.h"

using namespace std;

BubbleSort::BubbleSort() { }

SelectionSort::SelectionSort() { }

void BubbleSort::sort(Container* container) {
	for (int i = 0; i < container->size(); ++i) {
		for (int j = 0; j < container->size() - 1; ++j) {
			if (container->at(j + 1)->evaluate() > container->at(j)->evaluate()) {
				container->swap(j, j + 1);
			}
		}
	}
}

void SelectionSort::sort(Container* container) {
	for (int i = 0; i < container->size(); ++i) {
		int min = i;
		for (int j = i + 1; j < container->size(); ++j) {
			if (container->at(j)->evaluate() < container->at(min)->evaluate()) {
				min = j;
			}
		}
		container->swap(i, min);
	}
}

