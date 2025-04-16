#include <stdio.h>

#define MAX_SIZE 10

// Function declarations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
int isValidDimension(int rows, int cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions and matrix elements for A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    while (!isValidDimension(rowsA, colsA)) {
        printf("Invalid dimensions. Please enter again (rows and columns): ");
        scanf("%d %d", &rowsA, &colsA);
    }

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // Input dimensions and matrix elements for B
    printf("Enter the number of rows and columns for Matrix B (rows and colunms): ");
    scanf("%d %d", &rowsB, &colsB);
    while (!isValidDimension(rowsB, colsB) || rowsA != rowsB || colsA != colsB) {
        if (rowsA != rowsB || colsA != colsB) {
            printf("Matrix dimensions must match for addition or subtraction.\n");
        }
        printf("Invalid dimensions. Please enter again (rows and columns): ");
        scanf("%d %d", &rowsB, &colsB);
    }

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Menu-driven program loop
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
                printf("\nAddition of Matrices:\n");
                addMatrices(A, B, result, rowsA, colsA);
                printMatrix(result, rowsA, colsA);
                break;
            case 2:
                printf("\nSubtraction of Matrices:\n");
                subtractMatrices(A, B, result, rowsA, colsA);
                printMatrix(result, rowsA, colsA);
                break;
            case 3:
                printf("\nTranspose of Matrix A:\n");
                transposeMatrix(A, result, rowsA, colsA);
                printMatrix(result, colsA, rowsA); // Transpose changes the dimension
                break;
            case 4:
                printf("\nTranspose of Matrix B:\n");
                transposeMatrix(B, result, rowsB, colsB);
                printMatrix(result, colsB, rowsB); // Transpose changes the dimension
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to check if the matrix dimensions are valid (<= 10x10)
int isValidDimension(int rows, int cols) {
    return (rows > 0 && rows <= MAX_SIZE && cols > 0 && cols <= MAX_SIZE);
}
