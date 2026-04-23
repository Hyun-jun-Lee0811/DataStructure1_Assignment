<<<<<<< HEAD
#include <stdio.h>
=======
﻿#include <stdio.h>
>>>>>>> origin/main
#include "sparseMatrix.h"

int main() {
    sparseMatrix* input1 = createSparseMatrix(5, 5);
    addElementSparseMatrix(input1, 2, 1, 10);
    addElementSparseMatrix(input1, 3, 3, 15);
    addElementSparseMatrix(input1, 4, 1, 3);

    sparseMatrix* input2 = createSparseMatrix(5, 5);
    addElementSparseMatrix(input2, 2, 1, 10);
    addElementSparseMatrix(input2, 3, 4, 15);
    addElementSparseMatrix(input2, 4, 1, 3);

    printf("Matrix 1\n");
    printSparseMatrix(input1);
    printf("\nMatrix 2\n");
    printSparseMatrix(input2);

    sparseMatrix* sm3 = addSparseMatrix(input1, input2);
    printf("\n더한 결과\n");
    printSparseMatrix(sm3);

    destroyArrayList(input1);
    destroyArrayList(input2);
    destroyArrayList(sm3);

    return 0;
}