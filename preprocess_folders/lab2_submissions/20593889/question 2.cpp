#include <stdio.h>
 
//set the condition for the names
#define name_length 50
#define num_students 3

//calculation of average steps
float calculateaverage(const float marks[], int count) 
{
    float sum = 0.0;
    for (int i = 0; i < count; ++i) 
    {
        sum = sum + marks[i];
    }
    return sum / count;
}

//displaying student names and marks
void displaydata(const char names[][name_length], const float marks[], int count) {
    printf("\nstudent names and marks:\n");
    for (int i = 0; i < count; ++i) 
    {
        printf("%s: %.2f\n", names[i], marks[i]);
    }
}

int main() {
    char studentnames[num_students][name_length];
    float studentmarks[num_students];

    for (int i = 0; i < num_students; ++i) 
    {
        printf("enter the name of student %d: ", i + 1);
        scanf(" %[^\n]", &studentnames[i], name_length);

        printf("enter the mark of student %d: ", i + 1);
        scanf("%f", &studentmarks[i]);
    }

    //using calculateaverage to get the average after getting the numbers needed
    float averagemark = calculateaverage(studentmarks, num_students);
    
    //using displaydata to see the data
    displaydata(studentnames, studentmarks, num_students);

    //print the answer
    printf("\naverage mark: %.2f\n", averagemark);

    return 0;
}