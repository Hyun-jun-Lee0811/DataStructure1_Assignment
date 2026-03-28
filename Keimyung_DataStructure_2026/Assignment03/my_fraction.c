#define _CRT_SECURE_NO_WARNINGS
#include "my_fraction.h"
#include "my_math.h"
#include <stdio.h>
#include <stdlib.h>

Fraction simplify(Fraction f) {
    if (f.den == 0) {
        return f;
    }
    int common = get_gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;
    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }
    return f;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.den +
        f2.num * f1.den,
        f1.den * f2.den };
    return simplify(res);
}

Fraction subtract(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.den -
        f2.num * f1.den,
        f1.den * f2.den };
    return simplify(res);
}

Fraction multiply(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.num,
        f1.den * f2.den };
    return simplify(res);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction res = { f1.num * f2.den,
        f1.den * f2.num };
    return simplify(res);
}

Fraction fromString(char* str) {
    Fraction f = { 0, 1 };
    if (sscanf(str, "%d/%d",
        &f.num, &f.den) != 2) {
        f.den = 1;
    }
    return f;
}

void printFraction(Fraction f) {
    f = simplify(f);

    if (f.den == 1) {
        printf("%d", f.num);
    }
    else {
        printf("%d/%d", f.num, f.den);
    }
}