#include <stdio.h>

#define MAX_SIZE 10

// Declare FUnction Prototypes// 
int inputMatrix();
int displayMatrix();
int additionMatrix();
int subtractMatrix();
int transposeMatrix();


int main(void){
    // Declare variable zone //
    int rowA, rowB, columnA, columnB = 0;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result [MAX_SIZE] [MAX_SIZE];
    int choice = 0;
    
    //Matrix A//
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowA, &columnA);

    // Output for invalid range from 1 to 10 //
    while(rowA < 1 || rowA > 10 || columnA < 1 || columnA > 10){
        printf("Invalid dimension.");
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &columnA);
    }

     // Ask user to enter the elements for matrix //
        printf("Enter elements for Matrix A:\n");
        inputMatrix(rowA, columnA, matrixA);

    //Matrix B//
    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowB, &columnB);

    // Output for invalid range from 1 to 10 //
     while(rowB < 1 || rowB > 10 || columnB < 1 || columnB > 10){
        printf("Invalid dimension.");
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &columnB);
    }

    // Ask user to enter the elements for matrix //
    printf("Enter elements for Matrix B:\n");
    inputMatrix(rowA, rowB, matrixB);

    do{

        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                if (rowA == rowB && columnA == columnB){
                    additionMatrix(rowA, columnA, matrixA, matrixB, result);
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(rowA, columnA, result);
                }
                else{
                    printf("Addition is not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 2:
                if (rowA == rowB && columnA == columnB){
                    subtractMatrix(rowA, columnA, matrixA, matrixB, result);
                    printf("Result of Matrix A - Matrix B:\n");
                    displayMatrix(rowA, columnA, result);
                }
                else{
                    printf("Subtraction is not possible. Matrices must have the same dimensions.\n");
                }
                break;

            case 3:
                transposeMatrix(rowA, columnA, matrixA, result);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(columnA, rowA, result);
                break;

            case 4:
                transposeMatrix(rowB, columnB, matrixB, result);
                printf("\nTranspose of Matrix A:\n");
                displayMatrix(columnB, rowB, result);
                break;

            case 5:
                printf("Exiting program.\n");
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    }while(choice != 5);



}

// FUNCTIONS //
int inputMatrix (int rows, int cols, int mat[MAX_SIZE][MAX_SIZE]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i + 1 , j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

int displayMatrix (int rows, int cols, int mat[MAX_SIZE][MAX_SIZE]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

}

int additionMatrix (int rows, int cols, int a [MAX_SIZE][MAX_SIZE], int b [MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

int subtractMatrix (int rows, int cols, int a [MAX_SIZE][MAX_SIZE], int b [MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

int transposeMatrix(int rows, int cols, int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[j][i] = mat[i][j];
        }
    }
}

