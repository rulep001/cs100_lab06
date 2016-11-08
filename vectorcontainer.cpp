#include <iostream>
#include <vector>
#include "vectorcontainer.h"

using namespace std;

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


int VectorContainer::size() {
        return vectcont.size();
}
