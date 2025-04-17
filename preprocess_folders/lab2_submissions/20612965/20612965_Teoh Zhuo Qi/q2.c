//lab 2 question 2
#include <stdio.h>

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][50], const float marks[], int count);

int main() {
    char names[3][50];
    float marks[3];
    
    for (int i = 0; i < 3; ++i) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }
    
    float average = calculateAverage(marks, 3);
    
    displayStudentData(names, marks, 3);
    printf("\n");
    printf("Average mark: %.2f\n", average);
    
    return 0;
}

float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][50], const float marks[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; ++i) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}
