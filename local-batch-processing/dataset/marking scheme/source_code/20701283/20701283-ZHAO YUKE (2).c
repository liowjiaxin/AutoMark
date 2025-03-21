#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Define the general merchandise structure
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
    bool inStock; // inventory status:true indicated stock£¬false out of stock
} GroceryItem;

// Define the grocery inventory structure.
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int totalItems; // The number of items currently in stock
} GroceryInventory;

// Add product function
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *newItem = &inventory->items[inventory->totalItems];
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem->name);
    printf("Enter item category: ");
    scanf(" %[^\n]", newItem->category);
    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem->price);

    newItem->inStock = (newItem->quantity > 0);
    inventory->totalItems++;

    printf("Item added successfully!\n");
}

// Lists all commodity functions
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nInventory Items:\n");
    int i;
	for ( i = 0; i < inventory->totalItems; i++) {
        const GroceryItem *item = &inventory->items[i];
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", item->name);
        printf("  Category: %s\n", item->category);
        printf("  Quantity: %d\n", item->quantity);
        printf("  Price: %.2f\n", item->price);
        printf("  Availability: %s\n", item->inStock ? "In Stock" : "Out of Stock");
    }
}

// Update the quantity function
void updateQuantity(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", itemName);

    int i;
	for ( i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &inventory->items[i].quantity);
            inventory->items[i].inStock = (inventory->items[i].quantity > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Delete commodity function
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", itemName);

    int i;
	for ( i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            int j;
			for ( j = i; j < inventory->totalItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->totalItems--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// main function
int main() {
    GroceryInventory inventory = {.totalItems = 0};
    int choice;

    do {
        printf("\nGrocery Inventory Menu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Item Quantity\n");
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
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

