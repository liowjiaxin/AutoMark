#include <stdio.h>

#define NAME 50
#define TOTALSTD 3

float calAverage(const float mark[], int count);
void disData(const char name[][NAME], const float mark[], int count);

int main(void) {
    char name[TOTALSTD][NAME];
    float mark[TOTALSTD];
    int i;

    //Input names and marks
    for (i = 0; i < TOTALSTD ; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", name[i]); // Read name with spaces
        printf("Enter the mark of student %d: ", i + 1);
        scanf("%f", &mark[i]);    // Read mark
    }

    //Calculate and display the average mark
    float average = calAverage(mark,TOTALSTD);

    //Display data
    disData(name, mark,TOTALSTD);
    printf("\nAverage Mark: %.2f\n", average);

}

//Function to calculate the average mark
float calAverage(const float mark[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += mark[i];
    }
    return sum / count;
}

//Function to display names and marks
void disData(const char name[][NAME], const float mark[], int count) {
    printf("\nStudent Names and Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", name[i], mark[i]);
    }
}
