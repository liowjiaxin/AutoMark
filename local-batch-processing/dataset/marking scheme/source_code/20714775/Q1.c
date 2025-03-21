#include <stdio.h>


#define MAX 10


void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter elements for Matrix A:\n");
    inputMatrix(matrixA, rowsA, colsA);

    
    printf("\nEnter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter elements for Matrix B:\n");
    inputMatrix(matrixB, rowsB, colsB);

    
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
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices dimensions do not match for addition.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices dimensions do not match for subtraction.\n");
                }
                break;

            case 3:
                transposeMatrix(matrixA, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;

            case 4:
                transposeMatrix(matrixB, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}


void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}


void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}