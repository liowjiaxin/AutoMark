#include <stdio.h>

#define MAX_SIZE 10

void displayMenu();
void add(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int sum[MAX_SIZE][MAX_SIZE]);
void subtract(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int diff[MAX_SIZE][MAX_SIZE]);
void transpose(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE], int trans[MAX_SIZE][MAX_SIZE]);
void printMatrix(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE]);

int main() {
    int rowsA, columnsA, rowsB, columnsB;
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE], diff[MAX_SIZE][MAX_SIZE], trans[MAX_SIZE][MAX_SIZE];

    // Input dimensions for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &columnsA);

    // Validate dimensions for Matrix A
    if (rowsA > MAX_SIZE || columnsA > MAX_SIZE || rowsA <= 0 || columnsA <= 0) {
        printf("Invalid dimensions! Rows and columns must be between 1 and 10.\n");
        return 1;
    }

    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Input dimensions for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    // Validate dimensions for Matrix B
    if (rowsB > MAX_SIZE || columnsB > MAX_SIZE || rowsB <= 0 || columnsB <= 0) {
        printf("Invalid dimensions! Rows and columns must be between 1 and 10.\n");
        return 1;
    }

    // Check if the dimensions of Matrix B match Matrix A
    if (rowsA != rowsB || columnsA != columnsB) {
        printf("Matrix dimensions of A and B do not match! Cannot perform addition or subtraction.\n");
        return 1;  
    }

    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    while (1) {
        int choice;

        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(rowsA, columnsA, a, b, sum);
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(rowsA, columnsA, sum);
                break;

            case 2:
                subtract(rowsA, columnsA, a, b, diff);
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(rowsA, columnsA, diff);
                break;

            case 3:
                transpose(rowsA, columnsA, a, trans);
                printf("Transpose of Matrix A:\n");
                printMatrix(rowsA, columnsA, trans);
                break;

            case 4:
                transpose(rowsB, columnsB, b, trans);
                printf("Transpose of Matrix B:\n");
                printMatrix(rowsB, columnsB, trans);
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

// Function to print menu
void displayMenu() {
    printf("\nMatrix Operation Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
}

// Function to add two matrices
void add(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int sum[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int rows, int columns, int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int diff[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to transpose a matrix
void transpose(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE], int trans[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            trans[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int columns, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}
