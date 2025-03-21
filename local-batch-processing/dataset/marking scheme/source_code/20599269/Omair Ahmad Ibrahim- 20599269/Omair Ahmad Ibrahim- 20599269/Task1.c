#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB, choice;

    // Input dimensions for matrices
    printf("Enter the number of rows and columns for Matrix A (max 10): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the number of rows and columns for Matrix B (max 10): ");
    scanf("%d %d", &rowsB, &colsB);

    // Validate dimensions
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
        printf("Matrix size exceeds the maximum allowed (10x10).\n");
        return 1;
    }

    // Input matrices
    printf("Enter elements for Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    // Menu-driven operations
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
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Addition not possible. Dimensions do not match.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Subtraction not possible. Dimensions do not match.\n");
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
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function definitions
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
