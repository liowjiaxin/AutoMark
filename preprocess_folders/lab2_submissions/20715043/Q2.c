#include <stdio.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    //input student name and mark
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    //find the average
    float average = calculateAverage(marks, STUDENT_COUNT);

    //display
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage mark: %.2f\n", average);

    return 0;
}

//calculate average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

//display average mark, names, and student marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks: \n");
    for (int i = 0; i < count; i++) {
        printf("%s,: %.2f\n", names[i], marks[i]);
    }
}
