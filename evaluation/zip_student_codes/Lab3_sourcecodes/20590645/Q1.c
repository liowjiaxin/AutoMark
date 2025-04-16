#include <stdio.h>

// Maximum matrix size
#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for Matrix A
    printf("Enter dimensions of Matrix A (rows cols): ");
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions for Matrix B
    printf("Enter dimensions of Matrix B (rows cols): ");
    scanf("%d %d", &rowsB, &colsB);

    // Validate matrix dimensions
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX || rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions. Maximum allowed is %dx%d.\n", MAX, MAX);
        return 1;
    }

    // Input elements of Matrix A
    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input elements of Matrix B
    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    do {
        // Display menu
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
                // Add matrices
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Addition not possible: Dimensions do not match.\n");
                }
                break;
            case 2:
                // Subtract matrices
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Subtraction not possible: Dimensions do not match.\n");
                }
                break;
            case 3:
                // Transpose Matrix A
                transposeMatrix(A, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;
            case 4:
                // Transpose Matrix B
                transposeMatrix(B, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix neatly in a table format
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("+");
    for (int j = 0; j < cols; j++) {
        printf("-------+");
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf(" %5d |", matrix[i][j]);
        }
        printf("\n+");
        for (int j = 0; j < cols; j++) {
            printf("-------+");
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
