#include <stdio.h>

#define NUM_STUDENTS 3
#define NAME_LENGTH 50
float calculateaverage(const float marks[], int count);
void displaystudentdata(const char names[][NAME_LENGTH], const float marks[]);// Function prototypes

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];
    
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);// get name from user
        scanf(" %s", names[i]);  //read name
        printf("Enter the mark of student %d: ", i + 1);//get mark from user
        scanf("%f", &marks[i]);//read marks
    }

    // the average mark of studnets
    float average = calculateaverage(marks, NUM_STUDENTS);

    // tell user student data and average mark
    displaystudentdata(names, marks);
    printf("Average Mark: %.2f\n", average);

    return 0;
}

// the structure of function 
float calculateaverage(const float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;//in the end we can get the value of sum/count
}

// Function to display student names and marks
void displaystudentdata(const char names[][NAME_LENGTH], const float marks[]) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);//do it ,we can get names and marks  
    }
}
