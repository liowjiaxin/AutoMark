#include <stdio.h>

//function to count discount percentage, initial cost and final cost after discount
int counting(double quan, double price){ //require quantity and price
    int disPer;
    double iniCost, finCost;
    
    //request discount percentage
    printf("Enter discount percentage (or 0 for no discount): "); 
    scanf("%d", &disPer);

    //Calculation   
    iniCost = (double)price * quan; // calculate initial cost
    disPer = 100-disPer; // calculate the discount percentage
    finCost = (double)iniCost * disPer /100; // calculate final cost after discount

    //display initial cost and final cost after discount    
    printf("The total cost is: $%.2f\n", iniCost);
    printf("The final cost after applying the discount is: $%.2f\n\n", finCost);

    return 0;
}

//Main program
int main(void)
{
    // product code set as 1
    int proCode = 1;
    double price, quan; //price and quantity
    
    while (proCode != 0){ //loop if product code not equal to 0

        //request product code
        printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
        scanf("%d", &proCode);
        
        switch (proCode){
            case 1:  // fruit
                printf("Enter the weight of fruits (in kg): ");
                scanf("%lf", &quan);
                printf("Enter the price per kg of fruits: ");
                scanf("%lf", &price);
                counting(quan, price);
                break;
            case 2: //vegetables
                printf("Enter the weight of vegetables (in kg): ");
                scanf("%lf", &quan);
                printf("Enter the price per kg of vegetables: ");
                scanf("%lf", &price);
                counting(quan, price);
                break;
            case 3: // dairy product
                printf("Enter the quantity of dairy product (item): ");
                scanf("%lf", &quan);
                printf("Enter the price per item of dairy product: ");
                scanf("%lf", &price);
                counting(quan, price);
                break;
            case 4: // canned goods
                printf("Enter the quantity of canned goods (item): ");
                scanf("%lf", &quan);
                printf("Enter the price per item of canned goods: ");
                scanf("%lf", &price);
                counting(quan, price);
                break;
            case 0: // stop the loop
                break;
            default: // wrong input alert
                printf("Invalid input\n");
                break;
        }
        
        //quit the while loop
        if (proCode == 0){
            break;
        }

    }
    
    return 0;
}