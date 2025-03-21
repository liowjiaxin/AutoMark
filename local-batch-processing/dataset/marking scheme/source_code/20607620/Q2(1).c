#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 100
#define CATEGORY_LENGTH 50


typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
    int inStock; 
} GroceryItem;


typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount; 
} GroceryInventory;

// Add function
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) { // Check if the inventory is full
        printf("Inventory is full!\n");
        return;
    }
    GroceryItem *item = &inventory->items[inventory->itemCount];
    
    // Take input for the new item
    printf("Enter Item Name: ");
    scanf(" %[^\n]", item->name);
    printf("Enter Category: ");
    scanf(" %[^\n]", item->category);
    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter Price: ");
    scanf("%f", &item->price);
    
    // Set item availability based on quantity
    item->inStock = (item->quantity > 0);
    inventory->itemCount++;
    printf("Grocery item added successfully!\n");
}

// Listing function
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->itemCount == 0) { // Check if the inventory is empty
        printf("No grocery items in the inventory.\n");
        return;
    }
    for (int i = 0; i < inventory->itemCount; i++) {
        const GroceryItem *item = &inventory->items[i];
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", item->inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Update quantity function
void updateQuantity(GroceryInventory *inventory) {
    char itemName[NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem *item = &inventory->items[i];
        if (strcmp(item->name, itemName) == 0) { // If item is found
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);
            item->inStock = (item->quantity > 0); // Update stock status
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    // If item is not found in the inventory
    printf("Grocery item not found.\n");
}

// Remove function
void removeGroceryItem(GroceryInventory *inventory) {
    char itemName[NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) { // If item is found
            // Shift all subsequent items one position forward to remove the item
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--; // Decrease the item count
            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;
        }
    }
    // If item is not found
    printf("Grocery item not found.\n");
}

// Main function
int main() {
    GroceryInventory inventory = { .itemCount = 0 }; // Initialize inventory
    int choice;

    do {
        // Display menu options
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory); // Add item to inventory
                break;
            case 2:
                listGroceryItems(&inventory); // Display all items
                break;
            case 3:
                updateQuantity(&inventory); // Update item quantity
                break;
            case 4:
                removeGroceryItem(&inventory); // Remove item from inventory
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // Keep running until exit option is selected

    return 0;
}
