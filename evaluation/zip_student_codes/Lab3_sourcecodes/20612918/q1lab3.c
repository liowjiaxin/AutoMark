#include <stdio.h>
#define MAXROWS  10
#define MAXCOLS 10

//functions for matrix menu options
void matrix(int arr[MAXROWS][MAXCOLS], int *row, int *col, char matrixName);
void addMatrices(int row, int col, int matrixA[MAXROWS][MAXCOLS], int matrixB[MAXROWS][MAXCOLS]);
void subMatrices(int row, int col, int matrixA[MAXROWS][MAXCOLS], int matrixB[MAXROWS][MAXCOLS]);
void transposeMatrix(int row, int col, int matrix[MAXROWS][MAXCOLS], int transpose[MAXROWS][MAXCOLS], char matrixName);


int main(){
    int matrixA[MAXROWS][MAXCOLS], matrixB[MAXROWS][MAXCOLS], transposeA[MAXROWS][MAXCOLS], transposeB[MAXROWS][MAXCOLS];
    int rowA, colA, rowB, colB, choice;

    //matrix A
    matrix(matrixA, &rowA, &colA, 'A');

    //matrixB
    matrix(matrixB, &rowB, &colB, 'B');

   do{
        //printing menu
        printf("Matrix Operations Menus:\n1. Add Matrices\n2. Substract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //checking if number of rows and columns are equal
                if (rowA == rowB && colA == colB){
                    addMatrices(rowA, colA, matrixA, matrixB);
                }
                else{
                    printf("Matrices cannot be added");
                }
                break;
            case 2:
                if (rowA == rowB && colA == colB){
                    subMatrices(rowA, rowB, matrixA, matrixB);
                }
                else{
                    printf("Matrices cannot be substracted");
                }
                break;
            case 3:
                // transpose matrix A
                transposeMatrix(rowA, colA, matrixA, transposeA, 'A');
                break;
            case 4:
                //transpose matrix B
                transposeMatrix(rowB,  colB, matrixB, transposeB, 'B');
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Enter again...");
        }
   }while (choice != 5);
}

//input matrix function
void matrix(int arr[MAXROWS][MAXCOLS], int *row, int *col, char matrixName){ 
    do{    
        // loop to enter number of rows and columns
        printf("Enter dimensions for  Matrix %c: ", matrixName);
        scanf("%d %d", row, col);
        if(*row > MAXROWS || *col > MAXCOLS){
            printf("Exceeded matrix dimensions");
        }
    } while (*row > MAXROWS || *col > MAXCOLS);

    //loop to enter elements in each position in the matrix
    printf("Enter elements for Matrix %c\n", matrixName);
    for (int i=0; i < *row; ++i){
        for (int j=0; j < *col; ++j){
            printf("Element[%d][%d]: ", i + 1, j + 1);
            scanf("%d",  &arr[i][j]);
        }
    }
}


//function to add matrices
void addMatrices(int row, int col, int matrixA[MAXROWS][MAXCOLS], int matrixB[MAXROWS][MAXCOLS]){
    printf("Result of Matrix A + Matrix B:\n ");
    int addMatrix[MAXROWS][MAXCOLS];

    //loop to add and display
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            addMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", addMatrix[i][j]);    
        }
        printf("\n");
    }


}

//function to subtract matrices
void subMatrices(int row, int col, int matrixA[MAXROWS][MAXCOLS], int matrixB[MAXROWS][MAXCOLS]) {
    printf("Result of Matrix A - Matrix B:\n");
    int subMatrix[MAXROWS][MAXCOLS];

    //loop to subtract and display
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            subMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
            printf("%d ", subMatrix[i][j]);
        }
        printf("\n");
    }
}


void transposeMatrix(int row, int col, int matrix[MAXROWS][MAXCOLS], int transpose[MAXROWS][MAXCOLS], char matrixName){
    printf("Transpose of Matrix %c:\n", matrixName);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
        transpose[j][i] = matrix[i][j];
    }

    for (int i=0; i<row; i++){
        for (int  j=0; j<col; j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }


}

