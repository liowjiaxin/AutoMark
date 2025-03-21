#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Struct to store grocery item details
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
} GroceryItem;

// Struct to store availability status
typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

// Struct to store the grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(const GroceryInventory *inventory);
void updateItemQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .count = 0 };
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
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(&inventory);
                break;
            case 3:
                updateItemQuantity(&inventory);
                break;
            case 4:
                removeGroceryItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
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

    GroceryItem *item = &inventory->items[inventory->count];
    AvailabilityStatus *status = &inventory->status[inventory->count];

    printf("Enter item name: ");
    fgets(item->name, MAX_NAME_LEN, stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline

    printf("Enter item category: ");
    fgets(item->category, MAX_CATEGORY_LEN, stdin);
    item->category[strcspn(item->category, "\n")] = '\0'; // Remove newline

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter price: ");
    scanf("%f", &item->price);

    getchar(); // Consume newline

    status->inStock = (item->quantity > 0);
    status->outOfStock = !status->inStock;

    inventory->count++;
    printf("Grocery item added successfully!\n");
}

void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->status[i];

        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateItemQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }
    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to update quantity: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';   // Remove newline

    for (int i = 0; i < inventory->count; i++) {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->status[i];

        if (strcspn(item->name, name) == 0){
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);

            status->inStock = (item->quantity > 0);
            status->outOfStock = !status->inStock;

            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}

void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory to remove.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcspn(inventory->items[i].name, name) == 0) {
            printf("Grocery item '%s' removed successfully!\n", inventory->items[i].name);
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }

            inventory->count--;
            return;
        }
    }

    printf("Item not found in the inventory.\n");

}
