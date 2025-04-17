// c program that prompts userinput for studetn name and marks 

#include <stdio.h>
#define n 3 // number of students 
#define l 50 // the length of string



//function prototypes declared
float calculateAverage(const float marks[], int count);
void displayStudentData(const char names[][l], const float marks[], int count);

//functions that will carry out the required calculations, first average
float calculateAverage(const float marks[], int count){
float sum =0;
for(int i=0; i < count; i++){
sum+=marks[i];                // this will add all the marks together
}
return sum / count;            //since sum already declared as float, this will calculate average in float.
}

// display the stored data
void displayStudentData(const char names[][l], const float marks[], int count){

printf("\nStudent Names and Marks:");   //print on new line

for( int i=0; i < count; i++ ){
    printf("%s: %.2f", names[i], marks[i]);     //print the names and marks that are stored
}
}  


int main(){
//declare the variables 
char names[n][l];
float marks[n]; 

//userinput for name and marks
for( int i =0; i < n; i++){ 
    printf("Enter the name of student %d: ", i+1);
     getchar();
    scanf("%[^\n]", names[i]);

    printf("Enter the mark of student %d: ", i +1);
    scanf("%.2f", &marks[i]); // this will read the marks entered by user 
   
}


//call the functions to perform their tasks

float average = calculateAverage(marks, n);   //create formula to calculate avg

// display the result
displayStudentData(names, marks, n);
printf("Average mark: %.2f", average);
return 0;
}

