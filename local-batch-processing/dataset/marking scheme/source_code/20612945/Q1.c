#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputMatrix(int rows, int cols, int matrix[10][10]);
void printMatrix(int rows, int cols, int matrix[10][10]);
void addMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]);
void subtractMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]);
void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[10][10], matrixB[10][10];
    int result[10][10];
    int choice;

    //input matrix a
    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if (rowsA <= 0 || rowsA > 10 || colsA <= 0 || colsA > 10) {
        printf("Invalid dimensions\n");
        return 1;
    }

    //input matrix a element
    printf("Enter elements of Matrix A:\n");
    inputMatrix(rowsA, colsA, matrixA);

    //input matrix b
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if (rowsB <= 0 || rowsB > 10 || colsB <= 0 || colsB > 10) {
        printf("Invalid dimensions\n");
        return 1;
    }

    //input matrix b element
    printf("Enter elements of Matrix B:\n");
    inputMatrix(rowsB, colsB, matrixB);

    //main menu
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            //addition case
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Both matrices must have the same dimensions in order to perform addition.\n");
                }
                break;

            //substraction case
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Both matrices must have the same dimensions in order to perform substraction.\n");
                }
                break;

            //transpose a case
            case 3:
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;

            //transpose b case
            case 4:
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
                break;

            //exit
            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid input.\n");
        }
    } while (choice != 5);

    return 0;
}

//input function
void inputMatrix(int rows, int cols, int matrix[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//print function
void printMatrix(int rows, int cols, int matrix[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//addition 
void addMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//substraction
void subtractMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//transpose
void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
