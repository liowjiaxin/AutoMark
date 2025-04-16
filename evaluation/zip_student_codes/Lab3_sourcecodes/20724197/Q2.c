#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH_NAME 100
#define MAX_LENGTH_CATEGORY 50
#define MAX_ITEMS 100

typedef struct {
    char name[MAX_LENGTH_NAME];
    char category[MAX_LENGTH_CATEGORY];
    int quantity;
    float price;
} Item;

typedef struct {
    bool inStock;
    bool outOfStock;
} Status;

Item itemList[MAX_ITEMS];
Status statusList[MAX_ITEMS]; 
int itemCount = 0; // to track the number of items in list

// Declare prototypes function
void addItem();
void listItem();
void updateStatus(int count);
void updateQuantity();
void removeItem();
void showMenu();

// main Function
int main() {
    int decision;

  while (1)
  {
    showMenu();

    printf("Enter your choice: ");
    scanf("%d", &decision);
    getchar();

    switch (decision)
    {
    case 1: // Add
      addItem();
     
      break;
    case 2: // Display
      listItem();
      break;
    case 3: // Edit
      updateQuantity();
      break;
    case 4: // Delete
      removeItem();
      break;
    case 5: 
      printf("Exiting...");
      exit(0);
    default:
      printf("Invalid choice. \n");
      break;
    }
  }
  return 0;
}

void showMenu(){
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}
// Add an Item to the Inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Maximum number of items had stored in inventory !\n");
        return;
    }

    // prompt user inputs
    printf("Enter Item Name: ");
    fgets(itemList[itemCount].name, sizeof(itemList[itemCount].name), stdin);
    itemList[itemCount].name[strcspn(itemList[itemCount].name, "\n")] = '\0'; // Remove newline

    printf("Enter Category: ");
    fgets(itemList[itemCount].category, sizeof(itemList[itemCount].category), stdin);
    itemList[itemCount].category[strcspn(itemList[itemCount].category, "\n")] = '\0'; // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &itemList[itemCount].quantity);

    printf("Enter Price: ");
    scanf("%f", &itemList[itemCount].price);
    getchar(); 

    updateStatus(itemCount);

    itemCount++; // increment item count
    printf("Grocery item added successfully!\n");
}

// update status based on quantity
void updateStatus(int count){
    if (itemList[count].quantity > 0) {
        statusList[count].inStock = true;
        statusList[count].outOfStock = false;
    } else {
        statusList[count].inStock = false;
        statusList[count].outOfStock = true;
    }
}

// Diaplay all items in the inventory
void listItem() {
    if (itemCount == 0) {
        printf("No grocery item found.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {

        printf("Name: %s\n", itemList[i].name);
        printf("Category: %s\n", itemList[i].category);
        printf("Quantity: %d\n", itemList[i].quantity);
        printf("Price: %.2f\n", itemList[i].price);

        if(statusList[i].inStock){
            printf("Status: In Stock\n");
        }else
        {    printf("Status: Out of Stock\n");
            }  

     printf("\n"); 
    }
}

// Update the quantity of item
void updateQuantity(){

    char updateName[MAX_LENGTH_NAME];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(updateName, sizeof(updateName), stdin);
    updateName[strcspn(updateName, "\n")] = '\0'; // remove newline
    
    int indices=-1; // to track if item is found
    for(int i=0; i<itemCount; i++){

        if(strcmp(itemList[i].name, updateName)==0){
            indices=i;
            break;
        }
    }

     if (indices == -1) {
        printf("No grocery item found with the name '%s'.\n", updateName);
        return;
    }

    int newQuantity;
    printf("Enter new quantity for %s: ", updateName);
    scanf("%d", &newQuantity);
    getchar();

    itemList[indices].quantity=newQuantity;
    updateStatus(indices);

    printf("Quantity updated successfully!\n");
   
}

// remove item
void removeItem(){

    char deletedItem[MAX_LENGTH_NAME];
    printf("Enter the name of the grocery item to remove: ");
    fgets(deletedItem, sizeof(deletedItem), stdin);
    deletedItem[strcspn(deletedItem, "\n")] = '\0'; 

    int indices=-1;
    for(int i=0; i<itemCount; i++){
       
        if(strcmp(itemList[i].name, deletedItem)==0){
            indices=i;
            break;
        }
    }

     if (indices == -1) {
        printf("No grocery item found with the name '%s'.\n", deletedItem);
        return;
     }

     for (int i = indices; i < itemCount - 1; i++) {
            itemList[i] = itemList[i + 1];
        }

    printf("Grocery item '%s' removed successfully!\n", deletedItem);

        // decrease the array size
        itemCount--;

}





