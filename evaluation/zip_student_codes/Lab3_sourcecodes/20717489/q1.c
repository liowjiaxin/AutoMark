#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int m, int n);
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int m, int n);

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int m, n, p, q, choice;

    // Input dimensions of matrix A
    printf("Enter dimensions of matrix A (rows x columns, max 10x10): ");
    scanf("%d %d", &m, &n);
    if (m > 10 || n > 10 || m <= 0 || n <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // Input elements of matrix A
    printf("Enter elements of matrix A:\n");
    inputMatrix(a, m, n);

    // Input dimensions of matrix B
    printf("Enter dimensions of matrix B (rows x columns, max 10x10): ");
    scanf("%d %d", &p, &q);
    if (p > 10 || q > 10 || p <= 0 || q <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }
    if (m != p || n != q) {
        printf("Matrices A and B must have the same dimensions.\n");
        return 1;
    }

    // Input elements of matrix B
    printf("Enter elements of matrix B:\n");
    inputMatrix(b, p, q);

    do {
        // Menu for operations
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMatrices(a, b, result, m, n);
            printf("Result of addition:\n");
            printMatrix(result, m, n);
            break;
        case 2:
            subtractMatrices(a, b, result, m, n);
            printf("Result of subtraction:\n");
            printMatrix(result, m, n);
            break;
        case 3:
            transposeMatrix(a, result, m, n);
            printf("Transpose of Matrix A:\n");
            printMatrix(result, n, m);
            break;
        case 4:
            transposeMatrix(b, result, m, n);
            printf("Transpose of Matrix B:\n");
            printMatrix(result, n, m);
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

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}