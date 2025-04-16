#include <stdio.h>

#define MAX 10 // define the maximum size for the matrices instead of typing 10 each time

//declare all the functions that are below here
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX]; // matrices A B and result
    int rowsA, colsA, rowsB, colsB; // dimensions of matrices A and B
    int choice; // user menu choice

    // input dimensions for Matrix A bt user has to input next to eachother
    printf("Enter the number of rows and columns for Matrix A (max 10x10): ");
    scanf("%d %d", &rowsA, &colsA);

    // input dimensions for Matrix B bt user has to input next to eachother
    printf("Enter the number of rows and columns for Matrix B (max 10x10): ");
    scanf("%d %d", &rowsB, &colsB);

    // check if the dimensions exceed the maximum allowed size
    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
        printf("Matrix dimensions exceed the maximum allowed size of 10x10.\n");
        return 1; // Exit the program if dimensions are invalid
    }

    // input elements for Matrix A
    printf("Enter the elements of Matrix A:\n");
    inputMatrix(A, rowsA, colsA);

    // input elements for Matrix B
    printf("Enter the elements of Matrix B:\n");
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

        //switch case to check which case (operation) user wants to do
        switch (choice) {
            case 1:
                //check if dimensions match for addition
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices dimensions do not match for addition.\n");
                }
                break;
            case 2:
                //check if dimensions match for subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices sizes dont match for subtraction.\n");
                }
                break;
            case 3:
                // Transpose Matrix A
                transposeMatrix(A, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;
            case 4:
                // Transpose Matrix B
                transposeMatrix(B, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;
            case 5:
                //exit the program
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // loop until the user chooses to exit (choose option 5)

    return 0;
}

//function to input elements of a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//function to print a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//function to subtract one matrix from another
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

//function to transpose a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}