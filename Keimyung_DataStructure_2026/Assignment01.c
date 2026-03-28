#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define FRACTIONAL_BITS 8

int main() {

    /* 과제1 
    -1을 이진수로 표현하면 1의 보수에서는 0인 상태에서 반전하므로 ~0이며 
    2의 보수에서는 1의 보수에 1을 더하므로 -1 비트 패턴은 모두 1입니다. 
    따라서 i가 ~0과 같다면 2의 보수, 그렇지 않다면 1의 보수입니다. 
    */
    int i = -1;
    if (i == ~0) {
        printf("2의 보수입니다.\n");
    }
    else {
        printf("1의 보수입니다.\n");
    }

    /* 과제2
    scanf가 지원되지 않아 scanf_s를 사용했습니다. 
    고정소수점 변환을 위해 입력값에 곱한 뒤 반올림하여 정수로 변환하였습니다. 
    fractional bits를 8로 설정하여 Q8.8 형식을 사용하였습니다. 
    */
    double input;
    printf("입력값: ");

    if (scanf_s("%lf", &input) != 1) {
        return 1;
    }

    short num = (short)round(input * (1 << FRACTIONAL_BITS));

    for (int b = 15; b >= 0; b--) {
        printf("%d", (num >> b) & 1);
        if (b == FRACTIONAL_BITS) {
            printf(".");
        }
    }
    printf("\n");

    return 0;
}