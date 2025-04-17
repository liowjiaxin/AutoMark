#include <stdio.h>
#include <stdlib.h>

void main(){
    int number;

    //size of array
    printf("Enter the size of the array(N>=5):");
    scanf("%d",&number);
    while (number < 5){
        printf("Invalid.Enter the size of the array again:");
        scanf("%d",&number);
    }

    int array[100]={0};
    int* pointer=(int*)malloc(sizeof(array)); //Dynamic memory allocation

  
    //Enter array elements
    printf("Enter the array elements\n ");
    int i=0;
    while (i <number){
         printf("Element %d:",i);
         scanf("%d",&pointer[i]);
         i++;
         

    }
   
    

    // two indices
    int index1;
    int index2;
    printf("Enter the indices of the two elements(0 <=index1,index<%d):",number);
    scanf("%d %d",&index1,&index2);
    while ( (index1 <0 )|| (index2 >= number)){
        printf("Error:Please write again:");
        scanf("%d %d",&index1,&index2);

    }
    
    //sum
    int sum = *(pointer+index1) + *(pointer+index2);
    printf("The sum of the values at indices %d and %d is:%d",index1,index2,sum);



    


}