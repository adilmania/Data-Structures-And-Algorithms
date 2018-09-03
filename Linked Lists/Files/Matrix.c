#include "../Headers/Matrix.h"

/**
 * \file      Matrix.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Define all necessary functions for the dynamic creation
 *            of a matrix from an input file.
**/

/* ----------------------ReadInitFillMatrix----------------------------
* Reading, Initialising, Filling Matrix Function
* Entrance :
	* file	    : file adress
    * matrix	: Pointer on the matrix
	* m 		: Number of lines
	* n 		: Number of columns
	
* Entrance/Exit :
	* monscanner : File Values Structure
* ------------------------------------------------------------------------------------------- */

Scanner ReadInitFillMatrix(char *file, double **matrix, int m, int n, Scanner monscanner)
{

    FILE *f = NULL; /* Initialising file pointer */

    f = fopen(file, "r+"); /* Opening the file */

    if (f != NULL) /* Opening file success */
    {
        int i, j;

        fscanf(f, "%d %d", &m, &n); /* Reading Column and Line Numbers */

        matrix = (double **)malloc(sizeof(double *) * m); /* Line Allocation */
        for (i = 0; i < m; i++)
        {
            matrix[i] = (double *)malloc(sizeof(double *) * n); /* Column Allocation */
        }

        for (i = 0; i < m; i++) /* Reading the éléments from the file */
        {
            for (j = 0; j < n; j++)
            {
                fscanf(f, "%lf", &matrix[i][j]); /* Filling the matrix */
            }
        }

        monscanner.matrix = matrix; /* Saving the values */
        monscanner.m = m;
        monscanner.n = n;

        Display_Matrix(matrix, m, n); /* Matrix Display */
        fclose(f);                    /* File Closing */
    }
    else /* Reading Problem */
    {

        printf("Can't open the file!\n");
    }
    return monscanner;
}

/* ----------------------Display_Matrix----------------------------
* Matrix Diplay Function.
* Entrance :
    * matrix	: Pointer on the matrix
	* m 		: Number of lines
	* n 		: Number of columns
* Exit :
	* Aucune
* ------------------------------------------------------------------ */

void Display_Matrix(double **matrix, int m, int n)
{
    int i, j;
    printf("\n Display the matrix \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2f ", matrix[i][j]); /* Display all matrix nodes */
        }
        printf("\n");
    }
}