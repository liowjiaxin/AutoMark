#include <stdio.h>

// Function declarations
void inputMatrix(int matrix[10][10], int rows, int cols);    // Function to input matrix elements
void displayMatrix(int matrix[10][10], int rows, int cols); // Function to display a matrix
void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols);   // Add two matrices
void subtractMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols); // Subtract two matrices
void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols); // Transpose a matrix

int main() {
    // Declare matrices and their dimensions
    int a[10][10], b[10][10], result[10][10];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for matrices
    printf("Enter dimensions of Matrix A (rows and columns, max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter dimensions of Matrix B (rows and columns, max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if dimensions exceed limits
    if (rowsA > 10 || colsA > 10 || rowsB > 10 || colsB > 10) {
        printf("Matrix dimensions exceed the limit (10x10).\n");
        return 1; // Exit program if dimensions are invalid
    }

    // Input matrices
    printf("Enter elements of Matrix A:\n");
    inputMatrix(a, rowsA, colsA);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(b, rowsB, colsB);

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
                // Perform addition if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(a, b, result, rowsA, colsA);
                    printf("Result of Addition:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Addition not possible due to dimension mismatch.\n");
                }
                break;
            case 2:
                // Perform subtraction if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(a, b, result, rowsA, colsA);
                    printf("Result of Subtraction:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Subtraction not possible due to dimension mismatch.\n");
                }
                break;
            case 3:
                // Transpose Matrix A
                transposeMatrix(a, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;
            case 4:
                // Transpose Matrix B
                transposeMatrix(b, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
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

// Function to input elements of a matrix
void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]); 
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
