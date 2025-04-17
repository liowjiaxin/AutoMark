#include <stdio.h>

// Function to call to calculate the average
float calculate_average(float marks[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += marks[i];
    }
    return sum / count;
}

int main(void) {
    char names[3][100]; // Array to store names of 3 students, length to 100 characters
    float marks[3];     // Array to store marks

    // loop 3 times
    for (int i = 0; i < 3; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", names[i]); // Store name in the array
        printf("Enter student %d mark: ", i + 1);
        scanf("%f", &marks[i]); // Store mark as a float
    }

    // Print all student names and marks
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", names[i], marks[i]);
    }

    // Calculate and print the average of marks
    float average = calculate_average(marks, 3);
    printf("\nAverage Marks: %.2f\n", average);

    return 0;
}
