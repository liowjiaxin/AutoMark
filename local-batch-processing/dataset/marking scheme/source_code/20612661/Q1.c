#include <stdio.h>
#include <stdlib.h>

int arrA[10][10] = {0};
int arrB[10][10] = {0};
int rowA, colA, rowB, colB;
void clearInputBuffer();
void readMatrix();
void printOperationMenu();
int checkDimension();
void addMatrices();
void subtractMatrices();
void transposeMatrixA();
void transposeMatrixB();


void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF){}
}

void readMatrix(){


    // Enter value for Matrix A
    do{
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowA, &colA);
    }while(rowA > 10 || colA > 10);
    printf("Enter elements for Matrix A: \n");
    for (int i = 0; i<rowA; i++){
        for(int j = 0; j<colA; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &arrA[i][j]);
            clearInputBuffer();
        }
    }

    // Enter value for Matrix B
    do{
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowB, &colB);
    }while(rowB > 10 || colB > 10);
    printf("Enter elements for Matrix B: \n");
    for (int i = 0; i<rowB; i++){
        for(int j = 0; j<colB; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &arrB[i][j]);
            clearInputBuffer();
        }
    }
}

void printOperationMenu(){
    puts("Matrix Operations Menu: ");
    puts("1. Add Matrices");
    puts("2. Subtract Matrices");
    puts("3. Transpose Matrix A");
    puts("4. Transpose Matrix B");
    puts("5. Exit");
    printf("Enter Your Choice: ");
}

int checkDimension(){
    //printf("check: %d\n\n", (rowA == rowB) && (colA == colB));
    return ((rowA == rowB) && (colA == colB));
}

void addMatrices(){
    //Check dimension is similar
    if(checkDimension() == 0){
        puts("The matrix dimension are not similar, addition unable to occur.");
        puts("Return to menu.");
        return;
    }

    //Print result seperately
    printf("Result of Matrix A + Matrix B: \n");
    for (int i = 0; i< rowA; i++ ){
        for (int j = 0; j < colA; j ++){
            printf("%d ", arrA[i][j] + arrB[i][j]);
        }
        printf("\n");
    }
}

void subtractMatrices(){
    //Check dimension is similar
    if(checkDimension() == 0){
        puts("The matrix dimension are not similar, subtraction unable to occur.");
        puts("Return to menu.");
        return;
    }

    //Print result seperately
    printf("Result of Matrix A - Matrix B: \n");
    for (int i = 0; i< rowA; i++ ){
        for (int j = 0; j < colA; j ++){
            printf("%d ", arrA[i][j] - arrB[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrixA(){
    printf("Transpose of Matrix A: \n");
    // Reverse the row and column when reading 
    for (int j = 0; j< colA; j++ ){
        for (int i = 0; i < rowA; i ++){
            printf("%d ", arrA[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrixB(){
    // Reverse the row and column when reading 
    printf("Transpose of Matrix B: \n");
    for (int j = 0; j< colB; j++ ){
        for (int i = 0; i < rowB; i ++){
            printf("%d ", arrB[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int choice = 0;
    readMatrix();
    do{
        printOperationMenu();
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addMatrices();
                break;
            case 2:
                subtractMatrices();
                break;
            case 3:
                transposeMatrixA();
                break;
            case 4:
                transposeMatrixB();
                break;
            case 5:
                puts("Exiting...");
                break;
        }
    }while(choice != 5);
}