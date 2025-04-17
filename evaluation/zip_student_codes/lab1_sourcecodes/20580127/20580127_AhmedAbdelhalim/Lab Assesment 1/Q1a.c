#include<stdio.h>

int main(){

int rows;
int columns;
printf("Enter number of rows: "); //propmpt user to enter num of rows
scanf("%d",&rows);

printf("Enter number of columns: "); //prompt user to enter num of columns
scanf("%d",&columns);

for(int i=1;i<=rows;++i)
{
    printf("\n* ");
    //nested for loop 
    for(int i=2;i<=columns;++i){  //i is = 2 to take into account extra * from rows

    printf(" * ");
        }
}
}
