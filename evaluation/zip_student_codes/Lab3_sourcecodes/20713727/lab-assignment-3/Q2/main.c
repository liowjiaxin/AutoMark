#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Struct for Grocery Item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
    int inStock; // 1 for In Stock, 0 for Out of Stock
} GroceryItem;

// Inventory Struct
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

// Function Prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .totalItems = 0 };
    int choice;

    while (1) {
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->totalItems];
    printf("Enter Item Name: ");
    getchar(); // Clear newline character from buffer
    fgets(item->name, MAX_NAME_LENGTH, stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline character
    printf("Enter Category: ");
    fgets(item->category, MAX_CATEGORY_LENGTH, stdin);
    item->category[strcspn(item->category, "\n")] = '\0';
    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter Price: ");
    scanf("%f", &item->price);

    item->inStock = (item->quantity > 0) ? 1 : 0;
    inventory->totalItems++;
    printf("Grocery item added successfully!\n");
}

void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->totalItems; i++) {
        GroceryItem *item = &inventory->items[i];
        printf("\nName: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", item->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    getchar(); // Clear newline character from buffer
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", inventory->items[i].name);
            scanf("%d", &inventory->items[i].quantity);
            inventory->items[i].inStock = (inventory->items[i].quantity > 0) ? 1 : 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Grocery item '%s' not found.\n", itemName);
}

void removeGroceryItem(GroceryInventory *inventory) {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    getchar(); // Clear newline character from buffer
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

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

    printf("Grocery item '%s' not found.\n", itemName);
}