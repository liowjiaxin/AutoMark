#include <stdio.h>
#include <stdlib.h>

int main()
{

    int validnumberbids = 0;
    int numberofbids;
    int maxbid = 0;

    while (!validnumberbids)
    {
        printf("Enter the number of bids: ");
        scanf("%d", &numberofbids);

        if (numberofbids < 2)
        {
            printf("Number of bids must be at least 2. Please try again.\n");
        }
        else
        {
            validnumberbids=1;
        }
    }

    int *array = malloc(numberofbids * sizeof(*array)); // using malloc to dynamically allocate memory for size (from user input)

    for (int i = 0; i < numberofbids; ++i)
    {
        printf("Enter the bids (must be at least $100000): \n");
        printf("Bid %d:", i + 1);
        scanf("%d", &array[i]);
        if (array[i] < 100000)
        {
            printf("Bid must be at least $100000. Please try again.\n");
        }

        for (int i = 0; i < numberofbids; ++i)
        {
            if (array[i] > maxbid)
            {
                maxbid = array[i];
            }
        }
    }

    printf("The highest bid is: $%d", maxbid);
}