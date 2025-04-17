#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(){
// initialization of functions
int N=0;
int *array;
int i=0;
int index1=0;
int index2=0;

   do{
   printf("Enter the size of the array(N>=5):");// prompt the the user to enter
   scanf("%d",&N);//Get output form the user
   if(N<5){
    printf("Invalid");
   }
}while(N<5);{
        //allocate the memory
        array = (int*) malloc(N * sizeof(int));
    if (array == NULL) {
 }     printf("Memory allocation failed.\n");
}


printf("Enter the array elements:\n");
    for (i = 0; i < N; i++) {//loop through the array elements
        printf("Elements %d: ", i);
        scanf("%d", &array[i]);//get output form user
}


return 0;

}













