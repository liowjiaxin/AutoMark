#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_ITEMS 100

// Structure for grocery item
struct GroceryItem {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

// Structure for availability status
struct AvailabilityStatus {
    bool inStock;
};

// Structure for grocery inventory
struct GroceryInventory {
    struct GroceryItem items[MAX_ITEMS];
    struct AvailabilityStatus status[MAX_ITEMS];
    int itemCount;
};

// Function declarations
void initializeInventory(struct GroceryInventory *inventory);
void addGroceryItem(struct GroceryInventory *inventory);
void listGroceryItems(struct GroceryInventory *inventory);
void updateQuantity(struct GroceryInventory *inventory);
void removeGroceryItem(struct GroceryInventory *inventory);
int findItem(struct GroceryInventory *inventory, char *name);

int main() {
    struct GroceryInventory inventory;
    initializeInventory(&inventory);
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
        getchar(); // Clear input buffer

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initializeInventory(struct GroceryInventory *inventory) {
    inventory->itemCount = 0;
}

void addGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    struct GroceryItem *item = &inventory->items[inventory->itemCount];
    
    printf("Enter Item Name: ");
    fgets(item->name, MAX_NAME_LENGTH, stdin);
    item->name[strcspn(item->name, "\n")] = 0;
    
    printf("Enter Category: ");
    fgets(item->category, MAX_CATEGORY_LENGTH, stdin);
    item->category[strcspn(item->category, "\n")] = 0;
    
    printf("Enter Quantity: ");
    scanf("%d", &item->quantity);
    
    printf("Enter Price: ");
    scanf("%f", &item->price);

    inventory->status[inventory->itemCount].inStock = (item->quantity > 0);
    inventory->itemCount++;

    printf("Grocery item added successfully!\n");
}

void listGroceryItems(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        printf("Name: %s\n", inventory->items[i].name);
        printf("Category: %s\n", inventory->items[i].category);
        printf("Quantity: %d\n", inventory->items[i].quantity);
        printf("Price: %.2f\n", inventory->items[i].price);
        printf("Status: %s\n", inventory->status[i].inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

void updateQuantity(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    int index = findItem(inventory, itemName);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    printf("Enter new quantity for %s: ", itemName);
    scanf("%d", &inventory->items[index].quantity);
    inventory->status[index].inStock = (inventory->items[index].quantity > 0);
    printf("Quantity updated successfully!\n");
}

void removeGroceryItem(struct GroceryInventory *inventory) {
    if (inventory->itemCount == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    fgets(itemName, MAX_NAME_LENGTH, stdin);
    itemName[strcspn(itemName, "\n")] = 0;

    int index = findItem(inventory, itemName);
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    // Shift remaining items
    for (int i = index; i < inventory->itemCount - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->status[i] = inventory->status[i + 1];
    }
    inventory->itemCount--;
    printf("Grocery item '%s' removed successfully!\n", itemName);
}

int findItem(struct GroceryInventory *inventory, char *name) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}