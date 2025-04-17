

#include <stdio.h>



int main() {

// Question 3

// Describe the options
   
    int aCount = 0;
    int bCount = 0;
    int dCount = 0;

    int price = 0;
    
    printf("Enter the product code:\n 1 for fruits\n 2 for vegetables\n 3 for Dairy Product\n 4 for canned goods\n 0 to exit\n");
    int product = 0;

    while ((product = getchar()) !=0);
        // determine what number you want to pick
        switch(product){
            case 1:
                printf("Enter the weight of fruits (in kg): ");
                scanf("%d", aCount);
                printf("Enter the price per kg fruits: ");
                scanf("%d", price);
                break;
            case 2:
                printf("Enter the weight of vegetables (in kg): ");
                scanf("%d", bCount);
                printf("Enter the price per kg vegetables: ");
                scanf("%d", price);
                break;
            case 3:
                printf("Enter the Price of the Daily Products: ");
                scanf("%d", price);
                break;
            case 4: 
                printf("Enter the number of canned goods: ");
                scanf("%d", dCount);
                printf("Enter the price: ");
                scanf("%d", price);
                break;

    }
    
    printf("The total cost is: $%d", price);
    int final_cost; 
    printf("The final cost after applying discount: ");
    





    return 0;
}

    