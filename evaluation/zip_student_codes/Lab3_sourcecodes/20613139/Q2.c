#include <stdio.h>
#include <string.h>

// Define maximum sizes for arrays
#define MAX_ITEMS 100
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50

// Struct to store grocery item information
typedef struct {
    char name[MAX_NAME_LEN];       // Name of the item
    char category[MAX_CATEGORY_LEN]; // Category of the item
    int quantity;                 // Quantity of the item
    float price;                  // Price of the item
    int inStock;                  // Availability status (1 = in stock, 0 = out of stock)
} GroceryItem;

// Function declarations
void addItem(GroceryItem inventory[], int* count);
void listItems(GroceryItem inventory[], int count);
void updateQuantity(GroceryItem inventory[], int count);
void removeItem(GroceryItem inventory[], int* count);

int main() {
    GroceryItem inventory[MAX_ITEMS]; // Array to store grocery items
    int itemCount = 0;                // Current number of items in inventory
    int choice;

    do {
        // Display menu options
        printf("\nGrocery Inventory Management\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount); // Add a new item to the inventory
                break;
            case 2:
                listItems(inventory, itemCount); // List all items with their details
                break;
            case 3:
                updateQuantity(inventory, itemCount); // Update the quantity of an existing item
                break;
            case 4:
                removeItem(inventory, &itemCount); // Remove an item from the inventory
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

// Function to add a new item to the inventory
void addItem(GroceryItem inventory[], int* count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    // Input details for the new item
    printf("Enter item name: ");
    fgets(newItem.name, MAX_NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character

    printf("Enter item category: ");
    fgets(newItem.category, MAX_CATEGORY_LEN, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0'; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    // Set availability based on quantity
    newItem.inStock = (newItem.quantity > 0);

    // Add the new item to the inventory
    inventory[*count] = newItem;
    (*count)++;

    printf("Grocery item added successfully!\n");
}

// Function to list all items in the inventory
void listItems(GroceryItem inventory[], int count) {
    if (count == 0) {
        printf("No Grocery items in the inventory.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", inventory[i].name);
        printf("  Category: %s\n", inventory[i].category);
        printf("  Quantity: %d\n", inventory[i].quantity);
        printf("  Price: %.2f\n", inventory[i].price);
        printf("  Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an existing item
void updateQuantity(GroceryItem inventory[], int count) {
    char itemName[MAX_NAME_LEN];
    int newQuantity;

    // Input the name of the item to update
    printf("Enter the name of the item to update: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = '\0'; // Remove newline character

    // Search for the item in the inventory
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);

            // Update the item's quantity and availability status
            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove an item from the inventory
void removeItem(GroceryItem inventory[], int* count) {
    char itemName[MAX_NAME_LEN];

    // Input the name of the item to remove
    printf("Enter the name of the item to remove: ");
    fgets(itemName, MAX_NAME_LEN, stdin);
    itemName[strcspn(itemName, "\n")] = '\0'; // Remove newline character

    // Search for the item in the inventory
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift all items after the removed item
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            (*count)--; // Decrease the count of items
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}
