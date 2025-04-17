#include <stdio.h>

int main()
{
    // define variable
    int choice = 0;
    float weight = 0;
    float price = 0;
    float discount = 0;
    float cost = 0;
    float amountDiscount = 0;
    float afterDis = 0;
    
    // User input cchoice
    printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
    scanf("%d", &choice);
    
    // choice is 0, then exit
    if (choice == 0) {
        printf("Exiting program...");
    }
    
    // selection for the user choice to processing the program
    switch (choice) {
        
        // choice is 1
        case 1:
            // input data
            printf("Enter the weight of fruits (in kg):");
            scanf("%f", &weight);
            printf("Enter the price per kg of fruits: ");
            scanf("%f", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            // calculation
            cost = price * weight;
            
            if (discount!=0) {
                amountDiscount = cost * (discount/100);
                afterDis = cost - amountDiscount;
            }
            
            else {
                afterDis = cost;
            }
            
            break;
            
        // choice is 2
        case 2:
            // input data
            printf("Enter the weight of vegetables (in kg):");
            scanf("%f", &weight);
            printf("Enter the price per kg of vegetables: ");
            scanf("%f", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            // calculation
            cost = price * weight;
            
            if (discount!=0) {
                amountDiscount = cost * (discount/100);
                afterDis = cost - amountDiscount;
            }
            
            else {
                afterDis = cost;
            }
            
            break;
            
        
        // choice is 3
        case 3:
            // input data
            printf("Enter the weight of dairy products (in kg):");
            scanf("%f", &weight);
            printf("Enter the price per kg of dairy products: ");
            scanf("%f", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            // calculation
            cost = price * weight;
            
            if (discount!=0) {
                amountDiscount = cost * (discount/100);
                afterDis = cost - amountDiscount;
            }
            
            else {
                afterDis = cost;
            }
            
            break;
        
        // choice is 4
        case 4:
            // input data
            printf("Enter the weight of  Canned Goods (in kg):");
            scanf("%f", &weight);
            printf("Enter the price per kg of  Canned Goods: ");
            scanf("%f", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            // calculation
            cost = price * weight;
            
            if (discount!=0) {
                amountDiscount = cost * (discount/100);
                afterDis = cost - amountDiscount;
            }
            
            else {
                afterDis = cost;
            }
            
            break;
            
        // Invalid choice
        default:
            printf("Invalid choice!");
    }
    
    // display result in 2 s.f.
    printf("The total cost is: $%.2f\n", cost);
    printf("The final cost after applying the discount is: $%.2f\n", afterDis);

    return 0; // program execute successfully
}
