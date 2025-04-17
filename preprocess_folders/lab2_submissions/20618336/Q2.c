#include <stdio.h>
//QUESTION 2

int main() {
    char name1[50], name2[50], name3[50];// Variables to store the names of 3 students, each with a maximum length of 50 characters
    
    float mark1, mark2, mark3, average; // Variables to store the marks of three students (mark1, mark2, mark3) and the average of the marks.


    //  Key in Data for student 1
    printf("Enter the name of student 1: ");
    scanf("%s", name1);
    
    printf("Enter the mark of student 1: ");
    scanf("%f", &mark1);
    
    

    // Key in Data for student 2
    printf("Enter the name of student 2: ");
    scanf("%s", name2);
    
    printf("Enter the mark of student 2: ");
    scanf("%f", &mark2);
    
    

    // Key in Data for student 3
    printf("Enter the name of student 3: ");
    scanf("%s", name3);
    
    printf("Enter the mark of student 3: ");
    scanf("%f", &mark3);
    
    

    
    average = (mark1 + mark2 + mark3) / 3; //Calculate the average of the total marks

    
    printf("\nStudent Names and Marks:\n"); //Display the Results
    printf("%s: %.2f\n", name1, mark1);
    printf("%s: %.2f\n", name2, mark2);
    printf("%s: %.2f\n", name3, mark3);
    printf("\nAverage Mark: %.2f\n", average); 0//Display the result of the average

    return 0;
}
