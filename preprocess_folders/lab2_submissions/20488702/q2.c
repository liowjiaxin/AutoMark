#include <stdio.h>
struct student {
    char Name[50];
    float marks;
} s[5];


int main() {
    int i, sum = 0;
    printf("Enter information of students:\n");

    // storing information
    for (i = 0; i < 3; ++i) {
        printf("Enter Name: ");
        scanf("%s", s[i].Name);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
        sum += s[i].marks;
    }
    printf("Displaying Information:\n\n");

    // displaying information
    for (i = 0; i < 3; ++i) {
        printf("Name: ");
        puts(s[i].Name);
        printf("Marks: %.1f", s[i].marks);
        printf("\n");
    }
    
    
    float avg = sum / 3;
    
    printf("Average: %.2f", avg);
    
    
    return 0;
}