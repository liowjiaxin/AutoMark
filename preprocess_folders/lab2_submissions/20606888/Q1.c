#include <stdio.h>



int main() {
    //pointer declaration
    int *ptr1,  *ptr2;
    int n, sum;
    double arr[100];
    
    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Enter number%d: ", i + 1);
        scanf("%lf", &arr[i]);
    }

    
    for (int i = 0; i < 6; i++) {
        printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
        scanf("ptr1 = %u, ptr2 = %u\n", ptr1, ptr2);
    }
    
    
    //Sum of ptr1 and ptr2
    sum = ptr1 + ptr2;
    
    printf("The sum of values at indices 4 and 5 is: %d\n", sum);

    return 0;
}
    
  