#include <stdio.h>
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {

    char names[3][NAME_LENGTH] = {};
    float marks[3] = {};

    for (size_t i = 0; i < 3; i++) {
        printf("Enter student number %d: ", i + 1);
        scanf(" %[^\n]", &names[i]);

        printf("Enter mark of student %d: ", i + 1);
        scanf(" %f", &marks[i]);
    }
    
    printf("\nStudent names and marks:\n");
    displayStudentData(names, marks);

    float avg = calculateAverage(marks, 3);

    printf("\nAverage Mark: %.2f", avg);

    return 0;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

float calculateAverage(const float marks[], int count) {
    float sum = 0;

    for (size_t i = 0; i < count; i++) {
        sum += marks[i];
    }
    
    return sum/count;
}
