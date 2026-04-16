#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

void menu() {
    printf("1. 추가\n");
    printf("2. 삭제\n");
    printf("3. 변경\n");
    printf("4. 출력\n");
    printf("5. 초기화\n");
    printf("0. 종료\n");
    printf("입력: ");
}

int main() {
    arrayList* list = createArrayList(5);
    int choice, pos, val;

    while (1) {
        menu();
        if (scanf("%d", &choice) != 1) {
            printf("숫자를 입력해주세요.\n");
            while (getchar() != '\n'); {
                continue;
            }
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            printf("양의 정수와 위치 입력: ");
            scanf("%d %d", &val, &pos);
            if (val <= 0) {
                printf("양의 정수만 입력\n");
            }
            else if (!insertArrayList(list, pos, val)) {
                printf("위치가 잘못되었습니다.\n");
            }
            else {
                printf("추가 완료\n");
            }
            break;
        }

        case 2: {
            printf("삭제할 위치 입력: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= list->size) {
                printf("위치가 잘못되었습니다.\n");
            }
            else {
                deleteArrayList(list, pos);
                printf("삭제 완료!\n");
            }
            break;
        }

        case 3: {
            printf("변경할 위치와 새로운 양의 정수 입력: ");
            scanf("%d %d", &pos, &val);
            if (val <= 0) {
                printf("양의 정수만 가능\n");
            }
            else if (!replaceItemArrayList(list, pos, val)) {
                printf("위치가 잘못되었습니다.\n");
            }
            else {
                printf("변경 완료!\n");
            }
            break;
        }

        case 4: {
            printArrayList(list);
            break;
        }

        case 5: {
            initArrayList(list);
            printf("리스트가 초기화되었습니다.\n");
            break;
        }

        default: {
            printf("잘못된 선택입니다.\n");
            break;
        }
        }
    }

    destroyArrayList(list);
    return 0;
}