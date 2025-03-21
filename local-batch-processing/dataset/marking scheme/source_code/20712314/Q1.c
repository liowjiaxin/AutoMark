#include <stdio.h>
#include <ctype.h>

//Import libraries and write up function prototypes

void Print(int rows,int columns,int dimensions[rows][columns]);
void Addition(int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]);
void Subtraction(int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]);
void Transpose(int rows,int columns,int dimensions[rows][columns],int choice);
void Operations(int choice,int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]);

//Only one function is needed since all the functions are nested in one another

int main(){

    int rowsA,columnsA,rowsB,columnsB,choice;                          //Declaring variables
    do{                                                               //Repeating the matrix dimension defining process until the input is valid(non zero rows or columns)
        printf("\nEnter dimensions for Matrix A(rows and columns):");
        scanf("%d %d",&rowsA,&columnsA);                              
        while(getchar()!='\n');                                       //Clearing buffer in case user enters  non-digit values
        if(rowsA<1||columnsA<1||rowsA>10||columnsA>10){               //Letting user know the limitation
            printf("\nThe range is from 1 till 10(maximum 10 x 10)\n");
        }
    }while(rowsA<1||columnsA<1||rowsA>10||columnsA>10);
    int dimensionsA[rowsA][columnsA];                                 //Once the input is valid,create a array big enough to place the matrix
    printf("\nEnter elements for Matrix A:\n");                       //Receiving matrix entries
        for(int i=0;i<rowsA;i++){
            for(int j=0;j<columnsA;j++){
                printf("\nElement[%d][%d]:",i+1,j+1);
                scanf("%d",&dimensionsA[i][j]);   
            }
        }
        
    do{                                                                //Same process as matrix A for matrix B
        printf("\nEnter dimensions for Matrix B(rows and columns):");
        scanf("%d %d",&rowsB,&columnsB);
        while(getchar()!='\n');
        if(rowsB<1||columnsB<1||rowsB>10||columnsB>10){
            printf("\nThe range is from 1 till 10(maximum 10 x 10)\n");
        }
    }while(rowsB<1||columnsB<1||rowsB>10||columnsB>10);
    int dimensionsB[rowsB][columnsB];
    printf("\nEnter elements for Matrix B:\n");
    for(int x=0;x<rowsB;x++){
        for(int y=0;y<columnsB;y++){
            printf("\nElement[%d][%d]:",x+1,y+1);
            scanf("%d",&dimensionsB[x][y]);     
        }
    }   

    Operations(choice,rowsA,columnsA,rowsB,columnsB,dimensionsA,dimensionsB); //Placing the Operations function inside the Matrix function

    return 0;
}



//Defining functions

    

void Print(int rows,int columns,int dimensions[rows][columns]){               //A printing function for matrices so the matrix can look as proper as how we would handwrite it
    for(int z=0;z<rows;z++){
        for(int k=0;k<columns;k++){
            printf("%d\t",dimensions[z][k]);                                   //Putting a horizontal tab between entries so they can have enough space between each other
        }
        printf("\n");                                                          //So the rows can be seperated properly
    }
}

void Addition(int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]){     //Addition function
    int rowsC=rowsA;                                                    //Declaring a local array big enough to hold the result of addition
    int columnsC=columnsA;
    int dimensionsC[rowsC][columnsC];
    for(int z=0;z<rowsB;z++){               
        for(int k=0;k<columnsB;k++){
            dimensionsC[z][k]=dimensionsA[z][k]+dimensionsB[z][k];      //Performing addition between entries then placing the values in the "result" matrix
        }
    }
    printf("\nResult of Matrix A + Matrix B:\n");
    Print(rowsC,columnsC,dimensionsC);                                  //Printing the answer using the matrix printing function
}

void Subtraction(int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]){      //Subtraction function
    int rowsC=rowsA;                                                    //Declaring a local array big enough to hold the result of subtraction
    int columnsC=columnsA;
    int dimensionsC[rowsC][columnsC];
    for(int z=0;z<rowsB;z++){
        for(int k=0;k<columnsB;k++){
            dimensionsC[z][k]=dimensionsA[z][k]-dimensionsB[z][k];      //Performing subtraction between entries then placing the values in the "result" matrix
        }
    }
    printf("\nResult of Matrix A - Matrix B:\n");
    Print(rowsC,columnsC,dimensionsC);                                   //Printing the answer using the matrix printing function
}

void Transpose(int rows,int columns,int dimensions[rows][columns],int choice){        //Transpose function
    int rowsC=columns;                              //Declaring a local array big enough to hold the result of the Transposed matrix
    int columnsC=rows;
    int dimensionsC[rowsC][columnsC];               //The transposed matrix will have the row size of the original matrix's column size,and a column size of the ori's row size
    for(int z=0;z<rowsC;z++){
        for(int k=0;k<columnsC;k++){
            dimensionsC[z][k]=dimensions[k][z];     //Eg: The entry on the third row second column of the original matrix will become the entry on the second row third column of the "result" matrix
        }
    }
    if(choice==3){                                  //There are only two possible values of choices,when the value of choice is 3,it's meant for transpose of A,when it's 4(in this case "not 3"),it's for transpose of B
        printf("\nTranspose of Matrix A:\n");
        Print(rowsC,columnsC,dimensionsC);
    }
        else{
            printf("\nTranspose of Matrix B:\n");
            Print(rowsC,columnsC,dimensionsC);
        }
    
}

void Operations(int choice,int rowsA,int columnsA,int rowsB,int columnsB,int dimensionsA[rowsA][columnsA],int dimensionsB[rowsB][columnsB]){    //The function for the collective available operations on matrices
    while(choice!=5){                                                                               //While the user doesn't choose to exit the menu,we will keep repeating the pop up for the operations menu
    printf("\n\nMatrix Operations Menu:\n");                                                        //Printing the operations menu 
    printf("1.Add Matrices\n");
    printf("2.Subtract Matrices\n");
    printf("3.Transpose Matrix A\n");
    printf("4.Transpose Matrix B\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);                                                                             //Receiving the value for the user's choice
    if((choice==1 || choice==2) && (rowsA!=rowsB || columnsA!=columnsB)){                            //To validate whether the two matrices are available for addition or subtraction if the user chooses one of these two options
        printf("\nMatrices must be of same size in order to perform addition or subtraction");
        continue;                                                                                    //To ensure that the operations menu will still pop up after this message,i cannot just "stop" the while loop
    }
            else{
                switch (choice){                                                                     //Using the appropriate functions depending on the user's choice of operation
                    case 1:                                                                           
                        Addition(rowsA,columnsA,rowsB,columnsB,dimensionsA,dimensionsB);             //Entering the necessary parameters for the addition function
                        break;                                                                       //Breaking after each case so the program won't perform matrix operations the user didn't choose
                    case 2:
                        Subtraction(rowsA,columnsA,rowsB,columnsB,dimensionsA,dimensionsB);          //Entering the necessary parameters for the subtraction function
                        break;
                    case 3:
                        Transpose(rowsA,columnsA,dimensionsA,choice);                                //Entering the necessary parameters of matrix  A for the transpose function
                        break;     
                    case 4:
                        Transpose(rowsB,columnsB,dimensionsB,choice);                                //Entering the necessary parameters of matrix  B for the transpose function
                        break;
                    case 5:
                        printf("\nExiting...\n");
                        return;
                    default:
                        printf("\nYou have not entered a valid choice\n");                             //The case where the user has entered a choice that's not one of the 5 available ones                
                        break;
                }
            }
    }
}
    