#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Availability status structure
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Grocery item structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    AvailabilityStatus status;
} GroceryItem;

// Grocery inventory structure
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int count;
} GroceryInventory;

GroceryInventory inventory = {0};

// Function to add a grocery item
void addGroceryItem() {
    if (inventory.count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter item name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n");  

    printf("Enter item category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");  

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    // Set availability status
    newItem.status.inStock = (newItem.quantity > 0);
    newItem.status.outOfStock = (newItem.quantity == 0);

    // Add item to inventory
    inventory.items[inventory.count++] = newItem;
    printf("Item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems() {
    if (inventory.count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("Grocery Inventory:\n");
    printf("%-20s %-15s %-10s %-10s %-15s\n", "Name", "Category", "Quantity", "Price", "Availability");
    
    for (int i = 0; i < inventory.count; i++) {
        printf("%-20s %-15s %-10d %-10.2f ", 
               inventory.items[i].name, 
               inventory.items[i].category, 
               inventory.items[i].quantity, 
               inventory.items[i].price);

        if (inventory.items[i].status.inStock) {
            printf("In Stock\n");
        } else {
            printf("Out of Stock\n");
        }
    }
}

// Function to update item quantity
void updateQuantity() {
    char itemName[MAX_NAME_LENGTH];
    int newQuantity;

    printf("Enter item name to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");  

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            printf("Current quantity: %d\n", inventory.items[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            inventory.items[i].quantity = newQuantity;
            inventory.items[i].status.inStock = (newQuantity > 0);
            inventory.items[i].status.outOfStock = (newQuantity == 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item
void removeGroceryItem() {
    char itemName[MAX_NAME_LENGTH];

    printf("Enter item name to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");  

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            // Shift remaining items to fill the gap
            for (int j = i; j < inventory.count - 1; j++) {
                inventory.items[j] = inventory.items[j + 1];
            }
            inventory.count--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

int main() {
    int choice;

    do {
        printf("\nGrocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

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
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}