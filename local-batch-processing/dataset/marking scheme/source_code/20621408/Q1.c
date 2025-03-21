#include <stdio.h>

#define MAX_SIZE 10

// FUNCTIONS:
//      Get User Input before going into Main Menu Loop
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, char name)
{
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//      Display Matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//      Addition
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//      Subtraction
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//      Transposition
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// MAIN PROGRAM ----------------------------------------------------------------------------------------------------------------------
int main()
{
    int rowA, colA;
    int rowB, colB;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Get User Input for Matrices A
    do
    {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &colA);
    } while (rowA <= 0 || rowA > MAX_SIZE || colA <= 0 || colA > MAX_SIZE);

    inputMatrix(matrixA, rowA, colA, 'A');

    // Get User Input for Matrices B
    do
    {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &colB);
    } while (rowB <= 0 || rowB > MAX_SIZE || colB <= 0 || colB > MAX_SIZE);

    inputMatrix(matrixB, rowB, colB, 'B');

    // Main Menu Loop
    while(1)
    {
        puts("");
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rowA == rowB && colA == colB)
                {
                    addMatrices(matrixA, matrixB, result, rowA, colA);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(result, rowA, colA);
                }
                else
                {
                    printf("Matrices must need to be the same dimensions in order to do Addition.\n");
                }
                break;

            case 2:
                if (rowA == rowB && colA == colB)
                {
                    subtractMatrices(matrixA, matrixB, result, rowA, colA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(result, rowA, colA);
                }
                else
                {
                    printf("Matrices must need to be the same dimensions in order to do Subtraction.\n");
                }
                break;

            case 3:
                transposeMatrix(matrixA, result, rowA, colA);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, colA, rowA);
                break;

            case 4:
                transposeMatrix(matrixB, result, rowB, colB);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, colB, rowB);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("INVALID... Try again.\n");
        }

        if (choice == 5)
        {
            break;
        }
    }

    return 0;
}