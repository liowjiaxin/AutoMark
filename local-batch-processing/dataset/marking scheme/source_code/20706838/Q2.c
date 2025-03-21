#include <stdio.h>
#include <string.h>

#define maximumItems 100 // Maximum number of grocery items to be stored

// Structure for a grocery item
typedef struct {
    char name[100];
    char category[50];
    int quantity;
    float price;
    int inStock; // 1 for in stock, 0 for out of stock
} GroceryItem;

// Function to add an item to the inventory
void addItem(GroceryItem inventory[], int *count) {
    if (*count >= maximumItems) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", inventory[*count].name);
    printf("Enter category: ");
    scanf(" %[^\n]", inventory[*count].category);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*count].price);

    if (inventory[*count].quantity > 0) {
    inventory[*count].inStock = 1;
} else {
    inventory[*count].inStock = 0;
}
(*count)++;


}

// Function to list all items in the inventory
void listItems(GroceryItem inventory[], int count) {
    printf("Inventory List:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%s) - %d @ %.2f (%s)\n",
               inventory[i].name, inventory[i].category, inventory[i].quantity, inventory[i].price,
               inventory[i].inStock ? "In Stock" : "Out of Stock");
    }
}

// Function to update the quantity of an item
void updateQuantity(GroceryItem inventory[], int count) {
    char name[100];
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            inventory[i].inStock = inventory[i].quantity > 0 ? 1 : 0;
            return;
        }
    }

    printf("Item not found.\n");
}

// Function to remove an item from the inventory
void removeItem(GroceryItem inventory[], int *count) {
    char name[100];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift items to remove the selected one
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Item removed.\n");
            return;
        }
    }

    printf("Item not found.\n");
}

int main() {
    GroceryItem inventory[maximumItems];
    int count = 0; // Number of items in the inventory
    int choice;

    do {
        printf("\nGrocery Inventory Management System:\n");
        printf("1. Add Grocery Item\n");
        printf("2. List All Grocery Items\n");
        printf("3. Update Quantity\n");
        printf("4. Remove Grocery Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                listItems(inventory, count);
                break;
            case 3:
                updateQuantity(inventory, count);
                break;
            case 4:
                removeItem(inventory, &count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
