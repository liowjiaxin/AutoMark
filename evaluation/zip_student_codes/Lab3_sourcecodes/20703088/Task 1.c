#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declaration
void addmatrix(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA], int B[rowsB][colsB]);
void subtractMatrices(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA], int B[rowsB][colsB]);
void transpose(int rows, int cols, int matrix[rows][cols], char matrixName);



int main(){
    int rowsA;
    int columnsA;
    int rowsB;
    int columnsB;
    int choice;
    //rows and column input for matrix A
    printf("Enter the number of rows and columns in matrix A (r c): ");
    scanf("%d %d", &rowsA, &columnsA);
    //store rows and columns inputted by the user 
    int matrixA[rowsA][columnsA];
    
    //rows and colums input for matrix B
    printf("Enter the number of rows and columns in the matrix B (r c): ");
    scanf("%d %d", &rowsB, &columnsB);
    //store rows and columns inputted by the user
    int matrixB[rowsB][columnsB];
    
    //take elements for matrix A
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    //take elements for matrix B
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }



        //code for menu options
        do{

        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //switch case to choose the required operation
    
        switch (choice)
        {
        case 1:
            addmatrix(rowsA, columnsA, rowsB, columnsB, matrixA, matrixB);
            break;
        
        case 2:
            subtractMatrices(rowsA, columnsA, rowsB, columnsB, matrixA, matrixB);
            break;
        
        case 3:
            transpose(rowsA, columnsA, matrixA, 'A');
            break;
        
        case 4:
            transpose(rowsB, columnsB, matrixB, 'B');
            break;
        
        case 5:
            printf("Exitting...\n");
            break;
        
        default:
            printf("Invalid choice, please try again");
            break;

        }
        }while(choice!= 5);
    
    return 0;

}
void addmatrix(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA], int B[rowsB][colsB] ){
    //check if addition of matrices is possible, matrix can be only added if dimensions of matrix are same
    if(rowsA != rowsB || colsA != colsB){
        printf("\n Addition of matrices not possible if they have different rows and columns number, dimensions must be same!");
        return;
    }

    //set the matrix to store the result, either row or column of A can be used as they must have same size for addition
    int result[rowsA][colsA];
    printf("Result of A + B: \n");
    for(int i = 0; i< rowsA; i++){
        for(int j =0; j< colsA; j++ ){
            result[i][j]= A[i][j] + B[i][j];
            printf("%d ", result[i][j]);
        }
        //add new line for readability after ever row 
        printf("\n");

    }
}

//function same as addition just with (-) sign for calculating the difference
void subtractMatrices(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA], int B[rowsB][colsB] ){
    //check if addition of matrices is possible, matrix can be only added if dimensions of matrix are same
    if(rowsA != rowsB || colsA != colsB){
        printf("\n Subtraction of matrices not possible if they have different rows and columns number, dimensions must be same!");
        return;
    }

    //set the matrix to store the result, either row or column of A can be used as they must have same size for subtraction
    int result[rowsA][colsA];
    printf("Result of A - B: \n");
    for(int i = 0; i< rowsA; i++){
        for(int j =0; j< colsA; j++ ){
            result[i][j]= A[i][j] - B[i][j];
            printf("%d ", result[i][j]);
        }
        //add new line for readability after ever row 
        printf("\n");

    }

}

//function to transpose matrix
void transpose(int rows, int cols, int matrix[rows][cols], char matrixName){
    printf("Transpose of Matrix %c:", matrixName);
    //iterate through rows as inner loop as it is transpose (opposite operation to the normal matrix)
    for(int i = 0; i<cols; i++){
        for(int j = 0; j<rows; j++){
            printf("%d ", matrix[j][i]);

        }
        printf("\n");
    }

}
