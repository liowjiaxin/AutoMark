#include <stdio.h>
#define STUDENT_AMOUNT 3
#define NAME_LENGTH 50


float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count);

int main() {
    char names[STUDENT_AMOUNT][NAME_LENGTH]; 
    float marks[STUDENT_AMOUNT];            
    float average;

// Input the name and grade
    for (int i = 0; i < STUDENT_AMOUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

//determine average
    average = calculateAverage(marks, STUDENT_AMOUNT);


    displayStudentData(names, marks, STUDENT_AMOUNT);
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


void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Name and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}