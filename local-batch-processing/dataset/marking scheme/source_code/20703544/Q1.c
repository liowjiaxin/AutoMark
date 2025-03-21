#include <stdio.h>

void addMatrix(int matrix1[10][10], int matrix2[10][10], int row1, int column1);
void subMatrix(int matrix1[10][10], int matrix2[10][10], int row1, int column1);
void tranMatrix(int matrix1[10][10], int row1, int column1);
int main()
{   
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int matrixA[10][10];
    int matrixB[10][10];
    int choice = 0;
    printf("Enter the dimensions of Matrix A (rows and columns): ");
    scanf("%d %d", &i, &j);
    while(1) {
    if((i>0 && i<=10) && (j>0 && j<=10)) {
    printf("Enter the elements of Matrix A: \n");
    for(int a = 0; a < i; a++) {
        for(int b = 0; b < j; b++){
            printf("Element[%d][%d]: ", a+1, b+1);
            scanf("%d", &matrixA[a][b]);
            }
        }
        break;
    } else {
        printf("The maximum dimensions for this matrix is 10 x 10\n");
        printf("Re-enter the rows and columns: ");
        scanf("%d %d", &i, &j);
        }
    }
    printf("Enter the dimensions of Matrix B (rows and columns): ");
    scanf("%d %d", &m, &n);
    while(1) {
    if((m>0 && m<=10) && (n>0 && n<=10)) {
    printf("Enter the elements of Matrix B: \n");
    for(int a = 0; a < m; a++) {
        for(int b = 0; b < n; b++){
            printf("Element[%d][%d]: ", a+1, b+1);
            scanf("%d", &matrixB[a][b]);
        }
      }
      break;
    } else {
        printf("The maximum dimensions for this matrix is 10 x 10\n");
        printf("Re-enter the rows and columns: ");
        scanf("%d %d", &m, &n);
        }
    }
    while(choice != 5) {
    printf("\nMatrix Operations Menu: \n");
    printf("1. Adds Matrices\n");
    printf("2. Subtracts Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1 : 
        if((i==m) && (j==n)) {
        addMatrix(matrixA, matrixB, i, j);
        } else {
            printf("Matrices with different dimensions cannot be added.\n");
            printf("Please try again by exit and restart the program.\n");
        }
        break;
        case 2:if((i==m) && (j==n)) {
        subMatrix(matrixA, matrixB, i, j);
        } else {
            printf("Matrices with different dimensions cannot be subtracted.\n");
            printf("Please try again by exit and restart the program.\n");
        }
        break;
        case 3:
        tranMatrix(matrixA, i, j);
        break;
        case 4:
        tranMatrix(matrixB, m, n);
        break;
        case 5:
        break;
        default:
        printf("Your choice is undefinded. Please try again.\n");
        break;
    }
    }
    
    return 0;
}

void addMatrix(int matrix1[10][10], int matrix2[10][10], int row1, int column1) {
         int matrix[10][10];
        // Add the matrices
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                matrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        // Print the matrix
        printf("The result of the added matrix:\n");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                printf("%d ", matrix[i][j]);
            }
            puts("");
        }
    
}
void subMatrix(int matrix1[10][10], int matrix2[10][10], int row1, int column1) {
         int matrix[10][10];
        // Add the matrices
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                matrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        // Print the matrix
        printf("The result of the added matrix:\n");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                printf("%d ", matrix[i][j]);
            }
            puts("");
        }
    
}

void tranMatrix(int matrix1[10][10], int row1, int column1) {
    int matrix[10][10] = {0};
    //revert matrix1 and assign to temporary matrix
    for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                matrix[j][i] = matrix1[i][j];
            }
        }
    //copy temp matrix back to original matrix
    for (int i = 0; i < column1; i++) {
            for (int j = 0; j < row1; j++) {
                matrix1[i][j] = matrix[i][j];
            }
        }
    // Print the matrix
        printf("The result of the transposed matrix:\n");
        for (int i = 0; i < column1; i++) {
            for (int j = 0; j < row1; j++) {
                printf("%d ", matrix1[j][i]);
            }
            puts("");
        }
}
