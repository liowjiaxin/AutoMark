#include <stdio.h>

//define size
#define STUDENT_COUNT 3
#define NAME_LENGTH 50

//calculate average score
float calcAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

//output display for student names and their marks
void displayData(const char names[][NAME_LENGTH], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

//main
int main() {
    char names[STUDENT_COUNT][NAME_LENGTH];
    float marks[STUDENT_COUNT]; 
    float average;

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    average = calcAverage(marks, STUDENT_COUNT);

    displayData(names, marks, STUDENT_COUNT);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}
