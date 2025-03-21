#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for Grocery Item
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; // 1 for In Stock, 0 for Out of Stock
} GroceryItem;

// Structure for Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int itemCount; // Number of items currently in the inventory
} GroceryInventory;

// Function to add a grocery item to the inventory
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->itemCount];

    printf("Enter Item Name: ");
    scanf(" %[^\n]", item->name);
    printf("Enter Category: ");
    scanf(" %[^\n]", item->category);
    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter Price: ");
    scanf("%f", &item->price);

    item->inStock = (item->quantity > 0) ? 1 : 0; // Determine availability based on quantity
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        const GroceryItem *item = &inventory->items[i]; // Add 'const' here
        printf("\nName: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", item->inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcasecmp(inventory->items[i].name, name) == 0) { // Case-insensitive comparison
            printf("Enter new quantity for %s: ", inventory->items[i].name);
            scanf("%d", &inventory->items[i].quantity);
            inventory->items[i].inStock = (inventory->items[i].quantity > 0) ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item not found.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcasecmp(inventory->items[i].name, name) == 0) { // Case-insensitive comparison
            printf("Grocery item '%s' removed successfully!\n", inventory->items[i].name); // Updated message
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->itemCount--;
            return;
        }
    }

    printf("Grocery item not found.\n");
}

// Main function
int main() {
    GroceryInventory inventory = {.itemCount = 0};
    int choice;

    do {
        // Display menu
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
            updateQuantity(&inventory);
            break;
        case 4:
            removeGroceryItem(&inventory);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
