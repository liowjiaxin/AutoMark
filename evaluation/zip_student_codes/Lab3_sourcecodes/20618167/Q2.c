#include <stdio.h>
#include <string.h>

// Define constants for maximum sizes
#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Define struct for a grocery item
typedef struct {
    char name[MAX_NAME_LEN];        // Name of the grocery item
    char category[MAX_CATEGORY_LEN]; // Category of the grocery item (e.g., Dairy, Vegetables)
    int quantity;                   // Quantity of the item in stock
    float price;                    // Price per unit of the item
} GroceryItem;

// Define struct for availability status
typedef struct {
    int inStock; // 1 for true (item is in stock), 0 for false (item is out of stock)
} AvailabilityStatus;

// Define inventory containing items, their availability, and item count
typedef struct {
    GroceryItem items[MAX_ITEMS];           // Array of grocery items
    AvailabilityStatus availability[MAX_ITEMS]; // Array to track the availability of each item
    int count;                              // Current number of items in the inventory
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory); // Adds a new item to the inventory
void listGroceryItems(GroceryInventory *inventory); // Lists all items in the inventory
void updateGroceryQuantity(GroceryInventory *inventory); // Updates the quantity of a specific item
void removeGroceryItem(GroceryInventory *inventory); // Removes an item from the inventory

// Main function to provide a menu-driven interface
int main() {
    GroceryInventory inventory = {.count = 0}; // Initialize the inventory with 0 items
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity of a Grocery Item\n");
        printf("4. Remove a Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user input and call the appropriate function
        switch (choice) {
            case 1:
                addGroceryItem(&inventory); // Add a new item
                break;
            case 2:
                listGroceryItems(&inventory); // Display all items
                break;
            case 3:
                updateGroceryQuantity(&inventory); // Update an item's quantity
                break;
            case 4:
                removeGroceryItem(&inventory); // Remove an item
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // Loop until the user chooses to exit

    return 0;
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        // Check if the inventory is full
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Get a reference to the next available slot for an item
    GroceryItem *item = &inventory->items[inventory->count];
    AvailabilityStatus *status = &inventory->availability[inventory->count];

    // Prompt the user to enter details for the new item
    printf("Enter name: ");
    scanf(" %[^\n]", item->name);
    printf("Enter category: ");
    scanf(" %[^\n]", item->category);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);

    // Set availability status based on the quantity
    status->inStock = (item->quantity > 0) ? 1 : 0;

    // Increment the inventory count
    inventory->count++;

    printf("Item added successfully.\n");
}

// Function to list all grocery items with their availability
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        // Check if the inventory is empty
        printf("No items in the inventory.\n");
        return;
    }

    // Loop through each item and display its details
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->availability[i];
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateGroceryQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        // Check if the inventory is empty
        printf("No items in the inventory.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", name);

    // Search for the item in the inventory
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Item found, prompt for the new quantity
            printf("Enter new quantity: ");
            scanf("%d", &inventory->items[i].quantity);

            // Update the availability status based on the new quantity
            inventory->availability[i].inStock = (inventory->items[i].quantity > 0) ? 1 : 0;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    // If the item is not found, notify the user
    printf("Item not found.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        // Check if the inventory is empty
        printf("No items in the inventory.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name);

    // Search for the item to remove
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Item found, shift all subsequent items up by one position
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }

            // Decrement the inventory count
            inventory->count--;

            printf("Item removed successfully.\n");
            return;
        }
    }

    // If the item is not found, notify the user
    printf("Item not found.\n");
}
