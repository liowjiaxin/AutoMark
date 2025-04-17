#include<stdio.h>
#include<stdlib.h>

int main(){
    size_t N;
    printf("Enter the size of the array (N>=5)");
    scanf("%d",&N);
    if(N<5){
        printf("Invalid input");
        exit(0);
    }
   
    int array[N];
    printf("Enter the array element\n");
    for(size_t i=0; i<N; i++){
        printf("Element %zu :",i);
        scanf("%d",&array[i]);
    }
    int indice1,indice2;
    printf("Enter the indices of the two element"
           " (0<=index1,index2<%zu)",N);
    scanf("%d %d", &indice1,&indice2);
    while((N<indice1<0) || (N<indice2<0)){
        printf("Error: Indice must be within the range. Please try again");
        printf("Enter the indices of the two element"
               " (0<=index1,index2<%d)",N);
        scanf("%d %d", &indice1,&indice2);
    }
    
    int *Ptr1=&array[indice1];
    int *Ptr2=&array[indice2];
    int sum=*Ptr1+*Ptr2;
    printf("The sum of the values at indice %d and %d is %d:",indice1,indice2,sum);

}