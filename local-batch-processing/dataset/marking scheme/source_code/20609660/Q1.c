#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main()
{
    int rowsA, colsA, rowsB, colsB, choice = 0;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE] = {0};

    // Input dimensions for matrices
    do
    {
        printf("Enter the dimensions for Matrix A (rows and columns): ");
        scanf(" %d %d", &rowsA, &colsA);
        if (rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE)
        {
            printf("Invalid dimensions. Please enter dimensions between 1 and 10.\n");
        }
    } while (rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE);

    // Input elements of matrix A
    printf("Enter elements of Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA, 'A');

    do
    {
        printf("Enter the dimensions for Matrix B (rows and columns): ");
        scanf(" %d %d", &rowsB, &colsB);
        if (rowsB < 1 || rowsB > MAX_SIZE || colsB < 1 || colsB > MAX_SIZE)
        {
            printf("Invalid dimensions. Please enter dimensions between 1 and 10.\n");
        }
    } while (rowsB < 1 || rowsB > MAX_SIZE || colsB < 1 || colsB > MAX_SIZE);
    printf("Enter elements of Matrix B:\n");

    // Input elements of matrix B
    inputMatrix(matrixB, rowsB, colsB, 'B');

    // Menu-driven loop
    do
    {
        printf("\nMatrix Operations Menu:\n\
1. Add Matrices\n\
2. Subtract Matrices\n\
3. Transpose Matrix A\n\
4. Transpose Matrix B\n\
5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            // Validate if matrices can be added
            if (rowsA == rowsB && colsA == colsB)
            {
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            }
            else
            {
                printf("Matrix addition not possible. Dimensions do not match.\n");
            }
            break;

        case 2:
            // Validate if matrices can be subtracted
            if (rowsA == rowsB && colsA == colsB)
            {
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            }
            else
            {
                printf("Matrix subtraction not possible. Dimensions do not match.\n");
            }
            break;

        case 3:
            transposeMatrix(matrixA, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
            break;

        case 4:
            transposeMatrix(matrixB, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input elements of a matrix from user
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name)
{
    // Loop through each element of the matrix, starting from row 1 and column 1 to row 1 and column 2, and so on
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element %c[%d][%d]: ", name, i + 1, j + 1);
            scanf(" %d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    // Loop through each element of the matrix and print it
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}
