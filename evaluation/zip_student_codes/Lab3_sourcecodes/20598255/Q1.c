#include <stdio.h>
#include <ctype.h> //for vaildating if input is digit 
#include <stdlib.h> //for strtol
#include <string.h.> //for string manipulation 

#define M_SIZE 10 //setting maximum size of 10

//function to ensure matrix is numeric input 
int ValidateInput(){
    char input[100]; //buffer to store user input
    char *endptr; //pointer to track invalid parts of input 
    int value;

    //loop until valid input is given
    while(1){ 
        scanf("%s", input); //read input as string
        value =strtol(input, &endptr,10); //convert input to integer
        
        //check if conversion was successful 
        if (*endptr =='\0'){ 
            return value; //read validated integer
        }else{
            printf("Invalid input! Please enter a numeric value:"); //prompt user to input again
        }
    }
}

//function to inputMatrix 
void inputMatrix(int matrix[M_SIZE][M_SIZE],int rows, int cols){
    //loop through rows
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){ //loop through columns
            printf("Enter element [%d][%d]:", i+1, j+1); //prompt user to input elements
            matrix[i][j] =ValidateInput(); //use validated input for each element
            
        }
        
    }
}

//function to display matrix 
void displayMatrix(int matrix[M_SIZE][M_SIZE], int rows, int cols){
    for (int i=0; i<rows; i++){ //loop through rows
        for(int j=0; j<cols;j++){ //loop through columns
            printf("%d ", matrix[i][j]); //print matrix element

        }
        printf("\n");
    }
}

// function to add two matrices 
void addMatrices(int matrixA[M_SIZE][M_SIZE], int matrixB[M_SIZE][M_SIZE],int result[M_SIZE][M_SIZE],int rows, int cols){
    for (int i= 0; i<rows; i++){ //loop through rows
        for (int j=0; j<cols; j++){ //loop through columns
            result[i][j]= matrixA[i][j] +matrixB[i][j]; //add elements together and saved into results
        }
    }
}

//function to subtract two matrices
void subtractMatrices(int matrixA[M_SIZE][M_SIZE], int matrixB[M_SIZE][M_SIZE],int result[M_SIZE][M_SIZE],int rows, int cols){
    for (int i= 0; i<rows; i++){ //loop through rows
        for (int j=0; j<cols; j++){ //loop through columns
            result[i][j]= matrixA[i][j] - matrixB[i][j]; //subtract and save into result
        }
    }
}

//function to transpose matrix
void transposeMatrix(int matrix[M_SIZE][M_SIZE],int transpose[M_SIZE][M_SIZE],int rows, int cols){
    for (int i=0; i<rows; i++){ //loop through rows
        for (int j=0; j<cols; j++){ //loop through columns
            transpose[j][i]=matrix[i][j]; //transpose matrix
        }
    }
}

int main (){
    int matrixA[M_SIZE][M_SIZE], matrixB[M_SIZE][M_SIZE]; //for matrices A and B
    int result[M_SIZE][M_SIZE]; // result matrix for addition and subtraction
    int rowsA,colsA,rowsB, colsB; //dimensions of matrices A and B 
    int choice; //variable to store user's menu choice
    int transposeA[M_SIZE][M_SIZE], transposeB[M_SIZE][M_SIZE]; //transpose matrices for A and B

    //prompt user for input for matrix A
    printf("Enter the number of rows and columns for matrix A (MAX 10 ROWS AND 10 COLUMNS:)");
    //check if its digit
    rowsA =ValidateInput();
    colsA= ValidateInput();

    //validate dimension for matrix A 
    if (rowsA> M_SIZE || colsA> M_SIZE|| rowsA <= 0|| colsA <=0){ //validation when input is smaller than 0, or bigger than 10 
        printf("Invalid dimensions! Exiting program.\n");
        return -1; 
    }

    printf("Enter the elements of Matrix A : \n");
    inputMatrix(matrixA,rowsA, colsA); //call function for inputting matrix

    //prompt user for input for matrix B 
    printf("Enter the number of rows and columns for matrix B (MAX 10 ROWS AND 10 COLUMNS:)");
    //validate if its digit
    rowsB= ValidateInput();
    colsB= ValidateInput();

    //validate dimensions 
    if (rowsB> M_SIZE || colsB> M_SIZE|| rowsB <= 0|| colsB <=0){ //validation when input is smaller than 0, or bigger than 10 
        printf("Invalid dimensions! Exiting program.\n");
        return -1; 
    }

    //prompt user for input of elements in matrix B 
    printf("Enter the elements of Matrix B : \n");
    inputMatrix(matrixB,rowsB,colsB); //call function to inputmatrix

    //main loop 
    while (1){
        //main menu 
        printf("\n Menu \n");
        printf("1. Add Matrices \n ");
        printf("2. Subtract Matrices \n ");
        printf("3. Transpose Matrice A \n ");
        printf("4. Transpose Matrice B \n ");
        printf("5. Exit\n");
        printf("Enter your choice:\n"); //prompt user for input
        scanf("%d",&choice); //input saved into variable choice

        //switch case 
        switch (choice){

            //choice 1 - add matrices
            case 1: 
                if (rowsA==rowsB && colsA==colsB){//both matrices need to have same number of rows and columns for addition to happen
                    addMatrices(matrixA,matrixB,result,rowsA,colsB); //call function add matrice
                    printf("Result of Matrix A + Matrix B:\n");
                    displayMatrix(result,rowsA,colsA); //call function displayMatrix to show results
                } else{
                    printf("Both matrix dimensions need to match for addition to happen.\n");
                }
                break;

            //choice 2 - subtract matrices
            case 2: 
                if (rowsA==rowsB && colsA==colsB){ //both matrices num of rows and columns need to be the same
                    subtractMatrices(matrixA,matrixB,result,rowsA,colsA); // call function to subtract 
                    printf("Result of Matrix A- Matrix B:\n");
                    displayMatrix(result,rowsA,colsA); //display result
                } else{
                    printf("Both matrix dimensions need to match for subtraction.\n"); //both matrices has different dimensions
                }
                break;

            //choice 3- transpose matrix A 
            case 3:
                transposeMatrix(matrixA,transposeA, rowsA, colsA); //call function to tranpose matrix
                printf("Transpose of Matrix A:\n"); 
                displayMatrix(transposeA, colsA, rowsA); //print transposed matrix of A
                break;

            //choice 4- transpose matrix B 
            case 4: 
                transposeMatrix(matrixB, transposeB,rowsB,colsB); //call function to transpose matrix
                printf("Transpose of Matrix B:\n");
                displayMatrix(transposeB,colsB,rowsB); //print transposed matrix of B
                break;

            //exit program 
            case 5:
                printf("Exiting the program.\n");
               
                return 0;  //end program
            
            default:
                printf("Invalid choice! Please try again.\n"); //invalid choice input (not 1-5)
        } 

       
    } 

    
    
}