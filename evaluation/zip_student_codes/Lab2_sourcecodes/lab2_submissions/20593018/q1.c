#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int id1, id2;
    
    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &N);

    while (N < 5) {
        printf("Error: N must be more than or equal to 5. Please try again:");
        scanf("%d", &N);
    }

    int *arr = (int *)malloc(N*sizeof(int));
    if (arr==NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the array elements:\n");
    for (int i=0; i<N; i++) {
        printf("Element %d:",i);
        scanf("%d", (arr+i));
    }

    while(1){
        printf("Enter the indices of the two elements (0<=index1, index2<%d):",N);
        scanf("%d %d",&id1,&id2);

        if(id1>=0 && id1<N && id2>=0 && id2<N) {
            break;
        } 
        else{
            printf("Error: Indices must be within the range of the array elements.Please try again.\n");
        }
    }

    int sum = *(arr+id1)+ *(arr+id2);
    printf("The sum of the values at indices %d and %d is:%d", id1, id2, sum);
    free(arr);

    return 0;
}


