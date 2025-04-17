#include <stdio.h>

int main() {
    float items = 0;
    float price;
    float discount;
    float total;
    float final_cost = (1-discount)*total;
    printf("Enter the Product code(1 for fruits, 2 for vegetables, 3 for Diary products, 4 for Canned goods, 0 to exit): ");
    scanf("%d", &items);

   if(items == 1) {
   printf("Enter the weight of the fruit: ");
   }
   else if(items == 2) {
        printf("Enter the weight of the Vegetables: ");
   }
    else if(items == 3) {
        printf("Enter fixed price per item of your diary product: ");
    }
    else if(items == 4){
        printf("Enter fixed price per item on quantity: ");
    }
    else {}



    return 0;
}