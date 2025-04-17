#include <stdio.h>
#define SIZE 10

int main(){
    int arr[SIZE];
    int size=0;
    int index1=0;
    int index2=0;
    int sum=0;

    printf("\nEnter the size of the array (N>=5) :");
    scanf("%d",&size);

    while(size<5){
        printf("\nSize of the array has to be >= 5\n");
        printf("\nEnter the size of the array (N>=5) :");
        scanf("%d",&size);
    }

    //input for the array
    printf("\nEnter the array elements:");
    for(int i=0;i<size;i++){
        printf("\nElement [%d]: ",i);
        scanf("%d",(arr + i));
    }

    printf("\nEnter the indices of the two elements (0 <= index 1, index 2 <%d): ",size);
    scanf("%d %d",&index1,&index2);

    while(index1<0 || index2>=size){
        printf("\nError: Indices must be within range of the elements. Please try again. ");
        printf("\nEnter the indices of the two elements (0 <= index 1, index 2 <%d): ",size);
        scanf("%d %d",&index1,&index2);
    }

    if(index1>=0 && index2<size){
        sum=*(arr + index1) + *(arr + index2);
        printf("\nThe sum of the values at indices %d and %d is: %d",index1,index2,sum);
    }

    return 0;
}