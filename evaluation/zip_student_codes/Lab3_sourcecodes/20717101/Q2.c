#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Define the structures
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
} GroceryItem;

typedef struct {
    bool inStock;
    bool outOfStock;
} AvailabilityStatus;

typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int totalItems;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(const GroceryInventory *inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory = { .totalItems = 0 };
    int choice;

    while (1) {
        // Display menu
        printf("\nGrocery Inventory Management:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

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
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->totalItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *newItem = &inventory->items[inventory->totalItems];
    AvailabilityStatus *newStatus = &inventory->status[inventory->totalItems];

    printf("Enter item name: ");
    fgets(newItem->name, sizeof(newItem->name), stdin);
    newItem->name[strcspn(newItem->name, "\n")] = '\0';

    printf("Enter item category: ");
    fgets(newItem->category, sizeof(newItem->category), stdin);
    newItem->category[strcspn(newItem->category, "\n")] = '\0';

    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);

    printf("Enter item price: ");
    scanf("%f", &newItem->price);

    // Update availability status
    newStatus->inStock = newItem->quantity > 0;
    newStatus->outOfStock = newItem->quantity == 0;

    inventory->totalItems++;
    printf("Item added successfully!\n");
}

void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nGrocery Inventory:\n");
    for (int i = 0; i < inventory->totalItems; i++) {
        const GroceryItem *item = &inventory->items[i];
        const AvailabilityStatus *status = &inventory->status[i];
        printf("%d.\n", i + 1);
        printf("Name: %s\n", item->name);
        printf("Category: %s\n", item->category);
        printf("Quantity: %d\n", item->quantity);
        printf("Price: %.2f\n", item->price);
        printf("Status: %s\n\n", status->inStock ? "In Stock" : "Out of Stock");
    }
}

void updateQuantity(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    char itemName[100];
    printf("Enter the name of the item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    for (int i = 0; i < inventory->totalItems; i++) {
        GroceryItem *item = &inventory->items[i];
        AvailabilityStatus *status = &inventory->status[i];

        if (strcmp(item->name, itemName) == 0) {
            printf("Enter new quantity for %s: ", item->name);
            scanf("%d", &item->quantity);
            getchar(); // Clear newline from buffer

            // Update availability status
            status->inStock = item->quantity > 0;
            status->outOfStock = item->quantity == 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item with name '%s' not found in inventory.\n", itemName);
}

void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->totalItems == 0) {
        printf("No items in inventory.\n");
        return;
    }

    char itemName[100];
    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    for (int i = 0; i < inventory->totalItems; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            for (int j = i; j < inventory->totalItems - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }

            inventory->totalItems--;
            printf("Item '%s' removed successfully!\n", itemName);
            return;
        }
    }

    printf("Item with name '%s' not found in inventory.\n", itemName);
}
