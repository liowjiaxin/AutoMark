
#include <stdio.h>


int main() {
    int weight, price, code, item;
    float cost, discount, discount_cost;
 
 while (1) {

    printf("Grocery Store!\n");
    printf("Enter the product code:\n 1 for Fruits\n 2 for Vegetables\n 3 for Dairy Products\n 4 for Canned Goods\n 0 to exit: \n");
    scanf("%d", &code);
    
    //Exit the program when user inputs 0 
    if (code == 0) {
        break;
    } 

    switch (code) {
        case 1: //fruits, when user inputs 1
        //Prompt user to input weight, price and discount
        printf("Enter the weight (in kg): ");
        scanf("%d", &weight);
        printf("Enter the price (per kg): ");
        scanf("%d", &price);
        printf("Enter discount percentage (or 0 for no discount): ");
        scanf("%f", &discount);
        
        //calculate total cost
        cost = weight*price;
        
        //calculate cost after discount(if any)
        if (discount == 0) {
                discount_cost = cost; //Assigns cost to discount cost if there is not discount (no change)
            } else {
                discount_cost = cost * (100 - discount)/100;
            }
            
        printf("The total cost of fruits: $%.2f\n", cost);
        printf("The final cost of fruits after discount is: $%.2f\n\n", discount_cost);
        break;
        
        
    
        case 2: //vegetables
            printf("Enter the weight (in kg): ");
            scanf("%d", &weight);
            printf("Enter the price (per kg): ");
            scanf("%d", &price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
    
            cost = weight*price;

            if (discount == 0) {
                discount_cost = cost;
            } else {
                discount_cost = cost * (100 - discount)/100;
            }
            
            printf("The total cost of vegetables: $%.2f\n", cost);
            printf("The final cost of vegetables after discount is: $%.2f\n\n", discount_cost);
            
            break;
            
        case 3: //milk
            //Price is fixed to 3.00 each
            printf("Price for 1 is $3.00.\n");
            printf("Enter number of items: ");
            scanf("%d", &item);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            cost = item*3;
            
            if (discount == 0) {
                discount_cost = cost;
            } else {
                discount_cost = cost * (100 - discount)/100;
            }
            
            printf("The total cost of milk is $%.2f\n", cost);
            printf("The final cost of milk after discount is: $%.2f\n\n", discount_cost);
            break;
            
        case 4: //canned goods
            //Price is fixed to 4.00 each
            printf("Price for 1 is $4.00.\n");
            printf("Enter number of items: ");
            scanf("%d", &item);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f", &discount);
            
            cost = item*4;
            
            if (discount == 0) {
                discount_cost = cost;
            } else {
                discount_cost = cost * (100 - discount)/100;
            }
            
            printf("The total cost of canned goods is $%.2f\n", cost);
            printf("The final cost of milk after discount is: $%.2f\n\n", discount_cost);
            break;
            
            
        default: //If user inputs numbers other than numbers 0-4, it will say error and loop back to the menu
            printf("Error. Enter a valid number.\n");
            break;
        
        
    }
    
 }
    return 0;
}