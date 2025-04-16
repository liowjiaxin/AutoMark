#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_GROCERY_ITEMS 100

// Structure to store grocery items
struct groceryItem {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
};

// Grocery inventory array and count
struct groceryItem inventory[MAX_GROCERY_ITEMS];
int inventoryCount = 0;

// Declaring all void function to be used in menu
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main () {
    while (1) {
        int choice;

        printf("Grocery Inventory Management System\n");
        printf("1. Add Grocery Items\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Please pick a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}

void addGroceryItem() {
    if (inventoryCount >= MAX_GROCERY_ITEMS) {
        printf("Inventory is full.\n");
    }

    struct groceryItem item;   // using struct

    printf("Enter Item Name: ");
    getchar(); // Consume leftover newline
    scanf("%[^\n]", item.name);   // read all characters until newline is found ([^\n])

    printf("Enter Category: ");
    getchar(); // Consume leftover newline
    scanf("%[^\n]", item.category);   // read all characters until newline is found ([^\n])

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter Price: ");
    scanf("%f", &item.price);

    inventory[inventoryCount++] = item;   // after adding one item, inventory[0] is filled, and inventoryCount becomes 1, next item will be stored in inventory[1]
    printf("Grocery item added successfully!\n\n");
}

void listGroceryItems() {
    if (inventoryCount == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }
    // using for loop to list grocery item one by one
    for (int i = 0; i < inventoryCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].quantity > 0 ? "In Stock" : "Out of Stock");   // using ternary operator to decide whether item in stock or not
        printf("\n");
    }

    printf("\n");
}

void updateQuantity() {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to update quantity: ");
    getchar();  // Consume leftover newline from previous input
    scanf("%[^\n]", itemName);   // Read item name including spaces

    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {   // Compare input name with inventory
            printf("Enter new quantity for %s: ", inventory[i].name);
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully!\n\n");
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}

void removeGroceryItem() {
    char itemName[MAX_NAME_LENGTH];
    printf("Enter name of the grocery item to remove: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift all items after the removed item
            for (int j = i; j < inventoryCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            inventoryCount--;
            printf("Grocery item '%s' removed successfully!\n\n", itemName);
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}
