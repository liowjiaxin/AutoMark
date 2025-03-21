#include <stdio.h>

#define MAX 10 // Define the maximum matrix size

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void printMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]);
void subtractMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

int main() {
    int rowsA, colsA, rowsB, colsB; // Dimensions of matrices
    int A[MAX][MAX], B[MAX][MAX];  // Matrices A and B
    int result[MAX][MAX];         // Result matrix for operations
    int choice;

    // Input dimensions for Matrix A
    printf("Enter rows and columns for Matrix A (max %d): ", MAX);
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions for Matrix B
    printf("Enter rows and columns for Matrix B (max %d): ", MAX);
    scanf("%d %d", &rowsB, &colsB);

    // Validate dimensions
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
        printf("Error: Dimensions exceed maximum limit of %d.\n", MAX);
        return 1;
    }

    // Input elements for matrices
    printf("Enter elements for Matrix A:\n");
    inputMatrix(rowsA, colsA, A);

    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowsB, colsB, B);

    // Menu for operations
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
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result); // Call the function to add matrices
                    printf("Result of Addition:\n");
                    printMatrix(rowsA, colsA, result); // Display the result
                } else {
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result); // Call the function to subtract matrices
                    printf("Result of Subtraction:\n");
                    printMatrix(rowsA, colsA, result); // Display the result
                } else {
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                }
                break;

            case 3:
                transposeMatrix(rowsA, colsA, A, result); // Transpose Matrix A
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result); // Display the transpose
                break;

            case 4:
                transposeMatrix(rowsB, colsB, B, result); // Transpose Matrix B
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result); // Display the transpose
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input elements of a matrix
// Prompts the user to input values for the matrix
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
// Loops through the matrix and prints its elements row by row
void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
// Adds corresponding elements from two matrices and stores in the result matrix
void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
// Subtracts corresponding elements from Matrix B from Matrix A and stores in the result matrix
void subtractMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix
// Converts rows into columns and vice versa
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
