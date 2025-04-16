#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void readMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int currentRow, int currentCol);

void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int currentRow, int currentCol);

void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE]);

void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE]);

void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int currentRow,
                     int currentCol);

int validDimension(int dimension);

//Main loop , pretty  important can't do anything without it
int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    //using do while loops to make sure the body of code executes at least once
    //not sure if doing so many do while loops was the best way to implement this but it works
    do {
        printf("Enter number of rows for Matrix A (1-10): ");
        scanf("%d", &rowsA);
    } while (!validDimension(rowsA));

    do {
        printf("Enter number of columns for Matrix A (1-10): ");
        scanf("%d", &colsA);
    } while (!validDimension(colsA));

    do {
        printf("Enter number of rows for Matrix B (1-10): ");
        scanf("%d", &rowsB);
    } while (!validDimension(rowsB));

    do {
        printf("Enter number of columns for Matrix B (1-10): ");
        scanf("%d", &colsB);
    } while (!validDimension(colsB));

    printf("Enter elements of Matrix A:\n");
    readMatrix(rowsA, colsA, A, 0, 0);

    printf("Enter elements of Matrix B:\n");
    readMatrix(rowsB, colsB, B, 0, 0);

    do {
        // Print the menu
        printf("Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int result[MAX_SIZE][MAX_SIZE];
        //Using switch as it's faster than if-else and also more easier to debug
        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Addition:\n");
                    printMatrix(rowsA, colsA, result, 0, 0);
                } else {
                    printf("Matrices dimensions do not match for addition.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Subtraction (A - B):\n");
                    printMatrix(rowsA, colsA, result, 0, 0);
                } else {
                    printf("Matrices dimensions do not match for subtraction.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsA, colsA, A, result, 0, 0);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result, 0, 0);
                break;
            case 4:
                transposeMatrix(rowsB, colsB, B, result, 0, 0);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result, 0, 0);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

int validDimension(int dimension) {
    return (dimension >= 1 && dimension <= MAX_SIZE) ? 1 : 0;
}

// Coding the Function Logic
void readMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int currentRow, int currentCol) {
    if (currentRow == rows) return;
    if (currentCol == cols) {
        readMatrix(rows, cols, matrix, currentRow + 1, 0);
        return;
    }

    printf("Enter element [%d][%d]: ", currentRow, currentCol);
    scanf("%d", &matrix[currentRow][currentCol]);
    readMatrix(rows, cols, matrix, currentRow, currentCol + 1);
}

void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int currentRow, int currentCol) {
    if (currentRow == rows) return;
    if (currentCol == 0) printf("[ ");
    printf("%d ", matrix[currentRow][currentCol]);
    currentCol == cols - 1
        ? (printf("]\n"), printMatrix(rows, cols, matrix, currentRow + 1, 0))
        : printMatrix(rows, cols, matrix, currentRow, currentCol + 1);
}

void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtractMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int currentRow,
                     int currentCol) {
    if (currentRow == rows) return;
    if (currentCol == cols) {
        transposeMatrix(rows, cols, matrix, result, currentRow + 1, 0);
        return;
    }
    result[currentCol][currentRow] = matrix[currentRow][currentCol];
    transposeMatrix(rows, cols, matrix, result, currentRow, currentCol + 1);
}
