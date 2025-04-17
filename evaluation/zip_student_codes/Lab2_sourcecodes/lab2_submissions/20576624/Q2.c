#include <stdio.h>

#define NAME_LENGTH 50
#define NUM_STUDENTS 3

// Function
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    // 1) Input
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);  // Read a line of text including spaces

        printf("Enter mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // 2) Average
    float average = calculateAverage(marks, NUM_STUDENTS);

    // 3) Print accotding yo the structure 
    displayStudentData(names, marks);

    printf("Average mark: %.2f\n", average);

    return 0;
}

// Average mark
float calculateAverage(const float marks[], int count) {
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

// Display
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Data:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s : %.2f\n", names[i], marks[i]);
    }
}
