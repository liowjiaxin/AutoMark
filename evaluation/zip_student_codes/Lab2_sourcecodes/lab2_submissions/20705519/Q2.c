#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]); // NAME_LENGTH 50 

int main () {
    char names[3][NAME_LENGTH];
    float marks[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i+1);
        fgets(names[i], NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = 0;

        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]);
        getchar();
    }

    displayStudentData(names, marks);

    printf("\nAverage Mark: %.2f", calculateAverage(marks, 3));

    return 0;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
} 

float calculateAverage(const float marks[], int count) {
    float average = 0;
    for (int i = 0; i < count; i++) {
        average += marks[i];
    }
    average /= 3;

    return average;
}