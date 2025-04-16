#include <stdio.h>
#include <string.h>

// Structure to represent a grocery item
typedef struct {
    char name[100];       // Name of the item
    char category[50];    // Category of the item
    int quantity;         // Quantity in stock
    float price;          // Price of the item
} GroceryItem;

// Structure to represent the availability status of an item
typedef struct {
    int inStock;          // 1 for true, 0 for false
} AvailabilityStatus;

// Structure to manage the inventory of grocery items
typedef struct {
    GroceryItem items[100];          // Array to store grocery items
    AvailabilityStatus statuses[100]; // Array for availability statuses
    int count;                       // Number of items in inventory
} GroceryInventory;

// Global inventory variable
GroceryInventory inventory = { .count = 0 };

// Function to add a new grocery item to the inventory
void addGroceryItem() {
    if (inventory.count >= 100) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]", inventory.items[inventory.count].name); // Read item name
    printf("Enter item category: ");
    scanf(" %[^\n]", inventory.items[inventory.count].category); // Read category
    printf("Enter item quantity: ");
    scanf("%d", &inventory.items[inventory.count].quantity); // Read quantity
    printf("Enter item price: ");
    scanf("%f", &inventory.items[inventory.count].price); // Read price

    // Determine availability based on quantity
    inventory.statuses[inventory.count].inStock = (inventory.items[inventory.count].quantity > 0) ? 1 : 0;
    inventory.count++;
    printf("Item added successfully!\n");
}

// Function to list all items with their details and availability
void listGroceryItems() {
    if (inventory.count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < inventory.count; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", inventory.items[i].name);
        printf("  Category: %s\n", inventory.items[i].category);
        printf("  Quantity: %d\n", inventory.items[i].quantity);
        printf("  Price: %.2f\n", inventory.items[i].price);
        printf("  Availability: %s\n", inventory.statuses[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a specific grocery item
void updateGroceryQuantity() {
    char name[100];
    int newQuantity;

    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", name); // Read item name

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity); // Read new quantity

            inventory.items[i].quantity = newQuantity;
            inventory.statuses[i].inStock = (newQuantity > 0) ? 1 : 0; // Update availability
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found!\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem() {
    char name[100];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name); // Read item name

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, name) == 0) {
            // Shift all subsequent items to fill the gap
            for (int j = i; j < inventory.count - 1; j++) {
                inventory.items[j] = inventory.items[j + 1];
                inventory.statuses[j] = inventory.statuses[j + 1];
            }
            inventory.count--; // Decrease item count
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found!\n");
}

// Main function to drive the inventory management program
int main() {
    int choice;

    do {
        printf("\nGrocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Grocery Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice

        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listGroceryItems();
                break;
            case 3:
                updateGroceryQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
