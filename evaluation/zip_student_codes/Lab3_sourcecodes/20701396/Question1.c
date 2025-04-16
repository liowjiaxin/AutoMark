#include <stdio.h>
#define MAXSIZE 10
//code runs on cmd


//function for matrix input
void matinput(int row, int column, int matrix[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traverses through row and column
            printf("Enter element [%d][%d]: ", i + 1, j + 1); //asks userto input elements
            scanf("%d", &matrix[i][j]); //saves the input into a matrix
        }
    }
}

//function to add matrix A and B
void matrixadd(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[i][j] = MatrixA[i][j] + MatrixB[i][j]; //finding the result of addition and putting it into the corresponding row and column for the result matrix
        }
    }
}

//function to subract 2 matrices
void matrixsub(int row, int column, int MatrixA[row][column], int MatrixB[row][column], int result[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[i][j] = MatrixA[i][j] - MatrixB[i][j]; //finding the result of subtraction and putting it into the corresponding row and column for the result matrix
        }
    }
}
//function to transpose a matrix
void transposeMatrix(int row, int column, int matrix[row][column], int result[column][row]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            result[j][i] = matrix[i][j]; //changing i to j and j to i
        }
    }
}
//function to display the matrix
void display(int row, int column, int matrix[row][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){ //traversing through row and column
            printf("%d\t", matrix[i][j]); // printing element
        }
        printf("\n"); //to go to next line after a column is done
    }
}

int main(){
    //variable declarations
    int rowA, columnA, rowB, columnB;
    int choice = 0;

    //while loop to ensure proper dimensions are inputted
    while(1){
    printf("Enter the number of rows in Matrix A: ");
    scanf("%d", &rowA);
    printf("Enter the number of columns in Matrix A: ");
    scanf("%d", &columnA);

    if (rowA > MAXSIZE || columnA > MAXSIZE) { //validate that the dimensions are 10x10
        printf("Error, max size for matrices is %dx%d!\n", MAXSIZE, MAXSIZE);
    }else{
        break;
    }
    }
    int MatrixA[rowA][columnA]; //initialising matrix

    //while loop to ensure proper dimensions are inputted
    while(1){
    printf("Enter the number of rows in Matrix B: ");
    scanf("%d", &rowB);
    printf("Enter the number of columns in Matrix B: ");
    scanf("%d", &columnB);

    if (rowB > MAXSIZE || columnB > MAXSIZE) {//validate the dimensions
        printf("Error, max size for matrices is is %dx%d!\n", MAXSIZE, MAXSIZE);
    }else{
        break;
    }
    }
    int MatrixB[rowB][columnB]; //initialising matrix

    printf("Enter the values for Matrix A\n"); //getting the values of the matrices
    matinput(rowA, columnA, MatrixA); //calling functions

    printf("Enter the values for Matrix B\n");
    matinput(rowB, columnB, MatrixB);

    int loop = 1;
    while(loop){ //loop to permit consecutive operations
        printf("\tMATRIX OPERATION MENU\n");
        printf("1. Add Matrices\n2. Subtract Matrices\n3. Transpose Matrix A\n4. Transpose Matrix B\n5. Exit\n");
        printf("Enter your choice: "); //For user to choose operation
        scanf("%d", &choice);

        switch(choice){
            case 1:
            if(rowA != rowB || columnA != columnB){
                printf("Matrices must have same size to be added\n"); //checking if matrix dimensions are equal
                break;
            }else{
                int resultMatrix[rowA][columnA]; //calculating the addition of matrix A and B
                matrixadd(rowA, columnA, MatrixA, MatrixB, resultMatrix);
                display(rowA, columnA, resultMatrix); //output
            break;
            }

            case 2:
            if(rowA != rowB || columnA != columnB){
                printf("Matrices must have same size to be subtracted\n"); //checking if matrices have same dimensions
                break;
            }else{
                int resultMatrix[rowA][columnA]; //calculating the difference between matrix A and B
                matrixsub(rowA, columnA, MatrixA, MatrixB, resultMatrix);
                display(rowA, columnA, resultMatrix); //output
                break;
            }

            case 3: {
            int resultMatrix[columnA][rowA]; //transposing matrix A
            transposeMatrix(rowA, columnA, MatrixA, resultMatrix);
            printf("Transpose of Matrix A: \n");
            display(columnA, rowA, resultMatrix);
            break;
            }

            case 4: {
            int resultMatrix[columnB][rowB]; //transposing matrix B
            transposeMatrix(rowB, columnB, MatrixB, resultMatrix);
            printf("Transpose of Matrix B: \n");
            display(columnB, rowB, resultMatrix);
            break;
            }

            case 5: //exit
            printf("Exiting...");
            loop = 0;
            break;

            default: //in case user enters unsupported values
            printf("Please enter a valid input.");
            break;
        }
    }
}



