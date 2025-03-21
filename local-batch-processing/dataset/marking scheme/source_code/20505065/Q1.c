#include <stdio.h>
#define MAX 10

// Function declarations
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void printMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]);
void subtractMatrices(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int choice;

    printf("Enter the number of rows and columns for Matrix A (max %d): ", MAX);
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the number of rows and columns for Matrix B (max %d): ", MAX);
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX || rowsA < 1 || colsA < 1 || rowsB < 1 || colsB < 1) {
        printf("Invalid matrix dimensions. Exiting.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(rowsA, colsA, A);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(rowsB, colsB, B);

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
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, A, B, result);
                    printf("\nResult of Addition:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Addition not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, A, B, result);
                    printf("\nResult of Subtraction:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Subtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsA, colsA, A, result);
                printf("\nTranspose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;
            case 4:
                transposeMatrix(rowsB, colsB, B, result);
                printf("\nTranspose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
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

void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
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
