
#include <stdio.h>

#define MAX_SIZE 10

// Function declarations
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void addMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[][MAX_SIZE], int transposed[][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols);

// Define A,B,result,rows and colomns
int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    while (1) {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rows, &cols);
        inputMatrix(A, rows, cols);

        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rows, &cols);
        inputMatrix(B, rows, cols);

//user selection variable
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

//operation of different variables

            switch (choice) {
                case 1:
                    addMatrices(A, B, result, rows, cols);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(result, rows, cols);
                    break;
                case 2:
                    subtractMatrices(A, B, result, rows, cols);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(result, rows, cols);
                    break;
                case 3:
                    transposeMatrix(A, result, rows, cols);
                    printf("Transpose of Matrix A:\n");
                    printMatrix(result, cols, rows);
                    break;
                case 4:
                    transposeMatrix(B, result, rows, cols);
                    printf("Transpose of Matrix B:\n");
                    printMatrix(result, cols, rows);
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 5);
    }
    return 0;
}


// Function definitions
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int transposed[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}