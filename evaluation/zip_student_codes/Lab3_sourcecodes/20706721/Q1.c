#include<stdio.h>


#define MAX_SIZE 10

int matrixA[MAX_SIZE][MAX_SIZE],matrixB[MAX_SIZE][MAX_SIZE],matrixtemp[MAX_SIZE][MAX_SIZE];
int dmsAx,dmsAy,dmsBx,dmsBy;

int n=1;

void initalMatrices();
void AddMatrices();// 1.AddMatrices
void SubtractMatrices();// 2. Subtract Matrices
void TransposeMatrixA();// 3. Transpose Matrix A
void TransposeMatrixB();// 4. Transpose Matrix B
void Exit();// 5. Exit (Loop back to the menu until the user chooses to exit.)
void menu();


int main(){


    int x,y,menuid;

    //
    initalMatrices();


//do loop until user select exit

    while(n){


        //output the menu
        menu();
        scanf("%d",&menuid);
    

        switch (menuid)
        {
        case 1:
            /* code */
            AddMatrices();
            break;
        case 2:
            SubtractMatrices();
            break;
        case 3:
            TransposeMatrixA();
            break;
        case 4:
            TransposeMatrixB();
            break;
        case 5:
            Exit();
            break;
        
        default:
            menu();
            break;
        }
    }
    return 0;

}

void menu(){
    printf("Please choose the menu number:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Transpose Matrix A\n");
    printf("4. Transpose Matrix B\n");
    printf("5. Exit\n");

}



/**
 * @brief 
 * The program should allow the user to input
 * • the dimensions (number of rows and columns) of two matrices A and B (maximum size: 10x10).
 * • the elements of both matrices.
 */
void initalMatrices(){

    

    int flag =1;
    //get Matrix A's x and y 
    while(flag){

        //get row and column for matrix A
        printf("Enter dimensions for Matrix A(rows and columns <=10):");
        scanf("%d %d",&dmsAx,&dmsAy);       

        printf("dmsAx: %d dmsAy: %d:\n",dmsAx,dmsAy);

        if(dmsAx>10||dmsAx<=0 || dmsAy>10||dmsAy<=0){
            printf("dimensions must be >=1 and <=10:");
        }else{

            printf("enter elements for Matrix A:\n");

            //get elements one by one
            int i=0;
            for(;i<dmsAx;i++){
                int j=0;
                for(;j<dmsAy;j++){
                    printf("Element [ %d , %d ] :",i+1,j+1);
                    scanf("%d",&matrixA[i][j]);
                }
                // printf("i:  %d  ",i);
            }

            flag=0;

        }

    }
    flag=1;
    //get Matrix B's x and y 
    while(flag){

        //get row and column for matrix B
        printf("Enter dimensions for Matrix B(rows and columns <=10):");
        scanf("%d %d",&dmsBx,&dmsBy);        
        if(dmsBx>10||dmsBx<=0 || dmsBy>10||dmsBy<=0){
            printf("dimensions must be >0 and <=10:");
        }else{

            printf("enter elements for Matrix B:\n");

            //get elements one by one
            int i=0;
            for(;i<dmsBx;i++){

                int j=0;
                for(;j<dmsBy;j++){
                    printf("Element [ %d , %d ] :",i+1,j+1);
                    scanf("%d",&matrixB[i][j]);
                }

            }

            flag=0;

        }

    }


}

// 1.AddMatrices
void AddMatrices(){

    //"Determine if the number of rows and columns of two matrices are equal."
    if( dmsAx!=dmsBx||dmsAy!=dmsBy){
        printf("The number of rows and columns of two matrices aren't equal!");
        return;
    }

    printf("Result of Matrix A + Matrix B:\n");
    int i=0;
    for(;i<dmsAx;i++){
        int j=0;
        for(;j<dmsAy;j++){
            printf(" %d ",matrixA[i][j]+matrixB[i][j]);
        }
        printf("\n");
    }

    

}
// 2. Subtract Matrices
void SubtractMatrices(){
    //"Determine if the number of rows and columns of two matrices are equal."
    if( dmsAx!=dmsBx||dmsAy!=dmsBy){
        printf("The number of rows and columns of two matrices aren't equal!");
        return;
    }
    
    printf("Result of Matrix A - Matrix B:\n");
    int i=0;
    for(;i<dmsAx;i++){
        int j=0;
        for(;j<dmsAy;j++){
            printf(" %d ",matrixA[i][j]-matrixB[i][j]);
        }
        printf("\n");
    }
}
/**
 * @brief 
 * Transpose and swap matrix A
 */
void TransposeMatrixA(){

    int i=0,temp;
    printf("Transpose of Matrix A:\n");
    
     for(i=0;i<dmsAx;i++){
        int j=0;
        for(;j<dmsAy;j++){
            printf(" %d ",matrixA[i][j]);
        }
        printf("\n");
    }

    int transposed[dmsAy][dmsAx];
    //Swap the rows and columns of the matrix and store them in a temporary object 
    for (int i = 0; i < dmsAx; i++) {
        for (int j = 0; j < dmsAy; j++) {
            transposed[j][i] = matrixA[i][j];
        }
    }
        
    
    
    //Swap the columns and rows of matrix A
    temp = dmsAy;
    dmsAy=dmsAx;
    dmsAx=temp;

    //Print the swapped matrix A     
    for(i=0;i<dmsAx;i++){
        int j=0;
        for(;j<dmsAy;j++){
            matrixA[i][j]=transposed[i][j];
            printf(" %d ",matrixA[i][j]);
        }
        printf("\n");
    }

}


/**
 * @brief 
 * Transpose and swap matrix B
 */
void TransposeMatrixB(){
    int i=0,temp;
    printf("Transpose of Matrix B:\n");
    
     for(i=0;i<dmsBx;i++){
        int j=0;
        for(;j<dmsBy;j++){
            printf(" %d ",matrixB[i][j]);
        }
        printf("\n");
    }

    int transposed[dmsBy][dmsBx];
    //Swap the rows and columns of the matrix and store them in a temporary object 
    for (int i = 0; i < dmsBx; i++) {
        for (int j = 0; j < dmsBy; j++) {
            transposed[j][i] = matrixB[i][j];
        }
    }
        
    
    
    //Swap the columns and rows of matrix B
    temp = dmsBy;
    dmsBy=dmsBx;
    dmsBx=temp;

    //Print the swapped matrix B     
    for(i=0;i<dmsBx;i++){
        int j=0;
        for(;j<dmsBy;j++){
            matrixB[i][j]=transposed[i][j];
            printf(" %d ",matrixB[i][j]);
        }
        printf("\n");
    }
}


// void TransposeMatrixB();// 4. Transpose Matrix B

// 5. Exit (Loop back to the menu until the user chooses to exit.)
void Exit(){
    n=0;
    

}