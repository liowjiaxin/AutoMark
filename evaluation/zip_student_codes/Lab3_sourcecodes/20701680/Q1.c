#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 10
//function to transpose a matrix
void transpose(int arr[][MAX_SIZE], int r, int c) {
    int trans[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            trans[j][i] = arr[i][j];
        }
    
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j) {
            printf("%d ", trans[i][j]);
            if (j == r - 1) {
                printf("\n");
            }
        }
}
//function to add 2 matrices
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int r, int c) {
    int sum[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
        }
   
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            printf("%d ", sum[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
        }
}
//function to subtract matrices
void sub(int a[][MAX_SIZE], int b[][MAX_SIZE], int r, int c) {
    int sum[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            sum[i][j] = a[i][j] - b[i][j];
        }
   
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            printf("%d ", sum[i][j]);
            if (j == c - 1) {
                printf("\n");
            }
        }
}

int main() {
    int choice;
    int rows, columns, rows1, columns1;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];
    //enter dimension for matrix A
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rows, &columns);
    while (rows > MAX_SIZE || columns > MAX_SIZE) {
        printf("Please enter less than or equal to 10  rows and columns\n");    // loop until less that 10 rows and columns are input
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rows, &columns);
    }
   // element for matrix a
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rows; ++i)
          for (int j = 0; j < columns; ++j) {
      printf("Element[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &A[i][j]);
        }
  // dimensions for matrix b
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rows1, &columns1);
    while (rows1 > MAX_SIZE || columns1 > MAX_SIZE) {                        // loop until less than 10 rows and columns are input
        printf("Please enter less than or equal to %d rows and columns\n", MAX_SIZE);
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rows1, &columns1);
    }

    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rows1; ++i)
        for (int j = 0; j < columns1; ++j) {
            printf("Element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
   // menu
    while (1) {    //loops until exit
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);;
        getchar();// Consume the newline character
  
        
        
        switch (choice) {
            case 1:
                if (rows == rows1 && columns == columns1) {
                    printf("Result of Matrix A + Matrix B:\n");
                    add(A, B, rows, columns);
                } else {
                    printf("Error: Matrices are not of the same size.\n");// for addition matrices have to be the same
                }
              break ;
           case 2 :
              if (rows == rows1 && columns == columns1) {
                    printf("Result of Matrix A - Matrix B:\n");
                    sub(A, B, rows, columns);
                } else {
                    printf("Error: Matrices are not of the same size.\n"); // for subtraction matrices have to be the same
                }
         
              break;
          case 3:
              printf("\n Transpose  of Matrix A\n");       //transpose function
             transpose(A,rows , columns);
             break;
          case 4:
             printf("\nTranspose of Matrix B\n");
             transpose(B,rows1, columns1);
              break;
         case 5 : 
             printf("Exiting......");
             return 0 ;   //exit program if 5 is entered
              break ;
         default :
              puts("Please enter a choice between 1 and 5");
              break ;





        }
 }
 

    return 0 ;
}