Question 3

int main() {

  int code, weight, price, discount, cost, discprice;

  printf("Enter Product Code (1 for Fruits, 2 for Vegetables, 3 for Dairy Products, 4 for Canned Goods, 0 to exit): ");
  scanf("%d", &code); //Input digit

  switch (code) { //Writing a case for every digit in 0-9

  case 1:
    printf("Enter Weight of Fruit: ");
    scanf("%d", &weight);
    
    printf("\nEnter Price per Fruit: ");
    scanf("%d", &price);
    
    printf("\nEnter discount percentage: ");
    scanf("%d", &discount);
    
    cost = weight * price;
    printf("\nTotal Cost: %d", &cost);
    
    discprice = cost / discount;
    printf("\nDiscounted Price: %d", &discprice);
    break;
    
  case 2:
    printf("Enter Weight of Vegetable: ");
    scanf("%d", &weight);
    
    printf("\nEnter Price per Vegetable: ");
    scanf("%d", &price);
    
    printf("\nEnter discount percentage: ");
    scanf("%d", &discount);
    
    cost = weight * price;
    printf("\nTotal Cost: %d", &cost);
    
    discprice = cost / discount;
    printf("\nDiscounted Price: %d", &discprice);
    break;
  case 3:
    printf("Enter Weight of Dairy Products: ");
    scanf("%d", &weight);
    
    printf("\nEnter Price per Dairy Products: ");
    scanf("%d", &price);
    
    printf("\nEnter discount percentage: ");
    scanf("%d", &discount);
    
    cost = weight * price;
    printf("\nTotal Cost: %d", &cost);
    
    discprice = cost / discount;
    printf("\nDiscounted Price: %d", &discprice);
    break;
  case 4:
    printf("Enter Weight of Canned Goods: ");
    scanf("%d", &weight);
    
    printf("\nEnter Price per Canned Goods: ");
    scanf("%d", &price);
    
    printf("\nEnter discount percentage: ");
    scanf("%d", &discount);
    
    cost = weight * price;
    printf("\nTotal Cost: %d", &cost);
    
    discprice = cost / discount;
    printf("\nDiscounted Price: %d", &discprice);
    break;
  case 5:
    return 0;
}