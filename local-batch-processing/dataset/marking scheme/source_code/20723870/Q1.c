#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], 
                     int transposed[MAX_SIZE][MAX_SIZE], int *rows, int *cols);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Matrix A Input:\n");
    inputMatrix(A, &rowsA, &colsA);

    printf("Matrix B Input:\n");
    inputMatrix(B, &rowsB, &colsB);

    while(choice != 5) {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //switch cases to choose functions
        switch(choice) {
            case 1:
                if (rowsA != rowsB || colsA != colsB) { //checking if same dimension
                    printf("Error: Matrices must have the same dimensions for addition.\n");
                } else {
                    addMatrices(A, B, C, rowsA, colsA);
                    printf("Result of Matrix Addition:\n");
                    printMatrix(C, rowsA, colsA);
                }
                break;

            case 2:
                if (rowsA != rowsB || colsA != colsB) { //checking if same dimension
                    printf("Error: Matrices must have the same dimensions for subtraction.\n");
                } else {
                    subtractMatrices(A, B, C, rowsA, colsA);
                    printf("Result of Matrix Subtraction:\n");
                    printMatrix(C, rowsA, colsA);
                }
                break;

            case 3:
                transposeMatrix(A, C, &rowsA, &colsA);
                printf("Transposed Matrix A:\n");
                printMatrix(C, colsA, rowsA);
                break;

            case 4:
                transposeMatrix(B, C, &rowsB, &colsB);
                printf("Transposed Matrix B:\n");
                printMatrix(C, colsB, rowsB);
                break;

            case 5:
                break; //exit code

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 

    return 0;
}

// Function to input matrix dimensions and elements
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) { //byref for rows and cols to check num of rows and cols
    while (*rows < 1 || *rows > MAX_SIZE) { //ensure row doesnt go above limit (input validation)
        printf("Enter number of rows (1-10): ");
        scanf("%d", rows);
    };

    while (*cols < 1 || *cols > MAX_SIZE){ //(input validation)
        printf("Enter number of columns (1-10): ");
        scanf("%d", cols);
    };

    printf("Enter matrix elements:\n");
    for (int i = 0; i < *rows; i++) { //input elements by iterating through matrice rows and columns
        for (int j = 0; j < *cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) { //iterate through matrice and print
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                 int C[MAX_SIZE][MAX_SIZE], int rows, int cols) { // C is result matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j]; //elem in A + elem in B = elem in C
        }
    }
}

// Function to subtract matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                      int C[MAX_SIZE][MAX_SIZE], int rows, int cols) { // C is result matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j]; //elem in B - elem in A = elem in C
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], 
                     int transposed[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {//
    // Swap rows and columns for transpose
    int temp = *rows;
    *rows = *cols;
    *cols = temp;

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            transposed[i][j] = matrix[j][i];//swapping rows and columns (i and j)
        }
    }
}