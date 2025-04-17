#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_BIDS_SIZE 2
#define MIN_BID_AMOUNT 100000

int get_int(const char *prompt, int *dest) {
	int status;
	do {
		fflush(stdin);
		fprintf(stdout, prompt);
		status = scanf(" %d", dest);
		if (status == EOF) {
			return EOF;
		}
	} while (status != 1);

	return 0;
}

int main(void) {
	int num_bids = 0;
	int *bids;

	if (get_int("Enter the number of bids: ", &num_bids) == EOF) {
		return 1;
	}

	while (num_bids < MIN_BIDS_SIZE) {
		if (get_int("Error: Number of bids must be at least 2. Please try again: ", &num_bids) == EOF) {
			return 1;
		}
	}

	bids = malloc(num_bids * sizeof(int));
	if (bids == NULL) {
		return 2;
	}

	printf("Enter the bids (must be at least $%d):\n", MIN_BID_AMOUNT);

	int highest_bid = 0;
	char prompt[100];
	for (int i = 0; i < num_bids; ++i) {
		sprintf(prompt, "Bid %d: ", i + 1);
		if (get_int(prompt, &(bids[i])) == EOF) {
			return 1;
		}

		while (bids[i] < MIN_BID_AMOUNT) {
			sprintf(prompt, "Error: Bid must be at least $%d. Please try again: ", MIN_BID_AMOUNT);
			if (get_int(prompt, &(bids[i])) == EOF) {
				return 1;
			}
		}

		if (highest_bid < bids[i]) {
			highest_bid = bids[i];
		}
	}

	printf("The highest bid is: $%d\n", highest_bid);

	free(bids);

	return 0;
}