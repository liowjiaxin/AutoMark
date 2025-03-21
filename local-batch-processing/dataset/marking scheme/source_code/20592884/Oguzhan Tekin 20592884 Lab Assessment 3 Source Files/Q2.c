#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100   // Maximum number of items in the inventory
#define MAX_NAME_LEN 100  // Maximum length for the item name
#define MAX_CATEGORY_LEN 50  // Maximum length for the category

// Struct to represent a grocery item
typedef struct {
    char name[MAX_NAME_LEN];  // Name of the grocery item
    char category[MAX_CATEGORY_LEN];  // Category of the grocery item
    int quantity;  // Quantity of the grocery item
    float price;  // Price of the grocery item
} GroceryItem;

// Enum to represent availability status
typedef enum {
    IN_STOCK,
    OUT_OF_STOCK
} AvailabilityStatus;

// Struct to represent the grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];  // Array of grocery items
    AvailabilityStatus status[MAX_ITEMS];  // Availability status array
    int totalItems;  // Total number of items in the inventory
} GroceryInventory;

// Function prototypes
void addItem(GroceryInventory* inventory);
void listItems(const GroceryInventory* inventory);
void updateQuantity(GroceryInventory* inventory);
void removeItem(GroceryInventory* inventory);
void displayMenu();
void clearInputBuffer();
int findItemIndexByName(const GroceryInventory* inventory, const char* name);

int main() {
    GroceryInventory inventory = { .totalItems = 0 };  // Initialize inventory with no items

    int choice;
    
    // Run the menu in a loop until the user decides to exit
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear any extra input left in the buffer
        
        switch(choice) {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                listItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeItem(&inventory);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\nGrocery Inventory Menu:\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items With Their Availability\n");
    printf("3. Update the Quantity of a Grocery Item\n");
    printf("4. Remove a Grocery Item From Inventory\n");
    printf("5. Exit\n");
}

// Function to clear any extra input left in the buffer (useful after scanf)
void clearInputBuffer() {
    while(getchar() != '\n');
}

// Function to find the index of an item by its name in the inventory
int findItemIndexByName(const GroceryInventory* inventory, const char* name) {
    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return i;  // Return index if the item is found
        }
    }
    return -1;  // Return -1 if the item is not found
}

// Function to add a new grocery item to the inventory
void addItem(GroceryInventory* inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Get item details from the user
    GroceryItem newItem;
    printf("Enter item name: ");
    fgets(newItem.name, MAX_NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  // Remove trailing newline

    // Check if the item already exists
    if (findItemIndexByName(inventory, newItem.name) != -1) {
        printf("Item with the name '%s' already exists in the inventory.\n", newItem.name);
        return;
    }

    printf("Enter item category: ");
    fgets(newItem.category, MAX_CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;  // Remove trailing newline

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    clearInputBuffer();  // Clear the buffer

    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    clearInputBuffer();  // Clear the buffer

    // Add the new item to the inventory
    inventory->items[inventory->totalItems] = newItem;

    // Set the availability status based on the quantity
    inventory->status[inventory->totalItems] = newItem.quantity > 0 ? IN_STOCK : OUT_OF_STOCK;

    inventory->totalItems++;  // Increase the total number of items in the inventory
    printf("Grocery Item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listItems(const GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nGrocery Items in Inventory:\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        GroceryItem item = inventory->items[i];
        AvailabilityStatus status = inventory->status[i];

        printf("\nItem %d:\n", i + 1);
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Availability: %s\n", status == IN_STOCK ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0;  // Remove trailing newline

    int itemIndex = findItemIndexByName(inventory, itemName);
    if (itemIndex == -1) {
        printf("Item '%s' not found in the inventory.\n", itemName);
        return;
    }

    // Get the new quantity from the user
    int newQuantity;
    printf("Enter new quantity for '%s': ", inventory->items[itemIndex].name);
    scanf("%d", &newQuantity);
    clearInputBuffer();  // Clear the buffer

    // Update the item's quantity and availability status
    inventory->items[itemIndex].quantity = newQuantity;
    inventory->status[itemIndex] = newQuantity > 0 ? IN_STOCK : OUT_OF_STOCK;

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from the inventory
void removeItem(GroceryInventory* inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = 0;  // Remove trailing newline

    int itemIndex = findItemIndexByName(inventory, itemName);
    if (itemIndex == -1) {
        printf("Item '%s' not found in the inventory.\n", itemName);
        return;
    }

    // Shift the items to remove the selected item
    for (int i = itemIndex; i < inventory->totalItems - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }

    inventory->totalItems--;  // Decrease the total number of items
    printf("Grocery Item '%s' removed successfully!\n", itemName);
}
