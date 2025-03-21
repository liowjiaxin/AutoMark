#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100 // Define the maximum number of items in the inventory

// Define a structure to represent a grocery item
typedef struct {
    char name[100];       // Name of the item
    char category[50];    // Category of the item
    int quantity;         // Quantity of the item in stock
    float price;          // Price of the item
    int inStock;          // Stock status (1 for in stock, 0 for out of stock)
} GroceryItem;

// Declare an array to hold the inventory items
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0; // Keep track of the number of items in the inventory

// Function to add a new item to the inventory
void addItem() {
    if (itemCount >= MAX_ITEMS) { // Check if inventory is full
        printf("Inventory full.\n");
        return;
    }

    GroceryItem item; // Create a new item
    printf("Enter item name: ");
    scanf(" %[^\"\n]s", item.name); // Read item name (handles spaces)
    printf("Enter category: ");
    scanf(" %[^\"\n]s", item.category); // Read category
    printf("Enter quantity: ");
    scanf("%d", &item.quantity); // Read quantity
    printf("Enter price: ");
    scanf("%f", &item.price); // Read price
    item.inStock = item.quantity > 0; // Update stock status based on quantity

    inventory[itemCount++] = item; // Add the item to the inventory and increment count
    printf("Item added successfully!\n");
}

// Function to list all items in the inventory
void listItems() {
    for (int i = 0; i < itemCount; i++) { // Loop through each item in the inventory
        printf("%s (%s) - Quantity: %d, Price: %.2f, Status: %s\n",
               inventory[i].name, inventory[i].category, inventory[i].quantity,
               inventory[i].price, inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an item
void updateQuantity() {
    char name[100];
    printf("Enter item name to update quantity: ");
    scanf(" %[^\"\n]s", name); // Read item name (handles spaces)

    for (int i = 0; i < itemCount; i++) { // Search for the item by name
        if (strcmp(inventory[i].name, name) == 0) { // Check if names match
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity); // Update quantity
            inventory[i].inStock = inventory[i].quantity > 0; // Update stock status
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n"); // If the item was not found
}

// Function to remove an item from the inventory
void removeItem() {
    char name[100];
    printf("Enter item name to remove: ");
    scanf(" %[^\"\n]s", name); // Read item name (handles spaces)

    for (int i = 0; i < itemCount; i++) { // Search for the item by name
        if (strcmp(inventory[i].name, name) == 0) { // Check if names match
            for (int j = i; j < itemCount - 1; j++) { // Shift items to fill the gap
                inventory[j] = inventory[j + 1];
            }
            itemCount--; // Decrease the item count
            printf("Item removed successfully!\n");
            return;
        }
    }

    printf("Item not found.\n"); // If the item was not found
}

int main() {
    int choice; // Variable to store user's menu choice

    // Menu-driven program for inventory management
    do {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a new item
                addItem();
                break;
            case 2: // List all items
                listItems();
                break;
            case 3: // Update the quantity of an item
                updateQuantity();
                break;
            case 4: // Remove an item
                removeItem();
                break;
            case 5: // Exit the program
                printf("Exiting program.\n");
                break;
            default: // Handle invalid menu choices
                printf("Invalid choice!\n");
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0; // Exit the program
}
