#include <stdio.h>
#define MAX_SIZE 10


// Function to add matrices
int AddMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int total[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            total[i][j] = A[i][j]+B[i][j];
        }
    }
}

// Function to subtract matrices
int SubtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int total[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            total[i][j] = A[i][j]-B[i][j];
        }
    }
}

// Function to transpose matrices A
int TransposeMatricesA(int A[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE],int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[j][i];
        }
    }
}

// Function to transpose matrices B
int TransposeMatricesB(int B[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE],int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = B[j][i];
        }
    }
}




int main() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int total[MAX_SIZE][MAX_SIZE];
    int transposeA[MAX_SIZE][MAX_SIZE], transposeB[MAX_SIZE][MAX_SIZE];
    int rowA, columnA;
    int rowB, columnB;
    int choice;

    
    printf("Enter dimensions for Matrix A (rows and column): ");
    scanf("%d %d", &rowA, &columnA);
    if (rowA > 10 || columnA > 10) {
        printf(" Maximum size is 10x10\n");        //message send to user if row and column is over 10x10
        return 1;
    }
    printf("Enter elements for Matrix A:\n");
     for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < columnA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("Enter dimensions for Matrix B (rows and column): ");
    scanf("%d %d", &rowB, &columnB);
    if (rowB > 10 || columnB > 10) {
        printf("Maximum size is 10x10\n");
        return 1;
    }
    printf("Enter elements for Matrix B:\n");
     for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < columnA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
    
    while(1){
       
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (rowA == rowB && columnA == columnB) {
                    AddMatrices(A, B, total, rowA, columnA);
                    printf("Result of Matrix A + Matrix B:\n");
                    for (int i = 0; i < rowA; i++) {       
                     for (int j = 0; j < columnA; j++) {   
                    printf("%d ", total[i][j]);
                     }
                        printf("\n");
                    }                 
                } else {
                    printf("Invalid matrix dimensions\n");
                }
                break;
            case 2:
                if (rowA == rowB && columnA == columnB) {
                    SubtractMatrices(A, B, total, rowA, columnA);
                    printf("Result of Matrix A - Matrix B:\n");
                    for (int i = 0; i < rowA; i++) {       
                     for (int j = 0; j < columnA; j++) {  
                    printf("%d ", total[i][j]);
                        }
                        printf("\n");
                     }
                } else {
                    printf("Invalid matrix dimensions\n");
                }
                break;
            case 3:
             TransposeMatricesA(A, transposeA, rowA, columnA);
                printf("Transpose of Matrix A:\n");
                for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < columnA; j++) {
                 printf("%d ", total[i][j]);
                }
                printf("\n");
              }
                break;
            case 4:
             TransposeMatricesB(B, transposeB, rowB, columnB);
                printf("Transpose of Matrix B:\n");
                for (int i = 0; i < rowB; i++) {
                for (int j = 0; j < columnB; j++) {
                printf("%d ", total[i][j]);
                }
                printf("\n");
              }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } 

    return 0;
}









