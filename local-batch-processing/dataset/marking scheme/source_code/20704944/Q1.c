#include <stdio.h>

#define MAX_SIZE 10

// Function declarations
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols);
void addMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols);
int getMenuChoice();

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    
    // Input dimensions for Matrix A
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowsA, &colsA);
    } while (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE);
    
    // Input elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    inputMatrix(A, rowsA, colsA);
    
    // Input dimensions for Matrix B
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowsB, &colsB);
    } while (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE);
    
    // Input elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    inputMatrix(B, rowsB, colsB);
    
    // Main menu loop
    while (1) {
        choice = getMenuChoice();
        
        switch (choice) {
            case 1: // Addition
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Error: Matrices dimensions must be equal for addition\n");
                }
                break;
                
            case 2: // Subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Error: Matrices dimensions must be equal for subtraction\n");
                }
                break;
                
            case 3: // Transpose Matrix A
                transposeMatrix(A, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                printMatrix(result, colsA, rowsA);
                break;
                
            case 4: // Transpose Matrix B
                transposeMatrix(B, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                printMatrix(result, colsB, rowsB);
                break;
                
            case 5: // Exit
                printf("Exiting...\n");
                return 0;
        }
    }
    
    return 0;
}

// Input matrix elements
void inputMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Matrix addition
void addMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Matrix subtraction
void subtractMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Matrix transpose
void transposeMatrix(int matrix[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Print matrix
void printMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Display menu and get user choice
int getMenuChoice() {
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
    } while (choice < 1 || choice > 5);
    
    return choice;
}
