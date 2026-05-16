#include "DLinkedList.h"

DLinkedList* createDLinkedList() {

	DLinkedList* temp;
	temp = (DLinkedList*)malloc(sizeof(DLinkedList));
	temp->head.prev = &(temp->head);
	temp->head.next = &(temp->head);
	temp->size = 0;

	return temp;
}

void destoryDLinkedList(DLinkedList* dl) {
	while (dl->size != 0) {
		deleteFirstDLinkedList(dl);
	}

	free(dl);
}

int insertFirstDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = &(dl->head);
	nPtr->next = dl->head.next;
	dl->head.next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}

int insertLastDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = dl->head.prev;
	nPtr->next = &(dl->head);
	nPtr->prev->next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}

int insertAtDLinkedList(DLinkedList* dl, int index, PointType item) {
	PointType* cur = dl->head.next;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->prev = cur->prev;
	nPtr->next = cur;
	cur->prev->next = nPtr;
	cur->prev = nPtr;
	dl->size++;
}

PointType deleteFirstDLinkedList(DLinkedList* dl) {

	PointType empty = { -1, -1, NULL, NULL };

	if (dl->size == 0) {
		return empty;
	}

	PointType* temp = dl->head.next;
	PointType item = *temp;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	dl->size--;
	free(temp);

	return item;
}

PointType deleteAtDLinkedList(DLinkedList* dl, int index) {

	PointType empty = { -1, -1, NULL, NULL };
	if (index < 0 || index >= dl->size) {
		return empty;
	}
	PointType* cur = dl->head.next;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}

	PointType item = *cur;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	dl->size--;
	free(cur);
	return item;
}

PointType deleteItemDLinkedList(DLinkedList* dl, int x, int y) {

	PointType empty = { -1, -1, NULL, NULL };
	PointType* cur = dl->head.next;
	for (int i = 0; i < dl->size; i++) {
		if (cur->x == x && cur->y == y) {
			PointType item = *cur;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			dl->size--;
			free(cur);
			return item;
		}

		cur = cur->next;
	}

	return empty;
}

void printDLinkedList(DLinkedList* dl) {

	printf("\nDLinkedList = \n");
	printf("Size: %d\n", dl->size);
	if (dl->size == 0) {
		return;
	}
	PointType* start = dl->head.next;
	for (int i = 0; i < dl->size; i++) {
		printf("[%d] x: %d, y: %d\n", i,start->x,start->y);
		start = start->next;
	}
}