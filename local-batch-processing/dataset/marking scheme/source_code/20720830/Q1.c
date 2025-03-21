#include <stdio.h>

// Declare functions
void add(int a[10][10], int b[10][10], int rowa, int cola, int rowb, int colb);
void subtract(int a[10][10], int b[10][10], int rowa, int cola, int rowb, int colb);
void transpose(int c[10][10], int row, int col);
void output(int c[10][10], int row, int col);

int a[10][10];
int b[10][10];
int rowa, cola, rowb, colb;

int main(){
    do{
        rowa,cola = 0;

        //Input dimensions for Matrix A
        printf("Enter dimensions for Matrix A (rows and columns): ");

        // Validate input to be a number
        if (scanf("%d %d", &rowa, &cola) != 2) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n'); // Loop to clear buffer if input is not a number
            continue;
        }

        // Validate matrix dimensions
        if (rowa > 10 || cola > 10 || rowa <= 0 || cola <= 0){
            printf("Invalid Input. Matrix dimensions cannot exceed 10x10 and should be more than 0.\n");
            continue;
        }

        printf("Enter elements for Matrix A: \n");

        //Loop and input elements for Matrix A
        for(int i=0; i<rowa; i++){
            for(int j=0; j<cola; j++){
                printf("Element [%d][%d]: ", i+1, j+1);
                // Validate input to be a number
                if (scanf("%d", &a[i][j]) != 1){
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Loop to clear buffer if input is not a number
                    j--;
                }
            }
        }

    } while (rowa > 10 || cola > 10 || rowa <= 0 || cola <= 0 );

    do{
        rowb,colb = 0;
        
        //Input dimensions for Matrix B
        printf("Enter dimensions for Matrix B (rows and columns): ");

        // Validate input to be a number
        if (scanf("%d %d", &rowb, &colb) != 2) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n'); // Loop to clear buffer if input is not a number
            continue;
        }

        // Validate matrix dimensions
        if (rowb > 10 || colb > 10 || rowb <= 0 || colb <= 0){
            printf("Invalid Input. Matrix dimensions cannot exceed 10x10 and should be more than 0\n");
            continue;
        }

        printf("Enter elements for Matrix B: \n");

        //Loop and input elements for Matrix B
        for(int i=0; i<rowb; i++){
            for(int j=0; j<colb; j++){
                printf("Element [%d][%d]: ", i+1, j+1);
                // Validate input to be a number
                if (scanf("%d", &b[i][j]) != 1){
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Loop to clear buffer if input is not a number
                    j--;
                }
            }
        }

    } while (rowb > 10 || colb > 10 || rowb <= 0 || colb <= 0 );

    int choice;
    //Loop menu for matrix operations
    do{
        printf("\nMatrix Operations Menu:");
        printf("\n1. Add Matrices");
        printf("\n2. Subtract Matrices");
        printf("\n3. Transpose Matrix A");
        printf("\n4. Transpose Matrix B");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add(a, b, rowa, cola, rowb, colb);
                break;
            case 2:
                subtract(a, b, rowa, cola, rowb, colb);
                break;
            case 3:
                transpose(a, rowa, cola);
                break;
            case 4:
                transpose(b, rowb, colb);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
                continue;
        }
    }while(choice!=5);//Exit when choice is 5
}

//Function to add matrices
void add(int a[10][10], int b[10][10], int rowa, int cola, int rowb, int colb){
    //Check if matrices can be added
    if(rowa!=rowb || cola!=colb){
        printf("Matrices cannot be added");
        return;
    }
    int c[10][10];
    //Loop and add elements of matrices to c
    for(int i=0; i<rowa; i++){
        for(int j=0; j<cola; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    //Output result
    printf("Result of Matrix A + Matrix B: \n");
    output(c, rowa, cola);
}

//Function to subtract matrices
void subtract(int a[10][10], int b[10][10], int rowa, int cola, int rowb, int colb){
    //Check if matrices can be subtracted
    if(rowa!=rowb || cola!=colb){
        printf("Matrices cannot be subtracted");
        return;
    }
    int c[10][10];
    //Loop and subtract elements of matrices to c
    for(int i=0; i<rowa; i++){
        for(int j=0; j<cola; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    //Output result
    printf("Result of Matrix A - Matrix B: \n");
    output(c, rowa, cola);
}

//Function to transpose matrices
void transpose(int c[10][10], int row, int col){
    int d[10][10];
    //Loop and transpose elements of matrices to d
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            d[j][i] = c[i][j];
        }
    }
    //Output result
    if (c == a) {
        printf("Transpose of Matrix A:\n");
    } else if (c == b) {
        printf("Transpose of Matrix B:\n");
    }
    output(d, col, row);
}

//Function to output matrices
void output(int c[10][10], int row, int col){
    //Loop and display elements of matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");//New line for next row
    }
}