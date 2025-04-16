#include <stdio.h>


//declare or define a size for the matrices that cannot be exceeded
#define MAX_MSIZE 10

//function prototypes
void MatrixInput(int matrix[MAX_MSIZE][MAX_MSIZE], int trows, int tcolumns);
void add_matrix(int matrix1[MAX_MSIZE][MAX_MSIZE], int matrix2[MAX_MSIZE][MAX_MSIZE], int matrix_result[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols);
void sub_matrix(int matrix1[MAX_MSIZE][MAX_MSIZE], int matrix2[MAX_MSIZE][MAX_MSIZE], int matrix_result[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols);
void transposeMatrix(int MatrixInput[MAX_MSIZE][MAX_MSIZE], int transposedMatrix[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols);
void display(int matrix[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols);




int main(){
// firstly ask for userinput for the matrices 

//declare the matrices with the maximum size 10 for column and rows
int matrix1[MAX_MSIZE][MAX_MSIZE];
int matrix2[MAX_MSIZE][MAX_MSIZE];
int matrix_result[MAX_MSIZE][MAX_MSIZE];
//declare the dimensions for the matrices
int row1, column1, row2, column2;
//declare userinput
int userinput;   // when user chooses operation
int dimensions = 0;

//input dimensions for the first matrix 
do{
    printf("Enter dimension for Matrix A (rows and columns): ");
    scanf("%d %d", &row1, &column1);
    if(row1 > 0 && row1 <= MAX_MSIZE && column1 > 0 && column1 <= MAX_MSIZE){
        dimensions = 1; // dimensions are correct 
    } else {
        printf("Invalid Dimensions! Please enter values between 1 and %d.\n", MAX_MSIZE);

    }
} while (!dimensions);  // do this loop till this condition is met


//input for elements for matrix 1
printf("Enter elements for Matrix A:\n");
//call the function for inputting the matrix 
MatrixInput(matrix1, row1, column1);



//input dimension for matrix B
dimensions=0; //reset the validation flag so that it doesnt continue when error message is sent
do{
    printf("Enter dimension for Matrix B (rows and columns): ");
    scanf("%d %d", &row2, &column2);
    if(row2 == row1 && column2 == column1){ //ensure matrices have matching dimensions
        dimensions= 1;       //valid dimensions    
    } else {
        printf("Invalid Dimensions! Matrix B must have same dimensions as Matrix A\n");   //Else print error message
     }
} while(!dimensions);  // do this loop till this condition is met where Matrix B matches Matrix A.

//input elements for matrix B
printf("Enter elements for Matrix B:\n");
MatrixInput(matrix2, row2, column2); //call the function 


//main menu for the operations to perform on the operations 
do{

printf("Matrix Operations Menu:\n");
printf("1. Add Matrices\n");
printf("2. Subtract Matrices\n");
printf("3. Transpose Matrix A\n");
printf("4. Transpose Matrix B\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &userinput); //take userinput 

//create switch cases to call the functions for each operation
 switch(userinput){
    case 1: //add the matrices
    add_matrix(matrix1, matrix2, matrix_result, row1, column1);
    printf("Result of Matrix A + B:\n");
    display(matrix_result, row1, column1);
    break;

    case 2: //subtraction
    sub_matrix(matrix1, matrix2, matrix_result, row1, column1);
    printf("Result of Matrix A - B:\n");
    display(matrix_result, row1, column1);
    break;

    case 3: //trasnpose Matrix A
    transposeMatrix(matrix1, matrix_result, row1, column1);
    printf("Transpose of Matrix A:\n");
    display(matrix_result, column1, row1);
    break;

    case 4: // transpose matrix B
    transposeMatrix(matrix2, matrix_result, row2, column2);
    printf("Transpose of Matrix B:\n");
    display(matrix_result, column2, row2);
    break;

    case 5: //exit
    printf("Exited!\n");
    break;

    default: //invalid choices
    printf("Invalid choice! Please try again.\n");
 }


}while( userinput !=5);

return 0;
}



//function for inputting the matrix
void MatrixInput(int matrix[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols){
    for( int row=0; row< numRows; row++){  //loop through the rows
     for( int col=0; col < numCols; col++){  //loop throught the columns
      printf("Element[%d][%d]: ", row+1, col+1);    //display each element 
      scanf("%d", &matrix[row][col]);      //input the elements
     }
    }
}

//function to add the matrices

void add_matrix(int matrix1[MAX_MSIZE][MAX_MSIZE], int matrix2[MAX_MSIZE][MAX_MSIZE], int matrix_result[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols){
    for(int row=0; row< numRows; row++){
        for(int col=0; col < numCols; col++){
            matrix_result[row][col]= matrix1[row][col] + matrix2[row][col];   //add the two matrix
        }
    }
}


//function to subtract the matrices

void sub_matrix(int matrix1[MAX_MSIZE][MAX_MSIZE], int matrix2[MAX_MSIZE][MAX_MSIZE], int matrix_result[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols){
    for(int row=0; row< numRows; row++){
        for(int col=0; col < numCols; col++){
            matrix_result[row][col]= matrix1[row][col] - matrix2[row][col];   //subtract the two matrix
        }
    }
}

//function to transpose matrix 
void transposeMatrix(int MatrixInput[MAX_MSIZE][MAX_MSIZE], int transposedMatrix[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols){
    for(int row=0; row< numRows; row++){
        for(int col=0; col < numCols; col++){
            transposedMatrix[col][row]= MatrixInput[row][col];  //transpose element 
        }
    }
}


//function to display the matrix
void display(int matrix[MAX_MSIZE][MAX_MSIZE], int numRows, int numCols){
    for(int row=0; row< numRows; row++){
        for(int col=0; col < numCols; col++){
           printf("%d ", matrix[row][col]); //print element
        }
        printf("\n"); //new line after each row. 
    }
}