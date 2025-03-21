#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ITEMS 100       // Maximum number of grocery items
#define NAME 100        // Maximum length for item name
#define CATEGORY 50     // Maximum length for item category

// Struct for Grocery Item
typedef struct {
    char name[NAME];
    char category[CATEGORY];
    int quantity;
    float price;
    bool inStock;                   // Availability status, true = in stock, false = out of stock
} GroceryItem;

// Inventory
GroceryItem inventory[ITEMS]; // Array to store grocery items
int itemCount = 0;                // Current count of items in inventory

// Function prototypes
void addGroceryItem();
void listAllGroceryItems();
void updateQuantity();
void removeGroceryItem();
void displayMenu();

int main() {
    int choice;

    // Menu loop
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                addGroceryItem(); 
                break;
            case 2:
                listAllGroceryItems(); 
                break;
            case 3:
                updateQuantity(); 
                break;
            case 4:
                removeGroceryItem();
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

// Display menu options
void displayMenu() {
    printf("\nGrocery Inventory Management System\n");
    printf("1. Add Grocery Item\n");
    printf("2. List All Grocery Items\n");
    printf("3. Update Quantity\n");
    printf("4. Remove Grocery Item\n");
    printf("5. Exit\n");
}

// Add a new grocery item
void addGroceryItem() {
    if (itemCount >= ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;

    // Input item details
    printf("Enter Item Name: ");
    fgets(newItem.name, NAME, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(newItem.category, CATEGORY, stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    getchar();

    // Set stock status based on quantity
    newItem.inStock = (newItem.quantity > 0);

    // Add item to inventory and increment item count
    inventory[itemCount++] = newItem;

    printf("Grocery item added successfully!\n");
}

// List all grocery items
void listAllGroceryItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        // Print details of each item
        printf("\nName: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Update the quantity of a specific item
void updateQuantity() {
    char name[NAME];

    // Input the name of the item to update
    printf("Enter the name of the grocery item to update: ");
    fgets(name, NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // If item found, update its quantity
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            getchar();

            // Update stock status based on the new quantity
            inventory[i].inStock = (inventory[i].quantity > 0);
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    // If item is not found
    printf("Item not found.\n");
}

// Remove a specific item from the inventory
void removeGroceryItem() {
    char name[NAME];

    // Input the name of the item to remove
    printf("Enter the name of the grocery item to remove: ");
    fgets(name, NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // If item found, shift remaining items to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }

            // Decrement item count
            itemCount--;
            printf("Grocery item removed successfully!\n");
            return;
        }
    }

    // If item is not found
    printf("Item not found.\n");
}
