#include <stdio.h>

int main(){
    int prodcode;
    float price;
    int weight;
    int discount;
    float totalcost,finalcost;


    printf("Enter a product code(1 for Fruits, 2 for Vegetables, 3 for Dairy Products,4 for Canned Goods, 0 to exit):\n");
    scanf("%d", &prodcode);

    if (prodcode == 0)
    {
        printf("Exiting program...");
        return 0;
    }
    
    switch (prodcode){
    case 1:
        printf("Enter the weight of fruits: ");
        scanf("%d", &weight);

        printf("Enter the price of fruits: ");
        scanf("%f", &price);
        break;

    case 2:
        printf("Enter the weight of vegetables in kg: ");
        scanf("%d", &weight);

        printf("Enter the price of vegetables: ");
        scanf("%f", &price);
        break;

    case 3:
        printf("Enter the weight of dairy products in kg: ");
        scanf("%d", &weight);

        printf("Enter the price of dairy products: ");
        scanf("%f", &price);
        break;

    case 4:
        printf("Enter the weight of canned goods in kg: ");
        scanf("%d", &weight);

        printf("Enter the price of canned goods:");
        scanf("%f", &price);
        break;

    }

    

    printf("Enter the discount, 0 for no discount:");
    scanf("%d", &discount);




    totalcost = price * weight;
    finalcost = ((totalcost*100)-(totalcost * discount))/100;

    printf("Cost before discount is %.2f\n",totalcost);
    printf("Cost after discount is %.2f",finalcost);

}