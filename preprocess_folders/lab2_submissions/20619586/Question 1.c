#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int* ptr;

    while (1)    {
        printf("Enter the size of the array (N >= 5):");
        scanf("%d",&n);
            if(n>=5){
                break;
            }
        }
    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    int num;
    int indice1, indice2;

    puts("Enter the array elements:");
    for (int i = 0; i < n; ++i) {
            printf("Element %d: ", i);
            scanf("%d",&num);
            ptr[i] = num;
    }

    while (1) {
        
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("%d %d",&indice1, &indice2);
        if(indice1 < n && indice1 >= 0 && indice2 < n && indice2 >= 0 ){
            break;
        }else{
            puts("Error: the indices of the elements must be within range of the array elements. Please try again.");
        }
    }

    int sum;
    sum = ptr[indice1] + ptr[indice2];
    printf("The sum o fthe values at indices %d and %d is: %d", indice1, indice2, sum);
}