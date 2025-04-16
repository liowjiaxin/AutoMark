#include <stdio.h>
#define MAX 10

// Function declarations
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for both matrices
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA <= 0 || rowsA > MAX || colsA <= 0 || colsA > MAX || rowsB <= 0 || rowsB > MAX || colsB <= 0 || colsB > MAX) {
        printf("Invalid dimensions. Maximum size is 10x10.\n");
        return 1;
    }

    // Input matrices
    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);
    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Menu-driven program
    do {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (rowsA == rowsB && colsA == colsB) {
                addMatrices(A, B, result, rowsA, colsA);
                printf("Result of Addition:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Addition not possible. Dimensions must match.\n");
            }
        } else if (choice == 2) {
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(A, B, result, rowsA, colsA);
                printf("Result of Subtraction:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Subtraction not possible. Dimensions must match.\n");
            }
        } else if (choice == 3) {
            transposeMatrix(A, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
        } else if (choice == 4) {
            transposeMatrix(B, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
        } else if (choice == 5) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Input elements for a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Subtract two matrices
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
