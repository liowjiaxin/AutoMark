#include <stdio.h>

#define MAX 10
// define input function
void inputMatrix(int rows, int cols, int matrix[MAX][MAX], char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
// define display function
void displayMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// define addition function
void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//define Subtraction function
void subMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//define transposition function
void transMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int choice;

    // Dimensions and contents of input matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA > MAX || colsA > MAX || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions! Exiting program.\n");
        return 1;
    }
    inputMatrix(rowsA, colsA, A, 'A');

    // Dimensions and contents of input matrix B
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB > MAX || colsB > MAX || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions! Exiting program.\n");
        return 1;
    }
    inputMatrix(rowsB, colsB, B, 'B');

    do {
        // display the menu
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
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible. Dimensions do not match.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subMatrices(rowsA, colsA, A, B, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible. Dimensions do not match.\n");
                }
                break;
            case 3:
                transMatrix(rowsA, colsA, A, result);
                printf("Transpose of Matrix A:\n");
                displayMatrix(colsA, rowsA, result);
                break;
            case 4:
                transMatrix(rowsB, colsB, B, result);
                printf("Transpose of Matrix B:\n");
                displayMatrix(colsB, rowsB, result);
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
