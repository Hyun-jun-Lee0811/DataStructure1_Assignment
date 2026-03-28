#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_fraction.h"
#include "my_math.h"

Fraction fromDouble(double d) {
    int den = 1000000;
    int num = (int)(d * den);
    Fraction f = { num, den };
    return simplify(f);
}

Fraction parseInput(char* str) {
    if (str == NULL) {
        printf("Error: invalid input\n");
        exit(1);
    }

    Fraction f;

    if (strchr(str, '/') != NULL) {
        if (sscanf(str, "%d/%d", &f.num, &f.den) != 2) {
            printf("Error: invalid fraction format\n");
            exit(1);
        }
    }
    else if (strchr(str, '.') != NULL) {
        double d = atof(str);
        return fromDouble(d);
    }
    else {
        f.num = atoi(str);
        f.den = 1;
    }

    if (f.den == 0) {
        printf("Error: denominator cannot be 0\n");
        exit(1);
    }

    return simplify(f);
}

int main(int argc, char** argv) {

    if (argc == 3) {
        Fraction width = parseInput(argv[1]);
        Fraction height = parseInput(argv[2]);

        Fraction two = { 2, 1 };

        Fraction perimeter = multiply(add(width, height), two);
        Fraction area = multiply(width, height);

        printf("Perimeter: ");
        printFraction(perimeter);
        printf(", Area: ");
        printFraction(area);
        printf("\n");

        return 0;
    }

    char line[100];
    printf("입력: ");
    fgets(line, sizeof(line), stdin);

    char* a = strtok(line, " \n");
    char* b = strtok(NULL, " \n");
    char* c = strtok(NULL, " \n");

    int count = 0;
    if (a != NULL) {
        count++;
    }
    if (b != NULL) {
        count++;
    }
    if (c != NULL) {
        count++;
    }

    if (count == 3 &&
        (strcmp(b, "+") == 0 || strcmp(b, "-") == 0 ||
            strcmp(b, "*") == 0 || strcmp(b, "/") == 0)) {

        Fraction f1 = parseInput(a);
        Fraction f2 = parseInput(c);
        Fraction result;

        if (strcmp(b, "+") == 0) {
            result = add(f1, f2);
        }
        else if (strcmp(b, "-") == 0) {
            result = subtract(f1, f2);
        }
        else if (strcmp(b, "*") == 0) {
            result = multiply(f1, f2);
        }
        else {
            if (f2.num == 0) {
                printf("0을 나눌 수가 없습니다\n");
                return 1;
            }
            result = divide(f1, f2);
        }

        printf("출력: ");
        printFraction(result);
        printf("\n");
    }

    else if (count == 2 &&
        strchr(a, '/') == NULL && strchr(b, '/') == NULL &&
        strchr(a, '.') == NULL && strchr(b, '.') == NULL) {

        int x = atoi(a);
        int y = atoi(b);

        printf("GCD: %d, LCM: %d\n", get_gcd(x, y), get_lcm(x, y));
    }

    else {
        printf("입력 오류\n");
    }

    return 0;
}