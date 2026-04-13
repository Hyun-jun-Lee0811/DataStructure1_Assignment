#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int fiboIter(int n) {
    int f1 = 1;
    int f2 = 1;

    if (n == 1) {
        return f1;
    }else if (n == 2) {
        return f2;
    } else {
        int fn;
        for (int i = 3; i <= n; i++) {
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
}

int fiboRecursion(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fiboRecursion(n - 1) + fiboRecursion(n - 2);
}

int main() {
    clock_t start;
    clock_t end;
    double iter;
    double recursion;

    for (int n = 1; n <= 46; n++) {
        start = clock();
        fiboIter(n);
        end = clock();

        iter = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        fiboRecursion(n);
        end = clock();

        recursion = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d,%lf,%lf\n", n, iter, recursion);
    }

    return 0;
}