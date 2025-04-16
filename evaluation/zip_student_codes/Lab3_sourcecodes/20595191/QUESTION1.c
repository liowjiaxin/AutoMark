#include <stdio.h>

#define MAX 10


void input(int matrix[MAX][MAX], int rows, int cols);
void print(int matrix[MAX][MAX], int rows, int cols);
void add(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void sub(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transpose(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    // Validate dimensions
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions! Maximum size is 10x10.\n");
        return 1;
    }

    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    input(matrixA, rowsA, colsA);

    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    // Validate dimensions
    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions! Maximum size is 10x10.\n");
        return 1;
    }

    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    input(matrixB, rowsB, colsB);

    while (1) {
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
                if (rowsA == rowsB && colsA == colsB) { //check if matrixes have the same 
                    add(matrixA, matrixB, result, rowsA, colsA); //call function
                    printf("Result of your choice:\n");
                    print(result, rowsA, colsA);
                } else {
                    printf(" Matrices must have the same dimensions therefor addition not possible.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) { //check if matrixes have the same 
                    sub(matrixA, matrixB, result, rowsA, colsA); //call function
                    printf("Result of your choice:\n");
                    print(result, rowsA, colsA);
                } else {
                    printf(" Matrices must have the same dimensions therfor substraction not possible.\n");
                }
                break;
            case 3:
                transpose(matrixA, result, rowsA, colsA);
                printf("Result of your choice:\n");
                print(result, colsA, rowsA);
                break;
            case 4:
                transpose(matrixB, result, rowsB, colsB);
                printf("Result of your choice:\n");
                print(result, colsB, rowsB);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to input elements of a matrix
void input(int matrix[MAX][MAX], int rows, int cols) { 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void print(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void sub(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose a matrix
void transpose(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
