#include <stdio.h>

#define STUDENT_COUNT 3
#define NAME_LENGTH 50


float calculateAverage(const float marks[], int count);
void studentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT]; 

    //Input student names and marks
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); 

        printf("Enter the mark for studet %s: ", names[i]);
        scanf("%f", &marks[i]);
    }

    //Calculate the average mark
    float average = calculateAverage(marks, STUDENT_COUNT);

    //Display student data and the average mark
    studentData(names, marks);
    printf("Average mark: %.2f\n", average);

    return 0;
}

//Calculate the average of marks
float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

//Display student data
void studentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
}
