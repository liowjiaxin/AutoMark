#include <stdio.h>

#define MAX 10

void inputMatrix(int rows, int columns, int matrix[MAX][MAX], char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int rows, int columns, int A[MAX][MAX], int B[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Result of Matrix A + Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void subtractMatrices(int rows, int columns, int A[MAX][MAX], int B[MAX][MAX]) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("Result of Matrix A - Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int rows, int columns, int matrix[MAX][MAX], char name) {
    int transpose[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    printf("Transpose of Matrix %c:\n", name);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int rowsA, columnsA, rowsB, columnsB;

    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &columnsA);
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &columnsB);

    if (rowsA > MAX || columnsA > MAX || rowsB > MAX || columnsB > MAX) {
        printf("Error!!! Matrix dimensions exceed maximum allowed size of %d\n", MAX);
        return 1;
    }

    if (rowsA != rowsB || columnsA != columnsB) {
        printf("Error!!! Addition and subtraction require matrices of the same dimensions.\n");
    }

    inputMatrix(rowsA, columnsA, A, 'A');
    inputMatrix(rowsB, columnsB, B, 'B');

    int choice;
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
                if (rowsA == rowsB && columnsA == columnsB) {
                    addMatrices(rowsA, columnsA, A, B);
                } else {
                    printf("Error!!! Matrices must have the same dimensions for addition.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && columnsA == columnsB) {
                    subtractMatrices(rowsA, columnsA, A, B);
                } else {
                    printf("Error!!! Matrices must have the same dimensions for subtraction.\n");
                }
                break;
            case 3:
                transposeMatrix(rowsA, columnsA, A, 'A');
                break;
            case 4:
                transposeMatrix(rowsB, columnsB, B, 'B');
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
