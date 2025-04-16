#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100       // Let MAX_ITEMS = 100

// Initialize variables
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    int inStock; // 1 for in stock, 0 for out of stock
} AvailabilityStatus;


typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    AvailabilityStatus status;

    printf("Enter Item Name: ");
    scanf(" %[^\n]", item.name);
    printf("Enter Category: ");
    scanf(" %[^\n]", item.category);
    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter Price: ");
    scanf("%f", &item.price);

    // Check the quantity of the item quantity > 0. If true status.inStock = 1, false = 0
    status.inStock = item.quantity > 0 ? 1 : 0;

    inventory->items[inventory->itemCount] = item;      // Add the new items into item array in inventory
    inventory->availability[inventory->itemCount] = status;     // Add the availability status of the new item to availability array in the inventory
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        GroceryItem item = inventory->items[i];
        AvailabilityStatus status = inventory->availability[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n\n", status.inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory to update.\n");
        return;
    }

    char name[100];
    int newQuantity;

    printf("Enter name of the grocery item to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {      // If the name of the i-th term is same as the inputed name.
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            inventory->items[i].quantity = newQuantity;         // Set the i-th term in inventory to newQuantity
            inventory->availability[i].inStock = newQuantity > 0 ? 1 : 0;       // Update the instock status, then check is newQuantity > 0.

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item '%s' not found in the inventory.\n", name);
}

// Function to remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory to remove.\n");
        return;
    }

    char name[100];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {        // Remove the item from the iventory
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCount--;     // Item count -1

            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Grocery item '%s' not found in the inventory.\n", name);
}

// Main function with menu
int main() {
    GroceryInventory inventory = {0};

    int choice;
    do {
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
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateGroceryItem(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
