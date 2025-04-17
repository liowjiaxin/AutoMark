#include <stdio.h>

#define NAME_LENGTH 50
#define NUM_STUDENTS 3

// Function prototypes
float calculateAverage(const int marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const int marks[], int count);

int main() 
{
    char names[NUM_STUDENTS][NAME_LENGTH]; //initiallize the size of arrays and define the max size
    int marks[NUM_STUDENTS]; 

    //prompt user for student names and marks
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", names[i]); //put the name in names array at index [i]

        printf("Enter the mark of student %d: ", i + 1);
        scanf("%d", &marks[i]); //put marks in marks array at index [i]
    }

    //calculate average mark using prototype given by question
    float averageMark = calculateAverage(marks, NUM_STUDENTS);

    //display student data and average mark using funciton
    printf("\nStudent Names and Marks:\n");
    displayStudentData(names, marks, NUM_STUDENTS);
    printf("Average Mark: %.2f\n", averageMark);

    return 0;
}

//fucntion to calculate the average mark
float calculateAverage(const int marks[], int count) //use const bc pass by value
{
    int sum = 0; //initialize sum
    for (int i = 0; i < count; i++) //loop to add sum from the students
    { 
        sum += marks[i]; //accumulate the sum of total marks
    }
    return (float)sum / count; //casting sum as a float so can get the result of avg mark as float
}

//funtion to display student names and marks
void displayStudentData(const char names[][NAME_LENGTH], const int marks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", names[i], marks[i]);
    }
}
