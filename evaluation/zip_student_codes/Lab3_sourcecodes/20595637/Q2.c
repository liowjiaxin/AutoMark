#include <stdio.h>
#include <string.h>

// Constants defining limits for the inventory system
#define MAX_ITEMS 100          // Maximum number of items that can be stored in the inventory
#define MAX_NAME_LEN 100       // Maximum length allowed for item names
#define MAX_CATEGORY_LEN 50    // Maximum length allowed for category names

// Function prototypes for managing the inventory
void addItem();               // Adds a new item to the inventory
void displayItems();          // Displays all items in the inventory
void updateItemQuantity();    // Updates the quantity of a specific item
void deleteItem();            // Removes an item from the inventory
void displayMenu();           // Displays the menu options for the user

// Structure to represent a single item in the inventory
typedef struct {
    char itemName[MAX_NAME_LEN];         // Name of the grocery item
    char itemCategory[MAX_CATEGORY_LEN]; // Category of the grocery item (e.g., Fruits, Vegetables)
    int itemQuantity;                    // Quantity of the item in stock
    float itemPrice;                     // Price per unit of the item
    int isAvailable;                     // Availability status: 1 (available), 0 (not available)
} InventoryItem;

// Global variables
InventoryItem inventoryList[MAX_ITEMS]; // Array to hold all inventory items
int totalItems = 0;                     // Current count of items in the inventory

// Function to display the main menu of the inventory manager
void displayMenu() {
    printf("\n========== Smart Inventory Manager ==========\n");
    printf("1. Add New Grocery Item\n");
    printf("2. View All Grocery Items\n");
    printf("3. Update Item Quantity\n");
    printf("4. Remove a Grocery Item\n");
    printf("5. Exit\n");
    printf("=============================================\n");
}

// Function to add a new grocery item to the inventory
void addItem() {
    if (totalItems >= MAX_ITEMS) {
        // Check if the inventory is full
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    InventoryItem newItem; // Temporary variable to store the new item details
    printf("\n--- Add a New Grocery Item ---\n");
    printf("Enter Item Name: ");
    fgets(newItem.itemName, MAX_NAME_LEN, stdin);
    newItem.itemName[strcspn(newItem.itemName, "\n")] = 0; // Remove the newline character

    printf("Enter Item Category: ");
    fgets(newItem.itemCategory, MAX_CATEGORY_LEN, stdin);
    newItem.itemCategory[strcspn(newItem.itemCategory, "\n")] = 0; // Remove the newline character

    printf("Enter Item Quantity: ");
    scanf("%d", &newItem.itemQuantity);

    printf("Enter Item Price: ");
    scanf("%f", &newItem.itemPrice);
    getchar(); // Clear the input buffer

    // Determine availability based on the quantity
    newItem.isAvailable = (newItem.itemQuantity > 0) ? 1 : 0;

    // Add the item to the inventory and update the total count
    inventoryList[totalItems++] = newItem;
    printf("Grocery item added successfully!\n");
}

// Function to display all items currently in the inventory
void displayItems() {
    if (totalItems == 0) {
        // If no items are present in the inventory
        printf("\nNo grocery items in the inventory.\n");
        return;
    }

    printf("\n--- Current Grocery Items ---\n");
    for (int i = 0; i < totalItems; i++) {
        // Display details of each item
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", inventoryList[i].itemName);
        printf("  Category: %s\n", inventoryList[i].itemCategory);
        printf("  Quantity: %d\n", inventoryList[i].itemQuantity);
        printf("  Price: $%.2f\n", inventoryList[i].itemPrice);
        printf("  Status: %s\n", inventoryList[i].isAvailable ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an existing grocery item
void updateItemQuantity() {
    if (totalItems == 0) {
        // Check if there are items in the inventory
        printf("\nNo grocery items in the inventory to update.\n");
        return;
    }

    char targetItem[MAX_NAME_LEN]; // Temporary variable to store the name of the item to update
    printf("\n--- Update Grocery Item Quantity ---\n");
    printf("Enter the Name of the Item to Update: ");
    fgets(targetItem, MAX_NAME_LEN, stdin);
    targetItem[strcspn(targetItem, "\n")] = 0; // Remove the newline character

    // Search for the item in the inventory
    for (int i = 0; i < totalItems; i++) {
        if (strcmp(inventoryList[i].itemName, targetItem) == 0) {
            int updatedQuantity;
            printf("Enter the New Quantity: ");
            scanf("%d", &updatedQuantity);
            getchar(); // Clear the input buffer

            // Update the quantity and availability status of the item
            inventoryList[i].itemQuantity = updatedQuantity;
            inventoryList[i].isAvailable = (updatedQuantity > 0) ? 1 : 0;

            printf("Grocery item quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item not found in the inventory.\n");
}

// Function to remove a grocery item from the inventory
void deleteItem() {
    if (totalItems == 0) {
        // Check if there are items in the inventory
        printf("\nNo grocery items in the inventory to remove.\n");
        return;
    }

    char targetItem[MAX_NAME_LEN]; // Temporary variable to store the name of the item to delete
    printf("\n--- Remove a Grocery Item ---\n");
    printf("Enter the Name of the Item to Remove: ");
    fgets(targetItem, MAX_NAME_LEN, stdin);
    targetItem[strcspn(targetItem, "\n")] = 0; // Remove the newline character

    // Search for the item and delete it if found
    for (int i = 0; i < totalItems; i++) {
        if (strcmp(inventoryList[i].itemName, targetItem) == 0) {
            // Shift remaining items to fill the gap left by the deleted item
            for (int j = i; j < totalItems - 1; j++) {
                inventoryList[j] = inventoryList[j + 1];
            }
            totalItems--; // Reduce the total item count
            printf("Grocery item removed successfully!\n");
            return;
        }
    }

    printf("Grocery item not found in the inventory.\n");
}

// Main function to run the inventory manager program
int main() {
    int menuChoice;

    do {
        displayMenu(); // Show the menu options to the user
        printf("Enter your choice (1-5): ");
        scanf("%d", &menuChoice);
        getchar(); // Clear the input buffer

        // Perform the action based on the user's choice
        switch (menuChoice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItemQuantity();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (menuChoice != 5); // Exit when the user chooses option 5

    return 0;
}
