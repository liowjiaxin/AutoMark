#include <stdio.h> // Standard library for input/output

#define MAX 10 // Defining

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void pMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int result[MAX][MAX];
    int choice;

    // Asking user to input the dimensions for Matrix A
    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    // If dimensions exceed 10 (MAX)
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions for Matrix A. Dimensions must be between 1 and %d. Exiting...\n", MAX);
        return 1;
    }

    // Asking user to input the elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    // Asking user to input the dimensions for Matrix B
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // If dimensions exceed 10 (MAX)
    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions for Matrix B. Dimensions must be between 1 and %d. Exiting.\n", MAX);
        return 1;
    }

    // Asking user to input the elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    // Do while, switch case for menu
    do {
        printf("\nMatrix Operations Menu:\n");
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
                    printf("Result of Matrix A + Matrix B:\n");
                    pMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible. Dimensions do not match.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    pMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible. Dimensions do not match.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Transpose of Matrix A:\n");
                pMatrix(colsA, rowsA, result);
                break;
            case 4:
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Transpose of Matrix B:\n");
                pMatrix(colsB, rowsB, result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input a matrix (Prompt for input)
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void pMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Choice 1: Function to add two matrices
void addMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Choice 2: Function to subtract two matrices
void subtractMatrices(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Choice 3 and 4: Function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
