#include <stdio.h>

int main() {
    
    //Declare Variables
    int productNumber;
    int quantity;
    float weight;
    int discount;
    double price;
    double totalCost = 0.0;
    double finalCost = 0.0;

    // Input product code from user
    printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
    scanf("%d", &productNumber);

    // Determine price based on product number
    switch (productNumber) {
        case 0:
            printf("Exiting...\n");
            return 0;
        case 1:
            printf("Enter the weight of fruits (in kg): ");
            scanf("%f", &weight);
            printf("Enter the price per kg of fruits: ");
            scanf("%lf", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            break;
        case 2:
            printf("Enter the weight of vegetables (in kg): ");
            scanf("%f", &weight);
            printf("Enter the price per kg of vegetables: ");
            scanf("%lf", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            break;
        case 3:
            printf("Enter the quantity of dairy products: ");
            scanf("%d", &quantity);
            printf("Enter the price per item: ");
            scanf("%lf", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            break;
        case 4:
            printf("Enter the quantity of canned goods: ");
            scanf("%d", &quantity);
            printf("Enter the price per item: ");
            scanf("%lf", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%d", &discount);
            break;
        default:
            printf("Invalid product number. Please enter a number between 1 and 4.\n");
            return 1;
    }

    // Calculate total cost
    if ((productNumber == 1 || productNumber == 2) && discount != 0) {
        totalCost = price * weight;
        finalCost = totalCost * (1 - (discount / 100.0));
        printf("The total cost is: %.2lf\n", totalCost);
        printf("The final cost after applying the discount is: %.2lf\n", finalCost);
    } else if ((productNumber == 3 || productNumber == 4) && discount != 0) {
        totalCost = price * quantity;
        finalCost = totalCost * (1 - (discount / 100.0));
        printf("The total cost is: %.2lf\n", totalCost);
        printf("The final cost after applying the discount is: %.2lf\n", finalCost);
    } else if ((productNumber == 1 || productNumber == 2) && discount == 0) {
        totalCost = price * weight;
        finalCost = totalCost;
        printf("The total cost is: %.2lf\n", totalCost);
        printf("The final cost after applying the discount is: %.2lf\n", finalCost);
    } else if ((productNumber == 3 || productNumber == 4) && discount == 0) {
        totalCost = price * quantity;
        finalCost = totalCost;
        printf("The total cost is: %.2lf\n", totalCost);
        printf("The final cost after applying the discount is: %.2lf\n", finalCost);
    }

    return 0; // Indicate successful execution
}
