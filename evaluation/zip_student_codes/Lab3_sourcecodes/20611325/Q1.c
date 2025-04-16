#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

//Declaration of matrix for global use
int rowsA, colsA, rowsB, colsB = 0;
int matrixA[MAX_ROWS][MAX_COLS];
int matrixB[MAX_ROWS][MAX_COLS];
int final_matrix[MAX_ROWS][MAX_COLS];

//Function prototypes
void insert_matrix(int matrix[MAX_ROWS][MAX_COLS], int row, int col, char matrix_identifier);
void matrix_calculation(int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int row, int col, char operation_symbol);
void matrix_transpose(int matrix[MAX_ROWS][MAX_COLS], int row, int col);
void output_matrix(int matrix[MAX_ROWS][MAX_COLS], int row, int col);

int main(){
    char choice;

    while (1){
        //Matrix A rows and columns
        printf("Enter dimensions for matrix A (rows and columns): ");
        scanf("%d %d", &rowsA, &colsA);

        if (rowsA <= 0 || colsA <= 0 || rowsA > 10 || colsA > 10){ //Check availability of matrix
            printf("Matrix cannot be formed due to invalid dimensions\n");
        } else {
            break;
        }
    }
    insert_matrix(matrixA , rowsA, colsA, 'A');

    while (1){
        //Matrix B rows and columns
        printf("Enter dimensions for matrix B (rows and columns): ");
        scanf("%d %d", &rowsB, &colsB);

        if (rowsB <= 0 || colsB <= 0 || rowsB > 10 || colsB > 10){ //Check availability of matrix
            printf("Matrix cannot be formed due to invalid dimensions\n");
        } else {
            break;
        }
    }
    insert_matrix(matrixB , rowsB, colsB, 'B');

    //Operation Menu
    while (choice != '5'){
        printf("Matrix Operation Menu:\n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);  // Note the space before %c to consume any leftover newline

        //Validation of choice given by user
        if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5'){
            switch (choice){
                case '1':   //Perform addition of matrices
                    if (rowsA != rowsB || colsA != colsB){    //Check whether matrix can be added
                        printf("Matrices cannot be added, because the dimensions do not match\n");
                        break;
                    }
                    matrix_calculation(matrixA, matrixB, rowsA, colsA, '+');
                    printf("Result of Matrix A + Matrix B:\n");
                    output_matrix(final_matrix, rowsA, colsA);
                    break;

                case '2':   //Perform subtraction of matrices
                    if (rowsA != rowsB || colsA != colsB){    //Check whether matrix can be subtracted
                        printf("Matrices cannot be subtracted, because the dimensions do not match\n");
                        break;
                    }
                    matrix_calculation(matrixA, matrixB, rowsA, colsA, '-');
                    printf("Result of Matrix A - Matrix B:\n");
                    output_matrix(final_matrix, rowsA, colsA);
                    break;

                case '3':   //Transpose of matrix A
                    matrix_transpose(matrixA, rowsA, colsA);
                    printf("Transpose of Matrix A:\n");
                    output_matrix(final_matrix, colsA, rowsA);
                    break;

                case '4':   //Transpose of matrix B
                    matrix_transpose(matrixB, rowsB, colsB);
                    printf("Transpose of Matrix B:\n");
                    output_matrix(final_matrix, colsB, rowsB);
                    break;              

                case '5':   //Exit
                    printf("Exiting...");
                    break;  
            }
        } else {   //Not a valid choice
            printf("Invalid choice. Please enter a valid choice: ");
        }
    }

}

//Insertion of elements in matrix
void insert_matrix(int matrix[MAX_ROWS][MAX_COLS], int row, int col, char matrix_identifier){
    printf("Enter elements for matrix %c:\n", matrix_identifier);
    for (int r = 0; r < row; r++){  //Row
        for (int c = 0; c < col; c++){  //Column
            printf("Element [%d][%d]: ", r + 1, c + 1);
            scanf("%d", &matrix[r][c]);
        }
    }
}

//Perform addition or subtraction of matrices
void matrix_calculation(int matrixA[MAX_ROWS][MAX_COLS], int matrixB[MAX_ROWS][MAX_COLS], int row, int col, char operation_symbol){
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            if (operation_symbol == '+'){
                final_matrix[r][c] = matrixA[r][c] + matrixB[r][c];
            } else if (operation_symbol == '-'){
                final_matrix[r][c] = matrixA[r][c] - matrixB[r][c];
            }
        }
    }
}

//Performing transpose of matrix
void matrix_transpose(int matrix[MAX_ROWS][MAX_COLS], int row, int col){
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            final_matrix[c][r] = matrix[r][c];    //Passing values from rows into columns
        }
    }
}

//Printing out finalised matrix
void output_matrix(int matrix[MAX_ROWS][MAX_COLS], int row, int col){
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
}