#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int totalItems;
} Inventory;

Inventory inventory = {0};

// Function Prototypes
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice;

    while (choice != 5) {
        printf("Grocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
      

        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listGroceryItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    };

    return 0;
}

void addGroceryItem() {
    if (inventory.totalItems >= MAX_ITEMS) {//check if item more than 100
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    //using fgets for string inputs as per reccomendation from AI and forums
    printf("Enter Item Name: ");
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;

    printf("Enter Category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    getchar();

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar();

    inventory.items[inventory.totalItems] = newItem;
    
    inventory.availability[inventory.totalItems].inStock = (newItem.quantity > 0);//if item greater than 0 set to true
    inventory.availability[inventory.totalItems].outOfStock = (newItem.quantity == 0);//if item 0 set to true

    inventory.totalItems++;//incerement totalitems
    printf("Item added successfully!\n");
}

void listGroceryItems() {
    if (inventory.totalItems == 0) { //check if empty
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nGrocery Inventory\n");
    printf("%-20s %-15s %-10s %-10s %-15s\n\n", 
           "Name", "Category", "Quantity", "Price", "Availability");
 

    for (int i = 0; i < inventory.totalItems; i++) {
        GroceryItem item = inventory.items[i];
        char* status = inventory.availability[i].inStock ? "In Stock" : "Out of Stock"; //switch case to print avaibality of stock
        
        printf("%-20s %-15s %-10d $%-9.2f %-15s\n", 
               item.name, item.category, item.quantity, item.price, status);
    }
}

void updateQuantity() {
    char itemName[MAX_NAME_LENGTH]; //temp var to store item to be updated
    
    printf("Enter Item Name to Update Quantity: ");
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0; //remove \n

    for (int i = 0; i < inventory.totalItems; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            int newQuantity;
            printf("Current Quantity: %d\n", inventory.items[i].quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &newQuantity);
            

            inventory.items[i].quantity = newQuantity; //update item quantity with newQuantity
            
            inventory.availability[i].inStock = (newQuantity > 0);
            inventory.availability[i].outOfStock = (newQuantity == 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void removeGroceryItem() {
    char itemName[MAX_NAME_LENGTH]; //to store item to be removed
    
    printf("Enter Item Name to Remove: ");
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    for (int i = 0; i < inventory.totalItems; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            for (int j = i; j < inventory.totalItems - 1; j++) {
                inventory.items[j] = inventory.items[j+1];
                inventory.availability[j] = inventory.availability[j+1];//move item to left to fill gap
            }
            
            inventory.totalItems--;//decrement totalitem
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}