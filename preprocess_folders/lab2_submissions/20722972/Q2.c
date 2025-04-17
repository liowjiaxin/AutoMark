// QUESTION 2

#include<stdio.h>
#define ARR_SIZE 3
#define MAX_NAME 50

// function prototypes
float calculateAverage(const float mark_arr[], size_t arr_size);
void displayStudentData(const char name_arr[][MAX_NAME], const float mark_arr[], size_t arr_size);

// function main begins program execution
int main(void){
    // initialise array and other variables
    char name_arr[ARR_SIZE][MAX_NAME];
    float mark_arr[ARR_SIZE];
    float input_mark=0.0;
    float avg=0.0;

    // prompt the user to enter the values of the three student names and marks one by one
    for(int i=0; i<ARR_SIZE; i++){
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", name_arr[i]); // ignore newline command
        printf("Enter the mark of student %d: ", i+1);
        scanf("%f", &input_mark);
        mark_arr[i]=input_mark;
    } 

    // display output
    displayStudentData(name_arr, mark_arr, ARR_SIZE);
}

// ============== OTHER FUNCTIONS ==================
// calculates average of all elements of given array
float calculateAverage(const float mark_arr[ARR_SIZE], size_t arr_size){
    float sum=0.0;
    for(int i=0; i<arr_size; i++){
        sum+=mark_arr[i];
    }
    return sum/arr_size; // return average (no casting required as sum is a float)
}

// displays names and marks of each student, and average of all marks at the end in formatted table
void displayStudentData(const char name_arr[ARR_SIZE][MAX_NAME],const float mark_arr[ARR_SIZE], size_t arr_size){
    puts("========== RESULTS ==========");
    printf("%-21s|%7s","Name", "Marks");
    printf("%s","\n-----------------------------");
    // loop to display each row entry
    for(int i=0; i<arr_size; i++){
        printf("\n%-21s|%7.2f", name_arr[i], mark_arr[i]);
    }
    printf("%s","\n-----------------------------");
    // display average row
    printf("\n%-21s|%7.2f", "Average mark", calculateAverage(mark_arr, arr_size));
}