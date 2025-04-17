#include <stdio.h>

int main() {
    //Store user information (names & marks)
    char names[3][50]; // Number of student (3), Name length (50)
    float marks[3];
    int i;

    //Prompt user input
    for (i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]); // Input name (handles spaces)
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]); // Input marks
    }

    //calculate average mark
    float Average(const float marks[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

    //Display student names, marks, and the average marks
    void displayStudentData(const char names[][50], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

    float average = Average(marks, 3);

    //Display student data and average mark
    displayStudentData(names, marks, 3);
    printf("\nAverage Mark: %.2f\n", average);

    return 0;
}