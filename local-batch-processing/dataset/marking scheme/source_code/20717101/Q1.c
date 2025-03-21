#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Input dimensions of matrices
    do {
        printf("Enter the dimensions of Matrix A (rows cols): ");
        scanf("%d %d", &rowsA, &colsA);
        if (rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE) {
            printf("Invalid dimensions! Please enter values between 1 and %d.\n", MAX_SIZE);
        }
    } while (rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE);

    do {
        printf("Enter the dimensions of Matrix B (rows cols): ");
        scanf("%d %d", &rowsB, &colsB);
        if (rowsB < 1 || rowsB > MAX_SIZE || colsB < 1 || colsB > MAX_SIZE) {
            printf("Invalid dimensions! Please enter values between 1 and %d.\n", MAX_SIZE);
        }
    } while (rowsB < 1 || rowsB > MAX_SIZE || colsB < 1 || colsB > MAX_SIZE);

    // Input matrices
    inputMatrix(matrixA, rowsA, colsA, 'A');
    inputMatrix(matrixB, rowsB, colsB, 'B');

    // Menu loop
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
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("\nResult of Addition:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("\nAddition not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("\nResult of Subtraction:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("\nSubtraction not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 3:
                transposeMatrix(matrixA, result, rowsA, colsA);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;

            case 4:
                transposeMatrix(matrixB, result, rowsB, colsB);
                printf("\nTranspose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("\nEnter elements of Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
