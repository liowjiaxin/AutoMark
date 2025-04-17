#include <stdio.h>

int main(){
    int N, indices1, indices2;
    int arr[N];
    int *p;
    
    //pointer to array
    p = arr;
     printf("Enter the size of the array (N>=5): ");
    scanf("%d", &N);
    if (N<5){
        printf("Size of the array has to be more than 5. Enter the size again: ");
        scanf("%d", &N);
    }

    //inputting the elements in the array
    printf("Enter the array elements: \n");
    for(int i=0; i<N; i++){
        for(int i=0; i<N; i++){
            printf("Element %d: ", i);
            scanf("%d", p);
            p++;
    }
    


    while(1){
        //prommpting user the index of elements to be summed
        printf("Enter the indices of the two elements (0<= index1, index2 < %d): ", N);
        scanf("%d %d", &indices1, &indices2);

        //checking if the indices are in between the range of elements in the array
        if ((indices1>=0 && indices1<N) && (indices2>=0 && indices2<N)){
            break;
        } else{
            //display error message if not
            printf("Error: Indices must be within the range of the array elements. Please try again.");
        }
    }

    //calculating sum  of elements at the indices chosen
    int sum = arr[indices1] + arr[indices2];

    printf("The sum of values at indices %d and %d is: %d", indices1, indices2, sum);

    return 0;
}
}