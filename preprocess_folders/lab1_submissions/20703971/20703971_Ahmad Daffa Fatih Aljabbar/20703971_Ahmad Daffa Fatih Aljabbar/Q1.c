#include <stdio.h>

int main() {
    int rows, columns;

    printf("Enter the number of columns: "); //ask for the columns
    scanf("%d", &rows); //scan

    printf("Enter the number of columns: "); //ask for the columns
    scanf("%d", &columns); //scan

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) { 
            if (j < columns - 1) {
                printf("* "); //print the "*"
            } else {
                printf("\n"); 
            }

        }

    }

}
