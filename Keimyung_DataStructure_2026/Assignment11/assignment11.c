#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"



int main() {
    polynomial* p1 = createPolynomial(100);
    polynomial* p2 = createPolynomial(100);
    int c;
    int e;

    printf("다항식 1(계수 지수): ");
    scanf("%d %d", &c, &e);
    while (e != -1) {
        addItemPolynomial(p1, (elementType) { c, e });
        scanf("%d %d", &c, &e);
    }

    printf("다항식 2(계수 지수): ");
    scanf("%d %d", &c, &e);
    while (e != -1) {
        addItemPolynomial(p2, (elementType) { c, e });
        scanf("%d %d", &c, &e);
    }

    printf("\n결과 \n");
    printPolynomial(p1);
    printPolynomial(p2);

    polynomial* pAdd = addPolynomial(p1, p2);
    printf("덧셈 : ");
    printPolynomial(pAdd);

    polynomial* pMul = multiplyPolynomial(p1, p2);
    printf("곱셈 : ");
    printPolynomial(pMul);

    destroyArrayList(p1);
    destroyArrayList(p2);
    destroyArrayList(pAdd);
    destroyArrayList(pMul);

    return 0;
}