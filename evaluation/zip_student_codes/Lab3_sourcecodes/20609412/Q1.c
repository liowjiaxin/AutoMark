#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10


void getMatrixElement(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name);
void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void subMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);


// Main function
int main(void) {

    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    char choice[2];

    // Input dimensions of matrices A
    do {
        printf("Enter the dimensions of Matrix A (rows cols): ");
        scanf("%d %d", &rowsA, &colsA);
    } while (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE);

    // Input elements of matrices A
    getMatrixElement(rowsA, colsA, matrixA, 'A');

    // Input dimensions of matrices B
    do {
        printf("Enter the dimensions of Matrix B (rows cols): ");
        scanf("%d %d", &rowsB, &colsB);
    } while (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE);
    
    // Input elements of matrices B
    getMatrixElement(rowsB, colsB, matrixB, 'B');

    do {
        // Display menu
        printf("\nMatrix Operations Menu:\n");
        printf("\n1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%s", choice);  // Read input as string
 
        
        if (strlen(choice) != 1) {
            printf("Invalid choice! Please select a valid option (1-5).\n");
            continue;
        }

        switch (choice[0]) {
            case '1': 
                //check if rows of A and B and columns of A and B are the same for addition
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Error: Matrices dimensions do not match for addition.\n");  
                }
                break;
            case '2': 
                //check if rows of A and B and columns of A and B are the same for subtraction
                if (rowsA == rowsB && colsA == colsB) {
                    subMatrices(rowsA, colsA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    printMatrix(rowsA, colsA, result);
                } else {
                    printf("Error: Matrices dimensions do not match for subtraction.\n");  
                } 
                break;
            case '3': 
                transposeMatrix(rowsA, colsA, matrixA, result);
                printf("Transpose of Matrix A:\n");
                printMatrix(colsA, rowsA, result);
                break;
            case '4': 
                transposeMatrix(rowsB, colsB, matrixB, result);
                printf("Transpose of Matrix B:\n");
                printMatrix(colsB, rowsB, result);
                break;
            case '5':
                printf("Exiting the program. Goodbye!\n"); 
                break;
            default: 
                printf("Invalid choice! Please select a valid option (1-8).\n");
        }

    }  while (choice[0] != '5');  // Loop until user chooses to exit



    return 0;
}


// get elements of the matrices
void getMatrixElement(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], char name) {
    printf("Enter elements of Matrix %c:\n", name);

    // Loop through each row and column to get the matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element Matrix %c[%d][%d]: ", name, i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// add matrices function
void addMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    // Loop through each element of the matrices A and B
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Add corresponding elements of A and B, store the result in the result matrix
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// add matrices function
void subMatrices(int rows, int cols, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    // Loop through each element of the matrices A and B
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Subtract corresponding elements of B from A and store the result
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// function to transpose matrix
void transposeMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    // Loop through each element of the matrices A and B
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Transpose the element by swapping rows and columns
            result[j][i] = matrix[i][j];
        }
    }
}

// print out the matrix results function
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    // Loop through each element of the matrices A and B
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]); // Allocate 4-character width for each number
        }
        printf("\n");
    }
}


