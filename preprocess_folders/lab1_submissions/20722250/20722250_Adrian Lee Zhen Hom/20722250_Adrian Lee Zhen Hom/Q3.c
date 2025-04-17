#include <stdio.h>

int main()
{
    int product_code;
    double weight;
    int quantity;
    double price;
    double discount_percentage;
    double total_cost;
    double final_cost;

    printf("Product codes:\n");
    printf("1. Fruits\n");
    printf("2. Vegetables\n");
    printf("3. Dairy Products\n");
    printf("4. Canned Goods\n");
    printf("0. Exit\n");

    while (1)
    {
        //prompt and read product code from user
        printf("Enter product code (1-4), enter 0 to exit: ");
        scanf("%d", &product_code);
        fflush(stdin);

        //exit condition
        if(product_code == 0)
        {
            break;
        }

        //prompt and read necessary info from user using switch
        switch(product_code)
        {
            case 1:
                printf("Enter weight of fruits (in kg): ");
                scanf("%f", &weight);
                
                printf("Enter price per kg of fruits: ");
                scanf("%f", &price);

                total_cost = weight * price;
                break;

            case 2:
                printf("Enter weight of vegetables (in kg): ");
                scanf("%f", &weight);

                printf("Enter price per kg of vegetables: ");
                scanf("%f", &price);

                total_cost = weight * price;
                break;

            case 3:
                printf("Enter quantity of dairy products: ");
                scanf("%d", &quantity);

                printf("Enter price per unit of dairy products: ");
                scanf("%f", &price);

                total_cost = quantity * price;
                break;

            case 4:
                printf("Enter quantity of canned goods: ");
                scanf("%d", &quantity);

                printf("Enter price per unit of canned goods: ");
                scanf("%f", &price);

                total_cost = quantity * price;
                break;

            default:
                printf("Invalid product code. Please enter a number between 1 and 4, or 0 to exit.");
                continue;  // skip this iteration and prompt user for input again since invalid input
        }

        //prompt and read discount from user
        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount_percentage);

        //convert discount percentage to decimal form
        double discount_decimal = discount_percentage / 100;

        //calculate final cost after discount
        final_cost = total_cost * (1 - discount_decimal);

        //display results
        printf("Total cost is: $%.2f\n", total_cost);
        printf("Final cost after applying discount is: $%.2f\n\n", final_cost);
    }

    return 0;
}