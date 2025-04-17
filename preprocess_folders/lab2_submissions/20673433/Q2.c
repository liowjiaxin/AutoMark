#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    int i;


    for (i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Read student name

        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]); 
    }

   
    float average = calculateAverage(marks, STUDENT_COUNT);

    
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("Average mark: %.2f\n", average);

    return 0;
}


float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}


void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %s, Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
