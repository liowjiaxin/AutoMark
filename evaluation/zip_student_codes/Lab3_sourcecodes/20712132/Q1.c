#include <stdio.h>

#define MAX_SIZE 10


void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions and elements of Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        printf("Matrix A dimensions exceed maximum allowed size.\n");
        return 1;
    }

    printf("Enter elements for Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input dimensions and elements of Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Matrix B dimensions exceed maximum allowed size.\n");
        return 1;
    }

    printf("Enter elements for Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Menu for matrix operations
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
                // Addition of matrices
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A + Matrix B:\n");
                    addMatrices(A, B, rowsA, colsA);
                } else {
                    printf("Matrix dimensions must match for addition.\n");
                }
                break;
            case 2:
                // Subtraction of matrices
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A - Matrix B:\n");
                    subtractMatrices(A, B, rowsA, colsA);
                } else {
                    printf("Matrix dimensions must match for subtraction.\n");
                }
                break;
            case 3:
                // Transpose of Matrix A
                printf("Transpose of Matrix A:\n");
                transposeMatrix(A, rowsA, colsA);
                break;
            case 4:
                // Transpose of Matrix B
                printf("Transpose of Matrix B:\n");
                transposeMatrix(B, rowsB, colsB);
                break;
            case 5:
                // Exit the program
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input elements of a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print elements of a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    printMatrix(result, rows, cols);
}

// Function to subtract one matrix from another
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    printMatrix(result, rows, cols);
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    printMatrix(result, cols, rows);
}
