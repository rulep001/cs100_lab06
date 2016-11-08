#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "container.h"

using namespace std;

void ListContainer::add_element(Base* element) {
        listcont.push_back(element);
}


void ListContainer::print() {
        list<Base*>::iterator it = listcont.begin();
        for (it = listcont.begin(); it != listcont.end(); ++it) {
                cout << (*it)->evaluate() << " ";
        }
	cout << endl;
}


void ListContainer::sort() {
	try {
		if (sort_function == NULL) {
			throw std::runtime_error("Error: No Sort");
		}
	}
	catch (std::runtime_error &e) {
		cout << e.what() << std::endl;
		exit(1);
	}
        this->sort_function->sort(this);
}


void ListContainer::swap(int i, int j) {
        list<Base*>::iterator it1 = listcont.begin();
        advance(it1, i);

        list<Base*>::iterator it2 = listcont.begin();
        advance(it2, j);

        Base* temp = *it1;
        *it1 = *it2;
        *it2 = temp;
}


Base* ListContainer::at(int i) {
        if (static_cast<int> (listcont.size()) > i) {
                list<Base*>::iterator it = listcont.begin();
                advance(it, i);
                return *it;
        }
        else {
                return NULL;
        }
}


int ListContainer::size() {
        return listcont.size();
}

VectorContainer::VectorContainer()
{ }

void VectorContainer::add_element(Base* element) {
        vectcont.push_back(element);
}


void VectorContainer::print() {
        for (unsigned i = 0; i < vectcont.size(); ++i) {
                cout << vectcont.at(i)->evaluate() << " ";
        }
	cout << endl;
}


void VectorContainer::sort() {
        try {
                if (sort_function == NULL) {
                        throw std::runtime_error("Error: No Sort");
                }
        }
        catch (std::runtime_error &e) {
                cout << e.what() << std::endl;
                exit(1);
        }
        this->sort_function->sort(this);
}


void VectorContainer::swap(int i, int j) {
        Base* temp = vectcont.at(i);
        vectcont.at(i) = vectcont.at(j);
        vectcont.at(j) = temp;
}


Base* VectorContainer::at(int i) {
        return vectcont.at(i);
}