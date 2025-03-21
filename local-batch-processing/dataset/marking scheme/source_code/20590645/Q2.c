#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50


// structure to represent grocery items
typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} GroceryItem;


// structure to represent availability status of an item
typedef struct {
    bool in_stock;
    bool out_of_stock;
} AvailabilityStatus;


// structure to represent entire grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    AvailabilityStatus status[MAX_ITEMS];
    int total_items;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);
void listGroceryItems(GroceryInventory inventory);
void updateQuantity(GroceryInventory *inventory);
void removeGroceryItem(GroceryInventory *inventory);


// interface
int main() {
    GroceryInventory inventory = {.total_items = 0};
    int choice;
    int valid_input;

    do {
        printf("\n--- Grocery Inventory Management ---\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        valid_input = scanf("%d", &choice);

        if (valid_input != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        getchar(); // Consume leftover newline character from the input buffer

        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                listGroceryItems(inventory);
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
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}


// function to add items to grocery list
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->total_items >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    AvailabilityStatus newStatus;

    printf("Enter item name: ");
    fgets(newItem.name, MAX_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline

    printf("Enter item category: ");
    fgets(newItem.category, MAX_CATEGORY_LENGTH, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    getchar();

    printf("Enter price: ");
    scanf("%f", &newItem.price);
    getchar();

    newStatus.in_stock = newItem.quantity > 0;
    newStatus.out_of_stock = newItem.quantity == 0;

    inventory->items[inventory->total_items] = newItem;
    inventory->status[inventory->total_items] = newStatus;
    inventory->total_items++;

    printf("Item added successfully!\n");
}


// function to list items in list
void listGroceryItems(GroceryInventory inventory) {
    if (inventory.total_items == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n--- Grocery Items ---\n");
    for (int i = 0; i < inventory.total_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inventory.items[i].name);
        printf("Category: %s\n", inventory.items[i].category);
        printf("Quantity: %d\n", inventory.items[i].quantity);
        printf("Price: $%.2f\n", inventory.items[i].price);
        printf("Availability: %s\n", 
               inventory.status[i].in_stock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}


// function to adjust value of items
void updateQuantity(GroceryInventory *inventory) {
    if (inventory->total_items == 0) {
        printf("No items in inventory to update.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->total_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory->items[i].quantity);
            getchar();

            inventory->status[i].in_stock = inventory->items[i].quantity > 0;
            inventory->status[i].out_of_stock = inventory->items[i].quantity == 0;

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}


// function to remove items from grocery list
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->total_items == 0) {
        printf("No items in inventory to remove.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < inventory->total_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->total_items - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
                inventory->status[j] = inventory->status[j + 1];
            }
            inventory->total_items--;
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
