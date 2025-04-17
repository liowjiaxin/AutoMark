#include<stdio.h>

int main(){

int productNum;
float weight;
float pricePerKg;
float totalCost;
float discountPercentage; 
int quantity;
float pricePerItem;


while(1){  //while loop so code keeps looping until user inputs 0 
printf("Enter the product code(1 for fruits, 2 for vegetables, 3 for dairy products, 4 for canned good, 0 to exit): ");
scanf("%d",&productNum );

if(productNum==0){
    break;
}

switch(productNum){
    case 1:
    printf("Enter the weight of the fruits (in kg): ");
    scanf("%d",&weight);
    printf("Enter the price per kg of fruits: ");
    scanf("%f",&pricePerKg);
    totalCost = weight * pricePerKg;
    printf("The total cost is : %.2f",totalCost);
    break;

    case 2: 
    printf("Enter the weight of the Vegetables (in kg): ");
    scanf("%d",&weight);
    printf("Enter the price per kg of vegetables: ");
    scanf("%f",&pricePerKg);
    totalCost = weight * pricePerKg;
    printf("The total cost is : %.2f",totalCost);
    break;

    case 3:
    printf("Enter the quantity of dairy products: ");
    scanf("%d", &quantity);
    printf("Enter the price per item for dairy products: ");
    scanf("%f", &pricePerItem);
    totalCost = quantity * pricePerItem;
    printf("Total cost for Dairy Products: $%.2f\n", totalCost);
    break;

    case 4: 
    printf("Enter the quantity of canned goods: ");
    scanf("%d", &quantity);
    printf("Enter the price per item for canned goods: ");
    scanf("%f", &pricePerItem);
    totalCost = quantity * pricePerItem;
    printf("Total cost for Canned Goods: $%.2f\n", totalCost);
    break;

    default:
    printf("Invalid product type. Please enter a valid code.\n");
    continue;

        }
 //end of while loop
}

float discount;
float finalCost;
printf("Enter discount percentage (0 if no discount): ");
        scanf("%f", &discount);

finalCost = totalCost * (discount / 100);

printf("Final cost after %.2f%% discount: $%.2f\n", discount, finalCost);
    

    return 0;

}


