
#include <stdio.h>
#include <stdlib.h> 

typedef struct matrix{
    int RowCount;
    int ColCount;
    int** values;
} Matrix;


//for clear scanf buffer if smth wrong was entered before
// use before scanf
void clear_scanf_buffer(){
    char c;
    // read until end of input
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

Matrix* input_matrix(char name);   // input matrix dimentions and cells
void malloc_values(Matrix* matrix); // allocates memory for matrix cells
void print_m(Matrix* matrix);   // prints matrix
void input_cell(Matrix* matrix, int row, int col);  // input one cell of matrix
Matrix* add_m(Matrix* A, Matrix* B);    // perform matrix addition
Matrix* sub_m(Matrix* A, Matrix* B);    // perform matrix substraction
Matrix* tr_m(Matrix* matrix);   // perform matrix transposition
void free_m(Matrix* matrix); // free memory of matrix

int menu_func(Matrix* A, Matrix* B, Matrix* C); // menu function to loop in main()



int main(){
    Matrix* A;
    Matrix* B;
    Matrix* C; //result matrix

    A = input_matrix('A');
    //print_m(A); // for debugging

    clear_scanf_buffer();
    printf("\n");

    B = input_matrix('B');
    //print_m(B); // for debugging
    printf("\n\n");

    //menu loop
    int flag = 1; // 1 - continue, 0 - exit
    while (flag) {
        flag = menu_func(A, B, C);
        printf("\n\n");
    }
    
    return 0;
}


// returns 0 if Exit option (to stop the loop in main()) , returns 1 for other options
int menu_func(Matrix* A, Matrix* B, Matrix* C){
    int option;  // option index
    int error;  // error for scanf

    printf("Matrix Operations Menu:\n" \
            "1. Add Matrices\n" \
            "2. Subtract Matrices\n" \
            "3. Transpose Matrix A\n" \
            "4. Transpose Matrix B\n" \
            "5. Exit (Loop back to the menu until the user chooses to exit.\n"
            "Enter your choice: ");

    //scan option
    clear_scanf_buffer();
    error = scanf("%d", &option);

    // error handling and input validation
    while ((error <= 0) || (option > 5 || option < 1)){
        if (error <= 0) printf("Invalid input. Try again.\n");  //input failed error
        else printf("Invalid input. There is no option %d. Try again.\n", option); // input option out of bound
        printf("Enter your choice: ");

        clear_scanf_buffer();
        error = scanf("%d", &option);
    }

    // option processing
    switch (option)
    {
    case 1: // addition
        C = add_m(A, B);

        // if different matrix sizes
        if (C == NULL){ 
            printf("Cannot add. Matrices sizes do not correspond.\nSize(A) = (%d, %d)\nSize(B) = (%d, %d)\n", 
                    A->RowCount, A->ColCount, B->RowCount, B->ColCount);
            return 1;
        }

        // if sizes correspond
        printf("Result of  A + B:\n");
        print_m(C);
        free_m(C);  // free matrix
        return 1;
    case 2: // substraction
        C = sub_m(A, B);

        // if different matrix sizes
        if (C == NULL){
            printf("Cannot substract. Matrices sizes do not correspond.\nSize(A) = (%d, %d)\nSize(B) = (%d, %d)\n", 
                    A->RowCount, A->ColCount, B->RowCount, B->ColCount);
            return 1;
        }

        //if sizes correspond
        printf("Result of A - B:\n");
        print_m(C);
        free_m(C); // free matrix
        return 1;
    case 3: // transpose A
        C = tr_m(A);
        printf("Result of tr(A):\n");
        print_m(C);
        free_m(C);  // free matrix
        return 1;
    case 4: // transpose B
        C = tr_m(B);
        printf("Result of tr(B):\n");
        print_m(C);
        free_m(C);  // free matrix
        return 1;
    case 5: // exit
        return 0;
    default:    // option validation has already been performed before
        perror("Impossible case"); //for debugging
        break;
    }
}



Matrix* input_matrix(char name){

    // name of matrix to be entered (for printf)
    // name can be only 'A' or 'B'
    if (name != 'A' && name != 'B') perror("impossible name"); 

    //memory allocation for matrix struct
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));



    //entering dimentions
    printf("Enter dimentions for matrix %c:\n", name);

    //rows
    printf("Number of Rows: ");

    int error = scanf("%d", &(matrix->RowCount));

    // rows validation and invalid input handling
    while ((error <= 0) || (matrix->RowCount > 10 || matrix->RowCount < 1)){
        if (error <= 0) {// if scanning failed
            printf("Invalid input. Try again.\n");
            printf("Number of Rows: ");
            clear_scanf_buffer();  
        }
        else { // if size is out of bound [1, 10]
            printf("Invalid input. Number of rows must satisfy: 1 < rows < 10. Try again.\n");  
            printf("Number of Columns: ");
        }

        error = scanf("%d", &(matrix->RowCount));
    }

    //columns
    printf("Number of Columns: ");
    clear_scanf_buffer();
    error = scanf("%d", &(matrix->ColCount));

    // columns validation and invalid input handling
    while ((error <= 0) || (matrix->ColCount > 10 || matrix->ColCount < 1)){
        if (error <= 0) {// if scanning failed
            printf("Invalid input. Try again.\n");
            printf("Number of Columns: ");
            clear_scanf_buffer();  
        }
        else { // if size is out of bound [1, 10]
            printf("Invalid input. Number of columns must satisfy: 1 < columns < 10. Try again.\n");  
            printf("Number of Columns: ");
        }

        //scan again
        error = scanf("%d", &(matrix->ColCount));
    }



    // memory allocation for matrix cell values
    malloc_values(matrix);
    
    //input cells
    printf("Enter elements for Matrix %c:\n", name);
    for (int row = 0; row < matrix->RowCount; row++){
        for (int col = 0; col < matrix->ColCount; col++){
            input_cell(matrix, row, col);
        }
    }


    return matrix;
}


