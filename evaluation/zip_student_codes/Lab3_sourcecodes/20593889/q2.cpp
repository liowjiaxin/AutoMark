#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// define structures
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool in_stock;
    bool out_of_stock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int count;
} GroceryInventory;

// function prototypes
void addGroceryItem(GroceryInventory* inventory);
void listGroceryItems(const GroceryInventory* inventory);
void updateGroceryQuantity(GroceryInventory* inventory);
void removeGroceryItem(GroceryInventory* inventory);
void displayMenu();

//  entry to the program
int main() {
    GroceryInventory inventory;
    inventory.count = 0;

    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
        case 1:
            addGroceryItem(&inventory);
            break;
        case 2:
            listGroceryItems(&inventory);
            break;
        case 3:
            updateGroceryQuantity(&inventory);
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

void displayMenu() {
    printf("\n=== Grocery Inventory Management ===\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity of a Grocery Item\n");
    printf("4. Remove a Grocery Item\n");
    printf("5. Exit\n");
}

void addGroceryItem(GroceryInventory* inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem* item = &inventory->items[inventory->count];
    AvailabilityStatus* status = &inventory->status[inventory->count];

    printf("Enter item name: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = '\0'; // Remove newline

    printf("Enter category: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    getchar(); // Clear the newline character

    printf("Enter price: ");
    scanf("%f", &item->price);
    getchar();

    status->in_stock = item->quantity > 0;
    status->out_of_stock = item->quantity == 0;

    inventory->count++;
    printf("Item added successfully.\n");
}

void listGroceryItems(const GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n=== Grocery Inventory ===\n");
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem* item = &inventory->items[i];
        const AvailabilityStatus* status = &inventory->status[i];

        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", item->name);
        printf("  Category: %s\n", item->category);
        printf("  Quantity: %d\n", item->quantity);
        printf("  Price: $%.2f\n", item->price);
        printf("  Status: %s\n", status->in_stock ? "In Stock" : "Out of Stock");
    }
}

void updateGroceryQuantity(GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char name[100];
    printf("Enter the name of the item to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        GroceryItem* item = &inventory->items[i];
        AvailabilityStatus* status = &inventory->status[i];

        if (strcmp(item->name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &item->quantity);
            getchar();

            status->in_stock = item->quantity > 0;
            status->out_of_stock = item->quantity == 0;

            printf("Quantity updated successfully.\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void removeGroceryItem(GroceryInventory* inventory) {
    if (inventory->count == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[100];
    printf("Enter the name of the item to remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->count--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
