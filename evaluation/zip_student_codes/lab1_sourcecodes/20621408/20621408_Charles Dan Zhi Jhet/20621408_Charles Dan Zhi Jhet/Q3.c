#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool loop = true;

    while(loop) 
    {
        int choice, weight = 0, quantity = 0, discount = 0;
        double price = 0.0, totalCost = 0.0, finalCost = 0.0;

        printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to Exit): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:         
                printf("Enter the weight of fruits (in kg): ");
                scanf("%d", &weight);
                printf("Enter the price per kg of fruits: ");
                scanf("%lf", &price);
                break;

            case 2:
                printf("Enter the weight of vegetables (in kg): ");
                scanf("%d", &weight);
                printf("Enter the price per kg of vegetables: ");
                scanf("%lf", &price);
                break;

            case 3:
                printf("Enter the quantity of dairy products: ");
                scanf("%d", &quantity);
                price = 4.50;   
                break;

            case 4:
                printf("Enter the quantity of canned goods: ");
                scanf("%d", &quantity);
                price = 5.00;
                break;

            default:
                break;
        }

        if(choice == 0)
        {
            printf("Exited. Thank you.\n");
            loop = false;
        }
        else if (weight != 0)                                               // if user choice is a item that uses weight to calculate
        {
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            totalCost = weight * price;
            printf("The total cost is: $%.2lf\n", totalCost);
            finalCost = ((100.0 - discount) / 100.0) * totalCost;
            printf("The final cost after applying the discount is: $%.2lf\n", finalCost);
            printf("\n");
        }
        else if (quantity != 0)                                             // if user choice is a item that uses quantity to calculate
        {
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            totalCost = quantity * price;
            printf("The total cost is: $%.2lf\n", totalCost);
            finalCost = ((100.0 - discount) / 100.0) * totalCost;
            printf("The final cost after applying the discount is: $%.2lf\n", finalCost);
            printf("\n");
        }
        else 
        {
            printf("Enter only integers from 0 to 4.\n");
        }        
    }

    return 0;
}