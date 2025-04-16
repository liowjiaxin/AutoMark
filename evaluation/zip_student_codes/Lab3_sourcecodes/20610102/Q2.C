#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Define Availability Status structure
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Define Grocery Item structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    AvailabilityStatus status;
} GroceryItem;

// Grocery Inventory structure
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus statuses[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function Prototypes
void initializeInventory(GroceryInventory *inventory);
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateItemQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);
int findItemIndex(GroceryInventory *inventory, char *itemName);

int main() {
    GroceryInventory inventory;
    int choice;

    // Initialize inventory
    initializeInventory(&inventory);

    // Main menu loop
    while (1) {
        // Display menu options
        printf("\n--- Grocery Inventory Management System ---\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        // Clear any previous input errors
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        getchar(); // Clear newline

        // Process user choice
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateItemQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Initialize inventory
void initializeInventory(GroceryInventory *inventory) {
    inventory->itemCount = 0;
}

// Add a new grocery item
void addGroceryItem(GroceryInventory *inventory) {
    // Check if inventory is full
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    // Input item name
    printf("Enter item name (max %d characters): ", MAX_NAME_LENGTH - 1);
    if (fgets(newItem.name, MAX_NAME_LENGTH, stdin) == NULL) {
        printf("Error reading item name.\n");
        return;
    }
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove newline

    // Check for duplicate items
    if (findItemIndex(inventory, newItem.name) != -1) {
        printf("Item with this name already exists!\n");
        return;
    }

    // Input category
    printf("Enter item category (max %d characters): ", MAX_CATEGORY_LENGTH - 1);
    if (fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin) == NULL) {
        printf("Error reading item category.\n");
        return;
    }
    newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove newline

    // Input quantity
    printf("Enter item quantity: ");
    if (scanf("%d", &newItem.quantity) != 1) {
        printf("Invalid quantity input.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    while (getchar() != '\n'); // Clear newline

    // Input price
    printf("Enter item price: ");
    if (scanf("%f", &newItem.price) != 1) {
        printf("Invalid price input.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    while (getchar() != '\n'); // Clear newline

    // Set availability status
    newItem.status.inStock = (newItem.quantity > 0);
    newItem.status.outOfStock = (newItem.quantity == 0);

    // Add item to inventory
    inventory->items[inventory->itemCount] = newItem;
    inventory->statuses[inventory->itemCount] = newItem.status;
    inventory->itemCount++;

    printf("Item added successfully!\n");
}

// Rest of the code remains the same as in the previous implementation
// (List, Update, Remove, and Find Item functions)