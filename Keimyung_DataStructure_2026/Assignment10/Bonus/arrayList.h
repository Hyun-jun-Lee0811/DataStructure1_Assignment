#pragma once
#ifndef EXTRA_ARRAY_LIST_H
#define EXTRA_ARRAY_LIST_H

typedef struct {
    int row;
    int col;
    int value;
} elementArrayList;

typedef struct {
    elementArrayList* data;
    int size;
    int capacity;
} arrayList;

arrayList* createArrayList(int size);
void destroyArrayList(arrayList* al);
int insertArrayList(arrayList* al, int pos, elementArrayList item);
elementArrayList getItemArrayList(arrayList* al, int pos);
int sizeArrayList(arrayList* al);
void printArrayList(arrayList* al);

#endif