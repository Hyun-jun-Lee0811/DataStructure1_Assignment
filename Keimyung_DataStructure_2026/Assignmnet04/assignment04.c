#include <stdio.h>
#include <time.h>
#include "my_math.h"

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    printf("n, F(n), GCD 결과, 소요 시간(ms)\n");

    for (int n = 5; n <= 45; n++) {
        clock_t start = clock();

        long long fn = fibonacci(n);
        long long fn_minus_1 = fibonacci(n - 1);

        int result = get_gcd((int)fn, (int)fn_minus_1);

        clock_t end = clock();

        double duration = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        printf("%d, %lld, %d, %.5f ms\n", n, fn, result, duration);

    }
    return 0;
}