#include <stdio.h>  // For standard input/output functions
#include <string.h>  // For string manipulation functions 
#include <stdbool.h>  // For 'true/false' logic using the data type 'bool'

// Define maximum lengths for strings
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_ITEMS 100

// Structure to represent the availability status of a grocery item
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Structure to represent a grocery item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    AvailabilityStatus status;
} GroceryItem;

// Structure to represent the grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function to add a new grocery item to the inventory
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name); // '%[^\n]' reads a line of text which includes spaces

    printf("Enter category: ");
    scanf(" %[^\n]", newItem.category);

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    // Set availability based on quantity
    newItem.status.inStock = newItem.quantity > 0;
    newItem.status.outOfStock = !newItem.status.inStock;

    inventory->items[inventory->itemCount] = newItem;
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items and their availability
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", inventory->items[i].status.inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory to update.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName);

    int itemIndex = -1;
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Grocery item '%s' not found.\n", itemName);
        return;
    }
    
    printf("Enter new quantity for %s: ", itemName);
    scanf("%d", &inventory->items[itemIndex].quantity);

    // Update availability status
    inventory->items[itemIndex].status.inStock = inventory->items[itemIndex].quantity > 0;
    inventory->items[itemIndex].status.outOfStock = !inventory->items[itemIndex].status.inStock;

    printf("Quantity has been updated successfully!\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No available grocery items in the inventory to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Please enter the name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName);

    int itemIndex = -1;
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex == -1) {
        printf("Grocery item '%s' was not found.\n", itemName);
        return;
    }

    // Shift items to fill the gap
    for (int i = itemIndex; i < inventory->itemCount - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }

    inventory->itemCount--;
    printf("Grocery item '%s' was successfully removed!\n", itemName);
}

int main() {
    GroceryInventory inventory;
    inventory.itemCount = 0; // Initialize inventory as empty
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}