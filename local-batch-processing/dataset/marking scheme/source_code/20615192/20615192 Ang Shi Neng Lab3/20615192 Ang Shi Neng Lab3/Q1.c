#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void handleAddition(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void handleSubtraction(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void handleTranspose(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions and elements for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    while (rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions. Please enter dimensions (1-10): ");
        scanf("%d %d", &rowsA, &colsA);
    }
    inputMatrix(matrixA, rowsA, colsA, 'A');

    // Input dimensions and elements for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    while (rowsB > MAX_SIZE || colsB > MAX_SIZE || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions. Please enter dimensions (1-10): ");
        scanf("%d %d", &rowsB, &colsB);
    }
    inputMatrix(matrixB, rowsB, colsB, 'B');

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
                handleAddition(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
                break;
            case 2:
                handleSubtraction(matrixA, matrixB, rowsA, colsA, rowsB, colsB);
                break;
            case 3:
                handleTranspose(matrixA, rowsA, colsA, 'A');
                break;
            case 4:
                handleTranspose(matrixB, rowsB, colsB, 'B');
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

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void handleAddition(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    int result[MAX_SIZE][MAX_SIZE];
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of Matrix A + Matrix B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Addition not possible. Matrices must have the same dimensions.\n");
    }
}

void handleSubtraction(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    int result[MAX_SIZE][MAX_SIZE];
    if (rowsA == rowsB && colsA == colsB) {
        subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
        printf("Result of Matrix A - Matrix B:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("Subtraction not possible. Matrices must have the same dimensions.\n");
    }
}

void handleTranspose(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    int result[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix, result, rows, cols);
    printf("Transpose of Matrix %c:\n", name);
    printMatrix(result, cols, rows);
}
