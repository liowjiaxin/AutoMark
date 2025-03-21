#include <stdio.h>

// Function prototypes
void addMatrices(int a[10][10], int rowsA, int colsA, int b[10][10]);
void subtractMatrices(int a[10][10], int rowsA, int colsA, int b[10][10]);
void transposeA(int a[10][10], int rowsA, int colsA);
void transposeB(int b[10][10], int rowsB, int colsB);

int main(){
    // initialising rows, columns, arrays
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;
    int matrixA[10][10];
    int matrixB[10][10];
    do{
    // get user input for MatrixA dimensions
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    if(rowsA > 10 || colsA > 10){
        // case if dimensions > 10, error message
        printf("Invalid Input. Maximum size is 10x10.\n");
        continue;
    }
    // get user input for the elements of the matrix
    printf("Enter elements for Matrix A: \n");
    for(int i = 1; i<=rowsA; i++){
        for(int j = 1; j<=colsA; j++){
        printf("Element [%d][%d]: ", i, j);
        scanf("%d", &matrixA[i-1][j-1]);
        }
    }
    }while(rowsA > 10 || colsA > 10);   // loop if user input is invalid
    
    do{
    // get user input for MatrixB dimensions
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    if(rowsB > 10 || colsB > 10){
        // case if dimensions > 10, error message
        printf("Invalid Input. Maximum size is 10x10.\n");
        continue;
    }
    // get user input for the elements of the matrix
    printf("Enter elements for Matrix B: \n");
    for(int i = 1; i<=rowsB; i++){
        for(int j = 1; j<=colsB; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i-1][j-1]);
        }
    }
    }while(rowsB > 10 || colsB > 10);   // loop if user input is invalid

    int choice;
    do{
    // print main menu display
    printf("\t----------------------------------------\n");
    printf("\tMatrix Operations Menu:\n");
    printf("\t1. Add Matrices\n");
    printf("\t2. Subtract Matrices\n");
    printf("\t3. Transpose Matrix A\n");
    printf("\t4. Transpose Matrix B\n");
    printf("\t5. Exit\n");
    printf("\t----------------------------------------\n");

        printf("\tEnter your choice: ");
        // Get input from user
        scanf("%d", &choice);
        getchar(); // read newline
        // switch case handling different user inputs
        switch (choice) {
            case 1:
                addMatrices(matrixA, rowsA, colsA, matrixB);
                break;
            case 2:
                subtractMatrices(matrixA, rowsA, colsA, matrixB);
                break;
            case 3:
                transposeA(matrixA, rowsA, colsA);
                break;
            case 4: 
                transposeB(matrixB, rowsB, colsB);
                break;
            case 5:
                printf("\n\t----------------------------------------------------------\n");
                printf("\tExiting the Program...");
                printf("\n\t----------------------------------------------------------\n");
                break;
            default:
                printf("\tInvalid input. Please input a number from 1 - 5.\n");
                break;
        }
    }while(choice != 5); // loop while user input is not the exit code
    return 0;
}

// Function for addition of Matrices
void addMatrices(int a[10][10], int rowsA, int colsA, int b[10][10]){
    printf("Result of Matrix A + Matrix B\n");
    for(int i = 1; i<=rowsA; i++){
        for(int j = 1; j<=colsA; j++){
            printf("%d ", a[i-1][j-1] + b[i-1][j-1]); // print each element from A and B, added to eachother
        }
        printf("\n"); // newline for proper matrix format
    }
}
// Function for subtraction of Matrices
void subtractMatrices(int a[10][10], int rowsA, int colsA, int b[10][10]){
    printf("Result of Matrix A - Matrix B\n");
    for(int i = 1; i<=rowsA; i++){
        for(int j = 1; j<=colsA; j++){
            printf("%d ", a[i-1][j-1] - b[i-1][j-1]); // print each element from A and B, subtracted from eachother
        }
        printf("\n"); // newline for proper matrix format
    }
}
// Function for transpositon of Matrix A
void transposeA(int a[10][10], int rowsA, int colsA){
    printf("Transpose of Matrix A: \n");
    for(int i = 1; i<=rowsA; i++){
        for(int j = 1; j<=colsA; j++){
            printf("%d ", a[j-1][i-1]); // print [i] of matrixA as [j], and vice versa
        }
        printf("\n"); // newline for proper formatting
    }
}
// Function for transposition of Matrix B
void transposeB(int b[10][10], int rowsB, int colsB){
    printf("Transpose of Matrix B: \n");
    for(int i = 1; i<=rowsB; i++){
        for(int j = 1; j<=colsB; j++){
            printf("%d ", b[j-1][i-1]); // print [i] of matrixB as [j], and vice versa
        }
        printf("\n"); // newline for proper formatting
    }
}