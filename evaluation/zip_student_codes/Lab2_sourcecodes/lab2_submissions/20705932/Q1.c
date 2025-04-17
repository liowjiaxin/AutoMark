#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int size;
    int index1 = -1;
    int index2 = -1;
    int sum;
    int *p;
    int *q;
    printf("Enter the size of the array: \n");
    scanf("%d",&size);
    
    int arr[size] = (int) malloc(size + 1 * sizeof(char));
    printf("enter each element of the array one by one: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
       
    }
    getchar();

    for (int i = 0; i < size; ++i) {
        printf("Element %d:%d \n", i, arr[i]);
        
    }
        
    
    printf("Choose the indices of the two elements(0 <= index1, index2 < 6): \n");
    scanf("%d\n%d",&index1,&index2);
    while ((index1 < 0|| index1 >= size) || (index2 < 0|| index2 >= size)) {
        printf("Error: Indices not in range. Try again.\n");
        scanf("%d",&index1);
        scanf("%d", &index2);
        
        
    }
    
    
    p = arr;
    q = arr;
    while (p != &arr[index1]) {
        p++;
    }
    while (q != &arr[index2]) {
        q++;
    }
    sum = *p + *q;
    printf("the sum of the values at indices %d and %d is %d", index1, index2, sum);
    

    return 0;
}