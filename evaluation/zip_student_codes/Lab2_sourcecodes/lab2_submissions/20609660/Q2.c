#include <stdio.h>
#define ARRAYSIZE 3

int main(void)
{
    // Initialisation
    char studentNameArr[ARRAYSIZE][50]; // Allocate memory for each student's name
    int studentMarksArray[ARRAYSIZE] = {0};

    // Function prototype
    double calculateAverageMarks(int studentMarksArray[]);
    void displayFunction(char studentNameArray[][50], int studentMarksArray[], double averageMarks);

    // Get the student's name and marks from user and store it in the array by looping through the index
    for (size_t i = 0; i < ARRAYSIZE; i++)
    {

        // Prompt user to enter student's name
        printf("Enter Student %d name (Not more than 50 characters): ", i + 1);
        scanf(" %[^\n]", studentNameArr[i]);

        // Prompt user to enter student's marks
        printf("Enter Student %d marks: ", i + 1);
        scanf(" %d", &studentMarksArray[i]);
    }

    // Calculate the average marks of the students
    double averageMarks = calculateAverageMarks(studentMarksArray);

    // Display the student's name, marks and average marks
    displayFunction(studentNameArr, studentMarksArray, averageMarks);
}

// Function to display the student's name, marks and average marks
void displayFunction(char studentNameArray[][50], int studentMarksArray[], double averageMarks)
{
    printf("Student's Name and Marks:\n");
    for (size_t i = 0; i < ARRAYSIZE; i++)
    {
        printf("%s: %d\n", studentNameArray[i], studentMarksArray[i]);
    }

    printf("\nAverage marks: %.2f", averageMarks);
}

// Function to calculate the average marks of the students
double calculateAverageMarks(int studentMarksArray[])
{
    // Initialisation
    int sum = 0;
    double averageMarks = 0;

    // Loop through the array to get the value stored
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        // Store all the values in the array into sum
        sum += studentMarksArray[i];
    }
    // Calculate the average marks
    averageMarks = (double)sum / ARRAYSIZE;

    return averageMarks;
}