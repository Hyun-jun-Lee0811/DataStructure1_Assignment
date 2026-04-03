#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    int N;
    int sum = 0;
    srand((unsigned int)time(NULL));

    printf("N 입력: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        *(arr + i) = rand() % (N + 1);
    }

    printf("\n정방향: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n역방향: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }

    int maxNum = *arr;
    int minNum = *arr;

    for (int i = 0; i < N; i++) {
        int val = *(arr + i);
        sum += val;
        if (val > maxNum) {
            maxNum = val;
        }
        if (val < minNum) {
            minNum = val;
        }
    }
    printf("\n합=%d, 최댓값=%d, 최솟값=%d\n", sum, maxNum, minNum);

    printf("\n마방진 입력: ");
    scanf("%d", &N);

    int** box = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        *(box + i) = (int*)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            *(*(box + i) + j) = 0;
        }
    }

    int firstStart = 0;
    int middleStart = N / 2;

    for (int num = 1; num <= N * N; num++) {
        *(*(box + firstStart) + middleStart) = num;

        int nextFirstStart = firstStart - 1;
        int nextMiddleStart = middleStart + 1;

        if (nextFirstStart < 0) {
            nextFirstStart = N - 1;
        }
        if (nextMiddleStart >= N) {
            nextMiddleStart = 0;
        }

        if (*(*(box + nextFirstStart) + nextMiddleStart) != 0) {
            firstStart = firstStart + 1;
            if (firstStart >= N) firstStart = 0;
        }
        else {
            firstStart = nextFirstStart;
            middleStart = nextMiddleStart;
        }
    }

    printf("\n%dx%d 홀수 마방진:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", *(*(box + i) + j));
        }
        printf("\n");
    }

    printf("\n<합계>:\n");
    int diagonal1 = 0;
    int diagonal2 = 0;

    for (int i = 0; i < N; i++) {
        int rawSum = 0;
        int columnSum = 0;
        for (int j = 0; j < N; j++) {
            rawSum += *(*(box + i) + j);
            columnSum += *(*(box + j) + i);
        }

        diagonal1 += *(*(box + i) + i);
        diagonal2 += *(*(box + i) + (N - 1 - i));
        printf("%d행의 합: %d, %d열의 합: %d\n", i + 1, rawSum, i + 1, columnSum);
    }

    printf("＼의 합: %d\n", diagonal1);
    printf("／의 합: %d\n", diagonal2);

    return 0;
}