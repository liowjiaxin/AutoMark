#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, total;
    

    printf("Enter the size of the array (N >= 5): ");
    scanf("%d", &n);

    if (n < 5) {
        printf("Invalid input. Array size must be at least 5.\n");
        return 1; 
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &numbers[i]);
    }

    int option1, option2;
    printf("Enter the indices of two elements to add: ");
    scanf("%d %d", &option1, &option2);

    
    if (option1 >= 0 && option1 < n && option2 >= 0 && option2 < n) {
        
        total= numbers[option1] + numbers[option2];
        printf("The total is %d",total );

        
        
    
    } else {
        printf("Invalid indices. Indices must be between 0 and %d.\n", n - 1);
    }

    
    free(numbers);

    return 0;
}
