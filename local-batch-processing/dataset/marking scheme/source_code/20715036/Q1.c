#include <stdio.h>

#define MAX_SIZE 10

// Function to input matrix dimensions
void inputMatrixDimensions(int* rows, int* cols) {
    do {
        printf("Enter number of rows (1-10): ");
        scanf("%d", rows);
        printf("Enter number of columns (1-10): ");
        scanf("%d", cols);

        if (*rows < 1 || *rows > MAX_SIZE || *cols < 1 || *cols > MAX_SIZE) {
            printf("Invalid dimensions. Please enter dimensions between 1 and 10.\n");
        }
    } while (*rows < 1 || *rows > MAX_SIZE || *cols < 1 || *cols > MAX_SIZE);
}

// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                     int* rows, int* cols) {
    // Swap rows and columns
    int temp = *rows;
    *rows = *cols;
    *cols = temp;

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, choice;

    printf("Enter dimensions for Matrix A:\n");
    inputMatrixDimensions(&rowsA, &colsA);
    inputMatrix(A, rowsA, colsA);

    printf("Enter dimensions for Matrix B:\n");
    inputMatrixDimensions(&rowsB, &colsB);
    inputMatrix(B, rowsB, colsB);

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
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions are not compatible for addition.\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrix dimensions are not compatible for subtraction.\n");
                }
                break;

            case 3:
                transposeMatrix(A, result, &rowsA, &colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, rowsA, colsA);
                break;

            case 4:
                transposeMatrix(B, result, &rowsB, &colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, rowsB, colsB);
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
