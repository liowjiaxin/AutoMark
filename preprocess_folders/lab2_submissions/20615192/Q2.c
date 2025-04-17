#include <stdio.h>
#define NAME_LENGTH 50

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);//NAME_LENGTH 50

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i<3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}


int main() {
    char names[3][NAME_LENGTH];
    float marks[3];

    for (int i=0; i<3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    displayStudentData(names, marks);
    float average = calculateAverage(marks,3);
    printf("Average Mark: %.2f\n", average);

    return 0;
}



