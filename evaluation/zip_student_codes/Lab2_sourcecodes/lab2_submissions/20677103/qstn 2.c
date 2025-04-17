#include <stdio.h>
float average(int a, int b, int c);


int main(){
    int rows=3;
    int columns=1;
    char name1[50];
    char name2[50];
    char name3[50];
    int marks1;
    int marks2;
    int marks3;
    
    int marks[columns][rows];//initialize a 2d array
    printf("enter name of studnet 1:");//ask for names and marks
    scanf("%s",name1);
    printf("enter name of studnet 2:");
    scanf("%s",name2);
    printf("enter name of studnet 3:");
    scanf("%s",name3);
    printf("enter marks of student 1:");
    scanf("%d",&marks1);
    printf("enter marks of student 2:");
    scanf("%d",&marks2);
    printf("enter marks of student 3:");
    scanf("%d",&marks3);
    float avg =average(marks1,marks2,marks3);//initailize avg that prints the function
    printf("the average marks are %.2f\n",avg);

    

    

    return 0;


}
float average(int a,  int b, int c){ //define the function
    return  (a+b+c)/3.0;//return the avg
}



