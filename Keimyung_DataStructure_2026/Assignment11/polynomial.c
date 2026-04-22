#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

polynomial* createPolynomial(int capacity) {
    return (polynomial*)createArrayList(capacity);
}

polynomial* addItemPolynomial(polynomial* po, elementType item) {
    int i;
    for (i = 0; i < sizeArrayList(po); i++) {
        if (po->data[i].expo <= item.expo) {
            break;
        }
    }

    if (i < sizeArrayList(po) && po->data[i].expo == item.expo) {
        po->data[i].coef += item.coef;
    }
    else {
        insertArrayList(po, i, item);
    }

    return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
    polynomial* r = createPolynomial(100);
    int i = 0;
    int j = 0;

    while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
        if (p1->data[i].expo < p2->data[j].expo) {
            addItemPolynomial(r, p2->data[j]);
            j++;
        }
        else if (p1->data[i].expo > p2->data[j].expo) {
            addItemPolynomial(r, p1->data[i]);
            i++;
        }
        else {
            elementType sumItem;
            sumItem.coef = p1->data[i].coef + p2->data[j].coef;
            sumItem.expo = p1->data[i].expo;
            if (sumItem.coef != 0) {
                addItemPolynomial(r, sumItem);
            }
            i++;
            j++;
        }
    }

    for (; i < sizeArrayList(p1); i++) {
        addItemPolynomial(r, p1->data[i]);
    }
    for (; j < sizeArrayList(p2); j++) {
        addItemPolynomial(r, p2->data[j]);
    }

    return r;
}

polynomial* multiplyPolynomial(polynomial* p1, polynomial* p2) {
    polynomial* r = createPolynomial(200);

    for (int i = 0; i < sizeArrayList(p1); i++) {
        for (int j = 0; j < sizeArrayList(p2); j++) {
            elementType newItem;
            newItem.coef = p1->data[i].coef * p2->data[j].coef;
            newItem.expo = p1->data[i].expo + p2->data[j].expo;
            addItemPolynomial(r, newItem);
        }
    }
    return r;
}

void printPolynomial(polynomial* po) {
    printf("Polynomial -> ");
    printArrayList(po);
    printf("\n");
}