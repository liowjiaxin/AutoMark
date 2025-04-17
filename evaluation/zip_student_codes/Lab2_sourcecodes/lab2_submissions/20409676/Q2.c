#include <stdio.h>

int main() {
    char names[3][51];  
    float marks[3], calculateAverage; 
    int count;

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i + 1);
        // using scanf to read the full name with spaces
        scanf(" %[^\n]", names[i]);  // this will read until a newline is encountered
        
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);  // read the marks as a float
        
        count += marks[i]; //sums the marks of student
    }
    
    calculateAverage = (float)count / 3;

    //to Display name and marks
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    printf("\nAverage Mark: %.2f\n", calculateAverage); //displays average mark

    return 0;
}