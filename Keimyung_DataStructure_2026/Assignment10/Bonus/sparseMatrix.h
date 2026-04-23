#pragma once
#ifndef EXTRA_SPARSE_MATRIX_H
#define EXTRA_SPARSE_MATRIX_H

#include "arrayList.h"

typedef arrayList sparseMatrix;

sparseMatrix* createSparseMatrix(int row, int col);
void addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value);
sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2);
void printSparseMatrix(sparseMatrix* sm);

#endif