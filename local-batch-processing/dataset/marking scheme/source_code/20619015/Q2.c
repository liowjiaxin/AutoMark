#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Structure for Grocery Item
struct GroceryItem {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

// Enum for availability status
typedef enum {
    IN_STOCK,
    OUT_OF_STOCK
} AvailabilityStatus;

// Structure for Inventory
struct GroceryInventory {
    struct GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int itemCount;
};

void addGroceryItem(struct GroceryInventory *inventory);
void listGroceryItems(struct GroceryInventory *inventory);
void updateQuantity(struct GroceryInventory *inventory);
void removeGroceryItem(struct GroceryInventory *inventory);

// Function to list all grocery items with their availability
void listGroceryItems(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\n--- Grocery Inventory ---\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        printf("Item %d: %s\n", i + 1, inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Availability: %s\n", inventory->status[i] == IN_STOCK ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    int itemIndex;
    printf("Enter the item number to update quantity: ");
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > inventory->itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    itemIndex--; // Adjust for 0-based index
    printf("Current quantity: %d\n", inventory->items[itemIndex].quantity);
    printf("Enter new quantity: ");
    scanf("%d", &inventory->items[itemIndex].quantity);

    // Update availability status based on new quantity
    if (inventory->items[itemIndex].quantity > 0) {
        inventory->status[itemIndex] = IN_STOCK;
    } else {
        inventory->status[itemIndex] = OUT_OF_STOCK;
    }

    printf("Quantity updated successfully!\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    int itemIndex;
    printf("Enter the item number to remove: ");
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > inventory->itemCount) {
        printf("Invalid item number.\n");
        return;
    }

    itemIndex--; // Adjust for 0-based index
    for (int i = itemIndex; i < inventory->itemCount - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }

    inventory->itemCount--;
    printf("Item removed successfully!\n");
}

int main() {
    struct GroceryInventory inventory = {{0}, {OUT_OF_STOCK}, 0};  // Initialize inventory

    int choice;
    do {
         printf("\n-- Grocery Inventory Menu --\n");
        printf("1. Add grocery item\n");
        printf("2. List all grocery items\n");
        printf("3. Update quantity\n");
        printf("4. Remove grocery item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item to the inventory
void addGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    struct GroceryItem newItem;
    printf("Enter item name: ");
    getchar();  // To consume the newline character left by scanf
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0;  // Remove trailing newline

    printf("Enter category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = 0;

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    // Set availability status based on quantity
    if (newItem.quantity > 0) {
        inventory->status[inventory->itemCount] = IN_STOCK;
    } else {
        inventory->status[inventory->itemCount] = OUT_OF_STOCK;
    }

    inventory->items[inventory->itemCount] = newItem;
    inventory->itemCount++;
    printf("Grocery item added successfully!\n");
}