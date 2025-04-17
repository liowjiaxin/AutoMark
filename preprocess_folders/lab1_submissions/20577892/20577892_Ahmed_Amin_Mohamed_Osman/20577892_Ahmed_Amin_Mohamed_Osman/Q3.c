#include <stdio.h>

int  main() {
    int product;
    float sum = 0;
    float weight = 0;
    float price = 0;
    float discount = 0;
    int quantity;
    

    printf("Enter product code (1 for fruits, 2 for vegetables, 3 for dairy products, 4 for canned goods, 0 to exit)");
    scanf("%d", &product);
    
   
    switch(product) {
        case 1:
        {
            printf("Enter the weight of fruits (in kg)");
            scanf("%f", &weight);
            printf("Enter the price per kg of fruits");
            scanf("%f", &price);
            price = price*weight;
            break;
        } 
        case 2:
        {
            printf("Enter the weight of vegetables (in kg)");
            scanf("%f", &weight);
            printf("Enter the price per kg of vegetables");
            scanf("%f", &price);
             
            price = price*weight;
            
            break;
        } 
        case 3:
        {
            printf("Enter the price of dairy product: ");
            scanf("%f", &price);
            price = price;
            
            break;
        } 
        case 4:
        {
            printf("Enter the price of one item: ");
            scanf("%f", &price);
            printf("Enter how many products you want: ");
            scanf("%d", &quantity);
            
            price = price*quantity;
        
            break;
        } 
        
        default: {
            printf("Exit...");
        }
    }
        
        printf("The total cost is: $%.2f \n", price);
        printf("Enter discount percentage (or no discount)");
        scanf("%f", &discount);
        price = price - discount;
        printf("The final cost after applying discount is: $%.2f", price);
    

    return 0;
}