#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME 100
#define MAX_CATEGORY 50

// Structure for grocery items
typedef struct 
{
    char name[MAX_NAME];
    char category[MAX_CATEGORY];
    int quantity;
    float price;
} GroceryItem;

// Structure for checking availability of the products
typedef struct
{
    int inStock;
    int outOfStock;
} Availibility;

// Structure for the inventory
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Holds grocery item data
    Availibility availibility[MAX_ITEMS]; // Holds availability status
    int count; // Number of items in inventory
} Inventory;

// Function declarations
void addItem(Inventory *inventory);
void listItems(const Inventory *inventory);
void updateQuantity(Inventory *inventory);
void removeItem(Inventory *inventory);
int findItemIndex(const Inventory *inventory, const char *name);
void menu();

int main() {
    int choice;
    Inventory inventory = {.count = 0}; // Initialize inventory
    do {
        menu(); // Display menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline left by scanf

        switch (choice) {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                listItems(&inventory);
                break;
            case 3:
                updateQuantity(&inventory);
                break;
            case 4:
                removeItem(&inventory);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void menu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add grocery item\n");
    printf("2. List all grocery items\n");
    printf("3. Update quantity of a grocery item\n");
    printf("4. Remove grocery item from inventory\n");
    printf("5. Exit\n");
}

// Add grocery items to the inventory
void addItem(Inventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    GroceryItem newItem; // Temporarily stores the new item's details
    Availibility newstatus; // Temporarily stores the availability of the item

    // Input details for new item
    printf("Enter the name of the grocery item: ");
    fgets(newItem.name, MAX_NAME, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

    printf("Enter the category of the item: ");
    fgets(newItem.category, MAX_CATEGORY, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0'; // Remove newline character

    printf("Enter the quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter the price: ");
    scanf("%f", &newItem.price);

    // Set the stock availability
    if (newItem.quantity > 0) {
        newstatus.inStock = 1;
        newstatus.outOfStock = 0;
    } else {
        newstatus.inStock = 0;
        newstatus.outOfStock = 1;
    }

    // Add the new item to the inventory
    inventory->items[inventory->count] = newItem;
    inventory->availibility[inventory->count] = newstatus;
    inventory->count++; // Increase the count of items in the inventory

    printf("Item added successfully!\n");
}

// List all grocery items in the inventory
void listItems(const Inventory *inventory) {
    if (inventory->count == 0) {
        printf("No items found.\n");
        return;
    }
    printf("Items in the inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem item = inventory->items[i]; // Get the grocery item
        Availibility status = inventory->availibility[i]; // Get availability status
        printf("\nItem: %s\n", item.name);
        printf("Category: %s\n", item.category);
        printf("Quantity: %d\n", item.quantity);
        printf("Price: %.2f\n", item.price);
        printf("Availability: %s\n", status.inStock ? "In Stock" : "Out of Stock");
    }
}

// Update quantity of a grocery item in the inventory
void updateQuantity(Inventory *inventory) {
    char itemName[MAX_NAME]; // Store the item name temporarily
    printf("Enter the name of the grocery item to update: ");
    fgets(itemName, MAX_NAME, stdin);
    itemName[strcspn(itemName, "\n")] = '\0'; // Remove newline character

    int index = findItemIndex(inventory, itemName); // Find the index of the item
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    int updatedQuantity; // Store updated quantity
    printf("Enter the quantity for %s: ", itemName);
    scanf("%d", &updatedQuantity);

    // Update the item's quantity and availability
    inventory->items[index].quantity = updatedQuantity;
    if (updatedQuantity > 0) {
        inventory->availibility[index].inStock = 1;
        inventory->availibility[index].outOfStock = 0;
    } else {
        inventory->availibility[index].inStock = 0;
        inventory->availibility[index].outOfStock = 1;
    }
    printf("Quantity updated successfully!\n");
}

// Remove a grocery item from the inventory
void removeItem(Inventory *inventory) {
    char itemName[MAX_NAME];
    printf("Enter the grocery item you want to remove: ");
    fgets(itemName, MAX_NAME, stdin);
    itemName[strcspn(itemName, "\n")] = '\0'; // Remove newline character

    int index = findItemIndex(inventory, itemName); // Find the index of the item
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    // Shift items to the left to remove the selected item
    for (int i = index; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1]; // Shift the item data to left
        inventory->availibility[i] = inventory->availibility[i + 1]; // Shift the availability status
    }

    inventory->count--; // Decrease the total count of items in the inventory
    printf("Item removed successfully!\n");
}

// Function to find the index of an item in the inventory by name
int findItemIndex(const Inventory *inventory, const char *name) {
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return i; // Return the index of the item if found
        }
    }
    return -1; // Return -1 if the item is not found
}
