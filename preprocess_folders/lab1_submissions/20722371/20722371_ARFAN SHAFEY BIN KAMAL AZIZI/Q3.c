#include <stdio.h>

int main()
{
    int code, weight, price, discount;
    float cost, disccost;

    printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to Exit): ");
    scanf("%d", &code); //input product code according to destination

    if (code == 1) //fruits
    {
        printf("\nEnter the weight of fruits (in kg) : "); 
        scanf("%d", &weight); //input weight

        printf("\nEnter the price per kg of fruits : ");
        scanf("%d", &price); //input price

        printf("\nEnter the discount percentage (0 for no discount) : ");
        scanf("%d", &discount); //input discount percentage

        cost = weight * price; //formula to obtain cost
        disccost = cost - (discount / 100.0) * cost; //formula to obtain discounted cost

        printf("\nThe total cost is : $%.2f", cost); //cost output
        printf("\nThe total discounted cost is : $%.2f", disccost); //discounted cost output
    }
    else if (code == 2) //vegetables
    {
        printf("\nEnter the weight of vegetables (in kg) : ");
        scanf("%d", &weight); //input weight

        printf("\nEnter the price per kg of vegetables : ");
        scanf("%d", &price); //input price 

        printf("\nEnter the discount percentage (0 for no discount) : ");
        scanf("%d", &discount); //input discount percentage

        cost = weight * price; //formula to obtain cost
        disccost = cost - (discount / 100.0) * cost; //formula to obtain discounted cost

        printf("\nThe total cost is : $%.2f", cost); //cost output
        printf("\nThe total discounted cost is : $%.2f", disccost); //discounted cost output
    }
    else if (code == 3) //dairy products
    {
        printf("\nEnter the weight of dairy products (in kg) : ");
        scanf("%d", &weight); //input weight

        printf("\nEnter the price per kg of dairy products : ");
        scanf("%d", &price); //input price

        printf("\nEnter the discount percentage (0 for no discount): ");
        scanf("%d", &discount); //input discount percentage

        cost = weight * price; //formula to obtain cost
        disccost = cost - (discount / 100.0) * cost; //formula to obtain discounted cost

        printf("\nThe total cost is : $%.2f", cost); //cost output
        printf("\nThe total discounted cost is : $%.2f", disccost); //discounted cost output
    }
    else if (code == 4) //canned goods
    {
        printf("\nEnter the weight of canned goods (in kg) : ");
        scanf("%d", &weight); //input weight

        printf("\nEnter the price per kg of canned goods : ");
        scanf("%d", &price); //input price

        printf("\nEnter the discount percentage (0 for no discount): ");
        scanf("%d", &discount); //input discount percentage

        cost = weight * price; //formula to obtain cost
        disccost = cost - (discount / 100.0) * cost; //formula to obtain discounted cost

        printf("\nThe total cost is : $%.2f", cost); //cost output
        printf("\nThe total discounted cost is : $%.2f", disccost); //discounted cost output
    }
    else if (code == 0) //exit
    {
        printf("\nHave a nice day!");
    }
    else //invalid code
    {
        printf("\nInvalid code entered.");
    }

    return 0;
}
