#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "arrayList.h"

typedef arrayList polynomial;

polynomial* createPolynomial(int capacity);
polynomial* addItemPolynomial(polynomial* po, elementType item);
void printPolynomial(polynomial* po);
polynomial* addPolynomial(polynomial* p1, polynomial* p2);
polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2);

#endif