#include "LinkedList.h"

LinkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(LinkedList* li) {
	struct pointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");

	for (int i = 0; i < li->size; i++) {
		printf("[%d] x:%d, y:%d, next:%x\n",
			i, current->x, current->y, current->next);

		current = current->next;
	}
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->next = NULL;

	if (li->head == NULL) {
		li->head = nPtr;
	}
	else {
		PointType* ptr = li->head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = nPtr;
	}
	li->size++;
	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (li == NULL || at < 0 || at >= li->size) {
		printf("오류.\n");
		return li;
	}

	PointType* fPtr = NULL;

	if (at == 0) {
		fPtr = li->head;
		li->head = fPtr->next;
	} else {
		PointType* nPtr = li->head;
		for (int i = 0; i < at - 1; i++) {
			nPtr = nPtr->next;
		}
		fPtr = nPtr->next;
		nPtr->next = fPtr->next;
	}

	if (fPtr != NULL) {
		printf("삭제 완료");
		free(fPtr);
		li->size--; 
	}

	return li;
}

LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item) {
	if (at < 0 || at > li->size) {
		printf("잘못됨\n");
		return li;
	}
	if (at == 0) {
		return insertFirstLinkedList(li, item);
	}

	PointType* pt;
	pt = (PointType*)malloc(sizeof(PointType));
	*pt = item;

	PointType* ptr;
	ptr = li->head;

	for (int i = 0; i < at - 1; i++) {
		ptr = ptr->next;
	}
	pt->next = ptr->next;
	ptr->next = pt;
	li->size++;

	return li;
}