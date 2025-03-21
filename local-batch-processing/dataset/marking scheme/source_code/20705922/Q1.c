#include <stdio.h>  // For standard input/output functions
#include <stdlib.h>  // For extra utilities like memeory allocation

// Define maximum size for matrices
#define MAX_ROWS 10
#define MAX_COLS 10

// Function to get matrix dimensions from the user
void getMatrixDimensions(int *rows, int *cols, char matrixName) {
    do {
        printf("Please enter dimensions for Matrix %c (rows and columns): ", matrixName);
        scanf("%d %d", rows, cols);

        if (*rows <= 0 || *rows > MAX_ROWS || *cols <= 0 || *cols > MAX_COLS) {
            printf("Invalid dimensions. Rows and columns must be between 1 and 10.\n");
        }
    } while (*rows <= 0 || *rows > MAX_ROWS || *cols <= 0 || *cols > MAX_COLS);
}

// Function to get matrix elements from the user
void getMatrixElements(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, char matrixName) {
    printf("Please enter elements for Matrix %c:\n", matrixName);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrics
void addMatrices(int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int transposed[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrixA[MAX_ROWS][MAX_COLS], matrixB[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    int exitProgram = 0; // This flag controls the main loop

    do {
        // Get dimensions and elements for Matrix A
        getMatrixDimensions(&rowsA, &colsA, 'A');
        getMatrixElements(matrixA, rowsA, colsA, 'A');

        // Get dimensons and elements for Matrix B
        getMatrixDimensions(&rowsB, &colsB, 'B');
        getMatrixElements(matrixB, rowsB, colsB, 'B');

        do {
            // Display menu for the user
            printf("\nMatrix Operations Menu:\n");
            printf("1. Add Matrices\n");
            printf("2. Subtract Matrices\n");
            printf("3. Transpose Matrix A\n");
            printf("4. Transpose Matrix B\n");
            printf("5. Exit\n");
            printf("Please enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    // Add the matrices
                    if (rowsA == rowsB && colsA == colsB) {
                        addMatrices(matrixA, matrixB, result, rowsA, colsA);
                        printf("Result of Matrix A + Matrix B:\n");
                        printMatrix(result, rowsA, colsA);
                    } else {
                        printf("Matrices cannot be added. They must have same dimensions.\n");
                    }
                    break;
                case 2:
                    // Subtract the matrices
                    if (rowsA == rowsB && colsA == colsB) {
                        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                        printf("Result of Matrix A - Matrix B:\n");
                        printMatrix(result, rowsA, colsA);
                    } else {
                        printf("Matrices cannot be subtracted. They must have same dimensions.\n");
                    }
                    break;
                case 3:
                    // Transpose Matrix A
                    transposeMatrix(matrixA, result, rowsA, colsA);
                    printf("Transpose of Matrix A:\n");
                    printMatrix(result, colsA, rowsA);
                    break;
                case 4:
                    // Transpose Matrix B
                    transposeMatrix(matrixB, result, rowsB, colsB);
                    printf("Transpose of Matrix B:\n");
                    printMatrix(result, colsB, rowsB);
                    break;
                case 5:
                    printf("Exiting program...\n");
                    exitProgram = 1; // This sets the exit flag for the program
                    break;
                default:
                    printf("Invalid choice. Please enter a number between 1 and 5.\n");
            }
        } while (choice != 5); 

    } while (!exitProgram); // Loop only if the exitProgram flag is not set

    return 0;
}