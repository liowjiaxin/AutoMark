#include<stdio.h>
#define numstudents 3
#define NAME_LENGTH 50

// function prototypes
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]); // NAME_LENGTH 50

int main(){
    char names[numstudents][NAME_LENGTH]; //Array for names
    float marks[numstudents];             // Array for marks
    int i;

    //Input loop to get names and marks
    for (i=0; i<numstudents; i++){
        printf("Enter the name of student %d: ",i+1);
        scanf(" %[^\n]", names[i]);
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &marks[i]);
    }

    //Calculate average
    float average= calculateAverage(marks, numstudents);
    displayStudentData(names, marks);
    printf("Average Mark: %.2f\n", average);

    return 0;
}

//Function to calculate average of marks
float calculateAverage(const float marks[], int count){
    float sum = 0.0;
    for (int i =0; i< count; i++){
        sum+= marks[i];
    }
    return sum/count;
}

//Function to display names and marks
void displayStudentData(const char names[][NAME_LENGTH], const
float marks[]){
    printf("\nStudent Names and Mark: \n");
    for (int i=0; i< numstudents; i++){
        printf("%s: %.2f\n", names[i],marks[i]);
    }
}