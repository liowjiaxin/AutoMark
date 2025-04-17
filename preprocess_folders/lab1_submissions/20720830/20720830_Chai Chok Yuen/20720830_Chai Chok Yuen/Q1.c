#include <stdio.h>

int main(){
    int row,col ;
    //Input rows and columns
    printf("Enter the number of rows: ");
    scanf("%d",&row);
    printf("Enter the number of columns: ");
    scanf("%d",&col);
    //print "*" according to rows and columns from input using nested for loops
    for(int i=0; i<row;i++){
        for(int j=1; j<col;j++){
            printf(" *");
        }
        printf(" *");
        printf("\n");
    }
    return 0;
}