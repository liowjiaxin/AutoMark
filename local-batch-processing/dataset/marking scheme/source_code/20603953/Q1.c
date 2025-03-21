#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10

// FUnction prototypes
int add_matrix(int a[MAX_ROW][MAX_COL], int b[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]);
int subtract_matrix(int a[MAX_ROW][MAX_COL], int b[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]);
int transpose_matrix(int matrix[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]);

int main(){
    // initialise variables
    int rowA=0; 
    int colA=0;
    int rowB=0;
    int colB=0;
    
    int matrixA[MAX_ROW][MAX_COL];
    int matrixB[MAX_ROW][MAX_COL];
    int result_matrix[MAX_ROW][MAX_COL];

    // while user inputs for row or col exceed 10(invalid), it'll keep looping until user enters a valid input
    while(1){

        printf("Enter dimensions for Matrix A (rows & columns): ");
        scanf("%d %d", &rowA, &colA);

        if (rowA >= 10 || colA >= 10){
            puts("Error. Matrix dimension size must be not more than 10.\n");
        }
        else{
            break;
        }   
    }
    puts("Enter elements for Matrix A:");
    // allocate elements into array
    for (int i=0; i<rowA; i++){
        for(int j=0; j<colA; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // while user inputs for row & col exceed 10(invalid), it'll keep looping until user enters a valid input
    while (1){
        printf("Enter dimensions for Matrix B (rows & columns): ");
        scanf("%d %d", &rowB, &colB);
        
        if (rowB >= 10 || colB >= 10){
            puts("Error. Matrix dimension size must be not more than 10.\n");
        }
        else{
            break;
        }
    }
    puts("Enter elements for Matrix B:");
    // allocate elements into array
    for (int i=0; i<rowB; i++){
        for(int j=0; j<colB; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    while(1){
        char choice;
        // menu
        puts("\n");
        puts("Matrix Operations Menu:");
        puts("1. Add Matrices");
        puts("2. Subtract Matrices");
        puts("3. Transpose Matrix A");
        puts("4. Transpose Matrix B");
        puts("5. Exit");

        printf("Enter your choice: ");
        scanf(" %c", &choice);
        // uses %c instead of %d to prevent error if user enters characters/string, space before %c to prevent newline being read as 2nd choice

        switch (choice){
        case '1':
        // only identical size/dimensions array can do addition
            if (rowA != rowB || colA != colB){
                printf("Error. Matrices must have identical dimensions.\n");
                break;
            }
            else{
                add_matrix(matrixA, matrixB, rowA, colA, result_matrix);   
            }
            break;
        case '2':
        // only identical size/dimensions array can do subtraction
            if (rowA != rowB || colA != colB){
                printf("Error. Matrices must have identical dimensions.\n");
            }
            else{
                subtract_matrix(matrixA, matrixB, rowA, colA, result_matrix);   
            }
            break;
        case '3':
            puts("Transpose of Matrix A:");
            transpose_matrix(matrixA, rowA, colA, result_matrix);
            break;
        case '4':
            puts("Transpose of Matrix B:");
            transpose_matrix(matrixB, rowB, colB, result_matrix);
            break;
        case '5':
            printf("Exiting...");
            return 0;
        default:
            printf("Error. Pls enter available choice(1-5).");
            break;
        }
    }
    return 0;
}

// Functions 
int add_matrix(int a[MAX_ROW][MAX_COL], int b[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]){
    // Matrix A + Matrix B
    for(int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    // print results
    puts("Result of Matrix A + Matrix B:");
    for(int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int subtract_matrix(int a[MAX_ROW][MAX_COL], int b[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]){
    // Matrix A - Matrix B
    for(int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    // print results
    puts("Result of Matrix A - Matrix B:");
    for(int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// swap values of row & cols
int transpose_matrix(int matrix[MAX_ROW][MAX_COL], int row, int col, int result[MAX_ROW][MAX_COL]){
    for(int i=0; i < row; i++){
        for (int j=0; j < col; j++){
            result[j][i]=matrix[i][j];
        }
        /*
        exp: 
            [0] [1] [2]
        [0]  1   2   3
        [1]  4   5   6

        when i=0, j=2
        result[2][0] = matrix[0][2] = 3

        result =    [0] [1] [2]
                 [0]    
                 [1]
                 [2] 3    
        
        when i=1, j=0
        result[0][1] = matrix[1][0] = 4
        
        result =    [0] [1] [2]
                 [0]     4
                 [1]
                 [2] 3   
                 .
                 :
        final result =      [0] [1] [2]
                        [0]  1   4
                        [1]  2   5
                        [2]  3   6
        */
    }
    // print transposed matrix
    for(int i=0; i < col; i++){
        for (int j=0; j < row; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}