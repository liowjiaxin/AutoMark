#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 50 //defining a const with the value 50 that represents the max length a name can be
#define NUM_OF_STUDENTS 3 //defining a const with the value 3 that represents how many students the program is reading


//this function is for reading student names and marks and storing them into their respective arrays
void register_student_data(char student_names[NUM_OF_STUDENTS][NAME_LENGTH], float marks[NUM_OF_STUDENTS]) {
    for(int i = 0; i<NUM_OF_STUDENTS; i++) { //running a for loop depending on the number of students
        printf("Enter the name of student %d: ", i+1);
        scanf(" %[^\n]", student_names[i]); //changing scanf so that it can read spaces and as such a name instead of stopping at a space

        printf("Enter the marks of student %d: ", i+1);
        scanf("%f", &marks[i]); //reading a float and storing it in marks 
    }
}

//this function is for calculating the avg marks
float calc_avg(float marks[NUM_OF_STUDENTS]) {
    float sum = 0; //initialising sum to 0
    for(int i = 0; i<NUM_OF_STUDENTS; i++) { //running a for loop to add all the marks together
        sum += marks[i];
    }

    float avg = sum / NUM_OF_STUDENTS; //diving the total marks by the number of students to get the avg
    return avg;
}

//this function is for displaying all the student data in a table like format
void display_student_data(char student_names[NUM_OF_STUDENTS][NAME_LENGTH], float marks[NUM_OF_STUDENTS]) {
    printf("\nStudent Names and Marks:\n"); //printing a header
    for(int i = 0; i<NUM_OF_STUDENTS; i++) {
        printf("%s: %.2f\n", student_names[i], marks[i]); //printing the names and marks one by one in the format of, NAME: MARKS
    }
}

int main(void) {
    char student_names[NUM_OF_STUDENTS][NAME_LENGTH]; //initialing a 2d char array to store names with a cap of 50 letters per name
    float marks[NUM_OF_STUDENTS]; //initialing an int array to store the marks of each student  

    register_student_data(student_names, marks); //reading student names and marks 

    float avg = calc_avg(marks); //initialising avg and storing the average marks in avg

    display_student_data(student_names, marks); //displaying student data

    printf("\nAverage Mark: %.2f\n", avg); //printing the avg marks

    return  0;
}