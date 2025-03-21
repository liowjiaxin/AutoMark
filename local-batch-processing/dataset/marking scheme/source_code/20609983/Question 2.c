#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// use structure to hold info
typedef struct {
    char name[100]; // grocery item name
    char category[50]; // category name
    int quantity; // number of stock quantity in interger
    float price; // make price per unit decimal
} GroceryItem;

// use structure to hold availability status
typedef struct {
    bool inStock; // Boolean to indicate if the item is in stock
} AvailabilityStatus;

// use structure for grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Array of grocery items
    AvailabilityStatus statuses[MAX_ITEMS]; // Array of availability statuses according to each item
    int itemCount; // number of items in the inventory
} GroceryInventory;

void addGroceryItem(GroceryInventory *inventory); // Add a new item to the inventory
void listAllGroceryItems(const GroceryInventory *inventory); // Display all items in the inventory
void updateQuantity(GroceryInventory *inventory); // Update the quantity of a specific item
void removeGroceryItem(GroceryInventory *inventory); // Remove an item from the inventory

int main() {
    GroceryInventory inventory = {.itemCount = 0}; // Initialize inventory with no items
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
                addGroceryItem(&inventory); // Call function to add a new item
                break;
            case 2:
                listAllGroceryItems(&inventory); // Call function to list all items
                break;
            case 3:
                updateQuantity(&inventory); // Call function to update item quantity
                break;
            case 4:
                removeGroceryItem(&inventory); // Call function to remove an item
                break;
            case 5:
                printf("Exiting the program.\n"); // Exit message
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) { // Check if the inventory is full
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item Name: ");
    getchar(); // Consume the newline character left by scanf
    fgets(newItem.name, sizeof(newItem.name), stdin); // Read the name of the item
    newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin); // Read the category of the item
    newItem.category[strcspn(newItem.category, "\n")] = 0; // Remove trailing newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity); // Read the quantity

    printf("Enter Price: ");
    scanf("%f", &newItem.price); // Read the price

    inventory->items[inventory->itemCount] = newItem; // Add item to inventory
    inventory->statuses[inventory->itemCount].inStock = newItem.quantity > 0; // Update availability status
    inventory->itemCount++; // Increment item count

    printf("Grocery item added successfully!\n");
}

void listAllGroceryItems(const GroceryInventory *inventory) {
    if (inventory->itemCount == 0) { // Check if the inventory is empty
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) { // Loop through all items
        const GroceryItem *item = &inventory->items[i]; // Get the current item
        const AvailabilityStatus *status = &inventory->statuses[i]; // Get the availability status

        // Display item details
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
        printf("-----------------------------\n");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to update: ");
    getchar(); // Consume the newline character left by scanf
    fgets(name, sizeof(name), stdin); // Read the name of the item
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < inventory->itemCount; i++) { // Search for the item
        if (strcmp(inventory->items[i].name, name) == 0) { // Match found
            int newQuantity;
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity); // Read the new quantity

            inventory->items[i].quantity = newQuantity; // Update quantity
            inventory->statuses[i].inStock = newQuantity > 0; // Update availability status

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n"); // Item not found
}

void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to remove: ");
    getchar(); // Consume the newline character left by scanf
    fgets(name, sizeof(name), stdin); // Read the name of the item
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    for (int i = 0; i < inventory->itemCount; i++) { // Search for the item
        if (strcmp(inventory->items[i].name, name) == 0) { // Match found
            for (int j = i; j < inventory->itemCount - 1; j++) { // Shift items to fill the gap
                inventory->items[j] = inventory->items[j + 1];
                inventory->statuses[j] = inventory->statuses[j + 1];
            }

            inventory->itemCount--; // Decrement item count
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n"); // Item not found
}
