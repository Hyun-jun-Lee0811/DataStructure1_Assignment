#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int x;
	int y;
	struct pointType* next;
} PointType;

typedef struct cLinkedList {
	PointType* tail;
	int size;
} CLinkedList;

extern CLinkedList* createCLinkedList();
extern void destoryCLinkedList(CLinkedList* cl);

extern int insertFirstCLinkedList(CLinkedList* cl, PointType item);
extern int insertLastCLinkedList(CLinkedList* cl, PointType item);

extern void printCLinkedList(CLinkedList* cl);