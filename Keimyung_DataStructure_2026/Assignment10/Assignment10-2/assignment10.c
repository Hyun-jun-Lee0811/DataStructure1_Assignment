#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

typedef struct {
    int rows;
    int cols;
    arrayList* al;
} SparseMatrix;

void initSparseMatrix(SparseMatrix* m) {
    m->rows = 10;
    m->cols = 10;
    m->al = createArrayList(20);

    for (int i = 0; i < 20; i = i + 1) {
        MatrixTerm term;
        term.row = i / 2;
        term.col = (i * 7) % 10;
        term.v = (i + 1) * 3;
        insertArrayList(m->al, m->al->size, term);
    }
}

void transpose(SparseMatrix* source) {
    SparseMatrix sm;
    sm.rows = source->cols;
    sm.cols = source->rows;
    sm.al = createArrayList(source->al->size);

    int cnt = 0;

    for (int c = 0; c < source->cols; c = c + 1) {
        for (int i = 0; i < source->al->size; i = i + 1) {
            cnt = cnt + 1;
            MatrixTerm mt = getItemArrayList(source->al, i);

            if (mt.col == c) {
                MatrixTerm tmp;
                tmp.row = mt.col;
                tmp.col = mt.row;
                tmp.v = mt.v;
                insertArrayList(sm.al, sm.al->size, tmp);
            }
        }
    }

    printf("데이터 이동 횟수: %d\n", cnt);

    destroyArrayList(sm.al);
}

int main() {
    SparseMatrix myMatrix;

    initSparseMatrix(&myMatrix);
    transpose(&myMatrix);
    destroyArrayList(myMatrix.al);

    return 0;
}