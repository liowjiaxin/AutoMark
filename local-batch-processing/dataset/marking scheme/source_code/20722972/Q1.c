#include<stdio.h>
#include<stdlib.h>
#define ROW_MAX_SIZE 10
#define COL_MAX_SIZE 10

// function prototypes
void print_menu(void);
void print_matrix(int **matrix, size_t row, size_t col);
int **add_matrix(int **m_a, int **m_b, size_t row_a, size_t col_a, size_t row_b, size_t col_b);
int **subtract_matrix(int **m_a, int **m_b, size_t row_a, size_t col_a, size_t row_b, size_t col_b);
int **transpose_matrix(int **matrix, size_t row, size_t col);
int **alloc_mem(size_t row, size_t col);
void free_mem(int **matrix, size_t row);

// function main begins program execution
int main(void){
    // initialisation 
    int choice=0;
    int row_A, col_A, row_B, col_B;

    // prompt user to input dimensions of matrices A and B
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d%d", &row_A, &col_A);
    while(row_A>ROW_MAX_SIZE || col_A>ROW_MAX_SIZE){ // check if size is valid
        puts("Error: Maximum size allowed is 10 x 10.");
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d%d", &row_A, &col_A);
    }
    int **matrix_A=alloc_mem(row_A, col_A);

    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d%d", &row_B, &col_B);
    while(row_B>COL_MAX_SIZE || col_B>COL_MAX_SIZE){ // check if size is valid
        puts("Error: Maximum size allowed is 10 x 10.");
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d%d", &row_B, &col_B);
    }
    int **matrix_B=alloc_mem(row_B, col_B);

    // prompt user to input matrix elements
    puts("Enter elements for Matrix A:");
    for(int i=0;i<row_A;i++){
        for(int j=0;j<col_A;j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d",&matrix_A[i][j]);
        }
    }
    //print_matrix(matrix_A, row_A, col_A); // for testing

    puts("\nEnter elements for Matrix B:");
    for(int i=0;i<row_B;i++){
        for(int j=0;j<col_B;j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d",&matrix_B[i][j]);
        }
    }
    //print_matrix(matrix_B, row_B, col_B); // for testing

    // perform matrix operations according to user's choice
    do{
        print_menu();
        printf("%s", "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // add matrices
            if(row_A==row_B && col_A==col_B){
                int **result=add_matrix(matrix_A, matrix_B, row_A, col_A, row_B, col_B);
                if(result==NULL){
                    break;
                }
                print_matrix(result, row_A, col_A);
            }else{
                puts("Error: Invalid operation (matrix A and B have different dimensions).");
            }
            
            break;

        case 2: // subtract matrices
        if(row_A==row_B && col_A==col_B){
                int **result=subtract_matrix(matrix_A, matrix_B, row_A, col_A, row_B, col_B);
                if(result==NULL){
                    break;
                }
                print_matrix(result, row_A, col_A);
            }else{
                puts("Error: Invalid operation (matrix A and B have different dimensions).");
            }

            break;

        case 3: // transpose matrix A
            int **transpose_A=transpose_matrix(matrix_A, row_A, col_A);
            if(transpose_A==NULL){
                break;
            }
            print_matrix(transpose_A, col_A, row_A); // row and col invert after transpose
            break;

        case 4: // transpose matrix B
            int **transpose_B=transpose_matrix(matrix_B, row_B, col_B);
            if(transpose_B==NULL){
                break;
            }
            print_matrix(transpose_B, col_B, row_B); // row and col invert after transpose
            break;

        case 5: // exit
            puts("Exiting...");
            break;
        
        default:
            puts("Error: Invalid input.");
            break;
        }

    }while(choice!=5);

    free_mem(matrix_A, row_A);
    free_mem(matrix_B, row_B);
}

// displays matrix operation menu
void print_menu(void){
    puts("\n========== Matrix Operations Menu ==========");
    printf("%10s%s\n","1:","Add Matrices.");
    printf("%10s%s\n","2:","Subtract Matrices.");
    printf("%10s%s\n","3:","Transpose Matrix A.");
    printf("%10s%s\n","4:","Transpose Matrix B.");
    printf("%10s%s\n","5:","Exit.");
    puts("============================================");
}

// displays the matrix in a grid form
void print_matrix(int **matrix, size_t row, size_t col){
    puts("");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%-3d ", matrix[i][j]);
        }
        puts("");
    }
}

// adds two matrices together and returns a pointer to the result
int **add_matrix(int **m_a, int **m_b, size_t row_a, size_t col_a, size_t row_b, size_t col_b){
    int **result=alloc_mem(row_a, col_a);
    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_a;j++){
            result[i][j]=m_a[i][j]+m_b[i][j];
        }
    }
    return result;
}

// subtracts the second matrix from the first and returns a pointer to the result
int **subtract_matrix(int **m_a, int **m_b, size_t row_a, size_t col_a, size_t row_b, size_t col_b){
    int **result=alloc_mem(row_a, col_a);
    for(int i=0;i<row_a;i++){
        for(int j=0;j<col_a;j++){
            result[i][j]=m_a[i][j]-m_b[i][j];
        }
    }
    return result;
}

// transpose the matrix and return a pointer to the result
int **transpose_matrix(int **matrix, size_t row, size_t col){
    int **result=alloc_mem(col, row);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result[j][i]=matrix[i][j];
        }
    }
    return result;
}

// allocate memory for a matrix and return a pointer to the matrix
int **alloc_mem(size_t row, size_t col){
    int **new_matrix=(int **)malloc(row*sizeof(int *));
    if(new_matrix==NULL){
        puts("Error: Unable to allocate memory.");
        return NULL;
    }
    for(int i=0;i<row;i++){
        new_matrix[i]=(int *)malloc(col*sizeof(int));
        if(new_matrix[i]==NULL){
        puts("Error: Unable to allocate memory.");
        return NULL;
    }
    }
    return new_matrix;
}

// free up allocated memory
void free_mem(int **matrix, size_t row){
    for(int i=0; i<row; i++){
        free(matrix[i]);
    }
    free(matrix);
}