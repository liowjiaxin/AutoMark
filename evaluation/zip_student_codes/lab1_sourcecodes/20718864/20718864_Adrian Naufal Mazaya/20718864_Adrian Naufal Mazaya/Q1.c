
#include <stdio.h>
int sum(int a, int b, int c);


int main(void) {

// Question 1

    // define i and j as int
    int i;
    int j;

    //create a nested loop and 2d arrat for the asterix (*)  
    for (i = 0; i<8; i++) {
      for (j = 0 ; j<9 ; j++){  
            printf("*");
        }
        // this what makes it 2d, it prints after the 8th asterix and then so on (8, 16, 24, etc)
        printf("\n");
    }

    printf("\n");



    return 0;
}
    

int sum(int a, int b, int c){
return a + b + c;

}