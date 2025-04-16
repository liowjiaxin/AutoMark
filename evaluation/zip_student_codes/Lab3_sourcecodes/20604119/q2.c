//q2

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of grocery items that can be stored

typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int in_stock;
    int out_of_stock;
} GroceryItem;

GroceryItem inventory[MAX_ITEMS];
int item_count = 0;

// Function to add a new grocery item to the inventory
void addGroceryItem() {
    if (item_count >= MAX_ITEMS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    // Prompt user for item details
    printf("Enter item name: ");
    scanf("%99s", inventory[item_count].name);
    printf("Enter category: ");
    scanf("%49s", inventory[item_count].category);
    printf("Enter quantity: ");
    scanf("%d", &inventory[item_count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[item_count].price);

    // Set the stock status
    inventory[item_count].in_stock = 1;
    inventory[item_count].out_of_stock = 0;
    item_count++;

    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items in the inventory
void listAllGroceryItems() {
    if (item_count == 0) {
        printf("No grocery items in the inventory.\n");
        return;
    }

    // Display the list of items
    printf("Grocery Item List:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%s (%s) - Quantity: %d, Price: $%.2f, Status: %s\n",
               inventory[i].name, inventory[i].category, inventory[i].quantity,
               inventory[i].price, inventory[i].in_stock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    printf("Enter the name of the grocery item to update quantity: ");
    scanf("%99s", name);

    int found = 0; // Flag to track if the item is found
    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Grocery item not found.\n");
    }
}

// Function to remove a grocery item from the inventory
void removeGroceryItem() {
    char name[100];
    printf("Enter the name of the grocery item to remove: ");
    scanf("%99s", name);

    int found = 0; //flag tracks if the item is found
    for (int i = 0; i < item_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < item_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            item_count--;
            printf("Grocery item '%s' removed successfully!\n", name);
            found = 1;
            break;
        }
    }

    if (!found) { // If item is not found
        printf("Error: Grocery item not found.\n");
    }
}

// Main function to display the menu and handle user choices
int main() {
    int choice;

    while (1) { // Infinite loop for the menu
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handles menu choices using a switch statement
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
                printf("Exiting Grocery Inventory Management System...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
