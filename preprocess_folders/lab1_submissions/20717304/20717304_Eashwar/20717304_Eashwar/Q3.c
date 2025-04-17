#include <stdio.h>

int main() {
    int ptype;
    float weight;
    int quan;
    float ppk;                // Initialise required variables
    float ppp;
    float ttc;
    float disc;
    float fc;

    while(1) {
        printf("\nEnter a product type code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
        scanf("%d", &ptype);            //Start a loop

        if(ptype == 0) {
            break;                     // Exits program when 0 is entered
        }

        switch(ptype) {                                      // Switch statement is initilaised for each case
            case 1:
                printf("Enter weight in kg: ");              
                scanf("%f", &weight);
                printf("Enter price per Kg of Fruits : ");   
                scanf("%f", &ppk);
                ttc = ppk * weight;                         // Calculates total cost in each case
                break;

            case 2:
                printf("Enter weight in kg: ");
                scanf("%f", &weight);
                printf("Enter price per Kg of Vegetables : ");
                scanf("%f", &ppk);
                ttc = ppk * weight;
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quan);
                printf("Enter price per product : ");
                scanf("%f", &ppp);
                ttc = ppp * quan;
                break;

            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quan);
                printf("Enter price per can : ");
                scanf("%f", &ppp);
                ttc = ppp * quan;
                break;

            default:
                printf("Invalid product code.\n");
                continue;                              //Goes out of the loop when an ivalid input is given
        }

        printf("Enter discount percentage (if any; 0 if no discount): ");
        scanf("%f", &disc);                            // Discount calculation

        if(disc > 0)
        {
            fc = ttc - (ttc * (disc / 100));          // Subtracting the discount amount for total cost
        }
        else
        {
            fc = ttc;                                 // Declaring final cost when there is no discount
        } 
        printf("The total cost is : %.2f\n", ttc);                  
        printf("The final cost is after discount is : %.2f\n", fc);   //Printing cost before and after discount
    }

    return 0;
}