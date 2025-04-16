#include <stdio.h>

#define SIZE 10

//Input element fuction
void matrix (int matrix[SIZE][SIZE], int row, int col, char character) {
    printf("Enter elements for Matrix %c: \n" ,character);
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//Addition of matrices function
void add (int A[SIZE][SIZE], int B[SIZE][SIZE], int row, int col) {
    printf("Result of matrix A + Matrix B:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }
}

//Subtraction of matrices function
void subtract (int A[SIZE][SIZE], int B[SIZE][SIZE], int row, int col) {
    printf("Result of matrix A - Matrix B:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", A[i][j] - B[i][j]);
        }
        printf("\n");
    }
}

//Transpose matrix function
void transpose(int matrix[SIZE][SIZE], int row, int col) {
    printf("Transpose of the Matrix:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    //Initialize variable
    int rowA, colA, rowB, colB;
    int matrixA[SIZE][SIZE];
    int matrixB[SIZE][SIZE];
    int choice;
    
    //Input details of matrix A, if not in condition need to input again
    do {
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &colA);
        
        if (rowA>SIZE || colA>SIZE) {
            printf("The maximum of rows and columns of matrix is 10x10. Plaese try again\n");
        }
        
        if (rowA<=0 || colA<=0){
            printf("Number of rows and columns must be greater than 0. Please try again\n");
        }
    } while(rowA>SIZE || colA>SIZE || rowA<=0 || colA<=0);
    
    //Pass data to input element function
    matrix(matrixA, rowA, colA, 'A');
    
    //Input details of matrix B, if not in condition need to input again
    do {
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &colB);
        
        if (rowB>SIZE || colB>SIZE) {
            printf("The maximum of rows and columns of matrix is 10x10. Plaese try again\n");
        }
        
        if (rowB<=0 || colB<=0){
            printf("Number of rows and columns must be greater than 0. Please try again\n");
        }
    } while(rowB>SIZE || colB>SIZE || rowB<=0 || colB<=0);
    
    //Pass data to input element function
    matrix(matrixB, rowB, colB, 'B');
    
    //Ask user to choose from menu, loop until 5 is choosen
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");    
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            
            //Addition
            case 1:
                if(rowA==rowB && colA==colB) {
                    add(matrixA, matrixB, rowA, colA);
                }
                
                else{
                    printf("Error: Dimension of both matrices must be same.\n");
                }
                
                break;
            
            //Subtraction    
            case 2:
                if(rowA==rowB && colA==colB) {
                    subtract(matrixA, matrixB, rowA, colA);
                }
                
                else{
                    printf("Error: Dimension of both matrices must be same.\n");
                }
                
                break;
            
            //Transpose matix A    
            case 3:
                transpose(matrixA, rowA, colA);
                break;
            
            //Transpose matix B    
            case 4:
                transpose(matrixB, rowB, colB);
                break;
            
            //Exit    
            case 5:
                printf("Exiting...\n");
                break;
            
            //Invalip option   
            default:
                printf("Invalid choice. Please try again.\n");
                
        }
    } while(choice != 5);

    return 0;
}