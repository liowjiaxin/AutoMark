#include <stdio.h>

int main() {
    int rows;
    int columns;
    int loop1;
    int loop2;
    
    printf("Enter number of rows: "); //Input rows from user
    scanf("%d", &rows);
    
    printf("Enter number of columns: "); //Input columns from user
    scanf("%d", &columns);

    for(loop1 = 1; loop1 <= rows; loop1++)     // Iterate through number of rows 
    {
        for(loop2 = 1; loop2 <= columns; loop2++) // Iterate through number of columns
        {
            printf("*"); // Print star for each column 
        }
        
        printf("\n"); // Move to the next line
    }

    return 0; //Indicate successful execution
}
