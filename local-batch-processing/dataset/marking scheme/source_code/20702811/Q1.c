#include <stdio.h>

#define MAX_ROW 10     // Define the max number of rows 
#define MAX_COLUMN 10  // Define the max number of columns


int main(void) {
    // define the following variables to use in the program
    int rowsA, columnsA, rowsB, columnsB, choice;
    int elementA[MAX_ROW][MAX_COLUMN], elementB[MAX_ROW][MAX_COLUMN], transposeA[MAX_COLUMN][MAX_ROW], transposeB[MAX_COLUMN][MAX_ROW];

    do {
        // Asks user to input dimensions for Matrix A and save the values into rowsA and columnsA
        printf("Enter dimensions for Matrix A (rows and columns): ");
        scanf("%d %d", &rowsA, &columnsA);     

    if (rowsA > MAX_ROW || columnsA > MAX_COLUMN) {
        printf("Please only input row and column value as 10 or less, and don't forget the space to differentiate rows and columns.\n");
        // If user inputs a value more than 10, prints the error and repeats the do while loop
    }
    } while (rowsA > MAX_ROW || columnsA > MAX_COLUMN);

    // Create a nested for loop where the program asks user to input dimensions for the matrix A and save them into elementA
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < columnsA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);   // i+1 and j+1 is use so that Element [%d][%d] starts at 11 instead of 00
            scanf("%d", &elementA[i][j]);
        }
    }

    do {
        // Asks user to input dimensions for Matrix A and save the values into rowsA and columnsA
        printf("Enter dimensions for Matrix B (rows and columns): ");
        scanf("%d %d", &rowsB, &columnsB);

    if (rowsB > MAX_ROW || columnsB > MAX_COLUMN) {
        printf("Please only input row and column value as 10 or less, and don't forget the space to differentiate rows and columns.\n");
        // If user inputs a value more than 10, prints the error and repeats the do while loop
    }
    } while (rowsB > MAX_ROW || columnsB > MAX_COLUMN);

    // Create a nested for loop where the program asks user to input dimensions for the matrix A and save them into elementA
    for(int i = 0; i < rowsB; i++) {
        for(int j = 0; j < columnsB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);   // i+1 and j+1 is use so that Element [%d][%d] starts at 11 instead of 00
            scanf("%d", &elementB[i][j]);
        }
    }
    
    do {
        // Prints out the menu and prompts user to input their choice
        printf("Matrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add Matrices
                // To add matrices, the dimension of rows of both matrices and the dimension of columns of both matrices must be equal
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Addition of Matrix A and B not possible.\n");  // Prints out an error message if either the rows or columns matrices are not equal
                    break;
                } else {
                    // define a new variable to use in this part of the code
                    int sumMatrix[MAX_ROW][MAX_COLUMN];

                    // Create a nested for loop to add the two matrice together
                    for (int i = 0; i < rowsA; i++) {
                        for (int j = 0; j < columnsA; j++) {
                            sumMatrix[i][j] = elementA[i][j] + elementB[i][j];
                            // Stores the sum of each dimension in the matrices into the new variable sumMatrix
                            // if currently sumMatrix[1][1] (which is the very first or top left dimension), then it will store the sum of elementA[1][1] and elementB[1][1]
                        }
                    }

                    // Create another nested for loop to output each stored value of sumMatrix
                    printf("Result of Matrix A + Matrix B:\n");
                    for (int i = 0; i < rowsA; i++) {
                        for (int j = 0; j < columnsA; j++) {
                            printf("%d\t", sumMatrix[i][j]);   // prints out all the stored value in one line spaced by \t (tab)

                            if (j == columnsA - 1) {           // create an if statement so that when count j is the equal to columnsA of user input (-1 is used since int j starts at 0)
                                printf("\n");                  // when equal, make a new line to make the output into a matrix form
                            }
                        }
                        printf("\n");                          // Create a new line to have a distance before the menu prompt prompts again
                    }
                    break;                                     // breaks the case and repeats the do while loop
                }
            case 2: // Subtract Matrices
                // To subtract matrices, the dimension of rows of both matrices and the dimension of columns of both matrices must be equal
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Addition of Matrix A and B not possible.\n");    // Prints out an error message if either the rows or columns matrices are not equal
                    break;
                } else {
                    // define a new variable to use in this part of the code
                    int subtractMatrix[MAX_ROW][MAX_COLUMN];

                    // Create a nested for loop to subtract the two matrice together
                    for (int i = 0; i < rowsA; i++) {
                        for (int j = 0; j < columnsA; j++) {
                            subtractMatrix[i][j] = elementA[i][j] - elementB[i][j];
                            // Stores the difference of each dimension in the matrices into the new variable subtractMatrix
                            // if currently subtractMatrix[1][1] (which is the very first or top left dimension), then it will store the difference of elementA[1][1] and elementB[1][1]
                        }
                    }

                    // Create another nested for loop to output each stored value of subtractMatrix
                    printf("Result of Matrix A - Matrix B:\n");
                    for (int i = 0; i < rowsA; i++) {
                        for (int j = 0; j < columnsA; j++) {
                            printf("%d\t", subtractMatrix[i][j]);     // prints out all the stored value in one line spaced by \t (tab)

                            if (j == columnsA - 1) {                  // create an if statement so that when count j is the equal to columnsA of user input (-1 is used since int j starts at 0)
                                printf("\n");                         // when equal, make a new line to make the output into a matrix form
                            }
                        }
                        printf("\n");                                 // Create a new line to have a distance before the menu prompt prompts again
                    }
                    break;                                            // breaks the case and repeats the do while loop
                }
            case 3:
                // Create a nested loop to swap (or transpose) the dimensions of elementA into transposeA
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < columnsA; j++) {
                        transposeA[j][i] = elementA[i][j];     // as long as nested for loop continues, the value stored in rowsA in elementA will be put into columnsA of transposeA and the columnsA in nestedA will be the rowsA in transposeA
                    }
                }

                // Create another nested for loop to output each stored value of transposeA
                printf("Transpose of Matrix A:\n");
                for (int i = 0; i < columnsA; i++) {
                    for (int j = 0; j < rowsA; j++) {
                        printf("%d\t", transposeA[i][j]);     // prints out all the stored value in one line spaced by \t (tab)
                    }
                    printf("\n");        // prints a new line after every time the second for loop breaks
                }
                printf("\n");            // Create a new line to have a distance before the menu prompt prompts again
                break;                   // breaks the case and repeats the do while loop
            case 4:
                // Create a nested loop to swap (or transpose) the dimensions of elementB into transposeB
                for (int i = 0; i < rowsB; i++) {
                    for (int j = 0; j < columnsB; j++) {
                        transposeB[j][i] = elementB[i][j];     // as long as nested for loop continues, the value stored in rowsB in elementB will be put into columnsB of transposeB and the columnsB in nestedB will be the rowsB in transposeB
                    }
                }

                // Create another nested for loop to output each stored value of transposeB
                printf("Transpose of Matrix B:\n");
                for (int i = 0; i < columnsB; i++) {
                    for (int j = 0; j < rowsA; j++) {
                        printf("%d\t", transposeB[i][j]);     // prints out all the stored value in one line spaced by \t (tab)
                    }
                    printf("\n");        // prints a new line after every time the second for loop breaks
                }
                printf("\n");            // Create a new line to have a distance before the menu prompt prompts again
                break;                   // breaks the case and repeats the do while loop
            case 5:
                printf("Exiting...\n");    // Inform user they have chosen to exit program
                break;                     // breaks the case
            default:
                printf("Invalid option choice. Please try again.\n");   // Inform user that option choice is invalid and to prompt them to try again
                break;       // breaks the case and repeats the do while loop
        }
    } while (choice != 5);   // do while loop repeats until user inputs 5 which whill finally end the loop and end the program

    return 0;
}