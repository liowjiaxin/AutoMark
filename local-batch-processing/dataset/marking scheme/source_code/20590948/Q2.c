#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100       // Maximum number of grocery items allowed in inventory
#define MAX_NAME_LEN 100    // Maximum length for item names
#define MAX_CATEGORY_LEN 50 // Maximum length for item categories

// Structure to store details of a grocery item
typedef struct {
    char name[MAX_NAME_LEN];       // Name of the grocery item
    char category[MAX_CATEGORY_LEN]; // Category to which the item belongs
    int quantity;                 // Number of items available
    float price;                  // Price per unit of the item
} GroceryItem;

// Structure to manage item availability status
typedef struct {
    bool inStock;                 // Indicates if the item is in stock
    bool outOfStock;              // Indicates if the item is out of stock
} AvailabilityStatus;

// Structure to maintain the inventory, including items and their statuses
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Array of grocery items
    AvailabilityStatus status[MAX_ITEMS]; // Array of item availability statuses
    int count;                    // Number of items currently in inventory
} GroceryInventory;

// Function declarations for inventory operations
void addItem(GroceryInventory* inventory);     // Function to add a new item to the inventory
void listItems(GroceryInventory* inventory);   // Function to list all items in the inventory
void updateQuantity(GroceryInventory* inventory); // Function to update the quantity of an item
void removeItem(GroceryInventory* inventory);  // Function to remove an item from the inventory

int main() {
    GroceryInventory inventory = {.count = 0}; // Initialize inventory with no items
    int choice; // Variable to store user's menu selection

    // Menu-driven program for inventory management
    do {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer to prevent issues with fgets

        switch (choice) {
            case 1:
                addItem(&inventory); // Add a new item to the inventory
                break;
            case 2:
                listItems(&inventory); // Display all items in the inventory
                break;
            case 3:
                updateQuantity(&inventory); // Update the quantity of an existing item
                break;
            case 4:
                removeItem(&inventory); // Remove an item from the inventory
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Add a new grocery item to the inventory
void addItem(GroceryInventory* inventory) {
    if (inventory->count >= MAX_ITEMS) { // Check if the inventory is full
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem* item = &inventory->items[inventory->count]; // Get pointer to the new item
    AvailabilityStatus* status = &inventory->status[inventory->count]; // Get pointer to the new item's status

    // Input details for the new item
    printf("Enter item name: ");
    fgets(item->name, MAX_NAME_LEN, stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline character from input

    printf("Enter category: ");
    fgets(item->category, MAX_CATEGORY_LEN, stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter price: ");
    scanf("%f", &item->price);

    // Update availability status based on quantity
    status->inStock = item->quantity > 0;
    status->outOfStock = !status->inStock;

    inventory->count++; // Increment the count of items in inventory
    printf("Grocery item added successfully!\n");
}

// Display all grocery items in the inventory
void listItems(GroceryInventory* inventory) {
    if (inventory->count == 0) { // Check if inventory is empty
        printf("No grocery items in the inventory.\n");
        return;
    }

    // Iterate through the inventory and display item details
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem* item = &inventory->items[i];
        AvailabilityStatus* status = &inventory->status[i];

        printf("\nItem %d:\n", i + 1);
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

// Update the quantity of a specific grocery item
void updateQuantity(GroceryInventory* inventory) {
    if (inventory->count == 0) { // Check if inventory is empty
        printf("No items in inventory to update.\n");
        return;
    }

    char name[MAX_NAME_LEN]; // Variable to store item name for search
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    // Search for the item by name
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);

            // Update availability status based on new quantity
            inventory->status[i].inStock = inventory->items[i].quantity > 0;
            inventory->status[i].outOfStock = !inventory->status[i].inStock;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Remove a grocery item from the inventory
void removeItem(GroceryInventory* inventory) {
    if (inventory->count == 0) { // Check if inventory is empty
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[MAX_NAME_LEN]; // Variable to store item name for removal
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    // Search for the item by name
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift items to remove the specified item
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }

            inventory->count--; // Decrease item count
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
