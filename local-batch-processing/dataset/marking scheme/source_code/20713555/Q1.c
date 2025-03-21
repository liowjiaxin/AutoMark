#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for Matrix A
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        if (scanf("%d %d", &rowsA, &colsA) != 2 || rowsA <= 0 || colsA <= 0 || rowsA > MAX_SIZE || colsA > MAX_SIZE) {
            printf("Invalid dimensions! Please enter values between 1 and %d.\n", MAX_SIZE);
            while(getchar() != '\n'); // Clear invalid input
        }
    } while (rowsA <= 0 || colsA <= 0 || rowsA > MAX_SIZE || colsA > MAX_SIZE);

    // Input elements for Matrix A
    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input dimensions for Matrix B
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        if (scanf("%d %d", &rowsB, &colsB) != 2 || rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
            printf("Invalid dimensions! Please enter values between 1 and %d.\n", MAX_SIZE);
            while(getchar() != '\n'); // Clear invalid input
        }
    } while (rowsB <= 0 || colsB <= 0 || rowsB > MAX_SIZE || colsB > MAX_SIZE);

    // Input elements for Matrix B
    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    do {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue; // Skip to next iteration of the loop
        }

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices must have the same dimensions for addition!\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices must have the same dimensions for subtraction!\n");
                }
                break;

            case 3:
                transposeMatrix(A, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA); // Note: Rows and columns are swapped
                break;

            case 4:
                transposeMatrix(B, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB); // Note: Rows and columns are swapped
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}