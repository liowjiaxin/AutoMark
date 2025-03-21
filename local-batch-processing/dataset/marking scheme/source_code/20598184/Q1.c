#include <stdio.h>

#define MAX_SIZE 10 // assigning 10 to MAX_SIZE to allow easier reading and understanding of code

// Calling function
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrix(int a[MAX_SIZE][MAX_SIZE],int b[MAX_SIZE][MAX_SIZE],int c[MAX_SIZE][MAX_SIZE] ,int rows, int cols);
void subMatrix(int a[MAX_SIZE][MAX_SIZE],int b[MAX_SIZE][MAX_SIZE],int c[MAX_SIZE][MAX_SIZE] ,int rows, int cols);
void tranposeMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rows, int cols );


int main(void) {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int choice;

    // Input dimensions for matrixA
    do {
        printf("Enter dimension for Matrix A (rows and columns): " );
        scanf("%d %d", &rowsA, &colsA);
    } while (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE);

    // Input dimensions for matrixB 
    do {
        printf("Enter dimension for Matrix B (rows and columns): " );
        scanf("%d %d", &rowsB, &colsB);
    } while (rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE);

    // Input elements for matrixA
    printf("\nEnter elements of Matrix A: \n");
    inputMatrix(matrixA, rowsA, colsA);

    // Input elemnts for matrixB
    printf("\nEnter elements of Matrix B: \n");
    inputMatrix(matrixB, rowsB, colsB);

    // Menu with do-while loop for validation
    do {
        printf("\nMatrix Operations Menu: \n");
        printf("1. Add matrices\n");
        printf("2. Substract matrices\n");
        printf("3. Tranpose matrixA\n");
        printf("4. Tranpose matrixB\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) { // Checks if matrices have same dimension
                    addMatrix(matrixA, matrixB, result, rowsA, colsA);
                    printf("Results of Matrix A + Matrix B: \n");
                    displayMatrix(result, rowsA, colsA);
                } else { // Prints error message if they do not have the same dimensions
                    printf("Matrix dimensions need to have the same dimension for addition. \n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) { // Checks if matrices have same dimension
                    subMatrix(matrixA, matrixB, result, rowsA, colsA);
                    printf("Result of Matrix A - Matrix B: \n");
                    displayMatrix(result, rowsA, colsA);
                } else { // Prints error message if they do not have the same dimensions
                    printf("Matrix dimensions need to have the same dimension for substraction. \n");
                }
                break;
            
            case 3:
                tranposeMatrix(matrixA, result, rowsA, colsA); 
                printf("Tranpose of Matrix A: \n");
                displayMatrix(result, colsA, rowsA); // Swap position of rows and cols to flip the matrix
                break;

            case 4:
                tranposeMatrix(matrixB, result, rowsB, colsB);
                printf("Tranpose of Matrix A: \n");
                displayMatrix(result, colsB, rowsB);
                break;

            case 5:
                printf("Exiting... \n");
                break;
/*
            case 6:
                displayMatrix(matrixA, rowsA, colsA);
                displayMatrix(matrixB, rowsB, colsB);
*/
            default:
                printf("Invalid choice. Please try again. \n");
            
        }    
    } while (choice != 5);

    return 0;
}

// Function implement section
// function for assigment elements to the matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function for printing matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// addition function for matrix
void addMatrix(int a[MAX_SIZE][MAX_SIZE],int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// substraction function for matrix
void subMatrix(int a[MAX_SIZE][MAX_SIZE],int b[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// tranposing matrix function
void tranposeMatrix(int a[MAX_SIZE][MAX_SIZE], int c[MAX_SIZE][MAX_SIZE], int rows, int cols ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[j][i];
        }
    }
}

