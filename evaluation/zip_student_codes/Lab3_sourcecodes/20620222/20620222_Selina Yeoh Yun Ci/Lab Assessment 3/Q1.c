#include <stdio.h>
#define MAX 10

void add(int rowA, int rowB, int colA, int colB, int arrA[rowA][colA], int arrB[rowB][colB]);
void subtract(int rowA, int rowB, int colA, int colB, int arrA[rowA][colA], int arrB[rowB][colB]);
void remove_whitespaces();
void transposeA(int rowA, int colA, int arrA[rowA][colA]);
void transposeB(int rowB, int colB, int arrB[rowB][colB]);

//Variables
int rowA, colA, rowB, colB;
int i, j;
int a[MAX][MAX], transpose[MAX][MAX];

int main(){
    char choice;
    puts("***************************************************************");
    puts("                            Matrix");
    puts("***************************************************************");

    //Matrix A
    printf("Enter number of rows for Matrix A: ");
    scanf("%d" ,&rowA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d" ,&colA);

    //Matrix B
    printf("\nEnter number of rows for Matrix B: ");
    scanf("%d" ,&rowB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d" ,&colB);

    //Check the possibility of matrix addition
    if (rowA != rowB || colA != colB) {
        printf("Matrix addition is not possible because matrix sizes don't match.\n");
        return 0;
    }

    //Matrix cannot exceed size 10x10
    if (rowA>10 || rowB>10 || colA>10 || colB>10){
        printf("Number of rows and columns cannot exceed 10x10.");
        return 0;
    }

    int arrA[rowA][colA], arrB[rowB][colB], result[rowA][colA];

    //Elements for Matrix A
    printf("\nPlease enter element in the matrix A:\n");
    for(i=0; i<rowA; i++){
        for(j=0; j<colA; j++){
            printf("Element [%d],[%d]: ",i,j);
            scanf("%d", &arrA[i][j]);
        }
    }

    //Elements of Matrix B
    printf("\nPlease enter element in matrix B:\n");
    for(i=0; i<rowB; i++){
        for(j=0; j<colB; j++){
            printf("Element [%d],[%d]: ",i,j);
            scanf("%d", &arrB[i][j]);
        }
    }

    //Display A
    printf("\nMatrix A:\n");
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("%d\t", arrA[i][j]);
        }
        printf("\n");
    }

    //Display B
    printf("\nMatrix B:\n");
    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            printf("%d\t", arrB[i][j]);
        }
        printf("\n");
    }

    while(1){
        puts("***************************************************************");
        puts("                            Main Menu");
        puts("***************************************************************");
        puts("                      1.   Add Matrices");
        puts("                      2. Subtract Matrices");
        puts("                      3. Transpose Matrix A");
        puts("                      4. Transpose Matrix B");
        puts("                      5.       Exit");
        puts("***************************************************************");

        printf("Please enter your choice: ");
        scanf(" %c", &choice);
        remove_whitespaces();

        switch(choice){
            case '1':
                add(rowA, colA, rowB, colB, arrA, arrB);
                break;
            case '2':
                subtract(rowA, colA, rowB, colB, arrA, arrB);
                break;
            case '3':
                transposeA(rowA, colA, arrA);
                break;
            case '4':
                transposeB(rowB, colB, arrB);
                break;
            case '5':
                puts("Exiting...");
                return 0;
            default:
                puts("Please enter a number from 1 to 5.");
                break;
        }
    }
    return 0;
}

//Matrix Addition
void add(int rowA, int rowB, int colA, int colB, int arrA[rowA][colA], int arrB[rowB][colB]){
    int result[i][j];
    //Add Matrices
    for(i=0; i<rowA; i++){
        for(j=0; j<colA; j++){
            result[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    //Display A+B
    printf("\nResultant Matrix (A + B):\n");
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

//Matrix Subtraction
void subtract(int rowA, int rowB, int colA, int colB, int arrA[rowA][colA], int arrB[rowB][colB]){
    int result[i][j];
    //Subtract Matrices
    for(i=0; i<rowA; i++){
        for(j=0; j<colA; j++){
            result[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    //Display A-B
    printf("\nResultant Matrix (A - B):\n");
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

//Transpose Matrix A
void transposeA(int rowA, int colA, int arrA[rowA][colA]){
    //Transpose
    for(i=0; i<rowA; ++i){
        for(j=0; j<colA; ++j){
        transpose[j][i] = arrA[i][j];
        }
    }

    //Print Transpose
    printf("\nTranspose of the matrix:\n");
    for(i=0; i<colA; ++i){
        for(j=0; j<rowA; ++j){
        printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
}

//Transpose Matrix B
void transposeB(int rowB, int colB, int arrB[rowB][colB]){
    //Transpose
    for(i=0; i<rowB; ++i){
        for(j=0; j<colB; ++j){
        transpose[j][i] = arrB[i][j];
        }
    }

    //Print Transpose
    printf("\nTranspose of the matrix:\n");
    for(i=0; i<colB; ++i){
        for(j=0; j<rowB; ++j){
        printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
}

//Function to Remove Whitespaces
void remove_whitespaces(){
    int ch;
        while((ch=getchar())!='\n')
            continue;
}