#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int inStock;
    int outOfStock;
} AvailabilityStatus;

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    GroceryItem items[100];
    AvailabilityStatus status[100];
    int count;
} GroceryInventory;

GroceryInventory inventory;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();
void updateItemStatus(int index);

int main() {
    inventory.count = 0;
    int choice;
    char input[100];

    do {
        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &choice) != 1) {
                printf("Invalid choice! Please try again.\n");
                continue;
            }

            switch (choice) {
            case 1: addGroceryItem(); break;
            case 2: listGroceryItems(); break;
            case 3: updateQuantity(); break;
            case 4: removeGroceryItem(); break;
            case 5: break;
            default: printf("Invalid choice! Please try again.\n");
            }
        }
    } while (choice != 5);

    return 0;
}

void addGroceryItem() {
    if (inventory.count >= 100) {
        printf("Inventory is full!\n");
        return;
    }

    GroceryItem* item = &inventory.items[inventory.count];

    printf("Enter Item Name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = 0;

    printf("Enter Category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = 0;

    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);
    clearInputBuffer();

    printf("Enter Price: ");
    scanf("%f", &item->price);
    clearInputBuffer();

    updateItemStatus(inventory.count);
    inventory.count++;
    printf("Grocery item added successfully!\n");
}

void listGroceryItems() {
    if (inventory.count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory.count; i++) {
        printf("Name: %s\n", inventory.items[i].name);
        printf("Category: %s\n", inventory.items[i].category);
        printf("Quantity: %d\n", inventory.items[i].quantity);
        printf("Price: %.2f\n", inventory.items[i].price);
        printf("Status: %s\n", inventory.status[i].inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity() {
    char itemName[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", itemName);
            if (scanf("%d", &inventory.items[i].quantity) != 1) {
                printf("Invalid input for quantity!\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();
            updateItemStatus(i);
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void removeGroceryItem() {
    char itemName[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    for (int i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.items[i].name, itemName) == 0) {
            for (int j = i; j < inventory.count - 1; j++) {
                inventory.items[j] = inventory.items[j + 1];
                inventory.status[j] = inventory.status[j + 1];
            }
            inventory.count--;
            printf("Grocery item '%s' removed successfully!\n", itemName);
            return;
        }
    }
    printf("Item not found!\n");
}

void updateItemStatus(int index) {
    if (inventory.items[index].quantity > 0) {
        inventory.status[index].inStock = 1;
        inventory.status[index].outOfStock = 0;
    }
    else {
        inventory.status[index].inStock = 0;
        inventory.status[index].outOfStock = 1;
    }
}