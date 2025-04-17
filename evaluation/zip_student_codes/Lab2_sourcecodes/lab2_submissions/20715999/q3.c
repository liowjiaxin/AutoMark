#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main(void){
    char input[50] = "\0";
    long bids[50] = {0};
    int N = 0;
    long highest_bid = 0;

    do {
        printf("Enter number of bids N (N >= 2): ");
        standard_input(input, sizeof(input)); // Get input
        if (!is_digit(input)) continue; // Get input again
        N = atoi(input); // Convert string to int
        if (N < 2) puts("The highest bid can not be determined");
    } while (N < 2);

    for (int i = 0; i < N;) {
        printf("Bid %d: $", i + 1);
        standard_input(input, sizeof(input));
        if (!is_digit(input)) continue; // Get input again if not a number
        bids[i] = atol(input); // Convert string to long
        if (bids[i] < 100000) {
            puts("Each bid must be at least $100,000");
            continue; // Get input again
        }
        i++; // Get next bid
    }

    for (int j = 0; j < N; j++) {
        if (bids[j] > highest_bid) highest_bid = bids[j]; // Update highest bid through the array of bids
    }

    printf("The highest bid is %ld", highest_bid);
}