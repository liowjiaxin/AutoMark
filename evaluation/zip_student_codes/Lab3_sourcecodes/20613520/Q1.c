#include <stdio.h>
#include <stdlib.h>

#define SIZE 10                 //Maximum numbers of rows and columns

//return input[0] (for just one input), save input in inputArr (for just two input)
int validateInteger(int inputArr[],int min,int max,char * message,int type){    //type same as number of input in one line, 1 or 2
    int input[2] = {0,0};       //default set input with two 0 element
    int pass=0;                 //default set validation fail
    while (1){
        printf("%s",message);
        if (type==1){           //enter one integer
            if (!(scanf(" %d",&input[0]))){
                printf("Input should be an integer.\n");
                while (getchar() != '\n'); //Clear buffer
                continue;       //reenter input
            }
        }else if (type==2){     //enter two integer
            if (!(scanf(" %d %d",&input[0],&input[1]))){
                printf("Both input should be integers.\n");
                while (getchar() != '\n'); //Clear buffer
                continue;       //reenter input
            }
        }
        //check input received
        for (int i=0;i<type;i++){
            if (min==max){      //no min max means no limit for number
                pass = 1;
                continue;       //check next integer
            }
            if (input[i]>=min && input[i]<=max){
                pass = 1;
                continue;       //check next integer
            }else if(input[i]<min){
                printf("Input should not less than %d.\n",min);
                pass = 0;
                break;          //exit check with pass fail
            }else{
                printf("Input should not more than %d.\n",max);
                pass = 0;
                break;          //exit check with pass fail
            }
        }
        if (pass == 1){
            //copy two elements to inputArr
            inputArr[0]=input[0];
            inputArr[1]=input[1];
            return input[0];    //pass validation, return first input integer
        }else{
            continue;           //fail validation, reenter integer(s)
        }
    }
}
//insert elements into matrix
void matrixSetup(int matrix[][SIZE],int row,int col,char ab){
    int inputArr[2];            //default at most two input in the array
    printf("Enter elements for Matrix %c:\n",ab);
    for (int i=0;i<row;i++){    //for rows
        for (int j=0;j<col;j++){//for columns
            char message[50];
            sprintf(message,"Element [%d][%d]: ",i+1,j+1);
            matrix[i][j] = validateInteger(inputArr,0,0,message,1); //once integer is validate, insert element into current index
        }
    }
}
//add or subtract matrix A with matrix B
void addsubMatrices(int matrixA[][SIZE],int matrixB[][SIZE],int inputA[],int inputB[], int add){    //check addition true or not
    //check for same dimension, if not print error
    if (!((inputA[0]==inputB[0])&&(inputA[1]==inputB[1]))){
        if (add){               //for addition fail
            printf("Addition of matrix A and matrix B fails due to different dimensions.\n");
        }else{                  //for subtraction fail
            printf("Subtraction of matrix A and matrix B fails due to different dimensions.\n");
        }
        return;                 //return to main menu
    }
    //display result after addition or subtraction
    //display result for each element one by one
    for (int i=0;i<inputA[0];i++){          //for rows
        for (int j=0;j<inputA[1];j++){      //for element in each row
            if (add){           //for addition
                printf("%d ",matrixA[i][j]+matrixB[i][j]);
            }else{              //for subtraction
                printf("%d ",matrixA[i][j]-matrixB[i][j]);
            }
        }
        printf("\n");           //print new line for each row
    }
}
//transpose matrix
void transMatrix(int matrix[][SIZE],int input[]){
    for (int i=0;i<input[1];i++){           //for initial columns
        for (int j=0;j<input[0];j++){       //for initial rows
            printf("%d ",matrix[j][i]);     //column list as row, row list as column
        }
        printf("\n");                       //new line after all element in each column display in one row
    }
}

//Main
int main(){
    int inputArr[2],inputA[2],inputB[2];            //declare array to store input, while inputA and inputB store number of rows and columns after input
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE];   //declare matrix A and matrix B
    int input;
    
    //Matrix A
    char dimensionA[] = "Enter dimensions for Matrix A (rows and columns): ";
    input = validateInteger(inputA,1,SIZE,dimensionA,2);    //gets number of rows and columns for matrix A
    matrixSetup(matrixA,inputA[0],inputA[1],'A');           //insert elements into rows and columns for matrix A

    //Matrix B
    char dimensionB[] = "Enter dimensions for Matrix B (rows and columns): ";
    input = validateInteger(inputB,1,SIZE,dimensionB,2);    //gets number of rows and columns for matrix B
    matrixSetup(matrixB,inputB[0],inputB[1],'B');           //insert elements into rows and columns for matrix B
    
    //Matrix Operations
    while (1){
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        char menu[] = "Enter your choice:";
        input = validateInteger(inputArr,1,5,menu,1);       //input choice
        switch (input){
            case 1:     //Add matrix A and matrix B
                addsubMatrices(matrixA,matrixB,inputA,inputB,1);
                break;
            case 2:     //Subtract matrix A with matrix B
                addsubMatrices(matrixA,matrixB,inputA,inputB,0);
                break;
            case 3:     //Transpose matrix A
                transMatrix(matrixA,inputA);
                break;
            case 4:     //Transpose matrix B
                transMatrix(matrixB,inputB);
                break;
            case 5:     //Stop matrix operation
                printf("Exiting...\n");
                exit(0);
        }
    }

    return 0;
}