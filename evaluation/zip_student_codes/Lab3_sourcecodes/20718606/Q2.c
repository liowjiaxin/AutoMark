#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define NAME_LEN 100
#define CATEGORY_LEN 50

// Struct to store item details
typedef struct {
    char name[NAME_LEN]; // Item name, max 100 characters
    char category[CATEGORY_LEN]; // Category of the item, max 50 characters
    int quantity; // Quantity available
    float price; // Price per item
} GroceryItem;

// Struct to store availability status
typedef struct {
    bool inStock; // True if item is in stock
    bool outOfStock; // True if item is out of stock
} AvailabilityStatus;

// Struct to manage the entire inventory
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Array to hold grocery items
    AvailabilityStatus status[MAX_ITEMS]; // Array to hold availability status
    int count; // Number of items currently in inventory
} GroceryInventory;

// Function to add a new grocery item to the inventory
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) { // -> is a pointer operator. In this case it points to the memory address of the count variable.
        printf("Inventory is full. Cannot add more items.\n"); 
        return;
    }

    GroceryItem newItem; // Temporary variable to hold the new item
    printf("Enter item name: ");
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline character

    printf("Enter category: ");
    fgets(newItem.category, CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity); // Read the quantity

    printf("Enter price: ");
    scanf("%f", &newItem.price); // Read the price
    getchar(); // Clear the newline left by scanf

    // Add the new item to the inventory
    inventory->items[inventory->count] = newItem;

    AvailabilityStatus newStatus;
    if (newItem.quantity > 0) {
        newStatus.inStock = true; // Item is available
        newStatus.outOfStock = false;
    } else {
        newStatus.inStock = false; // Item is not available
        newStatus.outOfStock = true;
    }

    inventory->status[inventory->count] = newStatus; // Update status
    inventory->count++; // Increment item count

    printf("Item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory List:\n");
    for (int i = 0; i < inventory->count; i++) { // Loop through all items
        printf("Item %d:\n", i + 1); 
        printf("  Name: %s\n", inventory->items[i].name);
        printf("  Category: %s\n", inventory->items[i].category);
        printf("  Quantity: %d\n", inventory->items[i].quantity);
        printf("  Price: %.2f\n", inventory->items[i].price);
        printf("  Availability: %s\n", inventory->status[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an existing item
void updateQuantity(GroceryInventory *inventory) {
    char itemName[NAME_LEN];
    printf("Enter the name of the item to update quantity: ");
    fgets(itemName, NAME_LEN, stdin); // Read the item name from user input
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) { // Check if the item name matches
            printf("Enter new quantity: "); 
            scanf("%d", &inventory->items[i].quantity); // Read the new quantity
            getchar(); // Clear the newline left by scanf

            // Update availability status using boolean conditions to check
            if (inventory->items[i].quantity > 0) {
                inventory->status[i].inStock = true; 
                inventory->status[i].outOfStock = false;
            } else {
                inventory->status[i].inStock = false;
                inventory->status[i].outOfStock = true;
            }

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove an item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    char itemName[NAME_LEN];
    printf("Enter the name of the item to remove: ");
    fgets(itemName, NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0; // Remove newline character

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            // Shift items down to remove the specified item
            for (int j = i; j < inventory->count - 1; j++) { // Shift items down
                inventory->items[j] = inventory->items[j + 1]; // Copy the next item
                inventory->status[j] = inventory->status[j + 1]; // Copy the next availability status
            }

            inventory->count--; // Decrease the count
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

int main() {
    GroceryInventory inventory = { .count = 0 }; // Initialize inventory
    int choice;

    do {
        // Display menu
        printf("\nGrocery Inventory Management:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice
        getchar(); // Clear the newline left by scanf

        switch (choice) {
            case 1:
                addGroceryItem(&inventory); // Add new item
                break;
            case 2:
                listGroceryItems(&inventory); // List all items
                break;
            case 3:
                updateQuantity(&inventory); // Update quantity of an item
                break;
            case 4:
                removeGroceryItem(&inventory); // Remove an item
                break;
            case 5:
                printf("Exiting program.\n"); // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    } while (choice != 5); // Loop until user chooses to exit

    return 0;
}
