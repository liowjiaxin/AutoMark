#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEM_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_INVENTORY_SIZE 100

// Structure for grocery item
typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;

// Structure for availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Structure for grocery inventory
typedef struct {
    GroceryItem items[MAX_INVENTORY_SIZE];
    AvailabilityStatus status[MAX_INVENTORY_SIZE];
    int count;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listAllGroceryItems(GroceryInventory inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory;
    inventory.count = 0;

    int choice;
    do {
        printf("Grocery Inventory Management System\n");
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
                listAllGroceryItems(inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_INVENTORY_SIZE) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *newItem = &inventory->items[inventory->count];
    AvailabilityStatus *newStatus = &inventory->status[inventory->count];

    printf("Enter Item Name: ");
    scanf("%s", newItem->name);
    printf("Enter Category: ");
    scanf("%s", newItem->category);
    printf("Enter Quantity: ");
    scanf("%d", &newItem->quantity);
    if (newItem->quantity > 0) {
        newStatus->inStock = true;
        newStatus->outOfStock = false;
    } else {
        newStatus->inStock = false;
        newStatus->outOfStock = true;
    }
    printf("Enter Price: ");
    scanf("%f", &newItem->price);

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

void listAllGroceryItems(GroceryInventory inventory) {
    if (inventory.count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("Grocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
    printf("Enter your choice: 2\n");

    for (int i = 0; i < inventory.count; i++) {
        printf("Name: %s\n", inventory.items[i].name);
        printf("Category: %s\n", inventory.items[i].category);
        printf("Quantity: %d\n", inventory.items[i].quantity);
        printf("Price: %.2f\n", inventory.items[i].price);
        if (inventory.status[i].inStock) {
            printf("Status: In Stock\n");
        } else {
            printf("Status: Out of Stock\n");
        }
        printf("\n");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    char name[MAX_ITEM_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    scanf("%s", name);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            if (inventory->items[i].quantity > 0) {
                inventory->status[i].inStock = true;
                inventory->status[i].outOfStock = false;
            } else {
                inventory->status[i].inStock = false;
                inventory->status[i].outOfStock = true;
            }
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void removeGroceryItem(GroceryInventory *inventory) {
    char name[MAX_ITEM_NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    scanf("%s", name);

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}