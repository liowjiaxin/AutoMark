#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum sizes
#define MAX_ITEMS 100
#define NAME_LENGTH 100
#define CATEGORY_LENGTH 50

// Define struct for Grocery Item
typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
    int inStock; // 1 if in stock, 0 for no stock
} GroceryItem;

// Define struct for grocery Inventory
typedef struct {
    GroceryItem items[MAX_ITEMS];
    int count;
} GroceryInventory;

// Function to add a grocery item to the inventory
void addItem(GroceryInventory *inventory) {
    if ((*inventory).count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem *item = &((*inventory).items[(*inventory).count]);
    printf("Enter item name: ");
    fgets((*item).name, NAME_LENGTH, stdin);
    (*item).name[strcspn((*item).name, "\n")] = '\0'; // Remove '\n' character

    printf("Enter item category: ");
    fgets((*item).category, CATEGORY_LENGTH, stdin);
    (*item).category[strcspn((*item).category, "\n")] = '\0'; // Remove '\n' character

    printf("Enter item quantity: ");
    scanf("%d", &(*item).quantity);
    getchar(); // Remove '\n' left by scanf

    printf("Enter item price: ");
    scanf("%f", &(*item).price);
    getchar(); // Remove '\n' left by scanf

    (*item).inStock = (*item).quantity > 0 ? 1 : 0; // Set availability status
    (*inventory).count++;

    printf("Item added successfully!\n");
}

// Function to list all grocery items with their availability
void listItems(GroceryInventory *inventory) {
    if ((*inventory).count == 0) { // Checks if inventory is empty or not
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < (*inventory).count; i++) {
        GroceryItem *item = &((*inventory).items[i]);
        printf("Name: %s\n", (*item).name);
        printf("Category: %s\n", (*item).category);
        printf("Quantity: %d\n", (*item).quantity);
        printf("Price: %.2f\n", (*item).price);
        printf("Status: %s\n", (*item).inStock ? "In Stock" : "Out of Stock");
        printf("\n");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity(GroceryInventory *inventory) {
    if ((*inventory).count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter item name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove '\n' character

    for (int i = 0; i < (*inventory).count; i++) {
        GroceryItem *item = &((*inventory).items[i]);
        if (strcmp((*item).name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &(*item).quantity);
            getchar(); // Remove '\n' left by scanf
            (*item).inStock = (*item).quantity > 0 ? 1 : 0; // Update availability status
            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to remove a grocery item from the inventory
void removeItem(GroceryInventory *inventory) {
    if ((*inventory).count == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter item name: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove '\n' character

    // Use linear search to look for the item name
    for (int i = 0; i < (*inventory).count; i++) {
        // Check if the item name matches the input
        if (strcmp((*inventory).items[i].name, name) == 0) {
            for (int j = i; j < (*inventory).count - 1; j++) {
                (*inventory).items[j] = (*inventory).items[j + 1];
            }
            (*inventory).count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    GroceryInventory inventory;
    inventory.count = 0; // Initialize inventory count

    int choice;
    while (1) {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List Grocery Items\n");
        printf("3. Update Grocery Item\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove '\n' character left by scanf

        // Use switch case to determine what function to use
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
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
