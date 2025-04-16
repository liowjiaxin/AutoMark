#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define max sizes
#define MAX_GROCERY_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Define a boolean type for clarity
typedef enum { false, true } bool;

// Structure for Grocery Item
typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
} GroceryItem;

// Availability Status structure
typedef struct {
    bool inStock;
} AvailabilityStatus;

// Grocery Inventory structure
typedef struct {
    GroceryItem items[MAX_GROCERY_ITEMS];
    AvailabilityStatus availability[MAX_GROCERY_ITEMS];
    int count;
} GroceryInventory;

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);

void listGroceryItems(GroceryInventory *inventory, int index);

void updateItemQuantity(GroceryInventory *inventory);

void removeGroceryItem(GroceryInventory *inventory);

int main() {
    GroceryInventory inventory;
    inventory.count = 0;

    int choice;
    //using do while loops to make sure the body of code executes at least once
    do {
        printf("\nGrocery Inventory Menu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Item Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        //Using switch as it's faster than if-else and also more easier to debug
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);
                break;
            case 2:
                if (inventory.count == 0) {
                    printf("No items in inventory.\n");
                } else {
                    printf("Listing all items:\n");
                    listGroceryItems(&inventory, 0); // recursive list, more recursion yay!!!
                }
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
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_GROCERY_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    strtok(newItem.name, "\n");

    printf("Enter Category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    strtok(newItem.category, "\n");

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    getchar();

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar();

    // Determine availability
    AvailabilityStatus newStatus;
    newStatus.inStock = newItem.quantity > 0 ? true : false;

    // Insert into inventory
    inventory->items[inventory->count] = newItem;
    inventory->availability[inventory->count] = newStatus;
    inventory->count++;

    printf("Item added successfully.\n");
}

// Recursive function to list all grocery items
void listGroceryItems(GroceryInventory *inventory, int index) {
    if (index >= inventory->count) {
        return; // base case
    }
    GroceryItem *current = &inventory->items[index];
    AvailabilityStatus *stat = &inventory->availability[index];

    printf("Item %d:\n", index + 1);
    printf("Name: %s\n", current->name);
    printf("Category: %s\n", current->category);
    printf("Quantity: %d\n", current->quantity);
    printf("Price: %.2f\n", current->price);
    printf("Availability: %s\n", stat->inStock ? "In Stock" : "Out of Stock");
    printf("\n");

    // Recursively list next item
    listGroceryItems(inventory, index + 1);
}

// Function to update item quantity
void updateItemQuantity(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items to update.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter the name of the item to update: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    int foundIndex = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            foundIndex = i;
            break;
        }
    }

    foundIndex == -1
        ? printf("Item not found.\n")
        : (printf("Enter new quantity: "),
           scanf("%d", &inventory->items[foundIndex].quantity),
           getchar(),
           inventory->availability[foundIndex].inStock = inventory->items[foundIndex].quantity > 0 ? true : false,
           printf("Quantity updated.\n"));
}

// Function to remove a grocery item
void removeGroceryItem(GroceryInventory *inventory) {
    if (inventory->count == 0) {
        printf("No items to remove.\n");
        return;
    }

    char itemName[MAX_NAME_LEN];
    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    strtok(itemName, "\n");

    int foundIndex = -1;
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Item not found.\n");
        return;
    }

    // Shift all items after foundIndex one step left
    for (int j = foundIndex; j < inventory->count - 1; j++) {
        inventory->items[j] = inventory->items[j + 1];
        inventory->availability[j] = inventory->availability[j + 1];
    }

    inventory->count--;
    printf("Item removed successfully.\n");
}
