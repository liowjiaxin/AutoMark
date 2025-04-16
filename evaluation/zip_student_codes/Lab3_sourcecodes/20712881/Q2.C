#include <stdio.h>
#include <string.h>  // For string manipulation functions like strcmp

#define MAX_ITEMS 100 // Maximum number of items allowed in the inventory

// Structure to represent each grocery item
typedef struct {
    char name[100];          // Name of the item
    char category[50];       // Category of the item (e.g., dairy, produce, etc.)
    int quantity;            // Available stock quantity
    float price;             // Price per unit of the item
} GroceryItem;               // Structure that stores details about a single grocery item

// Structure to represent the grocery inventory
typedef struct {
    GroceryItem items[MAX_ITEMS]; // Array to store all grocery items in the inventory
    int count;                    // Keeps track of how many items are in the inventory
} GroceryInventory;             // Structure to represent the inventory of all items

// Function prototypes
void addGroceryItem(GroceryInventory *inventory);  // Add a new grocery item
void listGroceryItems(const GroceryInventory *inventory);  // List all grocery items
void updateQuantity(GroceryInventory *inventory);  // Update the quantity of an existing item
void removeGroceryItem(GroceryInventory *inventory);  // Remove an item from the inventory

int main() {
    GroceryInventory inventory = { .count = 0 }; // Initialize the inventory with zero items
    int choice;  // Store user's menu selection

    do {
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in input buffer

        // Execute the appropriate function based on user's choice
        switch (choice) {
            case 1:
                addGroceryItem(&inventory);  // Add a new item to inventory
                break;
            case 2:
                listGroceryItems(&inventory);  // Display all items in the inventory
                break;
            case 3:
                updateQuantity(&inventory);  // Update the quantity of an existing item
                break;
            case 4:
                removeGroceryItem(&inventory);  // Remove an item from the inventory
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);  // Continue looping until the user selects 'Exit'

    return 0;
}

// Function to add a new grocery item to the inventory
void addGroceryItem(GroceryInventory *inventory) {
    if (inventory->count >= MAX_ITEMS) {  // Check if inventory is full
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &inventory->items[inventory->count];  // Get the next available slot

    // Prompt user to enter details of the new item
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", item->name);
    printf("Enter category: ");
    scanf(" %[^\n]%*c", item->category);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);

    inventory->count++;  // Increment the count of items in inventory
    printf("Item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listGroceryItems(const GroceryInventory *inventory) {
    if (inventory->count == 0) {  // If there are no items in inventory
        printf("No items in inventory.\n");
        return;
    }

    // Loop through the inventory and print details of each item
    printf("\nGrocery Items:\n");
    for (int i = 0; i < inventory->count; i++) {
        const GroceryItem *item = &inventory->items[i];
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", item->name);
        printf("  Category: %s\n", item->category);
        printf("  Quantity: %d\n", item->quantity);
        printf("  Price: %.2f\n", item->price);
        printf("  Availability: %s\n", item->quantity > 0 ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an existing grocery item
void updateQuantity(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to update quantity: ");
    scanf(" %[^\n]%*c", name);

    // Search for the item in the inventory
    for (int i = 0; i < inventory->count; i++) {
        GroceryItem *item = &inventory->items[i];
        if (strcmp(item->name, name) == 0) {  // Check if the item matches the name
            printf("Enter new quantity: ");
            scanf("%d", &item->quantity);  // Update the quantity
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeGroceryItem(GroceryInventory *inventory) {
    char name[100];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]%*c", name);

    // Search for the item and shift subsequent items to fill the gap
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {  // Check if the item matches the name
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];  // Shift items left
            }
            inventory->count--;  // Decrease the item count
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}