// inputs one cell
void input_cell(Matrix* matrix, int row, int col){

    printf("Element [%d][%d]: ", row, col);

    int error; // error for scanf

    // enter cell value
    clear_scanf_buffer();
    error = scanf("%d", &matrix->values[row][col]);

    // invalid input handling
    while (error <= 0){
        printf("Invalid input. Try again.\n");
        printf("Element [%d][%d]: ", row, col);

        clear_scanf_buffer();
        error = scanf("%d", &matrix->values[row][col]);
    }
}


// print matrix
void print_m(Matrix* matrix){
    for (int row = 0; row < matrix->RowCount; row++){
        for (int col = 0; col < matrix->ColCount; col++){
            printf("%d ", matrix->values[row][col]);
        }
        printf("\n");
    }
}


// perform matrix addition
// returns NULL if sizes do not correspond
Matrix* add_m(Matrix* A, Matrix* B){
    //check for same sizes
    if ((A->ColCount != B->ColCount) || (A->RowCount != B->RowCount)) return NULL;

    // memory allocation for matrix struct
    Matrix* C = (Matrix*)malloc(sizeof(Matrix)); // C - result matrix pointer

    // setting size of result matrix
    C->ColCount = A->ColCount;
    C->RowCount = A->RowCount;

    // memory allocation for matrix cell values
    malloc_values(C);

    // summing matrices
    for (int row = 0; row < C->RowCount; row++){
        for (int col = 0; col < C->ColCount; col++){
            C->values[row][col] = A->values[row][col] + B->values[row][col];
        }
    }

    return C;
}



// perform matrix substraction
// returns NULL if sizes do not correspond
Matrix* sub_m(Matrix* A, Matrix* B){
    //check for same sizes
    if ((A->ColCount != B->ColCount) || (A->RowCount != B->RowCount)) return NULL;

    // memory allocation for matrix struct
    Matrix* C = (Matrix*)malloc(sizeof(Matrix));  // C - result matrix pointer

    // setting size of result matrix
    C->ColCount = A->ColCount;
    C->RowCount = A->RowCount;

    // memory allocation for matrix cell values
    malloc_values(C);

    // substracting matrices
    for (int row = 0; row < C->RowCount; row++){
        for (int col = 0; col < C->ColCount; col++){
            C->values[row][col] = A->values[row][col] - B->values[row][col];
        }
    }

    return C;
}


Matrix* tr_m(Matrix* matrix){
    // memory allocation for matrix struct
    Matrix* A = (Matrix*)malloc(sizeof(Matrix));

    // setting size of result matrix
    A->ColCount = matrix->RowCount;
    A->RowCount = matrix->ColCount;

    // memory allocation for matrix cell values
    malloc_values(A);

    for (int row = 0; row < A->RowCount; row++){
        for (int col = 0; col < A->ColCount; col++){
            A->values[row][col] = matrix->values[col][row];
        }
    }

    return A;
}


// memory allocation for matrix values
void malloc_values(Matrix* matrix){
    matrix->values = (int**)malloc(matrix->RowCount * sizeof(size_t));
    for (int row = 0; row < matrix->RowCount; row++){
        matrix->values[row] = (int*)malloc(matrix->ColCount * sizeof(int));
    }
    
}


// free matrix
void free_m(Matrix* matrix){
    for (int i = 0; i < matrix->RowCount; i++){
        free(matrix->values[i]);
    }
    free(matrix);
}