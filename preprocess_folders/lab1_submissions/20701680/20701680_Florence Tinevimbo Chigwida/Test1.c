#include <stdio.h>
int main () {

int i,j ;
int rows;
int columns ;
printf("Please enter the number of rows");
scanf("%d", &rows);

printf("Please enter the number of columns");
scanf("%d",& columns);

for ( int i = 0 ; i < rows ; i ++){
    for ( int j = 0 ;  j < columns ; j++){
    printf (" * ") ;
    }
printf("\n") ;
}

return 0 ;
 }

