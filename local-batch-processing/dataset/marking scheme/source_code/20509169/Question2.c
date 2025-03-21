#include <stdio.h>
#include <string.h>

// Define a struct to represent a Grocery Item
typedef struct {
    char name[100];        // Name of the grocery item (max length: 100)
    char category[50];     // Category of the item (max length: 50)
    int quantity;          // Quantity of the item
    float price;           // Price of the item
    int inStock;           // Availability status (1: in stock, 0: out of stock)
} GroceryItem;

// Global array to store grocery items
GroceryItem inventory[100];
int itemCount = 0; // Tracks the total number of items in the inventory

// Function prototypes
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice; // Variable to store user's menu choice

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity of an Item\n");
        printf("4. Remove a Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        // Handle menu choices
        switch (choice) {
            case 1:
                addGroceryItem();
                break;
            case 2:
                listGroceryItems();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeGroceryItem();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5); // Exit loop when user selects 5

    return 0;
}

// Function to add a grocery item
void addGroceryItem() {
    if (itemCount >= 100) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    // Get details of the new item from the user
    printf("Enter item name: ");
    fgets(inventory[itemCount].name, 100, stdin);
    strtok(inventory[itemCount].name, "\n"); // Remove newline character

    printf("Enter category: ");
    fgets(inventory[itemCount].category, 50, stdin);
    strtok(inventory[itemCount].category, "\n"); // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[itemCount].price);

    inventory[itemCount].inStock = inventory[itemCount].quantity > 0 ? 1 : 0; // Determine availability

    itemCount++; // Increment item count
    printf("Item added successfully.\n");
}

// Function to list all grocery items
void listGroceryItems() {
    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    int found = 0;

    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    // Ask for the name of the item to update
    printf("Enter the name of the item to update: ");
    fgets(name, 100, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            inventory[i].inStock = inventory[i].quantity > 0 ? 1 : 0; // Update availability
            printf("Quantity updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

// Function to remove a grocery item
void removeGroceryItem() {
    char name[100];
    int found = 0;

    if (itemCount == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    // Ask for the name of the item to remove
    printf("Enter the name of the item to remove: ");
    fgets(name, 100, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift items to overwrite the removed item
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--; // Decrease item count
            printf("Item removed successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}