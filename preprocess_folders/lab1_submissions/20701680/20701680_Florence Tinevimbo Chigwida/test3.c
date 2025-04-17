#include  <stdio.h>
int main() {
    char product_code  ;
    int quantity ;
    float weight , price , total ,final_cost , discount;

   printf("Enter the product code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products,4 for Canned Goods, 0 to exit):"); 
   scanf("%c",&product_code) ;

 switch(product_code) {
    case ('1') :
    printf("\nEnter the weight of fruits (in kg): ");
    scanf("%f",&weight);
    printf("\nEnter the price per kg of fruits: ");
    scanf("%f", & price);
    printf("\nEnter discount percentage (or 0 for no discount ): ");
    scanf("%f",&discount);
    total = weight * price ;
    
    final_cost = (1 - discount/100 )* total ;
    
    break ;
    case ('2') :
    printf("\nEnter the weight of vegetables (in kg): ");
    scanf("%f",&weight);
    printf("\nEnter the price per kg of vegetables: ");
    scanf("%f", & price);
    printf("\nEter discount percentage (or 0 for no discount ): ");
    scanf("%f",&discount);
    total = weight * price ;
   
        final_cost = (1- discount/100)* total ;
    
    break ;
    case ('3') :
    printf("\nPlease enter the price of the item") ;
    scanf("%f",&price) ;
    printf("\nPlease enter the quantity of the items ");
    scanf("%d",&quantity);
     printf("\nEter discount percentage (or 0 for no discount ): ");
    scanf("%f",&discount);
    total = quantity * price ;
    
    final_cost = (1- discount/100 )* total ;
    
    break ;
    case ('4') :
    printf("\nEnter the number of canned goods: ");
    scanf("%d",&quantity);
    printf("\nEnter the price per can: ");
    scanf("%f", & price);
    printf("\nEter discount percentage (or 0 for no discount ): ");
    scanf("%f",&discount);
    total = quantity * price ;
    
        final_cost = (1 - discount/100)* total ;
    
    break ;
    case ('0') :
    return 1 ;
    break ;
    default :
    printf("Reenter your code");
 }

  printf("The total cost is %.2f", total);
  printf("\nThe final cost after applying discount is %.2f",final_cost) ;
 return 0 ;
}




