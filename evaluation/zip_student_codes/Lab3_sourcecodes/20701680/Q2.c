#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>

//define a struct
typedef struct {
  char name[100];
  char category[50];
  int Quantity ;
  double Price ;
}Groceries ;


typedef struct {
    bool inStock ;
    bool outofStock ;

}AvailabilityStatus;

typedef struct{
 Groceries items[100];
 AvailabilityStatus Availability[100];
 int count ; 
}GroceryInventory ;

void add(GroceryInventory* inventory){
    //allow user to add the items
    printf("Please enter name : ");
    fgets(inventory->items[inventory->count].name,100,stdin);
    inventory->items[inventory->count].name[strcspn(inventory->items[inventory->count].name, "\n")] = '\0';

    printf("\nPlease enter category: ");
    fgets(inventory->items[inventory->count].category,50,stdin);
    inventory->items[inventory->count].category[strcspn(inventory->items[inventory->count].category, "\n")] = '\0';

    printf("\nPlease enter quantity:");
    scanf("%d",&inventory->items[inventory->count].Quantity);

     printf("\nPlease enter price:");
     scanf("%lf",&inventory->items[inventory->count].Price);
    //since item is added make instock true
     inventory->Availability[inventory->count].inStock = true;
     inventory->Availability[inventory->count].outofStock = false;

}

//function to list all the items
void list (GroceryInventory* inventory){
  for (int i = 0 ; i < inventory->count ; i++){
    printf("Name: %s\n",inventory->items[i].name);
    printf("Category: %s\n",inventory->items[i].category);
    printf("Quantity: %d\n",inventory->items[i].Quantity);
    printf("Price: %.2lf\n",inventory->items[i].Price);
    if(inventory->Availability[i].inStock){
        printf("Status: InStock\n");
    }
    else{
        printf("Status: OutofStock\n");
    }
     printf("----------------------------------\n");
  }
}
//function to update quantity 
void update(GroceryInventory* inventory){
    char change[100] ;

    printf("\nPlease enter name of item to be changed quantity: ");
    fgets(change,100,stdin);
    change[strcspn(change,"\n")] ='\0' ;
    for (int i = 0 ; i < inventory->count ; i++){
    if (strcmp(change,inventory->items[i].name)==0){
        printf("\nEnter new quantity :"); 
        scanf("%d",&inventory->items[i].Quantity);
        printf("Item updated successfully\n");
     }
     else{
         printf("Item does not exist\n");
     }
     if (inventory->items[i].Quantity == 0 ){
       inventory->Availability[i].inStock = false ;
     inventory->Availability[i].outofStock = true ;
    }
    }  
}

//function to remove grocery item 
void removeitem(GroceryInventory* inventory){
  char change[100] ;
 printf("\nPlease enter name of item to be removed ");
  fgets(change,100,stdin);
  change[strcspn(change,"\n")] ='\0' ;
  for (int i = 0 ; i < inventory->count ; i++){
    if (strcmp(change,inventory->items[i].name)==0){
      for (int j = i; j < inventory->count-1 ; j++){
        inventory->items[j]=inventory->items[j+1];
       inventory->Availability[j] = inventory->Availability[j+ 1];

     }
    }
  }
}
int main(){
 GroceryInventory* inventory = (GroceryInventory*)malloc(sizeof(GroceryInventory));
  inventory->count = 0;

  char choice ;
 // loop until exit
   while (1){
     
        //menu
   printf("Grocery Inventory Management System\n");
   printf("1:Add Grocery Item\n");
   printf("2:List All Grocery Items\n");
   printf("3:Update Quantity\n");
   printf("4:Remove Grocery Item\n");
   printf("5:Exit\n");
   
   printf("\nEnter your choice : ");
   scanf(" %c",&choice);
  getchar();// Consume the newline character


   switch(choice){
      case '1' :
        if (inventory->count >= 100) {
         printf("\nInventory is full. Cannot add more items.\n");
          break;
        }
          add(inventory);
          inventory->count++ ;
          printf("Item added successfully\n");
          break ;
      case '2' :
         if (inventory->count == 0) {
         printf("\nThere are no items in the inventory\n");
          break;
        }
         list(inventory);
         break;
      case '3' :
          if (inventory->count == 0) {
         printf("There are no items in the inventory\n");
          break;
        }

         update(inventory);
         
          break;
      case '4' :
          if (inventory->count == 0) {
         printf("There are no items in the inventory\n");
          break;
        }
         removeitem(inventory);
         inventory->count-- ;
         printf("Item removed successfully\n");
         break;
      case '5' :
         printf("Exiting.......");
          return 0;
          break;
     default :
         printf("Please enter a choice between 1 and 5 \n");
         break;
   }
       
   }
       

    return 0 ;
}