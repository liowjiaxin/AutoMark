
#include <stdio.h>
#define MAX 10

void inputmatrix(int rows,int cols,int matrix[rows][cols],char name){
    printf("Enter elements of Matrix %c (%dx%d):\n",name,rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0; j <cols;j++) {
            printf("Matrix%c[%d][%d]:",name,i,j);
            scanf("%d",&matrix[i][j]);
        }//get matrix from user
    }
}
void printmatrix(int rows,int cols,int matrix[rows][cols]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }//print matrix
        printf("\n");/*when I printed, I noticed that 
        the output only had one column, so I thought, 
        I should probably add a newline when printing*/
    }
}
void addmatrices(int rows,int cols,int A[rows][cols],int B[rows][cols],int result[rows][cols]){
    for(int i=0;i<rows;i++)
        for(int j = 0;j<cols;j++)
            result[i][j]=A[i][j]+B[i][j];
}//this is the addition between matrices
void subtractmatrices(int rows,int cols,int A[rows][cols], int B[rows][cols],int result[rows][cols]){
    for(int i=0;i<rows;i++)
        for(int j=0; j<cols;j++)
            result[i][j]=A[i][j]-B[i][j];
}//this is the subtraction between matrices
void transposematrix(int rows,int cols,int matrix[rows][cols],int transposed[cols][rows]){
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            transposed[j][i]=matrix[i][j];
}//this is the matrix transpose
int main() {
    int rows,cols,choice;
    int A[MAX][MAX],B[MAX][MAX],result[MAX][MAX];

    printf("Enter dimensions of matrices(rows and columns):");
    scanf("%d %d",&rows,&cols);

    inputmatrix(rows,cols,A,'A');
    inputmatrix(rows,cols,B,'B');

    do{
        printf("\nMenu:\n1.Add Matrices\n2.Subtract Matrices\n3.Transpose Matrix A\n4.Transpose Matrix B\n5.Exit\n");
        printf("Choose an option:");
        scanf("%d", &choice);//provide choices

        switch(choice){//specific choices
            case 1:
                addmatrices(rows,cols,A,B,result);
                printf("Result of Addition:\n");
                printmatrix(rows,cols,result);
                break;//add
            case 2:
                subtractmatrices(rows,cols,A,B,result);
                printf("Result of Subtraction:\n");
                printmatrix(rows,cols,result);
                break;//sub
            case 3:
                transposematrix(rows,cols,A,result);
                printf("Transpose of Matrix A:\n");
                printmatrix(cols,rows,result);
                break;//transpose A
            case 4:
                transposematrix(rows,cols,B,result);
                printf("Transpose of Matrix B:\n");
                printmatrix(cols,rows,result);
                break;//transpose B
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice,try again.\n");
        }
    }
    while(choice!= 5);//do while 

    return 0;
}

