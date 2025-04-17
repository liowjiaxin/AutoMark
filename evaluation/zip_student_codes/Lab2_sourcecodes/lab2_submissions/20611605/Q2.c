#include <stdio.h>

int main() {
    //initialise variables
    char student1[50], student2[50], student3[50];
    float marks[3];

    //ask for first student and marks
    printf("Enter name of first student: "); 
    scanf("%s", student1);
    printf("Enter marks of first student: ");
    scanf("%f", marks);

    //ask for second student and marks
    printf("Enter name of first student: "); 
    scanf("%s", student2);
    printf("Enter marks of first student: ");
    scanf("%f", marks + 1);

    //ask for third student and marks 
    printf("Enter name of first student: "); 
    scanf("%s", student3);
    printf("Enter marks of first student: ");
    scanf("%f", marks + 2);

    //display marks 
    printf("Student Names and Marks\n");
    printf("%s: %.2f\n",student1, *marks);
    printf("%s: %.2f\n",student2, *(marks + 1));
    printf("%s: %.2f\n",student3, *(marks + 2));

    //display average 
    printf("\nAverage Mark: %.2f",((*(marks)) + (*(marks + 1)) + (*(marks + 2)))/3);
}
