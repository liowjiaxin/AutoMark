#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Defining the structures
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .count = 0 };
    int choice;

    do {
        printf("\nGrocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
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
    AvailabilityStatus *status = &inventory->availability[inventory->count];

    printf("Enter name: ");
    scanf(" %[^\n]", item->name);  
    printf("Enter category: ");
    scanf(" %[^\n]", item->category);  
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);

    status->inStock = item->quantity > 0;

    inventory->count++;
    printf("Item added successfully!\n");
}

void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->availability[i];
        printf("%d. Name: %s, Category: %s, Quantity: %d, Price: %.2f, %s\n",
               i + 1, item->name, item->category, item->quantity, item->price,
               status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int index;
    printf("Enter the item number to update quantity: ");
    scanf("%d", &index);

    if (index < 1 || index > inventory->count) {
        printf("Invalid item number.\n");
        return;
    }

    GroceryItem *item = &inventory->items[index - 1];
    AvailabilityStatus *status = &inventory->availability[index - 1];

    printf("Enter new quantity for %s: ", item->name);
    scanf("%d", &item->quantity);

    status->inStock = item->quantity > 0;
    printf("Quantity updated successfully!\n");
}

void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    int index;
    printf("Enter the item number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > inventory->count) {
        printf("Invalid item number.\n");
        return;
    }

    for (int i = index - 1; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
        inventory->availability[i] = inventory->availability[i + 1];
    }

    inventory->count--;
    printf("Item removed successfully!\n");
}
