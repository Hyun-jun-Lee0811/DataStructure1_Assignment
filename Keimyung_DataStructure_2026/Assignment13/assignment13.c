#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

int main() {
	int menu;
	int x;
	int y;
	int index;


	LinkedList* list;
	list = createLinkedList();

	while (1) {
		printf("1. 맨 앞에 추가\n");
		printf("2. 맨 뒤에 추가\n");
		printf("3. 특정 위치에 추가\n");
		printf("4. 특정 위치 삭제\n");
		printf("5. 전체 목록 출력\n");
		printf("6. 리스트 크기 확인\n");
		printf("0 종료\n");

		printf("입력 : ");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("x y 입력 : ");
			scanf("%d %d", &x, &y);

			insertFirstLinkedList(list,(PointType) {x, y, 0});
		}

		else if (menu == 2) {
			printf("x y 입력 : ");
			scanf("%d %d", &x, &y);

			insertLastLinkedList(list, (PointType) { x, y, 0 });
		}

		else if (menu == 3) {
			printf("입력 : ");
			scanf("%d", &index);

			printf("x y 입력 : ");
			scanf("%d %d", &x, &y);

			insertAtLinkedList(list,index,(PointType) {x, y, 0});
		}

		else if (menu == 4) {
			printf("입력 : ");
			scanf("%d", &index);

			deleteAtLinkedList(list, index);
		}

		else if (menu == 5) {
			printLinkedList(list);
		}

		else if (menu == 6) {
			printf("리스트 크기 : %d\n",sizeLinkedList(list));
		}

		else if (menu == 0) {
			destroyLinkedList(list);
			printf("종료\n");
			break;
		}

		else {
			printf("잘못된 입력\n");
		}
	}
}