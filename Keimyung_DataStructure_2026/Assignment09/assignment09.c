#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int main() {
    arrayList* myArrayList = createArrayList(2);

    insertArrayList(myArrayList, 0, 10);
    insertArrayList(myArrayList, 1, 20);
    printArrayList(myArrayList);
    insertArrayList(myArrayList, 2, 30);
    insertArrayList(myArrayList, 3, 40);
    printArrayList(myArrayList);
    insertArrayList(myArrayList, 4, 50);
    printArrayList(myArrayList);
    destroyArrayList(myArrayList);
    return 0;
}