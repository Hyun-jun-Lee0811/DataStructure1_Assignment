#include <stdio.h>

#include "DLinkedList.h"

int main() {
	DLinkedList* myList = createDLinkedList();
	int menu;

	while (menu != 0) {
		printf("\n");
		printf("1. 맨 앞 추가\n");
		printf("2. 맨 뒤 추가\n");
		printf("3. 특정 위치 추가\n");
		printf("4. 특정 위치 삭제\n");
		printf("5. 전체 출력\n");
		printf("6. 리스트 크기 출력\n");
		printf("0. 종료\n");

		printf("입력: ");
		scanf("%d", &menu);
		if (menu == 0) {
			destoryDLinkedList(myList);
			printf("프로그램 종료\n");
			break;
		}
		switch (menu) {
		case 1: {
			int x;
			int y;
			printf("x 입력: ");
			scanf("%d", &x);
			printf("y 입력: ");
			scanf("%d", &y);
			insertFirstDLinkedList(	myList,	(PointType) {x, y, 0, 0});
			break;
		}
		case 2: {
			int x;
			int y;
			printf("x 입력: ");
			scanf("%d", &x);
			printf("y 입력: ");
			scanf("%d", &y);
			insertLastDLinkedList(	myList,	(PointType) {x, y, 0, 0});
			break;
		}
		case 3: {
			int index;
			int x;
			int y;
			printf("index 입력: ");
			scanf("%d", &index);
			printf("x 입력: ");
			scanf("%d", &x);
			printf("y 입력: ");
			scanf("%d", &y);
			insertAtDLinkedList(	myList,index,	(PointType) {x, y, 0, 0});
			break;
		}
		case 4: {
			int index;
			printf("입력: ");
			scanf("%d", &index);
			PointType deleted =deleteAtDLinkedList(myList, index);
			printf(	"삭제된 값 -> x: %d y: %d\n",deleted.x,deleted.y);
			break;
		}
		case 5:
			printDLinkedList(myList);
			break;
		case 6:
			printf("현재 크기: %d\n", myList->size);
			break;

		default:
			printf("잘못s누름\n");
		}
	}

	return 0;
}