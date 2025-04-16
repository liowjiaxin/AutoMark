#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max sizes to avoid overflowing the memory
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_INVENTORY_SIZE 100

// A structure to represent a grocery item
struct GroceryItem {
    char name[MAX_NAME_LENGTH];      // Name of the item (like "Apple")
    char category[MAX_CATEGORY_LENGTH];  // Category of the item (like "Fruit")
    int quantity;                    // How many items are in stock
    float price;                     // Price of one item
};

// Enum to represent if an item is in stock or out of stock
enum AvailabilityAmount { IN_STOCK, OUT_OF_STOCK };

// A structure to represent the inventory of all grocery items
struct GroceryInventory {
    struct GroceryItem items[MAX_INVENTORY_SIZE];  // List of grocery items
    enum AvailabilityAmount availability[MAX_INVENTORY_SIZE];  // Available amount of each item
    int itemCount;  // The current number of items in the inventory
};

// Function prototypes (these are like "shortcuts" for the functions that come later)
void addGroceryItem(struct GroceryInventory *inventory);
void listGroceryItems(struct GroceryInventory *inventory);
void updateQuantity(struct GroceryInventory *inventory);
void removeGroceryItem(struct GroceryInventory *inventory);
void displayMenu();

int main() {
    struct GroceryInventory inventory = {{}, {}, 0};  // Start with an empty inventory
    int choice;

    // Keep showing the menu until the user decides to exit
    while (1) {
        displayMenu();  // Display options
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get user's choice

        // Perform the action based on the user's choice
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);  // Add a new item
                break;
            case 2:
                listGroceryItems(&inventory);  // Show all items
                break;
            case 3:
                updateQuantity(&inventory);  // Update quantity of an item
                break;
            case 4:
                removeGroceryItem(&inventory);  // Remove an item
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Try again.\n");  // Invalid option
        }
    }
    return 0;
}

// Display the menu with options
void displayMenu() {
    printf("\nGrocery Inventory Management\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Add a new grocery item to the inventory
void addGroceryItem(struct GroceryInventory *inventory) {
    // Check if there's space for new items
    if (inventory->itemCount >= MAX_INVENTORY_SIZE) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    struct GroceryItem newItem;

    // Get the item's name
    printf("Enter the name of the grocery item: ");
    getchar();  // Clear the leftover newline
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  // Remove the newline character at the end

    // Get the item's category
    printf("Enter the category of the grocery item: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;  // Remove newline

    // Get the item's quantity
    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);

    // Get the item's price
    printf("Enter the price: ");
    scanf("%f", &newItem.price);

    // Set the item's availability (In stock if quantity > 0)
    enum AvailabilityAmount Amount = (newItem.quantity > 0) ? IN_STOCK : OUT_OF_STOCK;

    // Add the new item to the inventory
    inventory->items[inventory->itemCount] = newItem;
    inventory->availability[inventory->itemCount] = Amount;
    inventory->itemCount++;

    printf("Item added successfully!\n");
}

// List all items in the inventory
void listGroceryItems(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nGrocery Inventory:\n");
    // Go through each item and print its details
    for (int i = 0; i < inventory->itemCount; i++) {
        struct GroceryItem item = inventory->items[i];
        enum AvailabilityAmount Amount = inventory->availability[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n", (Amount == IN_STOCK) ? "In Stock" : "Out of Stock");
        printf("--------------------------\n");
    }
}

// Update the quantity of an existing item
void updateQuantity(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update quentity: ");
    getchar();  // Clear the newline
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;  // Remove the newline

    // Search for the item in the inventory
    int found = 0;
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            found = 1;
            printf("Enter the new quantity for %s: ", itemName);
            int newQuantity;
            scanf("%d", &newQuantity);
            inventory->items[i].quantity = newQuantity;
            inventory->availability[i] = (newQuantity > 0) ? IN_STOCK : OUT_OF_STOCK;
            printf("Quantity updated successfully!!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found in inventory.\n");
    }
}

// Remove an item from the inventory
void removeGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    getchar();  // Clear the newline
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;  // Remove newline

    // Search for the item and remove it
    int found = 0;
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            found = 1;
            // Shift the items to remove the one at index i
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCount--;
            printf("Item '%s' has been removed succefully!.\n", itemName);
            break;
        }
    }

    if (!found) {
        printf("No item.\n");
    }
}
