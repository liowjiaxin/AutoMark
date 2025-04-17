#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 50
#define NUM_STUDENTS 3

float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][NAME_LENGTH], const float marks[]);

int main() {
    char names[NUM_STUDENTS][NAME_LENGTH];
    float marks[NUM_STUDENTS];

    // Prompt user for names and marks
    for (size_t i=0; i<NUM_STUDENTS; i++) {
        // Input names
        printf("Name of Student %d: ", i+1);
        fgets(names[i], NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Removes trailing newline of fgets return value

        // Input marks
        while (1) {
            printf("Mark of Student %d: ", i+1);
            scanf("%f", &marks[i]);
            getchar(); // scanf leaves the newline in the input buffer, getchar removes it so that the next fgets works

            // Mark validation
            if (0 <= marks[i] && marks[i] <= 100) {
                break;
            } else {
                puts("Mark needs to be in range 0-100. Please try again.");
            }
        }
    }
    puts("");
    displayStudentData(names, marks); // DisplayStudentData function call

    return 0;
}

// Calculate average of marks in an array and returns float
float calculateAverage(const float marks[], int count) {
    float sum = 0;
    for (size_t i=0; i<count; i++) {
        sum += marks[i];
    }
    return sum/count;
}

void displayStudentData(const char names[][NAME_LENGTH], const float marks[]) {
    puts("Student Names and Marks:");

    // Prints in format NAME: MARK
    for (size_t i = 0; i<NUM_STUDENTS; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
    puts("");

    // Calls calculateAverage and passes the result into the printf statement
    printf("Average Mark: %.2f", calculateAverage(marks, NUM_STUDENTS)); 
}