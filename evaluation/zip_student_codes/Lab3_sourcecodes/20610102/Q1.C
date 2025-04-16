#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols, char *name);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char *name);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int original[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], 
                     int *rows, int *cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int A_rows, A_cols, B_rows, B_cols, choice;
    
    printf("Matrix Operations Program\n");
    
    // Input matrices
    printf("\nEnter Matrix A:\n");
    inputMatrix(A, &A_rows, &A_cols, "A");
    
    printf("\nEnter Matrix B:\n");
    inputMatrix(B, &B_rows, &B_cols, "B");
    
    // Main menu loop
    while (1) {
        // Display menu
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        // Perform selected operation
        switch(choice) {
            case 1: 
                // Check if matrices can be added
                if (A_rows == B_rows && A_cols == B_cols) {
                    addMatrices(A, B, result, A_rows, A_cols);
                    printf("\nResult of Matrix Addition:\n");
                    printMatrix(result, A_rows, A_cols, "Result");
                } else {
                    printf("Error: Matrices must have the same dimensions for addition!\n");
                }
                break;
            
            case 2:
                // Check if matrices can be subtracted
                if (A_rows == B_rows && A_cols == B_cols) {
                    subtractMatrices(A, B, result, A_rows, A_cols);
                    printf("\nResult of Matrix Subtraction:\n");
                    printMatrix(result, A_rows, A_cols, "Result");
                } else {
                    printf("Error: Matrices must have the same dimensions for subtraction!\n");
                }
                break;
            
            case 3:
                transposeMatrix(A, result, &A_rows, &A_cols);
                printf("\nTranspose of Matrix A:\n");
                printMatrix(result, A_cols, A_rows, "Transposed A");
                break;
            
            case 4:
                transposeMatrix(B, result, &B_rows, &B_cols);
                printf("\nTranspose of Matrix B:\n");
                printMatrix(result, B_cols, B_rows, "Transposed B");
                break;
            
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    
    return 0;
}

// Function to input matrix elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols, char *name) {
    // Input matrix dimensions
    do {
        printf("Enter number of rows for Matrix %s (1-%d): ", name, MAX_SIZE);
        scanf("%d", rows);
        printf("Enter number of columns for Matrix %s (1-%d): ", name, MAX_SIZE);
        scanf("%d", cols);
        
        if (*rows < 1 || *rows > MAX_SIZE || *cols < 1 || *cols > MAX_SIZE) {
            printf("Invalid dimensions. Please enter values between 1 and %d.\n", MAX_SIZE);
        }
    } while (*rows < 1 || *rows > MAX_SIZE || *cols < 1 || *cols > MAX_SIZE);
    
    // Input matrix elements
    printf("Enter %d elements for Matrix %s:\n", (*rows) * (*cols), name);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix elements
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char *name) {
    printf("Matrix %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int original[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], 
                     int *rows, int *cols) {
    // Swap rows and columns for transposed matrix
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
    
    // Swap the number of rows and columns
    int temp = *rows;
    *rows = *cols;
    *cols = temp;
}