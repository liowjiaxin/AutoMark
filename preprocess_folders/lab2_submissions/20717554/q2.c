#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf_s(" %[\n]", names[i]);

        printf("Enter the mark of student %d: ", i + 1);
        while (scanf_s("%f", &marks[i]) != 1) {
            printf("Invalid input. Please enter a valid mark for student %d: ", i + 1);
            while (getchar() != '\n');
        }
    }

    displayStudentData(names, marks);

    float average = calculateAverage(marks, NUM_STUDENTS);
    printf("\nAverage Mark: %.2f\n", average);

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
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
