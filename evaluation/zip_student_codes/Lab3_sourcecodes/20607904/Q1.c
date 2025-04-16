#include <stdio.h>
#include <stdlib.h>


void print_matrix(int row, int col, int matrix[][col]) {
    int element;
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void matrix_addition(int row, int col, int matrix_A[][col], int matrix_B[][col]) {
    int added_matrix[row][col];
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++){
            added_matrix[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    printf("Result of Matrix A + Matrix B:\n");
    print_matrix(row, col, added_matrix);
}

void matrix_subtraction(int row, int col, int matrix_A[][col], int matrix_B[][col]) {
    int subtracted_matrix[row][col];
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++){
            subtracted_matrix[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }
    printf("Result of Matrix A - Matrix B:\n");
    print_matrix(row, col, subtracted_matrix);
}

void matrix_transposition(int row, int col, int matrix[][col], char mat) {
    int transposed_matrix[col][row];
    for(int i = 0; i<col; i++) {
        for(int j = 0; j<row; j++){
            transposed_matrix[i][j] = matrix[j][i];
        }
    }
    printf("Transpose of Matrix %c:\n", mat);
    print_matrix(col, row, transposed_matrix);
}


void add_elements_to_matrix(int matrix_max_i, int matrix_max_j, int matrix[][matrix_max_j]) {
    int element;
    for(int row = 0; row<matrix_max_i; row++) {
        for(int col = 0; col<matrix_max_j; col++) {
            printf("Element [%d][%d]: ", row+1, col+1);
            scanf("%d", &element);
            matrix[row][col] = element;
        }
    }
}

int main(void) {
    int function;
    int matrix_max_i, matrix_max_j;
    //matrix A initialisation
    int first_time = 1;
    printf("Enter the dimensions for Matrix A (rows and columns): ");
    do
    {
        if (first_time = 0) {
            printf("Error, maximum size is 10 by 10 matrix. Please try again.\n");
        }
        scanf("%d %d", &matrix_max_i, &matrix_max_j);
        first_time = 0;
    } while (matrix_max_i > 10 || matrix_max_j > 10);

    int matrix_A[matrix_max_i][matrix_max_j];
    int row_A = matrix_max_i, col_A = matrix_max_j;
    add_elements_to_matrix(matrix_max_i, matrix_max_j, matrix_A);

    // matrix B initialisation
    first_time = 1;
    printf("Enter the dimensions for Matrix B (rows and columns): ");
    do
    {
        if (first_time = 0) {
            printf("Error, maximum size is 10 by 10 matrix. Please try again.\n");
        }
        scanf("%d %d", &matrix_max_i, &matrix_max_j);
        first_time = 0;
    } while (matrix_max_i > 10 || matrix_max_j > 10);

    int matrix_B[matrix_max_i][matrix_max_j];
    int row_B = matrix_max_i, col_B = matrix_max_j;
    add_elements_to_matrix(matrix_max_i, matrix_max_j, matrix_B);
    
    //operations loop
    while(1) {
        printf("Matrix Operations Menu:\n1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &function);

        switch (function)
            {
            case 1: //Add matrices
                if(row_A != row_B || col_A != col_B) {
                    printf("Error, the 2 matrix are not the same size\n");
                    break;
                }
                matrix_addition(row_A, col_A, matrix_A, matrix_B);
                break;
            
            case 2: //Subtract matrices
                if(row_A != row_B || col_A != col_B) {
                    printf("Error, the 2 matrix are not the same size\n");
                    break;
                }
                matrix_subtraction(row_A, col_A, matrix_A, matrix_B);
                break;

            case 3: //Transpose matrix A
                matrix_transposition(row_A, col_A, matrix_A, 'A');
                break;
            
            case 4: //Transpose matrix B
                matrix_transposition(row_B, col_B, matrix_B, 'B');
                break;

            case 5: //Exit
            printf("Exiting...");
                exit(1);

            default:
            printf("Invalid choice, please try again\n");
                break;
            }
    }
    

    return 0;
}