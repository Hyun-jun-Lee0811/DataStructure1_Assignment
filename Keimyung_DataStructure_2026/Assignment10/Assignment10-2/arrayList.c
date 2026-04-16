#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    if (al != NULL) {
        al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
        al->size = 0;
        al->capacity = size;
    }
    return al;
}

void destroyArrayList(arrayList* al) {
    if (al != NULL) {
        if (al->data != NULL) {
            free(al->data);
        }
        free(al);
    }
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) {
        return 0;
    }

    if (al->size >= al->capacity) {
        int newCap = al->capacity * 2;
        elementArrayList* temp = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCap);
        if (temp == NULL) {
            return 0;
        }
        al->data = temp;
        al->capacity = newCap;
    }

    for (int i = al->size - 1; i >= pos; i--) {
        al->data[i + 1] = al->data[i];
    }
    al->data[pos] = item;
    al->size = al->size + 1;
    return 1;
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
    return al->data[pos];
}

int initArrayList(arrayList* al) {
    if (al != NULL) {
        al->size = 0;
        return 1;
    }
    return 0;
}