#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of grocery items

// Struct for grocery items
typedef struct {
    char name[50];
    char category[20];
    int quantity;
    float price;
    int inStock; 
} GroceryItem;

// Global variables
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;

// Function to add a grocery item
void addItem() {

    GroceryItem newItem;
    printf("Enter Item name: ");
    getchar(); // To clear the newline left by scanf
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline
    printf("Enter category: ");
    fgets(newItem.category, sizeof(newItem.category), stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    newItem.inStock = (newItem.quantity > 0) ? 1 : 0; // Set stock status

    inventory[itemCount] = newItem; // Add item to inventory
    itemCount++;
    printf("Item added successfully!\n");
}
// Function to list all grocery items
void listItems() {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Category: %s\n", inventory[i].category);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Status: %s\n\n", inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of a grocery item
void updateQuantity() {
    if (itemCount == 0) {
        printf("Inventory is empty! Add items first.\n");
        return;
    }
    char itemName[50];
    int newQuantity;
    printf("Enter name of the grocery item to update quantity: ");
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter new quantity for %s: ", inventory[i].name);
            scanf("%d", &newQuantity);

            inventory[i].quantity = newQuantity;
            inventory[i].inStock = (newQuantity > 0) ? 1 : 0;

            printf("Quantity updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: Item not found in inventory.\n");
    }
}

// Function to remove a grocery item
void removeItem() {
    if (itemCount == 0) {
        printf("Inventory is empty! Add items first.\n");
        return;
    }
    char itemName[50];
    printf("Enter name of the grocery item to remove: ");
    getchar();
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            // Shift items to "delete" the selected one
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;

            printf("Item removed successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Item not found in inventory.\n");
    }
}

int main() {
    int choice;

    // Menu loop
    do {
        printf("\nGrocery Inventory Management System\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addItem();
        } else if (choice == 2) {
            listItems();
        } else if (choice == 3) {
            updateQuantity();
        } else if (choice == 4) {
            removeItem();
        } else if (choice == 5) {
            printf("Goodbye, my 100 plus is super expensive.\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

