#include <stdio.h>

int main(void) {

    printf("Enter the number of bids: ");
    int nobids;
    scanf("%d", &nobids);

    if (nobids<2) {
        printf("The number of bids must be at least 2");
    }

    else {

        int bids[nobids];
        int *bidsptr=bids;

        for (int i=0;i<=nobids;i++) {
            printf("Enter Bid %d: ", i+1);
            scanf("%d", bidsptr+i);
        }

        int highest=0;

        for (int c=0;c<=nobids;c++) {
            if (bids[c]>bids[c+1]) {
                highest=bids[c];
            }
            else {
                continue;
            }
        }
        printf("%d", highest);
    }
}