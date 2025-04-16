#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

// Define the structure for Grocery Item
typedef struct {
    char name[MAX_NAME_LENGTH + 1]; // max length 100 + 1 for null terminator
    char category[MAX_CATEGORY_LENGTH + 1]; // max length 50 + 1 for null terminator
    int quantity;
    float price;
} GroceryItem;

// Define the structure for Availability Status
typedef struct {
    int inStock;
    int outOfStock;
} AvailabilityStatus;

// Define the structure for Grocery Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus availability[MAX_ITEMS];
    int itemCount;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory* inventory);
void listAllGroceryItems(GroceryInventory* inventory);
void updateQuantity(GroceryInventory* inventory, int quantity, char* name);
void removeGroceryItem(GroceryInventory* inventory, char* name);
void printGroceryItem(const GroceryItem* item, const AvailabilityStatus* status);

int main() {
    GroceryInventory inventory = { 0 }; // Initialize inventory with zero items
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity of a Grocery Item\n");
        printf("4. Remove a Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        switch (choice) {
        case 1:
            addGroceryItem(&inventory);
            break;
        case 2:
            listAllGroceryItems(&inventory);
            break;
        case 3: {
            char name[MAX_NAME_LENGTH + 1];
            int quantity;
            printf("Enter the name of the item to update: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            while (getchar() != '\n'); // Clear the input buffer
            updateQuantity(&inventory, quantity, name);
            break;
        }
        case 4: {
            char name[MAX_NAME_LENGTH + 1];
            printf("Enter the name of the item to remove: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            removeGroceryItem(&inventory, name);
            break;
        }
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addGroceryItem(GroceryInventory* inventory) {
    if (inventory->itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem* item = &inventory->items[inventory->itemCount];
    AvailabilityStatus* status = &inventory->availability[inventory->itemCount];

    printf("Enter the name of the item: ");
    fgets(item->name, sizeof(item->name), stdin);
    item->name[strcspn(item->name, "\n")] = 0; // Remove newline
    printf("Enter the category of the item: ");
    fgets(item->category, sizeof(item->category), stdin);
    item->category[strcspn(item->category, "\n")] = 0; // Remove newline
    printf("Enter the quantity of the item: ");
    scanf("%d", &item->quantity);
    while (getchar() != '\n'); // Clear the input buffer
    printf("Enter the price of the item: ");
    scanf("%f", &item->price);
    while (getchar() != '\n'); // Clear the input buffer

    status->inStock = item->quantity > 0;
    status->outOfStock = item->quantity <= 0;

    inventory->itemCount++;
    printf("Grocery item added successfully.\n");
}

void listAllGroceryItems(GroceryInventory* inventory) {
    if (inventory->itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    for (int i = 0; i < inventory->itemCount; i++) {
        printGroceryItem(&inventory->items[i], &inventory->availability[i]);
    }
}

void updateQuantity(GroceryInventory* inventory, int quantity, char* name) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i].quantity = quantity;
            inventory->availability[i].inStock = quantity > 0;
            inventory->availability[i].outOfStock = quantity <= 0;
            printf("Quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void removeGroceryItem(GroceryInventory* inventory, char* name) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->itemCount - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->availability[j] = inventory->availability[j + 1];
            }
            inventory->itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void printGroceryItem(const GroceryItem* item, const AvailabilityStatus* status) {
    printf("Name: %s\n", item->name);
    printf("Category: %s\n", item->category);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
    if (status->inStock) {
        printf("Availability: In Stock\n");
    }
    else {
        printf("Availability: Out of Stock\n");
    }
    printf("\n");
}