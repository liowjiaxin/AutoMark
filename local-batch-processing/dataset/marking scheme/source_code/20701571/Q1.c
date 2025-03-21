#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    //intialization
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;


    do{ 
    // input dimensions
    printf("Enter the demensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) { // this if statement ensures that the row size or column size for matrix A is not exceeded past 10 or is below or equal to 0 by using the logical OR.
        printf("Invalid dimensions for Matrix A. Try again!\n");
        
    }
    } while (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE); // the program loops backs to enter the dimensions again because the maximum size has been exceeded. 
    
    inputMatrix(A, rowsA, colsA, 'A'); // input elements of Matrix A
    
    do{
    printf("\nEnter the demensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) { // this if statement ensures that the row size or column size for matrix B is not exceeded past 10 or is below or equal to 0 by using the logical OR.   
        printf("Invalid dimensions for Matrix B. Try again!\n");

    }
    }while(rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE);

    inputMatrix(B, rowsB, colsB, 'B'); //input elements of Matrix B
    
    do{
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrix operations (add/subtract) require matching dimensions. Exiting...\n");  
    }
    }while (rowsA != rowsB || colsA != colsB);
    
    // Matrix Menu loop
    do { // use of do-while loop so the program displays the menu first time and then again after the user has performed a operation once and wishes to do it again the loop will allow the user to do either the same operation or a different one.
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
                printf("\nResult of Matrix A + Matrix B:\n");
                addMatrices(A, B, rowsA, colsA);
                break;
            case 2:
                printf("\nResult of Matrix A - Matrix B:\n");
                subtractMatrices(A, B, rowsA, colsA);
                break;
            case 3:
                printf("\nTranspose of Matrix A:\n");
                transposeMatrix(A, rowsA, colsA);
                break;
            case 4:
                printf("\nTranspose of Matrix B:\n");
                transposeMatrix(B, rowsB, colsB);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("Enter elements of Matrix %c (%dx%d) (each number in a element should be different):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {// Loop through each row of the matrix
        for (int j = 0; j < cols; j++) {// Loop through each column of the matrix
            printf("Element [%d][%d]: ", i + 1, j + 1); // Allows the user to enter the value for the current matrix element
            scanf("%d", &matrix[i][j]);
        }
    }
}

// The display a matrix function is designed to print the elements of a given matrix row by row in a readable format 
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Iterate over each row of the matrix
        for (int j = 0; j < cols; j++) {  // Iterate over each column in the current row
            printf("%d ", matrix[i][j]); // Print the current matrix element followed by a space
        }
        printf("\n"); // skips a line to display a matrix 
    }
}

// Function to add matrices
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    displayMatrix(result, rows, cols);
}

// Function to subtract matrices
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    // Iterate over the rows of the original matrix
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { // Iterate over the columns of the original matrix
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    displayMatrix(result, rows, cols); //The dimensions of the transposed matrix are swapped.
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE]; // Define a temporary result matrix to store the transposed values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];// Assign the value at position [i][j] in the original matrix 
            // to position [j][i] in the transposed matrix
        }
    }
    displayMatrix(result, cols, rows); //The dimensions of the transposed matrix are swapped.
}