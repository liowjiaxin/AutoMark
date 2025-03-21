#include <stdio.h>

#define MAX 10

void inputMatrix(const char *name, int rows, int cols, int matrix[MAX][MAX]) {
    printf("Enter elements for Matrix %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1); // 1-based indexing for user-friendly input
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB, choice;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

    // Input for Matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    inputMatrix("A", rowsA, colsA, A);

    // Input for Matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    inputMatrix("B", rowsB, colsB, B);

    // Ensure matrices are compatible for addition and subtraction
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix operations are only possible for matrices of the same dimensions.\n");
        return 1;
    }

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
            addMatrices(rowsA, colsA, A, B, result);
            printf("Result of Matrix A + Matrix B:\n");
            printMatrix(rowsA, colsA, result);
            break;
        case 2:
            subtractMatrices(rowsA, colsA, A, B, result);
            printf("Result of Matrix A - Matrix B:\n");
            printMatrix(rowsA, colsA, result);
            break;
        case 3:
            transposeMatrix(rowsA, colsA, A, result);
            printf("Transpose of Matrix A:\n");
            printMatrix(colsA, rowsA, result);
            break;
        case 4:
            transposeMatrix(rowsB, colsB, B, result);
            printf("Transpose of Matrix B:\n");
            printMatrix(colsB, rowsB, result);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
