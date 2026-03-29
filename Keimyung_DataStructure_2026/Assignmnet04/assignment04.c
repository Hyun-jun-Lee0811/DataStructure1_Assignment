#include <stdio.h>
#include <time.h>
#include "my_math.h"

long long fibonacci(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    printf("n  F(n)  F(n-1)  GCD 결과  소요 시간\n");

    for (int n = 5; n <= 45; n++) {
        long long fn = fibonacci(n);
        long long minus = fibonacci(n - 1);

        clock_t start = clock();
        int result = get_gcd((int)fn, (int)minus);
        clock_t end = clock();

        double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d %lld %lld %d %.5f\n", n, fn, minus, result, duration);
    }
    return 0;
}