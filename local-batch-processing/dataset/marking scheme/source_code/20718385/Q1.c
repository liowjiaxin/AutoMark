#include <stdio.h>
#define MAX 10

// Function to add matrices
void addition(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract matrices
void subtraction(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to transpose Matrix A
void transposeA(int matrixA[MAX][MAX], int result[MAX][MAX], int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[j][i] = matrixA[i][j];
        }
    }
}

// Function to transpose Matrix B
void transposeB(int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[j][i] = matrixB[i][j];
        }
    }
}

int main(){
    int rowA, colA, rowB, colB = 0;
    int matrixA[MAX][MAX];
    int matrixB[MAX][MAX];
    int result[MAX][MAX];
    int choice;

    // Prompt user to enter dimensions of Matrix A
    printf("Enter the dimensions for Matrix A (rows and columns): ");
    scanf("%d %d", &rowA, &colA);

    // Validate matrix dimensions
    if (rowA > MAX || colA > MAX) {
        printf("Maximum matrix size is %dx%d\n", MAX, MAX);
        return 1;
    }

    // Prompt user to enter elements for Matrix A
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Prompt user to enter dimensions of Matrix B
    printf("Enter the dimensions for Matrix B (rows and columns): ");
    scanf("%d %d", &rowB, &colB);

    // Validate matrix dimensions
    if (rowB > MAX || colB > MAX) {
        printf("Maximum matrix size is %dx%d\n", MAX, MAX);
        return 1;
    }
   
    // Prompt user to enter elements for Matrix B
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    while(choice != 5) {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            // Addition
            case 1:
                if(rowA == rowB && colA == colB){
                    addition(matrixA, matrixB, result, rowA, colA);
                    printf("Result of Matrix A + Matrix B:\n");
                    for(int i = 0; i < rowA; i++){
                        for(int j = 0; j < colA; j++){
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                }
                else{
                    printf("Matrices can be added if (if and only if) the order of the matrices are equal");
                }
                break;
            // Subtraction
            case 2:
                if(rowA == rowB && colA == colB){
                    subtraction(matrixA, matrixB, result, rowA, colA);
                    printf("Result of Matrix A - Matrix B:\n");
                    for(int i = 0; i < rowA; i++){
                        for(int j = 0; j < colA; j++){
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                }
                else{
                    printf("Matrices can be added if (if and only if) the order of the matrices are equal");
                }
                break;
            // Transpose Matrix A
            case 3:
                transposeA(matrixA, result, rowA, colA);
                printf("Transpose of Matrix A:\n");
                for(int i = 0; i < rowA; i++){
                        for(int j = 0; j < colA; j++){
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                break;
            // Transpose Matrix B
            case 4:
                transposeA(matrixB, result, rowB, colB);
                printf("Transpose of Matrix B:\n");
                for(int i = 0; i < rowB; i++){
                        for(int j = 0; j < colB; j++){
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }
                break;
            // Exit
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Enter a valid choice!");
        }

    }
    
    return 0;
}