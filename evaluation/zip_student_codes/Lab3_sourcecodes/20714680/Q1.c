#include <stdio.h>


void addMatrices(int A[10][10], int B[10][10], int result[10][10], int row, int column) { //defining function for adding matrices
            for(int i = 0; i<row; i++) {
                for(int j = 0; j<column; j++) {
                    result[i][j] = A[i][j] + B[i][j];   //Each element of matrix A is added to corresponding element of matrix B and answer is stored in result matrix
                }
            }
}

void subtractMatrices(int A[10][10], int B[10][10], int result[10][10], int row, int column) {    //defining function for subtracting matrices
            for(int i = 0; i<row; i++) {
                for(int j = 0; j<column; j++) {
                    result[i][j] = A[i][j] - B[i][j];   //Each element of matrix B is subtracted from corresponding element of matrix A and answer is stored in result matrix
                }
            }
}

void transposeA(int A[10][10], int result[10][10], int row, int column) {       //defining function for transpose of matrix A
            for(int i = 0; i<row; i++) {
                for(int j = 0; j<column; j++) {
                   result[j][i] = A[i][j];  //swap the row and column indices
                }
            }
}

void transposeB(int B[10][10], int result[10][10], int row, int column) {       //defining function for transpose of matrix B
            for(int i = 0; i<row; i++) {
                for(int j = 0; j<column; j++) {
                   result[j][i] = B[i][j];  //swap the row and column indices
                }
            }
}

void printMatrix(int matrix[10][10], int row, int column) {   //defining function for printing each element of resultant matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(void) {
    int rowA, columnA;
    int A[10][10];
    int rowB, columnB;
    int B[10][10];
    int result[10][10];
    int choice = 0;

    printf("Enter the dimensions for matrix A (rows and columns): ");       //Prompt the user to enter dimensions for matrix A
    scanf(" %d%d", &rowA, &columnA);

    for(int i = 0; i<rowA; i++) {
        for(int j = 0; j<columnA; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the dimensions for matrix B (rows and columns): ");       //Prompt the user to enter dimensions for matrix B
    scanf(" %d%d", &rowB, &columnB);

    for(int a = 0; a<rowB; a++) {
        for(int b = 0; b<columnB; b++) {
            printf("Element [%d][%d]: ", a+1, b+1);
            scanf("%d", &B[a][b]);
        }
    }
while(choice!=5)    {
    printf("Matrix Operations Menu:\n1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n5. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);   //Stores the number entered by user

    switch (choice) {       //Used switch case to control loop
        case 1:
            if (rowA==rowB && columnA==columnB) {           //Checks whether matrix A and matrix B have same number of rows and columns
                addMatrices( A, B, result, rowA, columnA);      //call the addMatrices function to add each element of matrix A to corresponding element of matrix B
                printf("Result of Matrix A + Matrix B:\n");
                printMatrix(result, rowA, columnA);     //call the printMatrix function to display the resultant matrix after adding both matrices
            } else {
                printf("Please enter valid dimensions for matrices");   //Gives error message when matrix A and matrix B dont have same number of rows and columns
            }
            break;

        case 2:
            if (rowA==rowB && columnA==columnB) {           //Checks whether matrix A and matrix B have same number of rows and columns
                subtractMatrices( A, B, result, rowA, columnA);    //call the subtractMatrices function to subtract each element of matrix A with corresponding element of matrix B
                printf("Result of Matrix A - Matrix B:\n");
                printMatrix(result, rowA, columnA);      //call the printMatrix function to display the resultant matrix after subtracting both matrices
            } else {
                printf("Please enter valid dimensions for matrices");   //Gives error message when matrix A and matrix B dont have same number of rows and columns
            }
            break;

        case 3:
            transposeA(A, result, rowA, columnA);     //call the transposeA function to perform transpose of matrix A
            printf("Transpose of Matrix A:\n");
            printMatrix(result, rowA, columnA);     //call the printMatrix function to display the resultant matrix after transpose of matrix A
            break;

        case 4:
            transposeB(B, result, rowB, columnB);    //call the transposeB function to perform transpose of matrix B
            printf("Transpose of Matrix B:\n");
            printMatrix(result, rowB, columnB);     //call the printMatrix function to display the resultant matrix after transpose of matrix B
            break;

        case 5:
            printf("Exiting...\n");     //If user enters five, exit the loop
            break;
        default:
            printf("Invalid choice! Please enter a number from 1 to 5");    //Gives error message when user enters invalid input
        }
    }
    return 0;
}