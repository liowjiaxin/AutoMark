#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50

// Function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH],const float mark[], float average);

int main(){
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    float average;

    // Step 1: Input student names and marks
    for (int i=0;i <NUM_STUDENTS;i++){
        printf("Enter the name of students%d: ",i+1);
        scanf(" %[^\n]",names[i]);  // Read the full name with spaces
        printf("Enter the mark of student %d: ",i+1);
        scanf("%f", &marks[i]);

    }
    // Step 2: Calculate the average marks
    average = calculateAverage(marks, NUM_STUDENTS);

    // Step 3: Display studnet data and average marks 
    displayStudentData(names,marks,average);

    return 0;
}

// Function to calculate the average of marks
float calculateAverage(const float marks[], int count){
    float sum=0;
    for (int i=0; i<count; i++){
        sum+=marks[i];
    }
    return sum/count;
}

// Function to display student data and average marks
void displayStudentData(const char names[][NAME_LENGTH],const float marks[], float average){
    printf("\nStudent Names and Marks:\n");
    for (int i=0; i<NUM_STUDENTS; i++){
        printf("Name: %s, Marks: %.2f\n", names[i], marks[i]);
    }
    printf("Average Marks:%.2f\n",average);
    
}