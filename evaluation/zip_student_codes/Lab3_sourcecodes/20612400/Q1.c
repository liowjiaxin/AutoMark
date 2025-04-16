#include <stdio.h>

#define MAX 10

void createMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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

void add(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int rows, int cols, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transpose(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Enter dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA > 10 || colsA > 10 || rowsB > 10 || colsB > 10 || rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0) {
        printf("Dimension not accepted.\n");
        return 1;
    }

    printf("Matrix A:\n");
    createMatrix(rowsA, colsA, a);
    printf("Matrix B:\n");
    createMatrix(rowsB, colsB, b);

    do {
        printf("\nChoose operation:\n");
        printf("1. Add\n2. Subtract\n3. Transpose A\n4. Transpose B\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    add(rowsA, colsA, a, b, result);
                    printf("Result:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Unable to add Matrices\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtract(rowsA, colsA, a, b, result);
                    printf("Result:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Unable to subtract Matrices\n");
                }
                break;

            case 3:
                transpose(rowsA, colsA, a, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;

            case 4:
                transpose(rowsB, colsB, b, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
