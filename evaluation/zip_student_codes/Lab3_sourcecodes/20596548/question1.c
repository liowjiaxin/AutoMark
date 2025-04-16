#include <stdio.h>

#define MAX 10

// Function prototypes
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void printMatrix(int A[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols;
    int choice;

    // Input matrix dimensions with validation
    do {
        printf("Enter the number of rows and columns (max 10x10): ");
        scanf("%d %d", &rows, &cols);
        if (rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
            printf("Invalid dimensions! Please enter values between 1 and 10.\n");
        }
    } while (rows < 1 || rows > MAX || cols < 1 || cols > MAX);

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

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
                addMatrices(A, B, result, rows, cols);
                printf("Result of A + B:\n");
                printMatrix(result, rows, cols);
                break;
            case 2:
                subtractMatrices(A, B, result, rows, cols);
                printf("Result of A - B:\n");
                printMatrix(result, rows, cols);
                break;
            case 3:
                transposeMatrix(A, result, rows, cols);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, cols, rows); // Transposed matrix has swapped dimensions
                break;
            case 4:
                transposeMatrix(B, result, rows, cols);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, cols, rows); // Transposed matrix has swapped dimensions
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Add corresponding elements of matrices A and B
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Subtract corresponding elements of matrices A and B
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Transpose matrix A
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j]; // Swap rows with columns
        }
    }
}

// Print matrix elements
void printMatrix(int A[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
