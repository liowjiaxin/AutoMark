#include <stdio.h>

#define MAX 10 // Maximum size for matrices

// Function to input matrix elements
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return 1; // Returns 1 to indicate success
}

// Function to subtract two matrices
int subtractMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return 1; // Returns 1 to indicate success
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
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int choice;

    // Get matrix dimensions and elements
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter elements for Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);

    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB); 
    printf("Enter elements for Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    while (1) {
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add matrices
            if (rowsA == rowsB && colsA == colsB) {
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Error, try again with other value.\n");
            }
        } else if (choice == 2) {
            // Subtract matrices
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Subtraction of Matrix A - Matrix B:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Error, try again with other value.\n");
            }
        } else if (choice == 3) {
            // Transpose Matrix A
            transposeMatrix(matrixA, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
        } else if (choice == 4) {
            // Transpose Matrix B
            transposeMatrix(matrixB, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
        } else if (choice == 5) {
            // Exit the program
            printf("Exiting........................byebyebyebyebyebyebyebye!!!!!!!\n");
            break;
        } else {
            // Invalid choice
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
