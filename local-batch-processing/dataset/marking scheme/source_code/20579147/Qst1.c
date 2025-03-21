
#include <math.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Function to add  thetwo matrices
void addMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {// loop through each elemt of matrices
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];// add elements form A and B  store in resukt
        }
    }
}

// Function to subtract  the two matrices
void subtractMatrices(int rows, int cols, int A[10][10], int B[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];//ssubtract corresponding  elements B form A
        }
    }
}

//  Function to transpose the matrix
void transposeMatrix(int rows, int cols, int matrix[10][10], int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];// swap row with columns
        }
    }
}

// Function to display the matrix
void displayMatrix(int rows, int cols, int matrix[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");// print new line after each row
    }
}

int main() {
    int rows=0; // initialization
    int  cols=0; // initialization
    int A[10][10], B[10][10], result[10][10];
    int choice;

    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns of the matrices (max 10x10): ");
    scanf("%d %d", &rows, &cols);

    // Input elements of matrix A
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of matrix B
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    do {
        // Display menu
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {//  the switch statement to handle different choices
            case 1:
                addMatrices(rows, cols, A, B, result);
                printf("Result of Addition:\n");
                displayMatrix(rows, cols, result);
                break;

            case 2:
                subtractMatrices(rows, cols, A, B, result);
                printf("Result of Subtraction:\n");
                displayMatrix(rows, cols, result);
                break;

            case 3:
                transposeMatrix(rows, cols, A, result);
                printf("Transpose of Matrix A:\n");
                displayMatrix(cols, rows, result);
                break;

            case 4:


                transposeMatrix(rows, cols, B, result);
                printf("Transpose of Matrix B:\n");
                displayMatrix(cols, rows, result);
                break;


            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);// continue till the user decides to exit

    return 0;
}
