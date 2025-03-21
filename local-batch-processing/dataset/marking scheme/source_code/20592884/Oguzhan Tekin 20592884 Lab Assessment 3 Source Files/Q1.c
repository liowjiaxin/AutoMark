#include <stdio.h>

#define MAX_SIZE 10  // Maximum matrix size

// Function declarations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for matrix A
    do {
        printf("Enter number of rows and columns for Matrix A (max 10x10): ");
        scanf("%d %d", &rowsA, &colsA);
        if (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsA <= 0 || colsA <= 0) {
            printf("Invalid dimensions, try again.\n");
        }
    } while (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsA <= 0 || colsA <= 0);

    // Input dimensions for matrix B
    do {
        printf("Enter number of rows and columns for Matrix B (max 10x10): ");
        scanf("%d %d", &rowsB, &colsB);
        if (rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsB <= 0 || colsB <= 0) {
            printf("Invalid dimensions, try again.\n");
        }
    } while (rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsB <= 0 || colsB <= 0);

    // Check if matrices A and B have the same dimensions for addition and subtraction
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix dimensions must match for addition or subtraction.\n");
        return 1;  // Exit if dimensions don't match
    }

    // Input elements for both matrices
    printf("Enter elements for Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    // Display menu for matrix operations
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add matrices
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(result, rowsA, colsA);
                break;
            case 2:
                // Subtract matrices
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(result, rowsA, colsA);
                break;
            case 3:
                // Transpose matrix A
                transposeMatrix(matrixA, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, colsA, rowsA); // Transposed dimensions
                break;
            case 4:
                // Transpose matrix B
                transposeMatrix(matrixB, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, colsB, rowsB); // Transposed dimensions
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
