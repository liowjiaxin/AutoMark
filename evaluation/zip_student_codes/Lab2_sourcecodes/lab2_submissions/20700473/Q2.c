#include<stdio.h>
#define NAME_LENGTH 50
#define NUMBER_STUDENT 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[], int count, float average);

int main (void){
    char names[NUMBER_STUDENT][NAME_LENGTH];
        float marks[NUMBER_STUDENT];
        int count = NUMBER_STUDENT;
        for (int i = 0; i < count; i++) {
            printf("Enter name of student %d: ", i + 1);
            scanf(" %[^\n]", names[i]); // Read the student's name
            printf("Enter mark of student %d: ", i + 1);
            scanf("%f", &marks[i]); // Read the student's mark
        }

        // Step 2: Calculate the average mark
        float average = calculateAverage(marks, count);
        displayStudentData(names, marks, count, average);
        return 0;
}

float calculateAverage(const float marks[], int count) {
    float sum = 0.0;
    int averageresult = 0.0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks [], int count, float average) {
    printf("\nStudent Name and Marks: \n");
    for (int i = 1; i <= count; i++) {
        printf("%s: %.2f\n", names[i-1], marks[i-1]);
    }
    printf("\nAverage Mark: %.2f\n", average);
}
