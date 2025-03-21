#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100 // Maximum number of grocery items

// Struct for Grocery Item
typedef struct {
    char name[100]; // Name of the item
    char category[50]; // Category of the item
    int quantity; // Quantity of the item
    float price; // Price of the item
} GroceryItem;

// Struct for Availability Status
typedef struct {
    bool inStock; // Availability status
} AvailabilityStatus;

// Struct for Grocery Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Array of grocery items
    AvailabilityStatus availability[MAX_ITEMS]; // Array of availability statuses
    int count; // Number of items in the inventory
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory); // Add a new grocery item
void listGroceryItems(const GroceryInventory *inventory); // List all grocery items
void updateQuantity(GroceryInventory *inventory); // Update the quantity of an item 
void removeGroceryItem(GroceryInventory *inventory); // Remove a grocery item

int main() {
    GroceryInventory inventory = { .count = 0 }; // Initialize inventory
    int choice;

    do {
        // Display menu
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addGroceryItem(&inventory); // add a new item 
                break;
            case 2:
                listGroceryItems(&inventory); // list all items 
                break;
            case 3:
                updateQuantity(&inventory); // Update item quantity 
                break;
            case 4:
                removeGroceryItem(&inventory); // Remove an item 
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) { // Check if inventory is full
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count]; // Get next available item slot 
    AvailabilityStatus *status = &inventory->availability[inventory->count]; // Get corresponding availability slot

    // Input item details 
    printf("Enter item name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline character

    printf("Enter category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter price: ");
    scanf("%f", &item->price);
    getchar(); // Clear newline character

    status->inStock = item->quantity > 0; // Set availability status

    inventory->count++; // Increment inventory count
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) { // Check if inventory is empty 
        printf("No items in inventory.\n");
        return;
    }

    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i]; // Get current item 
        const AvailabilityStatus *status = &inventory->availability[i]; // Get current availability status

        // Print item details 
        printf("%d.\n", i + 1);
        printf("   Name: %s\n", item->name);
        printf("   Category: %s\n", item->category);
        printf("   Quantity: %d\n", item->quantity);
        printf("   Price: %.2f\n", item->price);
        printf("   Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) { // Check if inventory is empty
        printf("No items in inventory to update.\n");
        return;
    }

    listGroceryItems(inventory);
    printf("Enter the item number to update: ");
    int itemNumber;
    scanf("%d", &itemNumber);
    getchar(); // Clear newline character

    if (itemNumber < 1 || itemNumber > inventory->count) {
        printf("Invalid item number.\n");
        return;
    }

    GroceryItem *item = &inventory->items[itemNumber - 1];
    AvailabilityStatus *status = &inventory->availability[itemNumber - 1];

    printf("Enter new quantity for %s: ", item->name);
    scanf("%d", &item->quantity);
    getchar(); // Clear newline character

    status->inStock = item->quantity > 0; // Update availability status
    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    listGroceryItems(inventory);
    printf("Enter the item number to remove: ");
    int itemNumber;
    scanf("%d", &itemNumber);
    getchar(); // Clear newline character

    if (itemNumber < 1 || itemNumber > inventory->count) {
        printf("Invalid item number.\n");
        return;
    }

    // Shift items to remove the selected item
    for (int i = itemNumber - 1; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->availability[i] = inventory->availability[i + 1];
    }

    inventory->count--; // Decrease count
    printf("Item removed successfully!\n");
}
