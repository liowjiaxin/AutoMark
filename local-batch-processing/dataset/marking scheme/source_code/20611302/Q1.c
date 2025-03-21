#include <stdio.h>
#define MAX 10 // Maximum matrix size

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[MAX][MAX], char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to compute the transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to print matrix
void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB, choice;

    // Input matrix dimensions
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Validate dimensions
    if (rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0 || rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
        printf("Invalid dimensions. Exiting program.\n");
        return 1;
    }

    // Input elements for both matrices
    inputMatrix(rowsA, colsA, A, 'A');
    inputMatrix(rowsB, colsB, B, 'B');

    do {
        // Display menu
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
                // Add matrices if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 2:
                // Subtract matrices if dimensions match
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 3:
                // Transpose Matrix A
                transposeMatrix(rowsA, colsA, A, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;
            case 4:
                // Transpose Matrix B
                transposeMatrix(rowsB, colsB, B, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
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
