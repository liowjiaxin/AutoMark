#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; // 1 for in stock, 0 for out of stock
} GroceryItem;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

void addItem(GroceryInventory *inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter Category: ");
    scanf(" %[^\n]", newItem.category);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    newItem.inStock = newItem.quantity > 0 ? 1 : 0;
    inventory->items[inventory->totalItems++] = newItem;

    printf("Grocery item added successfully!\n");
}

void listItems(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->totalItems; i++) {
        GroceryItem item = inventory->items[i];
        printf("Name: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n", item.inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No grocery items in the inventory to update.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", itemName);
            scanf("%d", &inventory->items[i].quantity);

            inventory->items[i].inStock = inventory->items[i].quantity > 0 ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item not found in the inventory.\n");
}

void removeItem(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No grocery items in the inventory to remove.\n");
        return;
    }

    char itemName[100];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            for (int j = i; j < inventory->totalItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->totalItems--;
            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;
        }
    }

    printf("Grocery item not found in the inventory.\n");
}

int main() {
    GroceryInventory inventory = { .totalItems = 0 };
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
        getchar(); // Clear newline character from input buffer

        switch (choice) {
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
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
