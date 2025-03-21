// Q1

#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int rows;
    int columns;
    int **matrix;
};

struct matrix *mA;
struct matrix *mB;
struct matrix *mC;

int enter_matrix();
int add_matrices();
int sub_matrices();
int trans_mA();
int trans_mB();

int main(){
    mA = (struct matrix *)malloc(sizeof(struct matrix));
    mB = (struct matrix *)malloc(sizeof(struct matrix));
    mC = (struct matrix *)malloc(sizeof(struct matrix));
    
    enter_matrix();
    
    int ans;
    while(1){
        printf("\n\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ans);
        
        switch(ans){
            case 1:
                add_matrices();
                break;
            case 2:
                sub_matrices();
                break;
            case 3:
                trans_mA();
                break;
            case 4:
                trans_mB();
                break;
            case 5:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice. Choose again.");
                break;
        }
    }

    return 0;
}

int enter_matrix(){
    printf("Enter Dimension for Matrix A (rows and columns): ");
    scanf("%d",&mA->rows);
    scanf("%d",&mA->columns);
    
    mA->matrix = (int **)malloc(mA->rows * sizeof(int *));
    for (int i = 0; i < mA->rows; i++) {
        mA->matrix[i] = (int *)malloc(mA->columns * sizeof(int));
    }
    
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < mA->rows; i++) {
        for (int j = 0; j < mA->columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mA->matrix[i][j]);
        }
    }
    
    printf("Enter Dimension for Matrix B (rows and columns): ");
    scanf("%d",&mB->rows);
    scanf("%d",&mB->columns);
    
    mB->matrix = (int **)malloc(mB->rows * sizeof(int *));
    for (int i = 0; i < mB->rows; i++) {
        mB->matrix[i] = (int *)malloc(mB->columns * sizeof(int));
    }
    
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < mB->rows; i++) {
        for (int j = 0; j < mB->columns; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mB->matrix[i][j]);
        }
    }
    
    return 0;
}

int add_matrices(){
    if (mA->rows != mB->rows || mA->columns != mB->columns){
        printf("\nMatrices must be in same size to perform addition.");
        return 0;
    }
    
    mC->rows = mA->rows;
    mC->columns = mA->columns;
    
    mC->matrix = (int **)malloc(mC->rows * sizeof(int *));
    for (int i = 0; i < mC->rows; i++) {
        mC->matrix[i] = (int *)malloc(mC->columns * sizeof(int));
    }
    
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            mC->matrix[i][j] = mA->matrix[i][j] + mB->matrix[i][j];
        }
    }
    
    printf("\nResult of Matrix A + Matrix B:\n");
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            printf("%d ",mC->matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

int sub_matrices(){
    if (mA->rows != mB->rows || mA->columns != mB->columns){
        printf("\nMatrices must be in same size to perform subtraction.");
        return 0;
    }
    
    mC->rows = mA->rows;
    mC->columns = mA->columns;
    
    mC->matrix = (int **)malloc(mC->rows * sizeof(int *));
    for (int i = 0; i < mC->rows; i++) {
        mC->matrix[i] = (int *)malloc(mC->columns * sizeof(int));
    }
    
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            mC->matrix[i][j] = mA->matrix[i][j] - mB->matrix[i][j];
        }
    }
    
    printf("\nResult of Matrix A - Matrix B:\n");
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            printf("%d ",mC->matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

int trans_mA(){
    mC->rows = mA->columns;
    mC->columns = mA->rows;
    
    mC->matrix = (int **)malloc(mC->rows * sizeof(int *));
    for (int i = 0; i < mC->rows; i++) {
        mC->matrix[i] = (int *)malloc(mC->columns * sizeof(int));
    }
    
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            mC->matrix[i][j] = mA->matrix[j][i];
        }
    }
    
    printf("\nTranspose of Matrix A:\n");
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            printf("%d ",mC->matrix[i][j]);
        }
        printf("\n");
    }
    
}

int trans_mB(){
    mC->rows = mB->columns;
    mC->columns = mB->rows;
    
    mC->matrix = (int **)malloc(mC->rows * sizeof(int *));
    for (int i = 0; i < mC->rows; i++) {
        mC->matrix[i] = (int *)malloc(mC->columns * sizeof(int));
    }
    
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            mC->matrix[i][j] = mB->matrix[j][i];
        }
    }
    
    printf("\nTranspose of Matrix B:\n");
    for (int i = 0; i < mC->rows; i++) {
        for (int j = 0; j < mC->columns; j++) {
            printf("%d ",mC->matrix[i][j]);
        }
        printf("\n");
    }
}
