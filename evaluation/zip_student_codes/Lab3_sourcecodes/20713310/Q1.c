#include <stdio.h>

#define MAX 10

// Function prototypes
void displayMenu();
void performOperation(int choice, int A[MAX][MAX], int B[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB);
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX][MAX], B[MAX][MAX];
    int choice;

    // Input dimensions for matrices
    do {
        printf("Enter the number of rows and columns for Matrix A (max %d): ", MAX);
        scanf("%d %d", &rowsA, &colsA);
    } while (rowsA <= 0 || rowsA > MAX || colsA <= 0 || colsA > MAX);

    do {
        printf("Enter the number of rows and columns for Matrix B (max %d): ", MAX);
        scanf("%d %d", &rowsB, &colsB);
    } while (rowsB <= 0 || rowsB > MAX || colsB <= 0 || colsB > MAX);

    // Input matrices
    printf("Enter elements for Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    printf("Enter elements for Matrix B:\n");
    inputMatrix(B, rowsB, colsB);

    // Menu-driven operations
    do {
        displayMenu();
        scanf("%d", &choice);
        performOperation(choice, A, B, rowsA, colsA, rowsB, colsB);
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void performOperation(int choice, int A[MAX][MAX], int B[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB) {
    int result[MAX][MAX];

    switch (choice) {
        case 1:
            if (rowsA == rowsB && colsA == colsB) {
                addMatrices(A, B, result, rowsA, colsA);
                printf("Result of Addition:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Matrix dimensions do not match for addition!\n");
            }
            break;

        case 2:
            if (rowsA == rowsB && colsA == colsB) {
                subtractMatrices(A, B, result, rowsA, colsA);
                printf("Result of Subtraction:\n");
                printMatrix(result, rowsA, colsA);
            } else {
                printf("Matrix dimensions do not match for subtraction!\n");
            }
            break;

        case 3:
            transposeMatrix(A, result, rowsA, colsA);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, colsA, rowsA);
            break;

        case 4:
            transposeMatrix(B, result, rowsB, colsB);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, colsB, rowsB);
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
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
