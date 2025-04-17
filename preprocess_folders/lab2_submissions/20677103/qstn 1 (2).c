#include<stdio.h>
// qstn 1

int main(){
    int size; // declare size variable
    printf("enter the size of the array (N>=5):");
    scanf("%d",&size);//input size of variable
    int arr[size];//declare an array with size of given size inpit by user
    for(int i=0;i<size;i++){// enter a for loop to accept inputs from the user and store in the array
        printf("element %d :",i);
        scanf("%d",&arr[i]);
    }
    int index1, index2;
    printf("enter the indices of the two elements with one space between them (0<=index1, index2< 6):");
    scanf("%d %d",&index1,&index2);
    
    if(0>index1 || index2>size){ // if the conditions arent met input another value
        printf("error: indices must be within the range of the array elements. please try again.");
        printf("enter the indices of the two elements with one space between them (0<=index1, index2< 6):");
        scanf("%d %d",&index1,&index2);
    }
    int *ptrindex1=&arr[index1];// declare pointers
    int *ptrindex2=&arr[index2];
    printf("the sum of the two inidices is:%d",*ptrindex1+*ptrindex2);//pointer arithmetic

    
    return 0;
}
