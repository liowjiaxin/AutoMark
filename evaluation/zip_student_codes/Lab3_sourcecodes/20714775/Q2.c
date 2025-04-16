#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100


typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool inStock;
} GroceryItem;


typedef struct {
    GroceryItem items[MAX_ITEMS];
    int count;
} GroceryInventory;


void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = {.count = 0};
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
        getchar();

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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter Item Name: ");
    fgets(item.name, sizeof(item.name), stdin);
    item.name[strcspn(item.name, "\n")] = 0;

    printf("Enter Category: ");
    fgets(item.category, sizeof(item.category), stdin);
    item.category[strcspn(item.category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter Price: ");
    scanf("%f", &item.price);

    getchar();

    item.inStock = item.quantity > 0;
    inventory->items[inventory->count++] = item;

    printf("Grocery item added successfully!\n");
}

void listGroceryItems(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        GroceryItem item = inventory->items[i];
        printf("\nName: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Status: %s\n", item.inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory->items[i].quantity);
            getchar();

            inventory->items[i].inStock = inventory->items[i].quantity > 0;
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}
