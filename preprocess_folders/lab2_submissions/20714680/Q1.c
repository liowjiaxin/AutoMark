// Q1
#include <stdio.h>

int main() {
    int N; 
    int arr[N];
    int a, b;

    printf("Enter the size of the array (N>=5): ");
    scanf("%d", &N);

    if(N<5) {
        printf("N should be >= 5. Please enter size gain: ");       //Prompt the user to enter size again if N<5
    }
    
    printf("Enter the array elements:\n");
    for(int i = 0; i<N; i++) {
        printf("Element[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the indices of the two elements (0<=index1,index2<6): ");
    scanf("%d%d", &a, &b);

    if((a<0 || a>N) || (b<0 || b>N)) {
        printf("Error: Indices must be within the range of the array elements. Please try again.\n");
        printf("Enter the indices of the two elements (0<=index1,index2<6): ");
        scanf("%d%d", &a, &b);
    }
    int sum = 0;
    sum = arr[a] + arr[b];
    printf("The sum of the values at indices %d and %d is: %d", a, b, sum);

    return 0;
}