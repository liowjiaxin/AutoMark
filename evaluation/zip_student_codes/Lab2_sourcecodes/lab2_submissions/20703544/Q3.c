#include <stdio.h>

int main()
{
    int num;
    int array[num];
    
    printf("Enter the number of bids: ");
    scanf("%d", &num);
    if(num<3) {
        printf("number of bids must at least 3. try again\n");
        scanf("%d", &num);
    }
    for(int i = 0; i < num; i++) {
    printf("Enter the bids(must be at least $100000: ");
    scanf("%d", &array[i]);
    if(array[i] < 100000){
        printf("The bids must be at least $100000.Try again: ");
        scanf("%d", &array[i]);
        }
    }
    
    int max = 0;
    int j;
    for(j = 0; j < num; j++) {
        if(max < array[j]) {
          max = array[j];
        }
    }
    printf("The highest bids is %d", max);
    return 0;
}
