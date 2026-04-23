#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    al->size = 0;
    al->capacity = size;
    return al;
}

void destroyArrayList(arrayList* al) {
    free(al->data);
    free(al);
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) {
        return 0;
    }
    if (al->size >= al->capacity) {
        al->capacity *= 2;
        al->data = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * al->capacity);
    }
    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }
    al->data[pos] = item;
    al->size++;
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    return al->data[pos];
}

void printArrayList(arrayList* al) {
    for (int i = 0; i < al->size; i++) {
        printf("(%d, %d, %d) ", al->data[i].row, al->data[i].col, al->data[i].value);
    }
    printf("\n");
}