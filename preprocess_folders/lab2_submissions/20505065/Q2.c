#include <stdio.h>
#define NAME_LENGTH 50
#define STUDENT_COUNT 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[STUDENT_COUNCIL][NAME_LENGTH];
    float marks[STUDENT_COUNT];
    float average;
    
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    
    average = calculateAverage(marks, STUDENT_COUNCIL);
    
    displayStudentData(names, marks);
    printf("Average Mark: %.2f\n", average);
    
    return 0;
}

float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf('%s: %.2f\n", names[i], marks[i]);
    }
}