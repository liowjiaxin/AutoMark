#include <stdio.h>

#define scount 3
#define NAME_LENGTH 50



float calculateAverage(const float marks[], int count) {
    float sum = 0;
    int i;
    for (i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}


void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    int i;
    for (i = 0; i < scount; i++) {
        printf("Student Name: %s, Mark: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char names[scount][NAME_LENGTH];
    float marks[scount];
    float average;

    // Prompt to enter the three student names and marks 
    int i;
    for (i = 0; i < scount; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
        while (getchar() != '\n'); 

        printf("Enter mark for student %s: ", names[i]);
        scanf("%f", &marks[i]);
    }

    // Calculate average mark
    average = calculateAverage(marks, scount);

    // Display student names, marks, average mark
    displayStudentData(names, marks);

    printf("The average mark is: %.2f\n", average);

    return 0;
}

