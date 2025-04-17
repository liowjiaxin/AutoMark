#include <stdio.h>
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    // Prompt the user to enter the names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 

        printf("Enter the marks of %s: ", names[i]);
        scanf("%f", &marks[i]);
    }

   
    displayStudentData(names, marks);

    // Calculate and display the average marks
    float average = calculateAverage(marks, STUDENT_COUNT);
    printf("The average marks of the students: %.2f\n", average);

    return 0;
}

// calculate the average marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

//  display student data
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d: %s, Marks: %.2f\n", i + 1, names[i], marks[i]);
    }
}
