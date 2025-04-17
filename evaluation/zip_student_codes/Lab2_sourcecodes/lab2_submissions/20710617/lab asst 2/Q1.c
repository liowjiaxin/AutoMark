#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int size;
  printf("Enter the size of the array (N>=5): ");
  scanf("%d",&size);
  
   while (size<5){
      printf("size must be greater than or equal to 5\n");
      printf("Enter the size of the array (N>=5): ");
      scanf("%d",&size);
    }
  
  int *arr=(int *)malloc(size*sizeof(int));
   
    printf("Enter the array of element:\n");
    for (int i =0; i<size ; i++){
        printf("Element[%d]=",i);
        scanf("%d",(arr + i));
    }
     
    
    int i1={0};
    int i2={0}; 
    
    printf("Enter the indices of the two elements 0<=index1, index2< %d:\n",size);
    scanf("%d %d",&i1 , &i2);
   
    while (i1<0 || i2>size){
        printf ("Error: Indices must be within the range of elemesnts. Please try again");
         printf("Enter the indices of the two elements 0<=index1, index2<%d: ",size);
         scanf("%d",i1);
         scanf("%d",i2);
        
    }

    int sum = *(arr + i1) + *(arr + i2);
    
    printf("sum of values at indices %d and %d is: %d\n",i1 , i2 , sum);
    free(arr);
   
    return 0;
}