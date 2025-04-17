#include <stdio.h>

int main()
{

  // used to store number of bids
  int num;

  printf("Enter the number of bids: ");
  scanf("%d", &num);
  getchar();

  // not >= 2
  if (num < 2)
  {
    while (1)
    {
      printf("Error: Number of bids must be at least 2. Please try again: ");
      scanf("%d", &num);
      getchar();

      if (num >= 2)
      {
        break;
      }
    }
  }

  int bidArray[num];

  printf("Enter the bids (must be at least $100000): \n");

  for (int i = 0; i < num; i++)
  {
    printf("Bid %d: ", i + 1);
    scanf("%d", &bidArray[i]);
    getchar();

    if (bidArray[i] < 100000)
    {
      // if we get error from previous output, keep asking for bid until the bid is more than 100000
      while (1)
      {
        printf("Error: Bid must be at least $100000. Please try again: ");
        scanf("%d", &bidArray[i]);
        getchar();

        if (bidArray[i] >= 100000)
        {
          break;
        }
      }
    }
  }

  int highestBid = bidArray[0];
  for (int i = 1; i < num; i++)
  {
    // compare if the highestBid value is more than next element in that array
    if (highestBid < bidArray[i])
    {
      highestBid = bidArray[i];
    }
  }
  printf("the highest bid is: $%d\n", highestBid);

  return 0;
}