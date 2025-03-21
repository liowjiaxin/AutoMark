#include <stdio.h>
#define MAX_SIZE 10

//define
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

//entry
int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Enter the dimensions for Matrix A (max %d x %d): ", MAX_SIZE, MAX_SIZE);
    scanf("%d %d", &rowsA, &colsA);

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        printf("Invalid dimensions for Matrix A. Exiting.\n");
        return 1;
    }

    printf("Enter the dimensions for Matrix B (max %d x %d): ", MAX_SIZE, MAX_SIZE);
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) {
        printf("Invalid dimensions for Matrix B. Exiting.\n");
        return 1;
    }

    printf("Enter the elements of Matrix A:\n");
    inputMatrix(a, rowsA, colsA);

    printf("Enter the elements of Matrix B:\n");
    inputMatrix(b, rowsB, colsB);

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
                addMatrices(a, b, result, rowsA, colsA);
                printf("Result of addition:\n");
                printMatrix(result, rowsA, colsA);
            }
            else {
                printf("Addition not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 2:
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(a, b, result, rowsA, colsA);
                printf("Result of subtraction:\n");
                printMatrix(result, rowsA, colsA);
            }
            else {
                printf("Subtraction not possible. Matrices must have the same dimensions.\n");
            }
            break;

        case 3:
            transposeMatrix(a, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
            break;

        case 4:
            transposeMatrix(b, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
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
