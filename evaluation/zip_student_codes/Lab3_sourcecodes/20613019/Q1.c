#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    // Input dimensions for Matrix A
    while (1) {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        if (scanf("%d %d", &rowsA, &colsA) != 2 || rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
            printf("Invalid input. Please enter two integers between 1 and %d.\n", MAX_SIZE);
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break; 
        }
    }

    // Input elements for Matrix A
    inputMatrix(matrixA, rowsA, colsA, 'A');

    // Input dimensions for Matrix B
    while (1) {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        if (scanf("%d %d", &rowsB, &colsB) != 2 || rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) {
            printf("Invalid input. Please enter two integers between 1 and %d.\n", MAX_SIZE);
            while (getchar() != '\n'); 
        } else {
            break; 
        }
    }

    // Input elements for Matrix B
    inputMatrix(matrixB, rowsB, colsB, 'B');

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A + Matrix B:\n");
                    addMatrices(matrixA, matrixB, rowsA, colsA);
                } else {
                    printf("Addition not possible, matrices have different dimensions.\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    printf("Result of Matrix A - Matrix B:\n");
                    subtractMatrices(matrixA, matrixB, rowsA, colsA);
                } else {
                    printf("Subtraction not possible, matrices have different dimensions.\n");
                }
                break;
            case 3:
                printf("Transpose of Matrix A:\n");
                transposeMatrix(matrixA, rowsA, colsA);
                break;
            case 4:
                printf("Transpose of Matrix B:\n");
                transposeMatrix(matrixB, rowsB, colsB);
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

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("Enter elements for Matrix %c:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            while (scanf("%d", &matrix[i][j]) != 1) { // Handle invalid input
                printf("Invalid input. Please enter an integer for Element [%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n'); 
            }
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

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    displayMatrix(result, rows, cols);
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    displayMatrix(result, rows, cols);
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    displayMatrix(result, cols, rows);
}
