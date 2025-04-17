#include <stdio.h>

int main(){

    int rows = 0;
    int columns = 0;



    printf("Enter the number of rows: \n"); //prompt user to enter no. of rows
    scanf("%d", &rows);

    printf("Enter the number of columns: \n"); //prompt user to enter no. of columns
    scanf("%d", &columns);

    for (int i=1; i<=rows; i++){

        for (int j=1; j<=columns; j++){
            printf("*");
        }


        printf("\n");
    }
    

    return 0;
}