#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, *ptr;
    int indice1, indice2;
    int num1,num2,sum;
    
    do{
        printf("\nEnter the size of the array (N>=5): ");
        scanf("%d",&N);
        if (N<5){
            printf("Array size must greater equal than 5!\n");
        }
    }while(N<5);
    
    ptr=(int*)malloc(N*sizeof(int));
    printf("Enter the array elements: \n");
    for (int i=0;i<N;i++){
        printf("Element %d: ",i);
        scanf("%d",ptr+i);
    }
    
    do{
        printf("Enter the indices of the two elements (0 <= index1, index2 < %d): ",N);
        scanf("%d %d",&indice1,&indice2);
        if (indice1<0||indice1>=N || indice2<0||indice2>=N){
            printf("Error: Indices must be within the range of the array elements. Please try again.\n\n");
        }
    }while (indice1<0||indice1>=N || indice2<0||indice2>=N);
    
    num1=*(ptr+indice1);
    num2=*(ptr+indice2);
    
    printf("The sum of the values at indices %d and %d is: %d",indice1,indice2,num1+num2);
    
}
