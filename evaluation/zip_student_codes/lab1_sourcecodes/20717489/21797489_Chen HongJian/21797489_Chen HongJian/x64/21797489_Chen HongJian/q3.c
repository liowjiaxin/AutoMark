#include<stdio.h>
int main()
{
	int cnt = 0;
	int quantity = 0;
	int price = 0;
	int discount = 0;
	int total = 0;
	int final = 0;
	printf("Enter the product code(1 for fruits, 2 for vegetables, 3 for Dairy products, 4 for canned goods, 0 to exit):");
	scanf_s("%d", &cnt);
	if (cnt == 0)
	{
		printf("exit!");
	}
	else
	{
		switch (cnt)
		{
		case 1: printf("Enter the weight of fruits(in kg):");
			scanf_s("%d", &quantity);
			printf("Enter the price per kg of fruits:");
			scanf_s("%d", &price);
			break;
		case 2: printf("Enter the weight of veggies(in kg):");
			scanf_s("%d", &quantity);
			printf("Enter the price per kg of veggies:");
			scanf_s("%d", &price);
			break;
		case 3: printf("Enter the price of this item:");
			scanf_s("%d", &price);
			quantity = 1;
			break;
		case 4: printf("Enter the quantity of canned goods:");
			scanf_s("%d", &quantity);
			break;
		}
		printf("Enter discount percentage(or 0 for no discount):");
		scanf_s("%d", &discount);
		total = price * quantity;
		final = total * (1 - discount * 0.01);
		printf("The total cost is %d\n", total);
		printf("The final cost after applying the discount is %d", final);
	}
	return 0;
}