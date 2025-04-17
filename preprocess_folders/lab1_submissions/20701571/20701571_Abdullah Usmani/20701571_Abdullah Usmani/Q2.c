#include <stdio.h>

int main() {
    int num1, num2, num3 = 0;

    printf("Enter three intgers separated by space: ");
    scanf("%d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    printf("Sum: %d", sum);
    


    return 0;
}