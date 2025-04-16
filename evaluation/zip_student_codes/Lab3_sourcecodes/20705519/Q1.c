#include <stdio.h>
#include <stdlib.h>

#define MAXROW 10
#define MAXCOL 10

// prototype declaration
int initMatrices ();
void displaymatrices ( int matrixDisplay[MAXROW][MAXCOL], int rows, int cols);
void addmatrices ();
void subtractmatrices ();
void transposeMatrix ( int targetMatrix [MAXROW][MAXCOL], char matrixLetter);

// global variable declaration
int rowA, colA, rowB, colB;
int matrixA[MAXROW][MAXCOL];
int matrixB[MAXROW][MAXCOL];
int matrixSum[MAXROW][MAXCOL];
int matrixDiff[MAXROW][MAXCOL];
int matrixTemp[MAXROW][MAXCOL];

int main () 
{
    // initialise Matrix A and B
    while (1)
    {
        int n = initMatrices();
        if (n > 0)
        {
            break;
        }
    }

    while (1)
    {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            addmatrices();
            break;
        case 2:
            subtractmatrices ();
            break;
        case 3:
            transposeMatrix(matrixA, 'A');
            break;
        case 4:
            transposeMatrix(matrixB, 'B');
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Enter a proper choice.\n");
            break;
        }
    }
    return 0;
}

// function to create Matrix A and B
int initMatrices ()
{
    // input for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns):");
    scanf("%d %d", &rowA, &colA);
    getchar();

    if (rowA > MAXROW || colA > MAXCOL)
    {
        printf("Invalid number of rows and/or columns entered (maximum size: 10x10).\n");
        return 0;       // return error flag
    }
    
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    // input for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns):");
    scanf("%d %d", &rowB, &colB);
    getchar();

    if (rowB > MAXROW || colB > MAXCOL)
    {
        printf("Invalid number of rows and/or columns entered (maximum size: 10x10).\n");
        return 0;       // return error flag
    }

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }
    return 1;
}

// function to display desired matrix
void displaymatrices ( int matrixDisplay[MAXROW][MAXCOL], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrixDisplay[i][j]);
        }
        printf("\n");
    }
}

// function to add Matrix A and B
void addmatrices ()
{
    if (rowA != rowB || colA != colB)
    {
        printf("Matrices of different orders cannot be added!\n");
        return;
    }
    
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    printf("Result of Matrix A + Matrix B:\n");
    displaymatrices(matrixSum, rowA, colA);
}

// function to subtract Matrix A and B
void subtractmatrices ()
{
    if (rowA != rowB || colA != colB)
    {
        printf("Matrices of different orders cannot be subtracted!\n");
        return;
    }
    
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    
    printf("Result of Matrix A - Matrix B:\n");
    displaymatrices(matrixDiff, rowA, colA);
}

// function to tranpose Matrix
void transposeMatrix ( int targetMatrix [MAXROW][MAXCOL], char matrixLetter)
{
    // check which matrix user wants to transpose
    if (matrixLetter == 'A')
    {
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                matrixTemp[j][i] = targetMatrix[i][j];
            }
        }
        
        printf("Transpose of Matrix %c:\n", matrixLetter);
        displaymatrices(matrixTemp, colA, rowA);
    }
    else
    {
        for (int i = 0; i < rowB; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                matrixTemp[j][i] = targetMatrix[i][j];
            }
        }
        
        printf("Transpose of Matrix %c:\n", matrixLetter);
        displaymatrices(matrixTemp, colB, rowB);
    }
}