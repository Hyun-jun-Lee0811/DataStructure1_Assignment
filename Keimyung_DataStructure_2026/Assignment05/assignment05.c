#include <stdio.h>
#include <stdlib.h>

#define N 10 
int main() {
    printf("배열 알아보기\n");
    int arr[N];
    int sum = 0;
    int maxNum = 0;
    int minNum = 0;


    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (i + 1);
    }
	minNum = arr[0];

    printf("정방향: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
        if (arr[i] < minNum) {
            minNum = arr[i];
        }
    }

    printf("\n역방향: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n합=%d, 최댓값=%d, 최솟값=%d\n", sum, maxNum, minNum);


    printf("마방진\n");

    int box[N][N] = { 0 };
    int firstStart = 0;           
    int middleStart = N / 2;
    int nextFirstStart;
    int nextMiddleStart;
    int diagonal1 = 0;
    int diagonal2 = 0;
    int BoxSum = 0;
    int rawSum = 0;
    int columnSum = 0;

    for (int num = 1; num <= N * N; num++) {
        box[firstStart][middleStart] = num;
        nextFirstStart = firstStart - 1;
        nextMiddleStart = middleStart + 1;

        if (nextFirstStart < 0) {
            nextFirstStart = N - 1;
        } else if (nextMiddleStart >= N) {
            nextMiddleStart = 0;
        }

        if (box[nextFirstStart][nextMiddleStart] != 0) {
            firstStart = firstStart + 1;
            if (firstStart >= N) {
                firstStart = 0;
            }
        } else {
            firstStart = nextFirstStart;
            middleStart = nextMiddleStart;
        }
    }

    printf("%dx%d 마방진:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", box[i][j]);
        }
        printf("\n");
    }
    BoxSum = N * (N * N + 1) / 2;
    printf("\n<합계>:\n", BoxSum);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rawSum += box[i][j];
            columnSum += box[j][i];
        }
        diagonal1 += box[i][i];
        diagonal2 += box[i][N - 1 - i];

        printf("%d행의 합: %2d, %d열의 합: %2d\n", i + 1, rawSum, i + 1, columnSum);
    }
    printf("＼의 합: %2d\n", diagonal1);
    printf("／의 합: %2d\n", diagonal2);

    return 0;
}