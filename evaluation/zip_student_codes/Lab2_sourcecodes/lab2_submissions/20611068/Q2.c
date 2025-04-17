#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define NUM_STUDENTS 3


float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nName:%s\nMarks:%.2f\n", names[i], marks[i]);
    }
    float average = calculateAverage(marks, NUM_STUDENTS);
    printf("\nAverage Mark: %.2f\n", average);
}

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);

        printf("Enter marks for student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    displayStudentData(names, marks);

    return 0;
}