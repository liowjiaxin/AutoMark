#include <stdio.h>
#define NAME_LENGTH 50

float average(const float marks[], int count) {
    float sum = 0; //initialize sum to 0
    //for loop to add all elements of my array 
    for (int i = 0; i < count; i++)
    {
        sum += marks[i];
    }
    float mean = sum / (float)count; //calculate average
    return mean;
}

void displayData(const char names[][NAME_LENGTH], const float marks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Student Name: %s, Mark: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char studentName[3][NAME_LENGTH]; //2d array for 3 names of maximum 50 letters each
    float studentMarks[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of the student %d: ", i + 1);
        scanf("%s", studentName[i]);
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &studentMarks[i]);
    }

    float avg = average(studentMarks, 3);

    displayData(studentName, studentMarks, 3);
    printf("Average mark is %.2f", avg);
}


