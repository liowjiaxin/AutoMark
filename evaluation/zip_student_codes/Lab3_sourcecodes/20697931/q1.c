#include <stdio.h>
#define MAXROW 10
#define MAXCOL 10


void PrintMatrix(int row, int column,int matrix[row][column]){
    
    for (int i =0; i<row; i++){
        for (int j=0; j<column;j++){
    
            printf("%d ",matrix[i][j]);
        }
        
        printf("\n");
    
    }
}

int  Add_Matrices(int matrixA[10][10],int matrixB[10][10],int row,int column){
        int sum=0;
        int add_matrix[row][column];

    
        for (int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                sum =matrixA[i][j] + matrixB[i][j];
                add_matrix[i][j]=sum;
            }
        }
        PrintMatrix(row, column,add_matrix);
        
    }
    
int  Sub_Matrices(int matrixA[10][10],int matrixB[10][10],int row,int column){
        int sum=0;
        int add_matrix[row][column];

    
        for (int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                sum =matrixA[i][j] + matrixB[i][j];
                add_matrix[i][j]=sum;
            }
        }
        PrintMatrix(row, column,add_matrix);
        
    }
    
    
    





void Transpose(int matrix[10][10],int row,int column){
    int transpose_matrix[row][column] ;
    for (int i =0; i< column;i++){
        for (int j=0; j < row; j++){
            transpose_matrix[j][i]=matrix[i][j];
        }   
    }
    PrintMatrix(row, column,transpose_matrix);

}



void main(){
    int rowA=0;
    int columnA=0;
    int rowB=0;
    int columnB=0;
    int matrixA[10][10]={0,0};
    int matrixB[10][10]={0,0};
    printf("\nEnter dimensions for Matrix A(rows and columns):");
    scanf("%d %d",&rowA,&columnA);

    printf("Enter elements for Matrix A:\n");
    for (int i=0;i<rowA;i++){
        for (int j=0;j<columnA;j++){
            printf("Element [%d][%d]:",i+1,j+1);
            scanf("%d",&matrixA[i][j]);
        
        }
    }

    printf("Enter dimensions for Matrix B(rows and columns):");
    scanf("%d %d",&rowB,&columnB);

    printf("Enter elements for Matrix B:\n");
    for (int i=0;i<rowB;i++){
        for (int j=0;j<columnB;j++){
            printf("Element [%d][%d]:",i+1,j+1);
            scanf("%d",&matrixB[i][j]);
        
        }
    }

    int choice=0;

    while(1){
        printf("\nMatrix Operations Menu:");
        printf("1.Add Matrices\n");
        printf("2.Subtract Matrices\n");
        printf("3.Transpose Matrix A\n");
        printf("4.Transpose Matrix B\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        //validation
        while(choice <1 || choice >5){
            printf("\nInvalid choice");
            printf("\nEnter your choice:");
            scanf("%d",&choice);
        }

        //exit
        if (choice == 5){
            break;
        }

        switch (choice)
        {
        //Addition
        case 1:
            printf("Result of Matrix A + Matrix B:\n");
            if ((rowA == rowB) && (columnA == columnB)){
                Sub_Matrices(matrixA,matrixB,rowA,columnA);
                
            }
            else{
                printf("\nAddition cant be done");

            }
            
            
            break;
        //Subtraction
        case 2:
            printf("Result of Matrix A - Matrix B:\n");
            if ((rowA == rowB) && (columnA == columnB)){
                Sub_Matrices(matrixA,matrixB,rowA,columnA);
        
            }
            else{
                printf("\nSubtraction cant be done");

            }
            
            
            break;


        //Transpose A
        case 3:
            printf("Transpose of Matrix A:\n");
            Transpose(matrixA,rowA,columnA);
            break;
        
        //Transpose B
        case 4:
            printf("Transpose of Matrix B:\n");
            Transpose(matrixB,rowB,columnB);
            break;
        

        
        }

    }
    


}
