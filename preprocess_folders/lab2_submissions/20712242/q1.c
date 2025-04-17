// c program array on integers and two target indices of the two elements in array from user. 

#include <stdio.h>

int main(){

// ask for user input 

int n;

printf("Enter the size of the array ( N >= 5): ");

while (1){
      scanf("%d", &n);  
      if( n >= 5){
    break;                         //read userinput where n has to be greater or equal to 5
   }
}

//get those n integers in array by the user by using for loop 

int arr[n];
printf("Enter the array elements: \n", n);
for(int i =0; i < n; i++){
    printf("Element %d: ", i );
    scanf("%d", &arr[i]);
}

// user user for indices of the two elements required. 

int index1;
int index2;

while (1){
printf("Enter the indices of the two elements (0 <= index1, index2 < 6): ");
scanf("%d %d", &index1, &index2);
if( index1 >=0 && index1 < n || index2 >=0 && index2 < n){
    break;
}
printf("Error: Inidces must be wihtin the range of the array elements. Please try again.");     //display error message if values are outside range 
}

// sum

int sum= arr[index1]  + arr[index2]; //add the two indexes 

//display the answer
printf("The sum of the values at indices 4 and 5 is: %d", sum);
return 0;
}
