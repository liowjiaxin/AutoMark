#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

// function for inputting matrix elements
int inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function for adding matrices
void addMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// function to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // intitializing variables
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // dimensions for Matrix A
    printf("Enter dimensions for matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE)
    {
        printf("Invalid dimensions for Matrix A. Please restart the program.\n"); // error funtion if rows or columns arent between MAX_SIZE
        return 1;
    }

    // inputting elements into the matrix A
    printf("Enter elements for matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    // dimensions for Matrix B
    printf("Enter dimensions for matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE)
    {
        printf("Invalid dimensions for Matrix B. Please restart the program.\n"); // error funtion if rows or columns arent between MAX_SIZE
        return 1;
    }

    // inputting elements into the matrix B
    printf("Enter elements for matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    do
    {
        // display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // switch case for input of the user
        switch (choice)
        {
        case 1:
            if (rowsA == rowsB && colsA == colsB) // checking if the dimensions are same for addition
            {
                addMatrices(rowsA, colsA, matrixA, matrixB, result); // using function addMatrices to add the matrices
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(rowsA, colsA, result); // displaying the matrix by printMatrix function
            }
            else
            {
                printf("Matrices dimensions do not match for addition.\n"); // error if the dimensions dont match
            }
            break;

        case 2:
            if (rowsA == rowsB && colsA == colsB) // checking if the dimensions are same for addition
            {
                subtractMatrices(rowsA, colsA, matrixA, matrixB, result); // using function subtractMatrices to subtract the matrices
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(rowsA, colsA, result); // displaying the matrix by printMatrix function
            }
            else
            {
                printf("Matrices dimensions do not match for subtraction.\n"); // error if the dimensions dont match
            }
            break;

        case 3:
            transposeMatrix(rowsA, colsA, matrixA, result); // function to make transpose of a matrix
            printf("Transpose of Matrix A:\n");
            printMatrix(colsA, rowsA, result); // displaying the transposed matrix
            break;

        case 4:
            transposeMatrix(rowsB, colsB, matrixB, result); // function to make transpose of a matrix
            printf("Transpose of Matrix B:\n");
            printMatrix(colsB, rowsB, result); // displaying the transposed matrix
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}