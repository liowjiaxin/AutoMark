#include <stdio.h>
#define NAME_LENGTH 50
#define SIZE 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main(void) {
    char nameArray[SIZE][NAME_LENGTH]; 
    float mark[SIZE];

    for (int i = 0; i < SIZE; ++i) {        //get user input
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", nameArray[i]);

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &mark[i]);
    }

    displayStudentData(nameArray, mark);
    
    float average = calculateAverage(mark, SIZE);
    printf("Average Mark: %.2f\n", average);

}

float calculateAverage(const float marks[], int count) {
    float total = 0.0; 
    for (int j = 0; j < count; ++j) { 
        total += marks[j];      //element in the array sum together
    }
    return total / count;       //calculate the average
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    
    printf("Student Names and Marks:\n");
    
    for (int j = 0; j < SIZE; ++j) { 
        printf("%s : %.2f\n", names[j], marks[j]);      //print the student name and mark
    }
}
