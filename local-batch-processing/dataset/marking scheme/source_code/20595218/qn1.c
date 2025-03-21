#include <stdio.h>
#define MAX 10

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void printMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

// Functions
void inputMatrix(int rows, int cols, int matrix[MAX][MAX])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX][MAX])
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

void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main()
{
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int choice;

    printf("Enter dimensions for Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter dimensions for Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX)
    {
        printf("Matrix size exceeds the maximum limit of %dx%d.\n", MAX, MAX);
        return 1;
    }

    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    do
    {
        printf("\nMenu:\n");
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
            if (rowsA == rowsB && colsA == colsB)
            {
                addMatrices(rowsA, colsA, matrixA, matrixB, result);
                printf("Matrix after Addition:\n");
                printMatrix(rowsA, colsA, result);
            }
            else
            {
                printf("Addition isn't possible. Dimensions don't match.\n");
            }
            break;
        case 2:
            if (rowsA == rowsB && colsA == colsB)
            {
                subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                printf("Matrix after Subtraction:\n");
                printMatrix(rowsA, colsA, result);
            }
            else
            {
                printf("Subtraction isn't possible. Dimensions don't match.\n");
            }
            break;
        case 3:
            transposeMatrix(rowsA, colsA, matrixA, result);
            printf("Transpose of Matrix A:\n");
            printMatrix(colsA, rowsA, result);
            break;
        case 4:
            transposeMatrix(rowsB, colsB, matrixB, result);
            printf("Transpose of Matrix B:\n");
            printMatrix(colsB, rowsB, result);
            break;
        case 5:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
