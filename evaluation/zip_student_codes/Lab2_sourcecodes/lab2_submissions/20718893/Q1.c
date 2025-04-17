#include<stdio.h>
#define SIZE 50
int main(){
    int N, index1 = -1 , index2 = -1;
    //comment user to enter the size of the array
    printf("Enter the size of the array (N >= 5):");
    scanf("%d",&N);
    if(N >= 5){     //size validate
        printf("Enter the array elements:\n");
        int element[SIZE];
        //comment user to enter the array elements
        for(int i = 0; i < N; i++){
            printf("Element %d:",i);
            scanf("%d",&element[i]);
        }
        //
        printf("Enter the indices of two elements (0 <= index1, index2 < 6):");
        scanf("%d %d",&index1,&index2);
        while(index1 < 0 || index1 < 0 || index1 >= N && index2 >= N){
            printf("Error: Indices must be within the range of the array elements. Please try again.\n");
            printf("Enter the indices of two elements (0 <= index1, index2 < 6):");
            scanf("%d %d",&index1,&index2);
        }
        int sum = element[index1] + element[index2];
        printf("The sum of the values at indice %d and %d is:%d",index1,index2,sum);
    }
    else{
        main();
    }
}