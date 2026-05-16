#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int x;
	int y;
	struct pointType* prev;
	struct pointType* next;
} PointType;

typedef struct dLinkedList {
	PointType head;
	int size;
} DLinkedList;

extern DLinkedList* createDLinkedList();
extern void destoryDLinkedList(DLinkedList* dl);

extern int insertFirstDLinkedList(DLinkedList* dl, PointType item);
extern int insertLastDLinkedList(DLinkedList* dl, PointType item);
extern int insertAtDLinkedList(DLinkedList* dl, int index, PointType item);

extern PointType deleteFirstDLinkedList(DLinkedList* dl);
extern PointType deleteAtDLinkedList(DLinkedList* dl, int index);
extern PointType deleteItemDLinkedList(DLinkedList* dl, int x, int y);

extern void printDLinkedList(DLinkedList* dl);