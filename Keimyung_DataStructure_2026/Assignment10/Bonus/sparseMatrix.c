#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
    return createArrayList(row * col);
}

void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
    insertArrayList(sm, sizeArrayList(sm), (elementArrayList) { row, col, value });
}

void printSparseMatrix(sparseMatrix* sm) {
    printf("Sparse Matrix->size: %d):\n", sizeArrayList(sm));
    printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
    sparseMatrix* smResult = createSparseMatrix(1, sizeArrayList(sm1) + sizeArrayList(sm2));
    int* visited = (int*)calloc(sizeArrayList(sm2), sizeof(int));

    for (int i = 0; i < sizeArrayList(sm1); i++) {
        elementArrayList t1 = getItemArrayList(sm1, i);
        int contact = 0;

        for (int j = 0; j < sizeArrayList(sm2); j++) {
            elementArrayList t2 = getItemArrayList(sm2, j);
            if (t1.row == t2.row && t1.col == t2.col) {
                insertArrayList(smResult, sizeArrayList(smResult),
                    (elementArrayList) {
                    t1.row, t1.col, t1.value + t2.value
                });
                visited[j] = 1;
                contact = 1;
                break;
            }
        }
        if (!contact) {
            insertArrayList(smResult, sizeArrayList(smResult), t1);
        }
    }

    for (int j = 0; j < sizeArrayList(sm2); j++) {
        if (!visited[j]) {
            insertArrayList(smResult, sizeArrayList(smResult), getItemArrayList(sm2, j));
        }
    }

    free(visited);
    return smResult;
}