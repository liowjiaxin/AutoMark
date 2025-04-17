#include <stdio.h>

int main() {
    int productCode;
    float weight;
    float pricePerKg;
    float discount;
    float totalCost;
    float finalCost;

    printf("Enter the product code(1 for fruit, 2 for vegetables, 3 for dairy products, 4 for Canned Goods, 0 to exit): ");
    scanf("%d", &productCode);

     if (productCode == 0) {
        printf("Exiting...\n");
        return 0;
    }
    printf("Enter the weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter the price per kg: ");
    scanf("%f", &pricePerKg);

    printf("Enter discount percentage (or 0 for no discount): ");
    scanf("%f", &discount);

    totalCost = weight * pricePerKg;
    printf("The total cost is: $%.2f\n", totalCost);

    finalCost = totalCost - (totalCost * discount / 100);
    printf("The final cost after applying the discount is: $%.2f\n", finalCost);

    return 0;
}



