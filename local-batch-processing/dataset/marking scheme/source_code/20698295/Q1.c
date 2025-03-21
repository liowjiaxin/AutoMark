#include <stdio.h>
#define MAX 10


//Function to prinr the matrices 
void printmatrice(int matrix[MAX][MAX],int matrows,int matcols){
    for(int i=0;i<matrows;++i){
        for(int j=0; j<matcols; ++j){
            printf("%d  ",matrix[i][j]);
        }
    printf("\n");
    }
}

//function for making the matrices
void creatematrix(int matrx[MAX][MAX],int matrows, int matcols){
    for(int i=0;i<matrows;++i){
        for(int j=0; j<matcols; ++j){
            printf("Element [%d][%d]: ", i+1,j+1);
            scanf("%d", &matrx[i][j] );
        }
    }

}

//function to add the 2 matrices
void addmatrice(int matrix1[MAX][MAX],int matrix2[MAX][MAX], int rows,int cols){
    int addedmatrx[MAX][MAX];
    for(int i=0;i<rows;++i){
        for(int j=0; j<cols; ++j){
            addedmatrx[i][j]=matrix1[i][j] + matrix2[i][j];
        }
    }
    printmatrice(addedmatrx,rows,cols);
}

//function for subtracting matrices
void submatrice(int matrix1[MAX][MAX],int matrix2[MAX][MAX], int rows,int cols){
    int submatrix[MAX][MAX];
    for(int i=0;i<rows;++i){
        for(int j=0; j<cols; ++j){
            submatrix[i][j]=matrix1[i][j] - matrix2[i][j];
        }
    }
    printmatrice(submatrix,rows,cols);
}

//function for transposing entered matrice
void transposematrix(int matrix[MAX][MAX],int rows,int cols){
    int transposedmat[MAX][MAX];
    for(int i=0;i<rows;i++){
        for(int j=0; j<cols; j++){
            transposedmat[j][i]=matrix[i][j];
        }
    }
    printmatrice(transposedmat,cols,rows);

}

int main(){

    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int rowsA,columnsA,rowsB,columnsB;
    int choice;
    printf("Enter dimensions for Matrix A (rows and columns): ");
    scanf("%d %d",&rowsA, &columnsA);
    while ((rowsA>10||rowsA<=0)|| (columnsA>10||columnsA<=0)){ //validation of row and column size
        printf("Rows and columns from 1 to 10 only.\n");
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d",&rowsA, &columnsA); //keep asking user for input until size is valid
    }

    printf("Enter Elements for Matrix A:\n");
    creatematrix(matrixA,rowsA, columnsA);  //calling creatematrix for matrix A

    printf("Enter dimensions for Matrix B (rows and columns): ");
    scanf("%d %d",&rowsB, &columnsB);
    while ((rowsB>10||rowsB<=0)|| (columnsB>10||columnsB<=0)){
        printf("Rows and columns from 1 to 10 only.\n");
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d",&rowsB, &columnsB);
    }

    printf("Enter Elements for Matrix B:\n");
    creatematrix(matrixB,rowsB, columnsB);   //calling creatematrix for matrix B

    do{
        //menu
        printf("\nMatrix Operations Menu:\n");
        printf("==========================\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            //addition only when size of matrices are equal
                if (rowsA==rowsB && columnsA==columnsB){
                    printf("Result of Matrix A + Matrix B:\n" );
                    addmatrice(matrixA,matrixB,rowsA,columnsA);
                }else{
                    printf("Matrices must be of equal size for addition.\n");
                }
                break;   
            
            case 2:
                //subtraction only when size of matrices are equal
                if (rowsA==rowsB && columnsA==columnsB){
                    printf("Result of Matrix A - Matrix B:\n" );
                    submatrice(matrixA,matrixB,rowsA,columnsA);
                }else{
                    printf("Matrices must be of equal size for subtraction.\n");
                }
                break;  

            case 3:
                printf("Transpose of Matrix A: \n");
                transposematrix(matrixA,rowsA,columnsA);
                break;

            case 4:
                printf("Transpose of Matrix B: \n");
                transposematrix(matrixB,rowsB,columnsB);
                break;
            
            case 5:
                printf("Exiting...");
                break;

            default:
                //if choice is invalid character
                printf("Invalid Choice: Must be within 1 to 5 only. \n");
        }   
            

            
    //looping menu until user exits
    }while(choice!=5);

    return 0;
}