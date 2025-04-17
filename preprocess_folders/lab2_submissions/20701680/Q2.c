#include <stdio.h>


typedef struct {
    char name[50];
    float mark;
} Marks;


float CalculateAverage(float sum, int count) {
    return sum / count;
}

int main() {
    Marks Students[3];
    float average;
    float sum = 0;

  
    for (int k = 0; k < 3; k++) {
        printf("\nEnter the name of student %d: ", k + 1);
        scanf("%s", Students[k].name); 
        printf("Enter mark of student %d: ", k + 1);
        scanf("%f", &Students[k].mark); 
    }

    
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.1f\n", Students[i].name, Students[i].mark);
        sum += Students[i].mark; 
    }

   
    average = CalculateAverage(sum, 3);
    printf("\nAverage mark: %.1f\n", average);

    return 0;
}

