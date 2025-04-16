#include <stdio.h> 
#include <stdlib.h>

#define MAX 10

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
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

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input the elements of matrix A
    printf("Enter the number of rows and columns for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    // Validate dimensions for matrix A
    if (rowsA <= 0 || rowsA > 10 || colsA <= 0 || colsA > 10) {
        printf("Invalid dimensions for Matrix A.\n");
        return 1;
    }

    // Input the elements of matrix A
    inputMatrix(matrixA, rowsA, colsA);

    // Input the dimensions of matrix B
    printf("Enter the number of rows and columns for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Validate dimensions for matrix B
    if (rowsB <= 0 || rowsB > 10 || colsB <= 0 || colsB > 10) {
        printf("Invalid dimensions for Matrix B.\n");
        return 1;
    }

    // Check if addition or subtraction can be performed
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices must have the same dimensions for addition or subtraction.\n");
        return 1;
    }

    // Input the elements of matrix B
    inputMatrix(matrixB, rowsB, colsB);

    do {
        // Display menu
        printf("\nMatrix Operation Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add matrices
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A + Matrix B:\n");
                displayMatrix(result, rowsA, colsA);
                break;
            case 2: // Subtract matrices
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A - Matrix B:\n");
                displayMatrix(result, rowsA, colsA);
                break;
            case 3: // Transpose matrix A
                transposeMatrix(matrixA, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA); // Swapping rows and columns for display
                break;
            case 4: // Transpose matrix B
                transposeMatrix(matrixB, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB); // Swapping rows and columns for display
                break;
            case 5: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    return 0;
}
