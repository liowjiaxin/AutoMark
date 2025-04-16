#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100

// Define a structure for Grocery Item
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    bool inStock;
} GroceryItem;

// Array to hold all grocery items
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0; // Total number of items in the inventory

// Function prototypes
void addItem();
void listItems();
void updateQuantity();
void removeItem();
void menu();

int main() {
    menu();
    return 0;
}

// Function to display the menu and handle user choices
void menu() {
    int choice;
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity \n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the choice

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

// Function to add a grocery item to the inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem newItem;
    printf("Enter item name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    getchar();

    // Determine availability based on quantity
    newItem.inStock = (newItem.quantity > 0);

    // Add the item to the inventory
    inventory[itemCount++] = newItem;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items with their details
void listItems() {
    if (itemCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("  Name: %s\n", inventory[i].name);
        printf("  Category: %s\n", inventory[i].category);
        printf("  Quantity: %d\n", inventory[i].quantity);
        printf("  Price: %.2f\n", inventory[i].price);
        printf("  Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a specific grocery item
void updateQuantity() {
    if (itemCount == 0) {
        printf("No items in the inventory to update.\n");
        return;
    }

    char itemName[100];
    printf("Enter the name of the item to update quantity: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            getchar();

            // Update availability status
            inventory[i].inStock = (inventory[i].quantity > 0);

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

// Function to remove a grocery item from the inventory
void removeItem() {
    if (itemCount == 0) {
        printf("No grocery ite\n");
        return;
    }

    char itemName[100];
    printf("Enter the name of the item to remove: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift items down to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}
