#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int id;
    int score;
} Student;

int main() {
    int N;
    int minIdx = 0;
    int maxIdx = 0;
    double sum = 0;
    char nameP[100][50];
    int nameCnt = 0;
    srand(time(NULL));

    FILE* fp;
    char path[] = "C:\\Users\\user\\OneDrive\\Desktop~1-HyunjunLee-56359672\\계명대\\자료구조1\\Keimyung_DataStructure_2026\\Assignment07\\name_list.txt";

    printf("학생 수: ");
    scanf("%d", &N);

    Student* students = (Student*)malloc(sizeof(Student) * N);

    if (students == NULL) {
        return 1;
    }

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        free(students);
        return 1;
    }

    while (fgets(nameP[nameCnt], sizeof(nameP[nameCnt]), fp) != NULL) {
        nameP[nameCnt][strcspn(nameP[nameCnt], "\n")] = 0;
        nameCnt++;
        if (nameCnt >= 100) {
            break;
        }
    }
    fclose(fp);

    for (int i = 0; i < N; i++) {
        strcpy(students[i].name, nameP[rand() % nameCnt]);
        students[i].id = i + 1;          
        students[i].score = rand() % 101 +1;
    }

    printf("\n인덱스 연산자\n");

    for (int i = 0; i < N; i++) {
        if (students[i].score < students[minIdx].score) {
            minIdx = i;
        }
        if (students[i].score > students[maxIdx].score) {
            maxIdx = i;
        }
        sum += students[i].score;
    }

    printf("최저점: %s(%d학번) -> %d점\n", students[minIdx].name, students[minIdx].id, students[minIdx].score);
    printf("최고점: %s(%d학번) -> %d점\n", students[maxIdx].name, students[maxIdx].id, students[maxIdx].score);
    printf("평균점수: %.2f\n", sum / N);

    printf("\n포인터 연산자\n");
    Student* minP = (students + 0);
    Student* maxP = (students + 0);
    sum = 0;

    for (int i = 0; i < N; i++) {
        if ((*(students + i)).score < (*minP).score) {
            minP = (students + i);
        } 
        if ((*(students + i)).score > (*maxP).score) {
            maxP = (students + i);
        }
        sum += (*(students + i)).score;
    }

    printf("최저점: %s(%d학번) -> %d점\n", (*minP).name, (*minP).id, (*minP).score);
    printf("최고점: %s(%d학번) -> %d점\n", (*maxP).name, (*maxP).id, (*maxP).score);
    printf("평균점수: %.2f\n", sum / N);

    return 0;
}