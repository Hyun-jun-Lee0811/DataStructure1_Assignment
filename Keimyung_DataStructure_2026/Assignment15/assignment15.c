#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "LinkedStack.h"

int main() {

	LinkedStack* myStack = createLinkedStack();

	int menu = -1;

	while (menu != 0) {
		printf("1. URL 추가\n");
		printf("2. URL 제거\n");
		printf("3. 스택 확인\n");
		printf("4. 전체 출력\n");
		printf("0. 종료\n");
		printf("입력: ");
		scanf("%d", &menu);

		switch (menu) {

		case 1: {
			char url[100];
			printf("URL 입력: ");
			scanf("%s", url);
			pushLinkedStack(myStack, url);
			printf("현재: %s\n",peekLinkedStack(myStack));
			break;
		}

		case 2: {

			if (emptyLinkedStack(myStack)) {
				printf("브라우저 종료.\n");
				destroyLinkedStack(myStack);
				return 0;
			}

			char* removed =popLinkedStack(myStack);
			printf("이탈: %s\n", removed);
			free(removed);

			if (emptyLinkedStack(myStack)) {
				printf("브라우저 종료.\n");
				destroyLinkedStack(myStack);
				return 0;
			}
			printf("현재: %s\n",peekLinkedStack(myStack));

			break;
		}

		case 3: {

			if (emptyLinkedStack(myStack)) {
				printf("비어 있습니다.\n");
			}
			else {
				printf("현재: %s\n",peekLinkedStack(myStack));
			}
			break;
		}

		case 4:
			printLinkedStack(myStack);
			break;

		case 0:
			destroyLinkedStack(myStack);
			printf("종료\n");
			break;
		default:
			printf("잘못된 입력\n");
		}
	}

	return 0;
}