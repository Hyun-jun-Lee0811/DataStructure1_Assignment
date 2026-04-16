#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
    int row;
    int col;
    int v;
} MatrixTerm;

typedef MatrixTerm elementArrayList;

typedef struct {
    elementArrayList* data;
    int size;
    int capacity;
} arrayList;

arrayList* createArrayList(int size);
void destroyArrayList(arrayList* al);
int insertArrayList(arrayList* al, int pos, elementArrayList item);
elementArrayList getItemArrayList(arrayList* al, int pos);
int initArrayList(arrayList* al);

#endif