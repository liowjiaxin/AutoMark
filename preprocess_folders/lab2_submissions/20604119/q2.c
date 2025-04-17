//Question 2
#include <stdio.h>
#define NAME_LENGTH 50
#define STUDENT_COUNT 3

//Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT];

    //Prompta the user to enter the values of the three student names and marks one by one
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    //Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    //Display student names and marks and the average mark
    displayStudentData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}

//Function to calculate the average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

//Function to display student names and marks and the average mark
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
