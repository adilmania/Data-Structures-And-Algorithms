#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data to scan from a file structure */

typedef struct Scanner Scanner;
struct Scanner
{
    double **matrix; /* Pointer on the matrix */
    int m;           /* Number of lines */
    int n;           /* Number of columns */
};

/* Reading, Initialising, Filling Matrix Function */

Scanner ReadInitFillMatrix(char *file, double **matrix, int m, int n, Scanner monscanner);

/* Matrix Diplay Function */

void Display_Matrix(double **matrix, int m, int n);

#endif
