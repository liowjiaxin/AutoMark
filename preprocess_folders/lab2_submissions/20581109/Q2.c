#include <stdio.h>
// declaring global variables
int sum, i, average;
char studName[3][50];
float mark[3];
// Declaring function to print names and marks
void myFunction(char studName[][50], float mark[]) {
    printf("Student names and marks:\n");
    for (int i = 0; i < 3; i++) { // Loop through the array
        printf("%s: %.2f\n", studName[i], mark[i]); // Corrected format specifiers
    }
}

void averageMark(float mark[]) {
    sum = mark[0] + mark[1] + mark[2];
    average = sum / 3;
    printf("average mark: %f", average);
}


int main() {
    // Loop to input data for 3 students
    for (i = 0; i < 3; i++) {
        printf("Enter the name of student %d:", i + 1);
        // storing name in the array
        scanf("%s", studName[i]);
        printf("Enter the mark of student %d:", i + 1);
        // Store mark in the array
        scanf("%f", &mark[i]);
    }

    // Call the myfunction to print the results
    myFunction(studName, mark);
    // Call averageMark to print the average
    averageMark(mark);

    return 0;
}
