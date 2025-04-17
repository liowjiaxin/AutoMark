#include <stdio.h>

int main(){

    int productCode = 0;
    float weight = 0.0;
    float price = 0.0;
    float discount = 0.0;
    float fruitVegeBeforeDiscount = 0.0;
    float fruitVegeAfterDiscount = 0.0;

    int quantity = 0;
    float dairyCannedBeforeDiscount = 0.0;
    float dairyCannedAfterDiscount = 0.0;

    printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
    scanf("%d", &productCode);

    printf("\n");

    switch (productCode){

        //For Fruits
        case 1:
        printf("Enter the weight of fruits (in kg): ");
        scanf("%f", &weight);

        printf("Enter the price per kg of fruits: ");
        scanf("%f", &price);

        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount);

        fruitVegeBeforeDiscount = weight * price;
        printf("The total cost is $%.2f.\n" ,fruitVegeBeforeDiscount);

        fruitVegeAfterDiscount = (1-(discount/100)) * fruitVegeBeforeDiscount;
        printf("The final cost after discount is $%.2f.\n", fruitVegeAfterDiscount);

        break;

        //For Vegetables
        case 2:

        printf("Enter the weight of vegetables (in kg): ");
        scanf("%f", &weight);

        printf("Enter the price per kg of vegetables: ");
        scanf("%f", &price);

        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount);

        fruitVegeBeforeDiscount = weight * price;
        printf("The total cost is $%.2f.\n" ,fruitVegeBeforeDiscount);

        fruitVegeAfterDiscount = (1-(discount/100)) * fruitVegeBeforeDiscount;
        printf("The final cost after discount is $%.2f.\n", fruitVegeAfterDiscount);

        break;

        //For Dairy products
        case 3: 

        printf("Enter the quantity of dairy products: ");
        scanf("%d", &quantity);

        printf("Enter the price for one dairy product: ");
        scanf("%f", &price);

        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount);

        dairyCannedBeforeDiscount = quantity * price;
        printf("The total cost is $%.2f.\n" ,dairyCannedBeforeDiscount);

        dairyCannedAfterDiscount = (1-(discount/100)) * dairyCannedBeforeDiscount;
        printf("The final cost after discount is $%.2f.\n", dairyCannedAfterDiscount);
        
        break;

        //For Canned goods
        case 4: 
        printf("Enter the quantity of canned goods: ");
        scanf("%d", &quantity);

        printf("Enter the price for one canned goods: ");
        scanf("%f", &price);

        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount);

        dairyCannedBeforeDiscount = quantity * price;
        printf("The total cost is $%.2f.\n" ,dairyCannedBeforeDiscount);

        dairyCannedAfterDiscount = (1-(discount/100)) * dairyCannedBeforeDiscount;
        printf("The final cost after discount is $%.2f.\n", dairyCannedAfterDiscount);
        break;

        //For exit
        case 0:
        printf("Exiting.\n");
        break;

        //For Default
        default:
        printf("Invalid product number.\n");
        break;

    }
    return 0;
}