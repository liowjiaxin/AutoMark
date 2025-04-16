#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Structure for Grocery Item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

// Structure for Availability Status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Structure for Grocery Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    GroceryItem newItem;
    printf("Enter Item Name: ");
    getchar();  // To clear the newline character from previous input
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  // Remove newline character from input

    printf("Enter Category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    // Update the inventory
    inventory->items[inventory->itemCount] = newItem;
    inventory->availability[inventory->itemCount].inStock = (newItem.quantity > 0);
    inventory->availability[inventory->itemCount].outOfStock = (newItem.quantity == 0);
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items with their availability
void listAllItems(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        printf("\nName: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", inventory->availability[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    getchar();  // To clear the newline character from previous input
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline character from input

    // Search for the item by name
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            int newQuantity;
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &newQuantity);

            inventory->items[i].quantity = newQuantity;
            inventory->availability[i].inStock = (newQuantity > 0);
            inventory->availability[i].outOfStock = (newQuantity == 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    getchar();  // To clear the newline character from previous input
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline character from input

    // Search for the item by name and remove it
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            // Shift items to remove the item
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCount--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Main menu for interacting with the inventory
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

int main() {
    GroceryInventory inventory = { .itemCount = 0 };  // Initialize the inventory with no items

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listAllItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
