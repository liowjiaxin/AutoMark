#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LENGTH 50

void clear_buffer(void) {
    while (getchar() != '\n'); // Flush the input buffer
}

void standard_input(char input[], size_t size) {
    fgets(input, size, stdin); // Directly read into the passed array
    if (!strchr(input, '\n')) { // Check if the newline was not present (overflow occurred)
        clear_buffer(); // Clear the buffer
    } else {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character if present
    }
}

int is_digit(char input[]){
    for(int i = 0; i < strlen(input); i++){
        if(!isdigit(input[i])) {
            puts("Invalid input. Input must only contain digits.");
            return 0; // Test failed
        }
    }
    return 1; // Test pass
}

int is_alpha(char input[]){
    for(int i = 0; i < strlen(input); i++){
        if(!isalpha(input[i])) {
            puts("Invalid input. Input must only contain alphabets.");
            return 0; // Test failed
        }
    }
    return 1; // Test pass
}

float calculateAverage(const float marks[], int count){
    float average = 0;
    for (int i = 0; i < count; i++) {
        average += *(marks + i); // Sum total
    }
    average /= count; // Divide by count
    return average;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    puts("Students names and marks:");
    for(int i = 0; i < 3; i++) {
        printf("%s: %f\n", names[i], marks[i]);
    }
}

int main(void) {
    char input[50] = "\0";
    float marks[3] = {0};
    char names[3][NAME_LENGTH] = {0};
    for (int i = 0; i < 3;){
        while(1) {
            printf("Enter the name of student %d: ", i+1);
            standard_input(input, sizeof(input));
            if(!is_alpha(input)) continue; // Get input again
            strcpy(names[i], input); // Copy input into name
            break;
        }
        while(1){
            printf("Enter the marks of student %d: ", i+1);
            standard_input(input, sizeof(input));
            if(!is_digit(input)) continue; // Get input again
            marks[i] = atoi(input); // Convert string to int
            if (marks[i] > 100) {
                printf("Marks must be between 0-100");
                continue;
            }
            break;
        }
        i++; // Get next student
    }

    displayStudentData(names, marks);

    float average_mark = calculateAverage(marks, 3);

    printf("Average mark: %f", average_mark);
}