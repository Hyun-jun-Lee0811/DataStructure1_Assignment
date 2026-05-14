#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
	CLinkedList* myList = createCLinkedList();
	insertFirstCLinkedList(myList, (PointType) { 10, 20, 0 });
	insertFirstCLinkedList(myList, (PointType) { 20, 30, 0 });
	insertLastCLinkedList(myList, (PointType) { 30, 40, 0 });
	insertLastCLinkedList(myList, (PointType) { 40, 50, 0 });
	printCLinkedList(myList);
	destoryCLinkedList(myList);
}