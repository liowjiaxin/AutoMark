#include <stdio.h>  

int main() {  
    int rows = 0; 
    int clmns = 0;

    printf("Enter the number of rows : ");  
    scanf("%d",&rows);                              //Takes user input for rows and assings it to variable
    printf("Enter the number of coloumns : ");
    scanf("%d", &clmns);                            //Takes user input for coloumns and assings it to variable

    for(int i=0; i<rows; i++)                      // For loop to iterate through rows
    {  
        for(int j=0; j<clmns; j++)                 // For loop to iterate through coloumns
        {  
            printf("*");  
        }  
        printf("\n");                              // Goes to a new line after every coloumn
    }  
      
    return 0;  
}  
