#include <stdio.h>

int main() {

    /*
    처음에는 31~0 비트를 하나의 반복문에서 출력하면서 공백을 조건문으로 처리하려했습니다。
    하지만 과제의 예시와 다르게 0/100 0000 1/011 1000 0000 0000 0000 0000가 나와서 여러 차례 서칭을 하거나 생각을 하였으며
    비트를 나누어 출력해보았습니다。 최상위 비트、 ４비트 단위로 공백 추가
    이렇게 하니 과제의 요구사항에 맞게 IEEE 754 형식의 출력하였습니다¡
    */
    float input;

    printf("입력: ");
    scanf_s("%f", &input);
    unsigned int v = *(unsigned int*)&input;

    printf("%d/", (v >> 31) & 1);

    for (int i = 30; i >= 23; i--) {
        printf("%d", (v >> i) & 1);

        if (i == 27) printf(" ");
    }
    for (int i = 22; i >= 0; i--) {
        printf("%d", (v >> i) & 1);

        if (i % 4 == 0 && i != 0)
            printf(" ");
    }

    printf("\n");

    /*
    아스키 코드에 따라 각각 숫자를 더하거나 빼서 문자변환을 하였습니다。
    */

    char input2[200] = { '\0' };

    printf("입력: ");
    scanf_s("%[^\n]", input2, 200);

    for (int i = 0; input2[i] != '\0'; i++) {
        if (input2[i] >= 'A' && input2[i] <= 'Z') {
            input2[i] += 32;
        }
        else if (input2[i] >= 'a' && input2[i] <= 'z') {
            input2[i] -= 32;
        }
    }

    printf("출력: %s\n", input2);

    return 0;
}