#include <stdio.h>

int main() {
    int num_students = 3;       
    char names[3][50];            
    int marks[3];
    float average;


    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }


    int sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += marks[i];
    }
    average = (float)sum / num_students;


    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", names[i], marks[i]);
    }

    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}
