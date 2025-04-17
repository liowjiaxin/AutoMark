Question 1:

#include <stdio.h>

int main(void)
{ 
    int row1;
    int col1;
    int i; 
    int j;
    printf("Please enter number of rows: "); 
    scanf("%d", &row1);
    
    printf("Please enter number of columns: "); 
    scanf("%d", &col1);

    for( i=0; i< row1;i++)
    { 
        for( j=0; j< col1; j++)
        { 
           printf("*");  
        }
        printf("\n"); 
    } 
    return 0; 
} 

