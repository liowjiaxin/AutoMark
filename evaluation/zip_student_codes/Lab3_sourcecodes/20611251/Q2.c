#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} StockStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    StockStatus stockStatus[MAX_ITEMS];
    int count;
} GroceryInventory;

void addItem(GroceryInventory *inventory);
void listItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .count = 0 };
    int choice;

    while (1) {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //remove newline

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
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count];
    StockStatus *status = &inventory->stockStatus[inventory->count];

    printf("Enter Item Name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter Price: ");
    scanf("%f", &item->price);

    status->inStock = item->quantity > 0;
    status->outOfStock = !status->inStock;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

void listItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        const StockStatus *status = &inventory->stockStatus[i];

        printf("\nName: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char name[100];
    printf("Enter the item name to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            GroceryItem *item = &inventory->items[i];
            StockStatus *status = &inventory->stockStatus[i];

            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);

            status->inStock = item->quantity > 0;
            status->outOfStock = !status->inStock;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item with name '%s' not found.\n", name);
}

void removeItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[100];
    printf("Enter the item name to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->stockStatus[j] = inventory->stockStatus[j + 1];
            }

            inventory->count--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item with name '%s' not found.\n", name);
}
