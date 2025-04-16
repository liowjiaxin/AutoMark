#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct for Grocery Item
typedef struct {
    char name[100]; // Name of the grocery item
    char category[50]; // Category of the grocery item
    int quantity; // Quantity available
    float price; // Price per item
} GroceryItem;

// Array for Grocery Items
GroceryItem inventory[MAX_ITEMS];
int total_items = 0; // Total number of items in the inventory

// Function prototypes
void addGroceryItem();
void listGroceryItems();
void updateQuantity();
void removeGroceryItem();

int main() {
    int choice;

    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a grocery item
void addGroceryItem() {
    if (total_items >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    GroceryItem item;
    printf("Enter Item Name: ");
    fgets(item.name, 100, stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // Remove newline character

    printf("Enter Category: ");
    fgets(item.category, 50, stdin);
    item.category[strcspn(item.category, "\n")] = '\0'; // Remove newline character

    printf("Enter Quantity: ");
    scanf("%d", &item.quantity);
    getchar(); // Consume newline character

    printf("Enter Price: ");
    scanf("%f", &item.price);
    getchar(); // Consume newline character

    inventory[total_items++] = item;
    printf("Grocery item added successfully!\n");
}

// Function to list all grocery items
void listGroceryItems() {
    if (total_items == 0) {
        printf("No items in the inventory.\n");
        return;
    }

    for (int i = 0; i < total_items; i++) {
        printf("\nName: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n", inventory[i].quantity > 0 ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    char name[100];
    printf("Enter name of the grocery item to update quantity: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < total_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &inventory[i].quantity);
            getchar(); // Consume newline character

            printf("Quantity updated successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}

// Function to remove a grocery item
void removeGroceryItem() {
    char name[100];
    printf("Enter name of the grocery item to remove: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < total_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < total_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            total_items--;
            printf("Grocery item removed successfully!\n");
            return;
        }
    }

    printf("Item not found in the inventory.\n");
}
