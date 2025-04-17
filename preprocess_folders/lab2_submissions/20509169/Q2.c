#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define STUDENT_COUNT 3

float calculate_average(const float marks[], int count);
void displaystudentdata(const char names[][NAME_LENGTH], const float marks[]);

int main()
{
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d:\n", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the marks of student %d:\n", i + 1);
        
        scanf("%f", &marks[i]);
        
        while (getchar() != '\n');
    }
    displaystudentdata(names, marks);
    return 0;
}

float calculate_average(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displaystudentdata(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudents name and Marks:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("\nAverage Marks: %.2f\n", calculate_average(marks, STUDENT_COUNT));
}
