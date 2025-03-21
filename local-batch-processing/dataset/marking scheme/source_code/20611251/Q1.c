#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Matrix A
    printf("Enter dimensions for Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);

    if (rowsA > MAX_SIZE || colsA > MAX_SIZE) {
        printf("Error: Matrix size exceeds the maximum allowed size (%dx%d).\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    printf("\nEnter elements for Matrix A:\n");
    inputMatrix(A, rowsA, colsA, 'A');

    //Matrix B
    printf("\nEnter dimensions for Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB > MAX_SIZE || colsB > MAX_SIZE) {
        printf("Error: Matrix size exceeds the maximum allowed size (%dx%d).\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    printf("\nEnter elements for Matrix B:\n");
    inputMatrix(B, rowsB, colsB, 'B');

    //Operations
    while (1) {
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
                    printf("\nResult of Addition:\n");
                    addMatrices(A, B, rowsA, colsA);
                } else {
                    printf("\nError: Dimensions of A and B do not match for addition.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    printf("\nResult of Subtraction:\n");
                    subtractMatrices(A, B, rowsA, colsA);
                } else {
                    printf("\nError: Dimensions of A and B do not match for subtraction.\n");
                }
                break;
            case 3:
                printf("\nTranspose of Matrix A:\n");
                transposeMatrix(A, rowsA, colsA);
                break;
            case 4:
                printf("\nTranspose of Matrix B:\n");
                transposeMatrix(B, rowsB, colsB);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element %c[%d][%d]: ", name, i + 1, j + 1);
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

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printMatrix(result, rows, cols);
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    printMatrix(result, rows, cols);
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transpose[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printMatrix(transpose, cols, rows);
}