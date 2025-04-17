#include <stdio.h>

#define STUDENT_COUNT 3   // number of students
#define NAME_LENGTH 50    // maximum length of student names


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH]; // array to store student names
    float marks[STUDENT_COUNT];            // array to store student marks
    float average;                         // variable to store the average marks

    // ask the user to enter student names and marks one by one
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // input name
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]); // input marks
    }

    // calculate the average marks
    average = calculateAverage(marks, STUDENT_COUNT);

    // display student data and average marks
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

// function to calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i]; // sum up all the marks
    }
    return sum / count; // return the average
}

// function to display student data and their marks
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s : %.2f\n",names[i], marks[i]);
    }
}
