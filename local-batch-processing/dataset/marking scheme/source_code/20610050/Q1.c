
#include <stdio.h>

#define MAX_SIZE 10
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void addMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subtractMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsA < 1 || colsA < 1 || rowsB < 1 || colsB < 1) {
        printf("Invalid matrix dimensions! Maximum size is 10x10.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Addition:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible, dimensions mismatch.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Subtraction:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible, dimensions mismatch.\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract matrices
void subtractMatrices(int rows, int cols, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
