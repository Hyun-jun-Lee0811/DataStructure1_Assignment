#include "CLinkedList.h"


CLinkedList* createCLinkedList() {
	CLinkedList* temp;
	temp = (CLinkedList*)malloc(sizeof(CLinkedList));
	temp->tail = NULL;
	temp->size = 0;

	return temp;
}

void destoryCLinkedList(CLinkedList* cl) {
	PointType* temp;
	temp = cl->tail->next;

	while (cl->size != 0) {
		PointType* nPtr = temp->next;
		free(temp);
		temp = nPtr;
		cl->size--;
	}

	free(cl);
}

int insertFirstCLinkedList(CLinkedList* cl, PointType item) {
	PointType* nPtr;
	nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (cl->size == 0) {
		nPtr->next = nPtr;
		cl->tail = nPtr;
	}
	else {
		nPtr->next = cl->tail->next;
		cl->tail->next = nPtr;
	}

	cl->size++;
	return 1;
}

int insertLastCLinkedList(CLinkedList* cl, PointType item) {
	insertFirstCLinkedList(cl, item);
	cl->tail = cl->tail->next;
	return 1;
}

void printCLinkedList(CLinkedList* cl) {
	printf("Print CLinkedList:\n");
	printf("Size: %d\n", cl->size);

	if (cl->size == 0) {
		return;
	}

	PointType* start = cl->tail->next;

	for (int i = 0; i < cl->size; i++) {
		printf("[%d] x: %d, y: %d, next: %x\n",
			i, start->x, start->y, start->next);

		start = start->next;
	}
}