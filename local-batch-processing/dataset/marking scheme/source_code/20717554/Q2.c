#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100  // Maximum number of grocery items.

// Structure for grocery item information.
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

// Inventory structure with grocery items and availability status.
typedef struct {
    GroceryItem items[MAX_ITEMS];
    bool availability[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function declarations.
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory;
    inventory.count = 0; // Initialize inventory count to 0.

    int choice;
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Add grocery item.
                addGroceryItem(&inventory);
                break;
            case 2:  // List all grocery items.
                listGroceryItems(&inventory);
                break;
            case 3:  // Update grocery quantity.
                updateQuantity(&inventory);
                break;
            case 4:  // Remove grocery item.
                removeGroceryItem(&inventory);
                break;
            case 5:  // Exit.
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item to the inventory.
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter the name of the grocery item: ");
    scanf("%s", item.name);
    printf("Enter the category of the grocery item: ");
    scanf("%s", item.category);
    printf("Enter the quantity of the grocery item: ");
    scanf("%d", &item.quantity);
    printf("Enter the price of the grocery item: ");
    scanf("%f", &item.price);

    inventory->items[inventory->count] = item;
    inventory->availability[inventory->count] = (item.quantity > 0) ? true : false;
    inventory->count++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items.
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nCurrent grocery items in the inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", inventory->availability[i] ? "In Stock" : "Out of Stock");
        printf("-------------------------\n");
    }
}

// Function to update the quantity of a grocery item.
void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the grocery item to update the quantity: ");
    scanf("%s", name);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &inventory->items[i].quantity);
            inventory->availability[i] = (inventory->items[i].quantity > 0) ? true : false;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item not found.\n");
}

// Function to remove a grocery item from the inventory.
void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the grocery item to remove: ");
    scanf("%s", name);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift items to remove the selected item.
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->count--;

            printf("Grocery item removed successfully!\n");
            return;
        }
    }

    printf("Grocery item not found.\n");
}