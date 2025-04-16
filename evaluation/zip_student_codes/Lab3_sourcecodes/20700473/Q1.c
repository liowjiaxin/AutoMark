/**
 * @file Q1.c
 * @brief This C program performs basic operations on two matrices.
 *
 * The program allow the user to input the dimensions of two matrices
 * A and B (maximum size: 10x10).
 * Provide a menu for the user to choose an operation:
 * 1. Add Matrices
 * 2. Subtract Matrices
 * 3. Transpose Matrix A
 * 4. Transpose Matrix B
 * 5. Exit (Loop back to the menu until the user chooses to exit.)
 *
 * @author Yichen Si
 * @date 2024-12-11
 * @note code is formated by vscode
 */

#include <stdio.h>

#define MAX_SIZE (10)
#define MAX_VALUE (10000)
#define MIN_VALUE (-10000)

// check if the matrix dimensions are valid
static int check_validity(int row, int col)
{
    if (row > MAX_SIZE || col > MAX_SIZE || row <= 0 || col <= 0)
    {
        return 0;
    }
    return 1;
}

// get matrix elements from user input
static void input_elements(int matrix[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            while (1)
            {
                if (scanf("%d", &matrix[i][j]) != 1)
                {
                    printf("Error: invalid input element. Enter again: ");
                    while (getchar() != '\n')
                        ; // clear the buffer to avoid messing up the next input
                    continue;
                }
                while (getchar() != '\n')
                    ; // clear the buffer to avoid messing up the next input
                if (matrix[i][j] > MAX_VALUE || matrix[i][j] < MIN_VALUE)
                {
                    printf(
                        "Error: value must within [-10000,10000]. Enter "
                        "again: ");
                }
                else
                {
                    break;
                }
            }
        }
    }
}

// add two matrices
static void add_matrix(int matrixA[MAX_SIZE][MAX_SIZE],
                       int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE],
                       int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// subtract two matrices
static void subtract_matrix(int matrixA[MAX_SIZE][MAX_SIZE],
                            int matrixB[MAX_SIZE][MAX_SIZE],
                            int result[MAX_SIZE][MAX_SIZE], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// transpose a matrix
static void tanspose_matrix(int matrix[MAX_SIZE][MAX_SIZE],
                            int result[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// display a matrix
static void display_result(int matrix[MAX_SIZE][MAX_SIZE], int row, int col)
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

int main(void)
{
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE],
        result[MAX_SIZE][MAX_SIZE];
    int rowA = 0, colA = 0;
    int rowB = 0, colB = 0;
    int choice = -1;

    printf("Enter dimensions for Matrix A(rows and columns): ");
    scanf("%d %d", &rowA, &colA);

    if (!check_validity(rowA, colA))
    {
        printf(
            "Error: invalid matrix dimensions. The row and col must > 0 and <= "
            "10\n");
        return -1;
    }

    printf("Enter elements for matrix A:\n");
    input_elements(matrixA, rowA, colA);

    printf("Enter dimensions for Matrix B(rows and columns): ");
    scanf("%d %d", &rowB, &colB);

    if (!check_validity(rowB, colB))
    {
        printf("Error: invalid matrix dimensions\n");
        return -1;
    }

    printf("Enter elements for matrix B:\n");
    input_elements(matrixB, rowB, colB);

    // menu of matrix operations
    while (1)
    {
        printf("Matrix Operations Menu: \n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrics\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case 1:
            if (rowA == rowB && colA == colB)
            {
                add_matrix(matrixA, matrixB, result, rowA, colA);
                printf("Result of Matrix A + Matrix B:\n");
                display_result(result, rowA, colA);
            }
            else
            {
                printf("Error: the dimensions don't match for addition\n");
            }
            break;
        case 2:
            if (rowA == rowB && colA == colB)
            {
                subtract_matrix(matrixA, matrixB, result, colA, rowA);
                printf("Result of Matrix A - Matrix B:\n");
                display_result(result, rowA, colA);
            }
            else
            {
                printf(
                    "Error: the dimensions don't match for subtraction\n");
            }
            break;
        case 3:
            tanspose_matrix(matrixA, result, rowA, colA);
            printf("Transpose of Matrix A:\n");
            display_result(result, colA, rowA);
            break;
        case 4:
            tanspose_matrix(matrixB, result, rowB, colB);
            printf("Transpose of Matrix B:\n");
            display_result(result, colB, rowB);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Error: invalid choice.\n");
            break;
        }
    }
}
