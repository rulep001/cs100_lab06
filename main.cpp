// Ryan Ulep
// Michael Pare

#include "Base.h"
#include "container.h"
#include "vectorcontainer.h"
#include "listcontainer.h"
#include "decorator.h"

using namespace std;

int main() {
	Op *op1 = new Op (-2.2);
	Op *op2 = new Op (5.5);
	Op *op3 = new Op (-3.3);
	Op *op4 = new Op (4.4);
	Mult *A = new Mult ( op1 ,  op4 );
	Add *B = new Add ( op3 ,  A );
	Sub *C = new Sub ( B ,  op2 );
	Sqr *D = new Sqr ( C );
	
	cout << D->evaluate() << endl;
	Base* X = new CeilDecorator(D);
	cout << "Test Ceil: \n" << X->evaluate() << endl;
	
	cout << B->evaluate() << endl;
	Base* Y = new FloorDecorator(B);
	cout << "Test Floor: \n" << Y->evaluate() << endl;
	
	cout << A->evaluate() << endl;
	Base* Z = new AbsDecorator(A);
	cout << "Test Abs: \n" << Z->evaluate() << endl;

	cout << Y->evaluate() << endl;
	Base* Q = new AbsDecorator(Y);
	cout << "Test Abs on Negative: " << Q->evaluate() << endl;
};
