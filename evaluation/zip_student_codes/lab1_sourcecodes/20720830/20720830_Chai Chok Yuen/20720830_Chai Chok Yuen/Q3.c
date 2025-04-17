#include <stdio.h>

int main(){
    int choice;
    float weight, price,disc,total,final;
    int num;
    //Input the product code
    printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
    scanf("%d", &choice);
    //Switch case to proceed with different process with different code input
    switch(choice){
        //Input 1 will lead to processes regarding fruits
        case 1: 
            //Input required information
            printf("Enter the weight of fruits (in kg): ");
            scanf("%f",&weight);
            printf("Enter the price per kg of fruits: ");
            scanf("%f",&price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f",&disc);
            //Calculation of total cost and final cost
            total = weight*price;
            final= (1-(disc/100))* total;
            //Print output of total cost and final cost
            printf("The total cost is: $%.2f\n",total);
            printf("The final cost after applying the discount is: $%.2f",final);
            break;
        //Input 2 will lead to processes regarding vegetables
        case 2:
            //Input required information
            printf("Enter the weight of vegetables (in kg): ");
            scanf("%f",&weight);
            printf("Enter the price per kg of vegetables: ");
            scanf("%f",&price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f",&disc);
            //Calculation of total cost and final cost
            total = weight*price;
            final= (1-(disc/100))* total;
            //Print output of total cost and final cost
            printf("The total cost is: $%.2f\n",total);
            printf("The final cost after applying the discount is: $%.2f",final);
            break;
        //Input 3 will lead to processes regarding dairy products
        case 3:
            //Input required information
            printf("Enter the quantity of dairy products: ");
            scanf("%d",&num);
            printf("Enter the price per item of dairy products: ");
            scanf("%f",&price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f",&disc);
            //Calculation of total cost and final cost
            total = num*price;
            final= (1-(disc/100))* total;
            //Print output of total cost and final cost
            printf("The total cost is: $%.2f\n",total);
            printf("The final cost after applying the discount is: $%.2f",final);
            break;
        //Input 4 will lead to processes regarding canned goods
        case 4:
            //Input required information
            printf("Enter the quantity of canned goods : ");
            scanf("%d",&num);
            printf("Enter the price per item of canned goods: ");
            scanf("%f",&price);
            printf("Enter discount percentage (or 0 for no discount): ");
            scanf("%f",&disc);
            //Calculation of total cost and final cost
            total = num*price;
            final= (1-(disc/100))* total;
            //Print output of total cost and final cost
            printf("The total cost is: $%.2f\n",total);
            printf("The final cost after applying the discount is: $%.2f",final);
            break;
        //Input 0 will lead to exit
        case 0:
            break;
    }

    return 0;
}
